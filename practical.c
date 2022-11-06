#include <stdio.h>
#define size 5
void initialisation(int a[][size], int m, int n, char str)
{
    printf("\n");
    printf("ENTER ELEMENTS OF MATRIX %c:\n", str);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
}
void print(int a[][size], int m, int n, char *str)
{
    printf("MATRIX %s:\n", str);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%4d ", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void addition(int a[][size], int b[][size], int c[][size], int row, int column)
{
    int i, j;
    for (i = 0; i < row; i++)
        for (j = 0; j < column; j++)
            c[i][j] = a[i][j] + b[i][j];
}

void subtraction(int a[][size], int b[][size], int c[][size], int row, int column)
{
    int i, j;
    for (i = 0; i < row; i++)
        for (j = 0; j < column; j++)
            c[i][j] = a[i][j] - b[i][j];
}

void multiplication(int a[][size], int b[][size], int c[][size], int row1, int col1,int col2)
{
    int i,j,k;
    for (i = 0; i < row1; ++i)
        for (j = 0; j < col2; ++j)
        {
            c[i][j] = 0;
            for (k = 0; k < col1; k++)
            {
                c[i][j] = c[i][j] + a[i][k] * b[k][j];
            }
        }
}

void transpose(int a[][size],int row,int col,int work[][size])
{
    int i,j;
    for (i=0;i<row;i++)
        for(j=0;j<col;j++)
            work[j][i]=a[i][j];
}

void cofactor(int a[][size], int row, int col, int n, int work[][size])
{
    int i = 0, j = 0, r, c;

    for (r = 0; r < n; r++)
    {
        for (c = 0; c < n; c++)
        {
            if (r != row && c != col)
            {
                work[i][j++] = a[r][c];
            }
            if (j == n - 1)
            {
                j = 0;
                i++;
            }
        }
    }
}
int determinant(int a[][size], int n)
{
    int work[size][size];
    int d = 0, i, sign = 1;
    if (n == 1)
        return a[0][0];

    for (i = 0; i < n; i++)
    {
        cofactor(a, 0, i, n, work);
        d = d + (sign * a[0][i] * determinant(work, n - 1));
        sign = -sign;
    }
    return d;
}

void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
void transpose_without(int a[][size],int row,int col)
{
    int i,j;
    for (i=0;i<row;i++)
        for(j=0;j<col;j++)
            if (i+j<i+i)
                swap(&a[j][i],&a[i][j]);
}

void main()
{
    int a[size][size], b[size][size], c[size][size], a_r, a_c, b_r, b_c, i, j,d;
    printf("==================================\n");
    printf("ENTER ROWS OF MATRIX A:");
    scanf("%d", &a_r);
    printf("ENTER COLUMNS OF MATRIX A:");
    scanf("%d", &a_c);
    initialisation(a, a_r, a_c, 'A');
    print(a, a_r, a_c,"A");
    printf("ENTER ROWS OF MATRIX B:");
    scanf("%d", &b_r);
    printf("ENTER COLUMNS OF MATRIX B:");
    scanf("%d", &b_c);
    initialisation(b, b_r, b_c, 'B');
    print(b, a_r, a_c,"B");

    addition(a, b, c, a_r, a_c);
    printf("ADDITION OF TWO MATRIX:\n");
    printf("=======================\n");
    print(c, a_r, a_c, "A + B");

    subtraction(a, b, c, a_r, a_c);
    printf("SUBTRACTION OF TWO MATRIX:\n");
    printf("==========================\n");
    print(c, a_r, a_c, "A - B");

    multiplication(a, b, c,a_r,a_c,b_c);
    printf("MULTIPLICATION OF TWO MATRIX:\n");
    printf("=============================\n");
    print(c, a_r, b_c, "A X B");

    transpose(a,a_r,a_c,c);
    printf("\nMATRIX A TRANSPOSE: \n");
    printf("===================\n");
    print(c,a_c,a_r,"A`");

    d = determinant(a, a_r);
    printf("DETERMINANT OF MATRIX A :%d", d);

    transpose_without(b,b_r,b_c);
    printf("\n\nMATRIX B TRANSPOSE: \n");
    printf("=======================\n");
    print(c,a_c,a_r,"B`");
    printf("==================================\n");
}
