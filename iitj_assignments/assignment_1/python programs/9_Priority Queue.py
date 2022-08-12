#!/usr/bin/env python
# coding: utf-8

class node:
    def __init__(self, data,priority):
        #initiation
        self.data = data
        self.priority = priority
        self.next = None

class priority_queue:
    #initiation
    def __init__(self):
        self.front = None
    #queue is empty or not
    def isEmpty(self):
        return self.front == None

    def insert(self, data,prio):
        newnode = node(data,prio)

        #if queue is empty or coming priority is less than front priority, then node will
        #added at start position

        if self.isEmpty() or prio<self.front.priority:
            newnode.next = self.front
            self.front = newnode

        #elements will be sorted in order of priority, find the right place for coming item
        else:
            temp = self.front
            while temp.next!=None and temp.next.priority<=prio:
                temp = temp.next
            newnode.next = temp.next
            temp.next = newnode
    #delete from front node
    def delete(self):
        if self.isEmpty():
            print("Underflow\n")
            return
        else:
            print(self.front.data," is deleted\n")
            self.front= self.front.next
   #display queue
    def display(self):
        if self.isEmpty():
            print("Underflow\n")
            return
        else:
            temp = self.front
            print("priority    Item\n")
            while(temp!=None):
                print(temp.priority,"       "  ,temp.data,"\n")
                temp = temp.next
            print()


# In[19]:


q=priority_queue()
q.insert(122,6)
q.insert(20,2)
q.insert(3567,1)
q.display()
q.delete()
q.display()
q.insert(4,-1)
q.insert(5,10)
q.display()
q.delete()
q.display()
