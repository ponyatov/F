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
#         if callable(that): return self << Cmd(that)
        self[that.val] = that ; return self
    def __setitem__(self,key,that):
        self.slot[key] = that ; return self
    def __getitem__(self,key):
        return self.slot[key]

    def push(self,that):
        self.nest.append(that) ; return self
    def pop(self):
        return self.nest.pop()
    
############################################################## primitive types

class Prim(Frame): pass

class Sym(Prim): pass

class Str(Prim): pass

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

class Cmd(Active): pass

################################################################# input/output

class IO(Frame): pass
            
class File(IO): pass

######################################################## FORTH Virtual Machine

W = Dict('FORTH') ; W['W'] = W
S = Stack('DATA') ; W['S'] = S

############################################################ PLY-powered lexer

import ply.lex as lex

tokens = ['sym']

t_ignore = ' \t\r\n'

def t_sym(t):
    r'[^ \t\r\n]+'
    return Sym(t.value)

def t_error(t): raise SyntaxError(t)

lexer = lex.lex()

################################################################## interpreter

def INTERPRET():
    lexer.input(S.pop().val)
    while True:
        if not WORD(): break
        if isinstance(S.top(),Sym): FIND()
        print S

################################################################## system init

for i in sys.argv[1:]:
    S // open(i).read() ; print S ; INTERPRET()
REPL()
