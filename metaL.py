import os,sys,threading
from __builtin__ import isinstance

print sys.argv

#################################################### Marvin Minsky frame model

class Frame:
    def __init__(self,V):
        self.type = self.__class__.__name__.lower()
        self.val  = V
        self.slot = {}
        self.nest = []

    def __repr__(self):
        return self.dump()
    def dump(self,depth=0,prefix=''):
        tree = self.pad(depth) + self.head(prefix)
        if not depth: Frame.dumped = []
        if self in Frame.dumped: return tree + ' _/'
        else: Frame.dumped.append(self)
        for i in self.slot:
            tree += self.slot[i].dump(depth+1,i+' = ')
        for j in self.nest:
            tree += j.dump(depth+1)
        return tree
    def head(self,prefix=''):
        return '%s<%s:%s> @%x' % \
            (prefix,self.type,self.str(),id(self))
    def pad(self,n):
        return '\n' + '\t' * n
    def str(self):
        return self.val

    def __floordiv__(self,that):
        if isinstance(that,str): return self // Str(that)
        if not isinstance(that, Frame): return self // Frame(that)
        return self.push(that)
        
    def __lshift__(self,that):
        if callable(that): return self << Cmd(that)
        self[that.val] = that ; return self
    def __setitem__(self,key,that):
        self.slot[key] = that ; return self
    def __getitem__(self,key):
        return self.slot[key]

    def push(self,that):
        self.nest.append(that) ; return self
    def pop(self):
        return self.nest.pop()
    def top(self):
        return self.nest[-1]
    def dup(self):
        return self // self.top()
    def drop(self):
        self.nest.pop() ; return self
    def dropall(self):
        self.nest = [] ; return self
        
    def __add__(self,that): raise SyntaxError((self,'+',that))
        
    def eval(self):
        S // self
    
############################################################## primitive types

class Prim(Frame): pass

class Sym(Prim): pass

class Str(Prim):
    def str(self):
        dump = ''
        for c in self.val:
            if c == '\n': dump += '\\n'
            else: dump += c
        return dump
    def __add__(self,that):
        return Str(self.val + that.val)

class Num(Prim): pass

class Int(Num): pass

class Hex(Int): pass

class Bin(Hex): pass

############################################################## data containers

class Cont(Frame): pass

class Stack(Cont): pass

class Dict(Cont): pass

####################################### active objects has execution semantics

class Active(Frame): pass

class Cmd(Active):
    def __init__(self,F):
        Frame.__init__(self, F.__name__)
        self.fn = F
    def eval(self):
        self.fn()

################################################################# input/output

class IO(Frame): pass
            
class File(IO): pass

############################################################## metaprogramming

class Meta(Frame): pass


######################################################## FORTH Virtual Machine

W = Dict('FORTH') ; W['W'] = W
S = Stack('DATA') ; W['S'] = S

def ST():
    B = S.pop() ; W[B.val] = S.pop()
W['!'] = Cmd(ST)

def LL():
    B = S.pop() ; S.top() << B
W['<<'] = Cmd(LL)

def PUSH():
    B = S.pop() ; S.top() // B
W['//'] = Cmd(PUSH)

def DUP(): S.dup()
W << DUP

def DROPALL():
    S.dropall()
W['.'] = Cmd(DROPALL)

def ADD():
    B = S.pop() ; S // ( S.pop() + B )
W['+'] = Cmd(ADD)



######################################################################## debug

def BYE():
    sys.exit(0)

def QQ():
    print W ; BYE()
W['??'] = Cmd(QQ)
    

############################################################ PLY-powered lexer

import ply.lex as lex

tokens = ['sym','str']

t_ignore = ' \t\r\n'

states = (('str','exclusive'),)
t_str_ignore = ''
def t_string(t):
    r'\''
    t.lexer.string=''
    t.lexer.push_state('str')
def t_str_string(t):
    r'\''
    t.lexer.pop_state()
    return Str(t.lexer.string)
def t_str_char(t):
    r'.'
    t.lexer.string += t.value

def t_sym(t):
    r'[`~]|[^ \t\r\n]+'
    return Sym(t.value)

def t_ANY_error(t): raise SyntaxError(t)

lexer = lex.lex()

################################################################## interpreter

def QUOTE():
    WORD()
W['`'] = Cmd(QUOTE)

def WORD():
    token = lexer.token()
    if not token: return False
    S // token ; return True

def FIND():
    token = S.pop().val
    try: S // W[token]
    except KeyError: S // W[token.upper()]
    
def EVAL():
    S.pop().eval()

def INTERPRET():
    lexer.input(S.pop().val)
    while True:
        if not WORD(): break
        if isinstance(S.top(),Sym): FIND()
        EVAL()

def REPL():
    while True:
        print W
        S // raw_input('\nok> ')
        INTERPRET()

################################################################## system init

for i in sys.argv[1:]:
    S // open(i).read() ; INTERPRET() ; print W
if not sys.argv[1:]:
    S // open('metaL.ml').read() ; INTERPRET()
    REPL()
