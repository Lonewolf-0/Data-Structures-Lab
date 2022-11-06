/* Write a program to store and print the roll no., name, age and marks of a student using structures.
 Write a program to store the roll no. (starting from 1), name and age of 5 students 
 and then print the details of the student with roll no. 1.*/
 #include<stdio.h>

 struct student
 {
    int roll,age,marks;
    char name[25];

 };
 
 int main()
 {
    struct student s[5];

    for(int i=0;i<5;i++)
    {   
        s[i].roll=i+1;
        printf("\n\nEnter details of student with roll number %d : ",s[i].roll);
        printf("\nEnter name : ");
        scanf("%s",&s[i].name);
        printf("\nEnter age : ");
        scanf("%d",&s[i].age);
        printf("\nEnter marks : ");
        scanf("%d",&s[i].marks);



    }

    //print

    for(int i=0;i<5;i++)
    {
        printf("\n\n");
        printf("\nRoll no. : %d",s[i].roll);
        printf("\nName : %s",s[i].name);
        printf("\nAge : %d",s[i].age);
        printf("\nMarks : %d",s[i].marks);


    }
    

    
 }