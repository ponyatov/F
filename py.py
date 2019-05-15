import os,sys

print sys.argv

class Frame:
    def __init__(self,V):
        self.type = self.__class__.__name__.lower()
        self.val  = V
        self.slot = {}
        self.nest = []

argv = Frame('argv')
for i in sys.argv: argv // i
print argv
