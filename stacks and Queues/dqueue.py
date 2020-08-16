class Dqueue(object):

    def __init__(self):
        self.items=[]
    
    def isEmpty(self):
        return self.items==[]
    
    def addFront(self,num):
        self.items.append(num)
        print("{} Added at front successfully..!".format(num))
    
    def addRear(self,num):
        self.items.insert(0,num)
        print("{} Added at rear successfully..!".format(num))

    def removeFront(self):
        r= self.items.pop()
        print('Successfully popped from front...!!'+str(r))
    
    def removeRear(self):
        r= self.items.pop(0)
        print("Successfuly removed from rear..!!"+str(r))

    def size(self):
        l= len(self.items)
        print("Length of Deque is "+ str(l))


d=Dqueue()

d.addFront(12)
d.addRear(45)
d.addFront(89)
d.addFront(78)
d.addFront(42)
d.addRear(890)
d.size()

d.removeFront()
d.removeRear()
d.size()

