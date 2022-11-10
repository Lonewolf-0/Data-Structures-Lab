/*7. Enter the marks of 5 students in Chemistry, Mathematics and Physics 
(each out of 100) using a structure named Marks having elements roll no.,
 name, chem_marks, maths_marks and phy_marks and then display the percentage of each student.*/
#include<stdio.h>

struct marks
{
    int roll,chem_marks,maths_marks,phy_marks;
    float percentage;
    char name[20];
   
};

int main()
{
    struct marks a[5];

    for(int i=0;i<5;i++)
    {
        a[i].roll=i+1;
        printf("\n\nEnter details of student : Roll no. - %d",a[i].roll);
        printf("\nEnter name : ");
        scanf("%s",&a[i].name);
        printf("\nEnter Maths marks : ");
        scanf("%d",&a[i].maths_marks);
        printf("\nEnter Chemistry Marks : ");
        scanf("%d",&a[i].chem_marks);
        printf("\nEnter Physics Marks : ");
        scanf("%d",&a[i].phy_marks);

        a[i].percentage=(float)(a[i].chem_marks+a[i].maths_marks+a[i].phy_marks)/3;


    }

    for(int i=0;i<5;i++)
    {
        printf("\n\nRoll no - %d ",a[i].roll);
        printf("\nPercentage - %d ",a[i].percentage);


    }


    return 0;
}
 