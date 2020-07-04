
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
        return self.items[len(self.items)-1]
    
    def pop(self):
        self.items.pop()
        


#creating object of stack
s=Stacks()
s.push(10)
s.push(23)      
        