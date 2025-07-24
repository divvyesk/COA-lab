#include<stdio.h>
#include<stdlib.h>
#define MAX 8

int Q[MAX];
int M[MAX];
int A[MAX] = {0,0,0,0};
int Q1 = 0;         

void dec_to_bin(int num, int binary[])
{
    if(num > 0)
    {
        for(int i= MAX-1; i>=0; i--)
        {
            binary[i] = num % 2;
            num = num/2;
        }
    }

    else{
        num = abs(num);
        int temp[MAX];

        for(int i= MAX-1; i>=0; i--) //binary form of +ve decimal number
        {
            temp[i] = num % 2;
            num = num / 2;
        }

        int carry = 1;

        for(int i=0; i< MAX; i++) //1s complement
        {
            temp[i] = (temp[i] == 0) ? 1 : 0;
        }

        for(int i = MAX-1; i>=0; i--) //2s complement
        {
            int sum = temp[i] + carry; //adding one to last bit
            temp[i] = sum % 2; // 1+1=2%2=0  1+0=1%2=1  0+1=1%2=1 0+0=0%2=0 this is truth table for storing ans
            carry = sum / 2; //1+1=2/2=1  1+0=1/2=0 0+1=1/2=0 0+0=0/2=0 this is truth table for carry
        }

        for(int i=0; i<MAX; i++)
        {
            binary[i] = temp[i]; //after taking 2s complement we add it in the binary wala array
        }

    }
}

void displaybin(int binary[])
{
    for(int i=0; i< MAX; i++)
    {
        printf("%d", binary[i]);
    }

    printf("\n");
}

void add(int A[], int M[])
{
    int carryover = 0;

    for(int i= MAX-1; i>=0; i--)
    {
        int sum = A[i] + M[i] + carryover;
        A[i] = sum % 2;
        carryover = sum/2;
    }
}

void twocomp(int A[], int M[])
{
    int temp[MAX];         

    //1s complement of M
    for(int i=0; i<MAX; i++)
    {
        if(M[i] == 0)
        {
            temp[i] = 1;
        }

        else
            temp[i] = 0;
    
    }

    int carry = 1;

    //2s complement
    for(int i=MAX-1; i>=0; i--)
    {
        int sum = temp[i] + carry;
        temp[i] = sum  % 2;
        carry = sum / 2;
    }

    add(A, temp);
}

void ars(int A[], int Q[], int Q1)
{
    int A2 = A[MAX-1];
    Q1 = Q[MAX-1];

    for(int i = MAX-1; i>0; i--)
    {
        Q[i] = Q[i-1];
    }
    Q[0] = A2;

    for(int i=MAX-1; i>0; i--)
    {
        A[i] = A[i-1];
    }
    A[0] = A[0];         
}
         
void booths_algo()
{
    printf("\n\n----INITIAL VALUES----\n\n");
    printf("A: ");
    displaybin(A);

    printf("Q: ");
    displaybin(Q);

    printf("M: ");
    displaybin(M);

    printf("Q1: %d\n", Q1);
    
    for(int count = 0; count < MAX; count++) //the algo will run n time
    {
        if(Q[MAX-1]== 1 && Q1 == 0) //Q0 and Q1 comparision
        {
            twocomp(A,M); 
            printf("A = A-M: ");
            displaybin(A);
        }

        else if(Q[MAX-1] == 0 && Q1 == 1){
            add(A,M);
            printf("A= A + M:");
            displaybin(A);
        }

        ars(A,Q,Q1);
        printf("\n\nAfter Right Shift: \n");
        printf("A: ");
        displaybin(A);

        printf("Q: ");
        displaybin(Q);

        printf("Q1: %d\n", Q1);

    }         

    printf("The product is: ");
    for(int i=0; i< MAX; i++)
    {
        printf("%d", A[i]);
    }

    for(int i=0; i<MAX; i++)
    {
        printf("%d", Q[i]);
    }

    printf("\n");

}

int main()
{
    int num1;
    int num2;

    printf("Name: Divvye Kansara\nDiv: C21\nRoll number: 2403080\n\n");

    printf("Enter the first decimal number: ");
    scanf("%d", &num1);
    dec_to_bin(num1, Q);


    printf("Enter the second decimal number: ");
    scanf("%d", &num2);
    dec_to_bin(num2, M);
         
    
    booths_algo();

    return 0;
}