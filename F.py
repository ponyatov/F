import os,sys

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

class Stack(Frame): pass

class Dict(Frame): pass

class Vector(Frame): pass

class Cmd(Frame):
    def __init__(self,F):
        Frame.__init__(self, F.__name__)
        self.fn = F
            
class File(Frame): pass

W = Dict('FORTH') ; W['W'] = W

S = Stack('DATA') ; W['S'] = S

W << ( Vector('ARGV') // File(sys.argv[0]) )
for i in sys.argv[1:]: W['ARGV'] // i
                      
def REPL():
    while True:
        print W
        S // raw_input('\nok> ')
W << REPL
REPL()

