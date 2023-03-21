///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// ******************************************Implementation of stack******************************************
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;

struct node
{
    int data;
    struct node *next;
};

bool isEmpty(PNODE ptr)
{
    if (ptr == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Push(PPNODE First, int No)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));
    newn->data = No;
    newn->next = NULL;

    if (*First == NULL)
    {
        *First = newn;
    }
    else
    {
        PNODE Temp = *First;

        while (Temp->next != NULL)
        {
            Temp = Temp->next;
        }

        Temp->next = newn;
    }
    printf(" Gets pushed in the stack succesfully\n ");
}

int Pop(PPNODE First)
{
    int value = 0;

    if (*First == NULL)
    {
        printf("Unable to pop the element as stack is empty\n");
        return -1;
    }
    else if ((*First)->next == NULL)
    {
        value = (*First)->data;
        *First = NULL;
        return value;
    }
    else
    {
        PNODE Temp = *First;

        while (Temp->next->next != NULL)
        {
            Temp = Temp->next;
        }

        value = Temp->next->data;

        free(Temp->next);
        Temp->next = NULL;
        return value;
    }
}

void Display(PNODE First)
{
    printf("Elements of stack are:\n");

    while (First != NULL)
    {
        printf("|%d|->", First->data);
        First = First->next;
    }
    printf("NULL\n");
}

int Count(PNODE First)
{
    int iCnt = 0;

    while (First != NULL)
    {
        iCnt++;
        First = First->next;
    }
    return iCnt;
}

int main()
{
    int iRet = 0;
    bool bRet = 0;
    PNODE Head = NULL;

    Push(&Head, 11);
    Push(&Head, 21);
    Push(&Head, 31);
    Push(&Head, 41);
    Display(Head);
    iRet = Count(Head);
    printf("No of nodes are %d\n", iRet);

    iRet = Pop(&Head);
    printf("Poped element is :%d\n ", iRet);
    Display(Head);
    iRet = Count(Head);
    printf("No of nodes are %d\n", iRet);

    bRet = isEmpty(Head);
    printf("%d\n", bRet);

    return 0;
}