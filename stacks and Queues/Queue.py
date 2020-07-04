class Queues(object):

    def __init__(self):
        self.items=[]

    def enqueue(self,item):
        self.items.insert(0,item)
    
    def dequeue(self):
        return self.items.pop()
    
    def isEmpty(self):
        return self.items==[]
    
    def size(self):
        return len(self.items)
    
q= Queues()

q.enqueue(100)
q.enqueue(200)
q.enqueue(89)
q.enqueue(23)

print(q.isEmpty())
print(q.dequeue())
print(q.size())
        