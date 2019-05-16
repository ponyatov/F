import os,sys
from threading import Thread

print sys.argv

class Num(Prim):
    def __init__(self,V):
        Prim.__init__(self, float(V))

class Int(Num):
    def __init__(self,V):
        Prim.__init__(self, int(V))
        
def t_int(t):
    r'[\+\-]?[0-9]+'
    return Int(t.value)

        i = Thread(target=INTERPRET) ; i.start() ; i.join(timeout=1)
W << REPL
REPL()
