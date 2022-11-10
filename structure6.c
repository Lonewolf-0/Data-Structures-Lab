/*6. Write a program to add two time in hour, minute and second using structure. 
The values of the time is to be taken from the user.*/

struct time 
{
    int hour,minute,second;
};
#include<stdio.h>

int main()
{
    struct time a,b,c;
    printf("\nEnter time 1 in hours, minutes and seconds : ");
    scanf("%d%d%d",&a.hour,&a.minute,&a.second);
    printf("\nEnter time 2 in hours, minutes and seconds : ");
    scanf("%d%d%d",&b.hour,&b.minute,&b.second);

    c.hour=a.hour+b.hour+(a.minute+b.minute+(a.second+b.second)/60)/60;
    c.minute=(a.minute+b.minute+(a.second+b.second)/60)%60;
    c.second=(a.second+b.second)%60;

    printf("\n\nSum of time 1 and 2 is %d hours %d minutes and %d seconds",c.hour,c.minute,c.second);


    return 0;
}