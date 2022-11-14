#include<stdio.h>

struct student 
{
    int roll;
    char name[20];

}s,*s1;
int main()
{
    s1=&s;
    for(int i=0;i<3;i++)
    {
        scanf("%d",&(s1+i)->roll);
        scanf("%s",&(s1+i)->name);
    }

    for(int i=0;i<3;i++)
    {
        printf("%d %s \n",(s1+i)->roll,(s1+i)->name);
    }



    return 0;
}