#!/usr/bin/env python
# coding: utf-8

# In[4]:


class node:
    #initiation
    def __init__(self, data):
        self.data = data
        self.next = None
class dequeue:
    #initiation
    def __init__(self):
        self.front = self.rear = None
    #queue is empty or not
    def isEmpty(self):
        return self.front == None
    #insert at rear end
    def insert_at_rear(self, data): #insert at rear end
        temp = node(data)
        if self.rear == None and self.front==None:
            self.front = self.rear = temp
        else:
            self.rear.next = temp
            self.rear = temp
    #insert at front end
    def insert_at_front(self,data):
        temp = node(data)
        if self.rear == None and self.front==None:
            self.front = self.rear = temp
        else:
            temp.next = self.front
            self.front = temp
    #delete from front
    def delete_from_front(self):
        if self.isEmpty():
            print("underflow\n")
            return
        temp = self.front.data
        self.front = self.front.next

        if(self.front == None):
            self.rear = None
        print(temp," is deleted\n")
    #delete from end
    def delete_from_rear(self):
        if self.isEmpty():
            print("underflow\n")
            return
        print(self.rear.data," is deleted\n")

        temp = self.front
        while(temp.next != self.rear):
            temp = temp.next
        temp.next = None
        self.rear= temp

   #display queue
    def display(self):
        if self.isEmpty():
            print("Underflow\n")
            return
        temp=self.front
        print("front\t")
        while(temp!=None):
            print(temp.data,"\t")
            temp = temp.next
        print("rear\n")

q=dequeue();
q.insert_at_rear(1);
q.insert_at_front(2);
q.display()
q.delete_from_rear();
q.display()
q.insert_at_rear(4);
q.insert_at_front(5);
q.insert_at_rear(6);
q.insert_at_front(7);
q.display()
q.delete_from_front();
q.display()


# In[ ]:
