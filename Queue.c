///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// ****************************************Implementation of Queue******************************************
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

bool isQueueEmpty(PNODE First)
{
    if (First == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void EnQueue(PPNODE First, int No)
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
}

int DeQueue(PPNODE First)
{
    int value = 0;

    if (*First == NULL)
    {
        printf("Unable to pop the element as Queue is empty\n");
        return -1;
    }
    else if ((*First)->next == NULL)
    {
        value = (*First)->data;
        (*First)->next = NULL;
        return value;
    }
    else
    {
        PNODE Temp = *First;
        value = (*First)->data;
        *First = (*First)->next; //*First = Temp->next;
        free(Temp);
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

    EnQueue(&Head, 11);
    EnQueue(&Head, 21);
    EnQueue(&Head, 51);
    EnQueue(&Head, 101);
    Display(Head);
    iRet = Count(Head);
    printf("No of elements in queue are %d\n", iRet);

    DeQueue(&Head);
    Display(Head);
    iRet = Count(Head);
    printf("No of elements in queue are %d\n", iRet);

    bRet = isQueueEmpty(Head);
    if (bRet == 0)
    {
        printf("Queue is not empty\n");
    }
    else
    {
        printf("Queue is empty\n");
    }

    return 0;
}
