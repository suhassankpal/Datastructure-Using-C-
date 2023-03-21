//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//****************************************Singly Linear LinkedList IN C *********************************************
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

#pragma pack(1)

typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;

struct node
{
    int data;
    struct node *next;
};

void InsertFirst(PPNODE First, int No)
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
        newn->next = *First;
        *First = newn;
    }
}

void InsertLast(PPNODE First, int No)
{
    PNODE Temp = *First;

    PNODE newn = (PNODE)malloc(sizeof(NODE));

    newn->data = No;
    newn->next = NULL;

    if (*First == NULL)
    {
        *First = newn;
    }
    else
    {
        while (Temp->next != NULL)
        {
            Temp = Temp->next;
        }

        Temp->next = newn;
    }
}

void DeleteFirst(PPNODE First)
{
    PNODE Temp = *First;

    if (*First == NULL)
    {
        return;
    }
    else if ((*First)->next == NULL)
    {
        free(*First);
        *First = NULL;
    }
    else
    {
        *First = Temp->next;
        free(Temp);
    }
}

void DeleteLast(PPNODE First)
{
    PNODE Temp = *First;

    if (*First == NULL)
    {
        return;
    }
    else if ((*First)->next == NULL)
    {
        free(*First);
        *First = NULL;
    }
    else
    {
        while (Temp->next->next != NULL)
        {
            Temp = Temp->next;
        }

        free(Temp->next);
        Temp->next = NULL;
    }
}

void InsertAtPos(PPNODE First, int No, int ipos)
{
    int NodeCnt = 0;
    NodeCnt = Count(*First);

    if ((ipos < 1) || (ipos > (NodeCnt + 1)))
    {
        printf("Invalid position\n");
        return;
    }

    if (ipos == 1)
    {
        InsertFirst(First, No);
    }
    else if (ipos == (NodeCnt + 1))
    {
        InsertLast(First, No);
    }
    else
    {
        PNODE newn = (PNODE)malloc(sizeof(NODE));

        newn->data = No;
        newn->next = NULL;

        PNODE Temp = *First;

        int i = 1;
        while (i < ipos - 1)
        {
            Temp = Temp->next;
            i++;
        }

        newn->next = Temp->next;
        Temp->next = newn;
    }
}

void DeleteAtPos(PPNODE First, int ipos)
{
    int NodeCnt = 0;
    NodeCnt = Count(*First);

    if ((ipos < 1) || (ipos > (NodeCnt)))
    {
        printf("Invalid position\n");
        return;
    }

    if (ipos == 1)
    {
        DeleteFirst(First);
    }
    else if (ipos == (NodeCnt))
    {
        DeleteLast(First);
    }
    else
    {
        PNODE Temp1 = *First;

        int i = 1;
        while (i < ipos - 1)
        {
            Temp1 = Temp1->next;
            i++;
        }

        PNODE Temp2 = Temp1->next;

        Temp1->next = Temp2->next;
        free(Temp2);
    }
}

void Display(PNODE First)
{
    printf("Elements of linked list are :\n");

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

    PNODE Head = NULL;

    InsertFirst(&Head, 51);
    InsertFirst(&Head, 21);
    InsertFirst(&Head, 11);
    Display(Head);
    iRet = Count(Head);
    printf("Number of elements in linkedlist are : %d\n", iRet);
    printf("\n");

    InsertLast(&Head, 111);
    InsertLast(&Head, 121);
    InsertLast(&Head, 151);
    Display(Head);
    iRet = Count(Head);
    printf("Number of elements in linkedlist are : %d\n", iRet);
    printf("\n");

    InsertAtPos(&Head, 101, 4);
    Display(Head);
    iRet = Count(Head);
    printf("Number of elements in linkedlist are : %d\n", iRet);
    printf("\n");

    DeleteAtPos(&Head, 4);
    Display(Head);
    iRet = Count(Head);
    printf("Number of elements in linkedlist are : %d\n", iRet);
    printf("\n");

    DeleteFirst(&Head);
    Display(Head);
    iRet = Count(Head);
    printf("Number of elements in linkedlist are : %d\n", iRet);
    printf("\n");

    DeleteLast(&Head);
    Display(Head);
    iRet = Count(Head);
    printf("Number of elements in linkedlist are : %d\n", iRet);
    printf("\n");

    return 0;
}