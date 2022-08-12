#!/usr/bin/env python
# coding: utf-8

# In[10]:


class node:
    #initiation
    def __init__(self, data):
        self.data = data
        self.next = None
class Queue:
    #initiation
    def __init__(self):
        self.front = self.rear = None
    #queue is empty or not
    def isEmpty(self):
        return self.front == None

    def enqueue(self, data): #insert at rear end
        temp = node(data)
        if self.rear == None and self.front==None:
            self.front = self.rear = temp
        else:
            self.rear.next = temp
            self.rear = temp

    def dequeue(self):   #delete from front end
        if self.isEmpty():
            print("underflow\n")
            return
        temp = self.front.data
        self.front = self.front.next

        if(self.front == None):
            self.rear = None
        return temp
q=Queue()
q.enqueue(1)
q.enqueue(2)
q.enqueue(3)
print(q.dequeue())
q.enqueue(4)
q.enqueue(5)
print(q.dequeue())
