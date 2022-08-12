#!/usr/bin/env python
# coding: utf-8

# In[ ]:


class node:
    def __init__(self,data):
        self.data = data
        self.next=None
class LinkedList:
    def __init__(self):
        self.head=None
    #Insert at the last position
    def insert_Last(self,data):
        newnode=node(data)
        if self.head==None:  #linked list is empty
            self.head = newnode
            self.head.next = self.head
        else:
            temp = self.head
            while temp.next!=self.head:
                temp = temp.next
            temp.next = newnode
            newnode.next = self.head
    #Insert at the first position
    def insert_First(self,data):
        newnode=node(data)
        if self.head==None:  #linked list is empty
            self.head = newnode
            self.head.next = self.head
        else:
            temp = self.head
            while temp.next!=self.head:
                temp = temp.next
            temp.next = newnode
            newnode.next = self.head
            self.head = newnode
    #delete from the first position
    def delete_first(self):
        if self.head==None:
            print("Linked List is empty")
        elif self.head.next == self.head:
            self.head=None
        else:
            temp = self.head
            while temp.next!=self.head:
                temp = temp.next
            temp.next = self.head.next
            self.head = self.head.next
    #delete from the end position
    def delete_last(self):
        if self.head==None:
            print("Linked List is empty")

        elif self.head.next==None:  #only one node
            self.head=None

        else:
            temp = self.head
            while temp.next.next !=None:
                temp = temp.next
            temp.next = self.start

    #display        
    def display(self):
        if self.head==None:
            print("Linked list is empty")
        else:
            temp = self.head
            print(temp.data,end=" ")
            temp=temp.next
            while(temp!=self.head):
                print(temp.data,end =" ")
                temp = temp.next
        print()

my_linked_list = LinkedList()
my_linked_list.insert_Last(10)
my_linked_list.insert_Last(20)
my_linked_list.insert_Last(30)
my_linked_list.insert_Last(40)
my_linked_list.insert_First(50)
my_linked_list.display()

my_linked_list.delete_first()
print("hi")
my_linked_list.delete_last()

print("hi")
my_linked_list.display()





# In[ ]:
