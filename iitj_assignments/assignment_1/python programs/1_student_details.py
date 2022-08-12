#!/usr/bin/env python
# coding: utf-8

# In[1]:


class student:
    
    def __init__(self,n,name,roll,marks):
        self.n =n
        self.name = name
        self.roll=roll
        self.marks = marks
    def display(self):
        print("Name : " ,self.name,"      Roll :",self.roll,"    Marks : ",self.marks)
    
    def update(self):
        print("1.Press 1 for name updation  \n 2.Press 2 for marks updation\n");
        what = int(input())
        if what ==1:
            print("Enter new name : ")
            self.name=input()
        else:
            print("Enter new marks : ")
            self.marks = int(input())
    


# In[3]:


students=[]
print("Enter number of students\n")
n=int(input())

#creation
for i in range(n):
    print("enter ",i+1," student details\n")
    print("Name :")
    name= input()
    print("Roll :")
    roll=int(input())
    print("Marks :")
    marks = float(input())
    
    students.append(student(n,name,roll,marks))

#display
for i in range(n):
    students[i].display()
    
#update
print("Which student details you want to update : \n")

stu_no =int(input())
if(stu_no<=0 or stu_no>n):
        print("Invalid student number\n");
else:
    students[i-1].update()

#display
for i in range(n):
    students[i].display()

