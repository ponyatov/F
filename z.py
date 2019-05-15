
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
        return self.push(that)
    def __setitem__(self,key,that):
        if callable(that): self[key] = Cmd(that) ; return self
        self.slot[key] = that ; that.ref += 1 ; return self

    def push(self,that):
        if isinstance(that,str): return self.push(Str(that))
        self.nest.append(that) ; that.ref += 1
    def pop(self):
        return self.nest.pop()
    
class Prim(Frame): pass

class Sym(Prim): pass

class Str(Prim): pass

class Active(Frame): pass
        
class Cmd(Active):
    def __init__(self,F):
        Active.__init__(self, F.__name__)
        self.fn = F
        
class Meta(Frame): pass

import ply.lex as ply

class Lexer(Meta):
    tokens = ['sym','str']
    t_ignore = ' \t\r\n'
    def t_sym(t):
        r'[^ \t\r\n]+'
        return Sym(t.value)
    def t_error(t): raise SyntaxError(t)
    lex = ply.lex()
    def input(self,command):
        self.lex.input(command)
    def token(self):
        return self.lex.token()
        
class VM(Active):
    lexer = Lexer('FORTH')
    def __init__(self,V):
        Active.__init__(self, V)
        self['lexer'] = self.lexer
        self['REPL'] = self.repl
    def word(self):
        token = self.lexer.token()
        if not token:   return False
        self // token ; return True
    def interpret(self):
        self.lexer.input( self.pop().val )
        while True:
            if not self.word(): break
            print self
    def repl(self):
        while True:
            print self
            self // raw_input('ok> ')
            self.interpret()

vm = VM('metaL')

vm.repl()
