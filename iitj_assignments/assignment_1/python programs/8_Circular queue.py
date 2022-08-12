#!/usr/bin/env python
# coding: utf-8

# In[2]:


class node:
    #initiation
    def __init__(self, data):
        self.data = data
        self.next = None

class circular_Queue:
    #initiation
    def __init__(self):
        self.front = self.rear = None
    #queue is empty or not
    def isEmpty(self):
        return self.front == None

    def enqueue(self, data): #insert at rear end
        temp = node(data)
        if self.isEmpty():
            self.front = temp
        else:
            self.rear.next = temp
        self.rear = temp
        self.rear.next = self.front

    def dequeue(self):   #delete from front end
        if self.isEmpty():
            print("underflow\n")
            return
        print(self.front.data ," is deleted\n")
        if self.front==self.rear : #only one element left
            self.front = self.rear = None
        else:
            self.front = self.front.next
            self.rear.next = self.front
    #display queue
    def display(self):
        temp = q.front
        print("front  ",end=" ")
        while (temp.next != self.front):
            print(temp.data, end = " ")
            temp = temp.next
        print(temp.data,"    rear\n")

q=circular_Queue()
q.enqueue(1)
q.enqueue(2)
q.enqueue(3)
q.display()
q.dequeue()
q.display()
q.enqueue(4)
q.enqueue(5)
q.display()
q.dequeue()
q.display()
