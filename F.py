import os,sys
from threading import Thread

print sys.argv

class Num(Prim):
    def __init__(self,V):
        Prim.__init__(self, float(V))

class Int(Num):
    def __init__(self,V):
        Prim.__init__(self, int(V))

class Cmd(Active):
    def __init__(self,F):
        Frame.__init__(self, F.__name__)
        self.fn = F
        
def t_int(t):
    r'[\+\-]?[0-9]+'
    return Int(t.value)

def WORD():
    token = lexer.token()
    if not token: return False
    S // token ; return True
W << WORD

def FIND():
    token = S.pop().val
    S // W[token]
W << FIND

W << INTERPRET
                      
def REPL():
    while True:
        print W
        S // raw_input('\nok> ')
        i = Thread(target=INTERPRET) ; i.start() ; i.join(timeout=1)
W << REPL
REPL()

