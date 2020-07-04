
class Stacks():
    def __init__(self):
        self.items=[]

    def isEmpty(self):
        return self.items==[]
    
    def push(self,item):
        self.items.append(item)
        print(str(item)+"  Pushed Sucessfuly \n")
    
    def size(self):
        return len(self.items)
    
    def peek(self):
        
        
        