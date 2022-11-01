#include<stdio.h>


//Get the input of student: Name, Roll No, Marks in 6 subjects in 12th. 
//Find if the student is eligible for admission in Delhi University. 
//A student is eligible for DU if he has scored 95 % or more in Best 4.

struct student
{
    char name[20];
    int roll,marks[6];
};

int main()
{
    struct student s;
    int total_sum=0;
    printf("\nEnter your name : ");
    gets(s.name);
    printf("\nEnter your roll number : ");
    scanf("%d",&s.roll);
    for(int i=0;i<6;i++)
    {
        printf("\nEnter marks of subject %d :",i+1);
        scanf("%d",&s.marks[i]);
    }
    int min=100,min2=100;
    for(int i=0;i<6;i++)
        total_sum+=s.marks[i];
    
    for(int i=0;i<6;i++)
    {
        if(min>s.marks[i])
            min=s.marks[i];
    }
    for(int i=0;i<6;i++)
    {
        if(min2>s.marks[i] && min!=s.marks[i])
            min2=s.marks[i];
    }
    
    
    float average=(total_sum-min-min2)/4;

    for(int i=0;i<100;i++)
        printf("-");
    
    printf("\n# Name : %s",s.name);
    printf("\n# Roll Number : %d ",s.roll);
    printf("\n\n\n# Marks ");
    for(int i=0;i<6;i++)
    {
        printf("\n  > Subject %d : %d",i,s.marks[i]);
    }

    printf("\nYour average percentage of best 4 is %d ",average);
    if(average>=95)
        printf("\nYou are eligible");
    else
        printf("\nYou are not eligible");
    
    



    return 0;
}
