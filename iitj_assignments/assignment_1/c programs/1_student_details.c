#include<stdio.h>
#include<stdlib.h>

//student structure
struct student{
  char name[100];
  int roll_no;
  float marks;
};

//Insertion of student details
void insertion(struct student s[],int n)
{
   for(int i=0;i<n;i++)
   {
     //Name
     printf("enter %d th student name :",i+1);
     fflush(stdin);
     gets(s[i].name);

     //Roll Number
     printf("enter %d th student roll number :",i+1);
     scanf("%d",&s[i].roll_no);

     //Marks
     printf("enter %d th student marks :",i+1);
     scanf("%f",&s[i].marks);

   }
}

//Updation of student details
void update(struct student s[],int n)
{
  int stu_no,what;
  printf("Which student's detail you wan to update ? \n");
  scanf("%d",&stu_no);


  printf("what value you want to update ? \n 1. Press 1 for Name\n 2. Press 2 for Marks\n");
  scanf("%d",&what);
  //Invalid student number
  if(what>n || what<=0)
  {
    printf(" %d number of students present\n",n);
    return;
  }


  printf("Update Now..\n");
  //Name Updation
  if(what == 1)
  {
    fflush(stdin);
    gets(s[stu_no-1].name);
  }
    else
      //Marks Updation
      scanf("%f",&s[stu_no-1].marks);

}

//Displaying student details
void display(struct student s[],int n)
{
  printf("Name \tRoll Number\tMarks\n");
  for(int i=0;i<n;i++)
      printf("%s\t %d\t\t %f\n",s[i].name,s[i].roll_no,s[i].marks);
}
//Util function to show menu to the user
void print_menu()
{
   printf("1.Update details\n");
   printf("2.Display\n");
   printf("3.EXIT\n");
   printf("enter your choice :\n");

}

//main function
int main()
{
   int n,choice;
   //printf("*************S T A R T************\n");
   printf("How many students in the class ? \n");
   scanf("%d",&n);

   //creation
   struct student s[n];
   //insertion
   printf("Enter student details one by one...\n");
   insertion(s,n);

   while(1)
   {
     printf("**************************************************\n");
     print_menu();
     scanf("%d",&choice);
     switch(choice)
     {         //student details updation
        case 1:update(s,n);
               break;
                //display student details
        case 2:  display(s,n);
                 break;
                 //exit from program
        case 3:
                 exit(0);
        default:
                 printf("wrong choice\n");
                 break;
      }
    }
}
