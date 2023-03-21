/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//******************************************Singly Circular LinkedList IN C ******************************************
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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

void InsertFirst(PPNODE First, PPNODE Last, int No)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));

    newn->data = No;
    newn->next = NULL;

    if ((*First == NULL) && (*Last == NULL))
    {
        *First = newn;
        *Last = newn;
        (*Last)->next = *First;
    }
    else
    {
        newn->next = *First;
        *First = newn;
        (*Last)->next = *First;
    }
}

void InsertLast(PPNODE First, PPNODE Last, int No)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));

    newn->data = No;
    newn->next = NULL;

    if ((*First == NULL) && (*Last == NULL))
    {
        *First = newn;
        *Last = newn;
        (*Last)->next = *First;
    }
    else
    {
        (*Last)->next = newn;
        *Last = newn;
        (*Last)->next = *First;
    }
}

void DeleteFirst(PPNODE First, PPNODE Last)
{
    if ((*First == NULL) && (*Last == NULL))
    {
        return;
    }
    else if (*First == *Last)
    {
        free(*First);
        *First = NULL;
        *Last = NULL;
    }
    else
    {
        *First = (*First)->next;
        free((*Last)->next);
        (*Last)->next = *First;
    }
}

void DeleteLast(PPNODE First, PPNODE Last)
{
    if ((*First == NULL) && (*Last == NULL))
    {
        return;
    }
    else if (*First == *Last)
    {
        free(*First);
        *First = NULL;
        *Last = NULL;
    }
    else
    {
        PNODE Temp = *First;

        while (Temp->next->next != (*First))
        {
            Temp = Temp->next;
        }

        free(*Last);
        (*Last) = Temp;
        (*Last)->next = *First;
    }
}

void InsertAtPos(PPNODE First, PPNODE Last, int No, int ipos)
{
    int NodeCnt = 0, i = 1;
    NodeCnt = Count(*First, *Last);

    if ((NodeCnt < 1) || (ipos > (NodeCnt + 1)))
    {
        printf("Invalid Position\n");
        return;
    }

    if (ipos == 1)
    {
        InsertFirst(First, Last, No);
    }
    else if (ipos == (NodeCnt + 1))
    {
        InsertLast(First, Last, No);
    }
    else
    {
        PNODE newn = (PNODE)malloc(sizeof(NODE));

        newn->data = No;
        newn->next = NULL;

        PNODE Temp = *First;

        while (i < ipos - 1)
        {
            Temp = Temp->next;
            i++;
        }

        newn->next = Temp->next;
        Temp->next = newn;
    }
}

void DeleteAtPos(PPNODE First, PPNODE Last, int ipos)
{
    int NodeCnt = 0, i = 1;
    NodeCnt = Count(*First, *Last);

    if ((NodeCnt < 1) || (ipos > (NodeCnt)))
    {
        printf("Invalid Position\n");
        return;
    }

    if (ipos == 1)
    {
        DeleteFirst(First, Last);
    }
    else if (ipos == (NodeCnt))
    {
        DeleteLast(First, Last);
    }
    else
    {
        PNODE Temp1 = *First;

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

void Display(PNODE First, PNODE Last)
{
    do
    {
        printf("|%d|->", First->data);
        First = First->next;

    } while (First != (Last)->next);
}

int Count(PNODE First, PNODE Last)
{
    int iCnt = 0;
    do
    {
        iCnt++;
        First = First->next;

    } while (First != (Last)->next);

    return iCnt;
}

int main()
{
    int iRet = 0;

    PNODE Head = NULL;
    PNODE Tail = NULL;

    InsertFirst(&Head, &Tail, 51);
    InsertFirst(&Head, &Tail, 21);
    InsertFirst(&Head, &Tail, 11);
    Display(Head, Tail);
    iRet = Count(Head, Tail);
    printf("No of linkedList are %d\n", iRet);
    printf("\n");

    InsertLast(&Head, &Tail, 101);
    InsertLast(&Head, &Tail, 111);
    InsertLast(&Head, &Tail, 121);
    Display(Head, Tail);
    iRet = Count(Head, Tail);
    printf("No of linkedList are %d\n", iRet);
    printf("\n");

    InsertAtPos(&Head, &Tail, 91, 4);
    Display(Head, Tail);
    iRet = Count(Head, Tail);
    printf("No of linkedList are %d\n", iRet);
    printf("\n");

    DeleteAtPos(&Head, &Tail, 4);
    Display(Head, Tail);
    iRet = Count(Head, Tail);
    printf("No of linkedList are %d\n", iRet);
    printf("\n");

    DeleteFirst(&Head, &Tail);
    Display(Head, Tail);
    iRet = Count(Head, Tail);
    printf("No of linkedList are %d\n", iRet);
    printf("\n");

    DeleteLast(&Head, &Tail);
    Display(Head, Tail);
    iRet = Count(Head, Tail);
    printf("No of linkedList are %d\n", iRet);
    printf("\n");

    return 0;
}