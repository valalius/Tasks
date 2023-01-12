#include <stdio.h>
#include <stdlib.h>

void task1();
void task2();
void task3();

int main()
{
    int task;
    printf(" Choose a task:");
    printf("\n 1 Sum of series");
    printf("\n 2 Operations with matrices");
    printf("\n 3 Counting vowels in a text file");
    printf("\n Your choice:\t");
    while (task!=1&&task!=2&&task!=3)
    {
       scanf("%d", &task);
    }
    system ("cls");
    switch (task)
    {
    case 1:
        task1();
        break;
    case 2:
        task2();
        break;
    case 3:
        task3();
        break;
    }
    return 0;
}
///////////////////////////////////////////////////////////////////
void task1()
{
    // ((-1)^n)*((a^(2n+1))/(2n+1)!)
    double a;
    int N, f;
    double first, second, third; // first = (-1)^n, second = a^(2n+1), third = (2n+1)!
    double result;

    printf("\t TASK 1");
    printf("\n Choose *a* and *N*\n");
    printf(" a = ");
    scanf(" %lf", &a);
    printf(" N = ");
    do
    {
        scanf(" %d", &N);
    } while (N<0);

    if (N%2==0)
    {
        first=1;
    }
    else
    {
        first=-1;
    }
    if (N==0)
    {
        second = a;
    }
    else
    {
        second=1;
        int prw=2*N+1; //power of a number
        for (int j=1; j<=prw; ++j)
            {
                second*=a;
            }
    }
    f=2*N+1; // number, factorial of which needs to be found
    third=1;
    for (int i=1; i<=f; ++i)
        {
            third*=i;
        }
    result=first*(second/third);
    printf("\n The result is: %lf\t\n", result);
}

void task2()
{
    srand(time(NULL));
    int N, sum, a;

    printf("\t TASK 2");
    printf("\n Enter the number of rows + columns of A\t");
    scanf("%d", &N);

    //creating space
    int **A = (int **)malloc(sizeof(int *)* N);
    for (int i=0; i<N; i++)
    {
        A[i]=(int *)malloc(sizeof(int)*N);
    }
    int **B = (int **)malloc(sizeof(int *)* N);
    for (int i=0; i<N; i++)
    {
        B[i]=(int *)malloc(sizeof(int)*N);
    }

    //main part of the task
    for (int i=0; i<N; i++)
    {
        for (int j=0; j<N; j++)
        {
            do
            {
                a = rand()%20+(-10);
            } while (a==0);
            A[i][j]=a;
        }
    }
    printf("\n Generated matrix A:\n");
    for (int i=0; i<N; i++)
    {
        for (int j=0; j<N; j++)
        {
            printf("%d\t", A[i][j]);
        }
         printf("\n");
    }
    sum=0;
    for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
                {
                    sum += A[i][j];
                }
        }
    for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
                {
                    B[i][j]= sum - A[i][j];
                }
        }

    //printing out matrix B
    printf("\n\n Generated matrix B:\n");
    for (int i=0; i<N; i++)
    {
        for (int j=0; j<N; j++)
        {
            printf("%d\t", B[i][j]);
        }
         printf("\n");
    }

    //clearing
    for (int i=0;i<N;i++)
    {
        free(A[i]);
    }
    free(A);
    for (int i=0;i<N;i++)
    {
        free(B[i]);
    }
    free(B);
}

void task3()
{
    FILE* fp_input;
    char c;
    int count = 0;
    fp_input = fopen("text_3.txt", "r");

    printf("\t TASK 3");

    if (fp_input==NULL) //checking if the file was opened correctly
    {
        printf("\n ERROR. CANNOT OPEN THE FILE.");
    }
    else
    {
        while ((c = fgetc(fp_input)) != EOF) //reads characters till the end of the file
        {
            switch(c)
            {
                case 'a':
                case 'e':
                case 'i':
                case 'o':
                case 'u':
                case 'y':
                case 'A':
                case 'E':
                case 'I':
                case 'O':
                case 'U':
                case 'Y':
                ++count; //storing +1 when reading the needed letter
            }
            printf("%c", c);//printing the text itself
        }
    }
    fclose(fp_input); //closing the file
    printf("\n Number of chosen characters: %d", count);
}
