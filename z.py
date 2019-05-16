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

## VM command        
class Cmd(Active):
    def __init__(self,F):
        Active.__init__(self, F.__name__)
        self.fn = F

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
