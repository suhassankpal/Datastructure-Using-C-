// ######################################################################################################################
// ************************************Stack implementation by using array************************************
// ######################################################################################################################

#include <stdio.h>
#include <stdlib.h>

#define max 5
int Arr[max], top = -1;

void push()
{
    int data;

    if (top == (max - 1))
    {
        printf("overflow or Stack is full\n");
    }
    else
    {
        printf("Enter data that you want to store\n");
        scanf("%d", &data);
        top++;
        Arr[top] = data;
        printf("Element is succesfully enterd\n");
    }
}

void pop()
{
    if (top == -1)
    {
        printf("uderflow or Stack is empty\n");
    }
    else
    {
        printf("Poped element is %d", Arr[top]);
        top--;
    }
}

void Display()
{
    if (top == -1)
    {
        printf("Stack is empty unable\n");
    }
    else
    {
        printf("element are :\n");
        for (int i = top; i >= 0; i--)
        {
            printf("%d\n", Arr[i]);
        }
    }
}

int main()
{
    int ch = 0;

    printf("Enter 1 : for push  or insert element\n");
    printf("Enter 2 : for pop or delete element\n");
    printf("Enter 3 : for Display the element\n");
    printf("Enter 4 : for end program\n");

    while (1)
    {
        printf("\nEnter choice\n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
        {
            push();
            break;
        }

        case 2:
        {
            pop();
            break;
        }

        case 3:
        {
            Display();
            break;
        }

        case 4:
        {
            exit(0);
        }

        default:
        {
            printf("Wrong choice\n");
        }
        }
    }

    return 0;
}