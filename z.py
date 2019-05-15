
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
        return tree
    def head(self,prefix=''):
        return '%s<%s:%s> /%i @%x' % (prefix,self.type,self.val,self.ref,id(self))
    def pad(self,n):
        return '\n' + '\t' * n
    
    def __floordiv__(self,that):
        self.nest.append(that)
        
class VM(Frame):
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
