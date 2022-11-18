#include <stdio.h>

int main()
{
    int row=3, col=3, i, j, dia1=0, dia2=0, f=0, sumCol, sumRow;

    int a[row][col];

    // getting input
    for(i=0; i<row; i++)
    {
        for(j=0; j<col; j++)
        {
            scanf("%d ", &a[i][j]);
        }
    }

    for(i=0; i<row; i++)
    {
        for(j=0; j<col; j++)
        {
            // sum of main diagonal
            if(i==j)
                dia1 += a[i][j];
            // sum of minor diagonal
            if(i+j==3-1)
            {
                dia2 += a[i][j];
            }
        }
    }

    if(dia1 != dia2)
        f=1;
    else
    {
        for(i=0; i<row; i++)
        {
            sumCol = 0;
            sumRow = 0;
            for(j=0; j<col; j++)
            {
                sumCol += a[j][i]; //sum of column
                sumRow += a[i][j]; //sum of row
            }
            if(sumCol != dia1)
                f=1;
            else if (sumRow != dia1)
                f=1;
            else
                f=0;
        }
    }

    if(f==0)
        printf("YES\n");
    else
        printf("No\n");

    return 0;
}
