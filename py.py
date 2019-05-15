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
        
class Vector(Frame): pass
            
class File(Frame): pass

argv = Frame('argv')
for i in sys.argv: argv // i
print argv
