
class Frame:
    
    def __init__(self,V):
        self.type = self.__class__.__name__.lower()
        self.val  = V
        self.slot = {}
        self.nest = []
        self.ref  = 0
        
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
        return '%s<%s:%s> /%i @%x' % \
            (prefix,self.type,self.val,self.ref,id(self))
    def pad(self,n):
        return '\n' + '\t' * n
    
    def __floordiv__(self,that):
        self.nest.append(that)
    def __setitem__(self,key,obj):
        if callable(obj): self[key] = Cmd(obj) ; return self
        self.slot[key] = obj ; return self

class Active(Frame): pass
        
class Cmd(Active):
    def __init__(self,F):
        Active.__init__(self, F.__name__)
        self.fn = F
        
class VM(Active):
    def __init__(self,V):
        Active.__init__(self, V)
        self['REPL'] = self.repl
    def interpret(self):
        lexer = lexer.input( self.pop().val )
        while True:
            if not self.word(): break
    def repl(self):
        while True:
            print self
            self // raw_input('ok> ')
            self.interpret()

vm = VM('metaL')

vm.repl()
