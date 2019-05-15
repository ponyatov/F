## @file

import os,sys,re

## @defgroup frame Marvin Minsky frame model
## `e`xtended with `nest[]`ed elements for attribute grammar and AST
## @{

## frame (object)
## shares universal knowledge representation, and any data/container
class Frame:
    
    ## @param[in] V frame name/scalar value
    def __init__(self,V):
        ## type/class tag
        self.type = self.__class__.__name__.lower()
        ## implementation language scalar type
        self.val  = V
        ## `slot{}`s = attributes = string-keyed associative array
        self.slot = {}
        ## `nest[]`ed elements = vector = stack = queue
        self.nest = []
        ## reference count
        self.ref  = 0
        
    ## @name printing
    
    def __repr__(self):
        return self.dump()
    ## short header-only dump
    def head(self,prefix=''):
        return '%s<%s:%s> /%i @%x' % \
            (prefix,self.type,self.str(),self.ref,id(self))
    ## full tree text dump 
    def dump(self,depth=0,prefix=''):
        tree = self.pad(depth) + self.head(prefix)
        for i in self.slot:
            tree += self.slot[i].dump(depth+1,i+' = ')
        for j in self.nest:
            tree += j.dump(depth+1)
        return tree
    ## pad dump tree with tabs
    def pad(self,n):
        return '\n' + '\t' * n
    ## format `val` for printing
    def str(self):
        return self.val
    
    ## @name operators
    
    ## `A // B`
    def __floordiv__(self,that):
        return self.push(that)
    ## `A[str] = B`
    def __setitem__(self,key,that):
        if callable(that): self[key] = Cmd(that) ; return self
        if isinstance(that,str): self[key] = Str(that) ; return self
        if isinstance(that,int): self[key] = Int(that) ; return self
        self.slot[key] = that ; that.ref += 1 ; return self
    ## `A[str]`
    def __getitem__(self,key):
        return self.slot[key]
    
    ## @name treat frame = stack

    ## push (to `nest[]`ed)
    def push(self,that):
        if isinstance(that,str): return self.push(Str(that))
        self.nest.append(that) ; #that.ref += 1
    ## pop
    def pop(self):
        return self.nest.pop()
    ## top element
    def top(self):
        return self.nest[-1]
    ## dup element
    def dup(self):
        return self // self.top()
    ## drop element
    def drop(self):
        self.nest.pop() ; return self
    
    ## @name execution / code generation
    
    ## evaluate/execute self in the given context
    ## (by default only push self to context stack)
    def eval(self,context):
        context.push(self)

## primitive
class Prim(Frame): pass

## symbol
class Sym(Prim): pass

## string
class Str(Prim): pass

## number
class Num(Prim):
    def __init__(self,N):
        Prim.__init__(self, float(N))
        
## integer
class Int(Num):
    def __init__(self,N):
        Prim.__init__(self, int(N))
        
## machine hex number
class Hex(Int):
    def __init__(self,N):
        Int.__init__(self, int(N[2:],0x10))
    def str(self):
        return '%X' % self.val
        
## bit string
class Bin(Int):
    def __init__(self,N):
        Int.__init__(self, int(N[2:],0x02))
    ## format `val` for printing
    def str(self):
        return bin(self.val)[2:]

## active objects has execution semantics
class Active(Frame): pass

## VM command        
class Cmd(Active):
    def __init__(self,F):
        Active.__init__(self, F.__name__)
        self.fn = F

## metaprogramming        
class Meta(Frame): pass

## @}

## @defgroup ply PLY-powered lexer
## FORTH has no syntax: it's lexer-only language
## @{

import ply.lex as ply

## lexer class
class Lexer(Meta):
    tokens = ['sym','str','num','int','hex','bin']
    t_ignore = ' \t\r\n'
    def t_hex(t):
        r'0x[0-9a-fA-F]+'
        return Hex(t.value)
    def t_bin(t):
        r'0b[01]+'
        return Bin(t.value)
    def t_num_exp(t):
        r'[\+\-]?[0-9]+(\.[0-9]*)?[eE][\+\-]?[0-9]+'
        return Num(t.value)
    def t_num(t):
        r'[\+\-]?([0-9]+\.[0-9]*|\.[0-9]+)'
        return Num(t.value)
    def t_int(t):
        r'[\+\-]?[0-9]+'
        return Int(t.value)
    def t_sym(t):
        r'[^ \t\r\n]+'
        return Sym(t.value)
    def t_error(t): raise SyntaxError(t)
    lex = ply.lex()
    ## @param[in] command source code
    def input(self,command):
        self.lex.input(command)
    ## @returns parsed token as **lexeme frame**: Sym Str Num ...
    def token(self):
        return self.lex.token()
    
## @}

## @defgroup forth FORTH Virtual Machine
## @{

## FORTH Virtual Machine
## @ingroup frame        
class VM(Active):
    lexer = Lexer('FORTH')
    def __init__(self,V):
        Active.__init__(self, V)
        self['lexer'] = self.lexer
        self['REPL'] = self.repl
    ## `WORD ( -- token )` parse next token from a source stream
    def word(self):
        token = self.lexer.token()
        if not token:   return False
        self // token ; return True
    ## `FIND ( token -- object )` search object in vocabulary by its name
    def find(self):
        token = self.pop().val
        try: self // self[token]
        except KeyError:
            try: self // self[token.upper()]
            except KeyError:
                raise SyntaxError(token)
    ## `INTERPRET ( str -- )` interpet string as source code
    ## /feeds whole string to @ref Lexer/
    def interpret(self):
        self.lexer.input( self.pop().val )
        while True:
            if not self.word(): break
            if isinstance(self.top(),Sym): self.find()
            self.pop().eval(self)
            print self
    ## `REPL ( -- )` user console
    def repl(self):
        while True:
            print self
            self // raw_input('ok> ')
            self.interpret()

## global virtual machine
glob = VM('metaL')

## @}

## @defgroup web web engine
## Flask-powered
## @{

## web server instance
class Web(Frame):
    def __init__(self,V):
        Frame.__init__(self, V)
        self['ip'] = '127.0.0.1'
        self['port'] = 8888
    def eval(self,context):
        import flask
        app = flask.Flask(self.val)
        
        @app.route('/')
        def index():
            return flask.render_template('dump.html',dump=context.dump())
        
        @app.route('/css/<path:css>')
        def css(css):
            return app.send_static_file(css)
        
        @app.route('/<path:path>')
        def path(path):
            return flask.render_template('dump.html',dump=context[path].dump())
        
        app.run(host=self['ip'].val,port=self['port'].val,debug=True,use_reloader=False)

glob['web'] = Web('Flask')
# glob['web'].eval(glob)

## @}

## @defgroup init system startup
## @{

if __name__ == '__main__':
    glob.repl()

## @}
