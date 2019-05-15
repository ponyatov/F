import os,sys
from threading import Thread

print sys.argv

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
        if not isinstance(that,Frame): return self // Frame(that)
        self.nest.append(that) ; return self
    def __lshift__(self,that):
        if callable(that): return self << Cmd(that)
        self[that.val] = that ; return self
    def __setitem__(self,key,that):
        self.slot[key] = that ; return self
    def __getitem__(self,key):
        return self.slot[key]
        
    def pop(self):
        return self.nest.pop()
    
class Prim(Frame): pass
    
class Sym(Prim): pass

class Str(Prim): pass

class Num(Prim):
    def __init__(self,V):
        Prim.__init__(self, float(V))

class Int(Num):
    def __init__(self,V):
        Prim.__init__(self, int(V))

class Cont(Frame): pass

class Stack(Cont): pass

class Dict(Cont): pass

class Vect(Cont): pass

class Active(Frame): pass

class Cmd(Active):
    def __init__(self,F):
        Frame.__init__(self, F.__name__)
        self.fn = F
        
class IO(Frame): pass
            
class File(IO): pass

W = Dict('FORTH') ; W['W'] = W

S = Stack('DATA') ; W['S'] = S

W << ( Vect('ARGV') // File(sys.argv[0]) )
for i in sys.argv[1:]: W['ARGV'] // i

import ply.lex as lex

tokens = ['int','sym']

t_ignore = ' \t\r\n'

def t_int(t):
    r'[\+\-]?[0-9]+'
    return Int(t.value)

def t_sym(t):
    r'[^ \t\r\n]+'
    return Sym(t.value)

def t_error(t): raise SyntaxError(t)

lexer = lex.lex()

def WORD():
    token = lexer.token()
    if not token: return False
    S // token ; return True
W << WORD

def FIND():
    token = S.pop().val
    S // W[token]
W << FIND

def INTERPRET():
    lexer.input(S.pop().val)
    while True:
        if not WORD(): break
        FIND()
        print S
W << INTERPRET
                      
def REPL():
    while True:
        print W
        S // raw_input('\nok> ')
        Thread(target=INTERPRET).start()
W << REPL
REPL()

