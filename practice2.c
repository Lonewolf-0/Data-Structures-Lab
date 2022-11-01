#include<stdio.h>


struct student
{
    int roll;
    char name[20];
    int marks;

};

int main()
{
    
    struct student s[5];
    
    for(int i=0;i<5;i++)
    {
        scanf("%d",&s[i].roll);
        gets(s[i].name);
        scanf("%d",&s[i].marks);
    }

    for(int i=0;i<5;i++)
    {
        printf("%d\n%s\n%d",s[i].roll,s[i].name,s[i].marks);
    }
    

    return 0;
}