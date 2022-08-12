#!/usr/bin/env python
# coding: utf-8

# In[14]:


class node:
    def __init__(self,data):
        self.data = data
        self.next = None
class Stack:
    #initiation
    def __init__(self):
        self.head = None
    #push element at top
    def push(self,data):  #inserting at start of linked list
        newnode=node(data)
        if self.head == None:
            self.head=newnode

        else:
            newnode.next = self.head
            self.head = newnode
    #pop element from top
    def pop(self):  #delete from head of linked list
        if self.isEmpty():
            return None

        else:
            temp = self.head.data
            self.head = self.head.next
            return temp

    # Returns the head node data
    def peek(self):
        if self.isEmpty():
            return None
        else:
            return self.head.data
    #display stack
    def display(self):

        temp = self.head
        if self.isEmpty():
            print("Stack Underflow")

        else:
            while(temp != None):
                print(temp.data,end = " ")
                temp = temp.next
    #stack is empty or not        
    def isEmpty(self):
        if self.head == None:
            return True
        else:
            return False
s=Stack()
s.push(1)
s.push(2)
s.push(3)
s.push(4)

# Display stack elements
s.display()
print(' ')

print("Top element is ",s.peek())


print("Popped element is ", s.pop())

print("Popped element is ", s.pop())

s.display()
