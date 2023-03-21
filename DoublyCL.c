/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//******************************************Doubly Circular LinkedList IN C ******************************************
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
    struct node *prev;
};

void InsertFirst(PPNODE First, PPNODE Last, int No)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));

    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if ((*First == NULL) && (*Last == NULL))
    {
        *First = newn;
        *Last = newn;

        (*First)->prev = *Last;
        (*Last)->next = *First;
    }
    else
    {
        newn->next = *First;
        newn->next->prev = newn;
        *First = newn;

        (*First)->prev = *Last;
        (*Last)->next = *First;
    }
}

void InsertLast(PPNODE First, PPNODE Last, int No)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));
    PNODE Temp = *First;

    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if ((*First == NULL) && (*Last == NULL))
    {
        *First = newn;
        *Last = newn;

        (*First)->prev = *Last;
        (*Last)->next = *First;
    }
    else
    {

        (*Last)->next = newn;
        newn->prev = *Last;
        *Last = newn;

        (*First)->prev = *Last;
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
        free((*First)->prev); // here we can use Temperary pointer

        (*First)->prev = *Last;
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

        *Last = (*Last)->prev;
        free((*Last)->next);

        (*First)->prev = *Last;
        (*Last)->next = *First;
    }
}

void InsertAtPos(PPNODE First, PPNODE Last, int No, int ipos)
{
    int NodeCnt = 0, i = 0;
    NodeCnt = Count(*First, *Last);

    if ((ipos < 1) || (ipos > (NodeCnt + 1)))
    {
        printf("Invalid position\n");
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
        newn->prev = NULL;

        PNODE Temp = *First;

        i = 1;
        while (i < ipos - 1)
        {
            Temp = Temp->next;
            i++;
        }

        newn->next = Temp->next;
        newn->next->prev = newn;

        newn->prev = Temp;
        Temp->next = newn;
    }
}

void DeleteAtPos(PPNODE First, PPNODE Last, int ipos)
{
    int NodeCnt = 0, i = 0;
    NodeCnt = Count(*First, *Last);

    if ((ipos < 1) || (ipos > (NodeCnt)))
    {
        printf("Invalid position\n");
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

        PNODE Temp = *First;

        i = 1;
        while (i < ipos - 1)
        {
            Temp = Temp->next;
            i++;
        }

        Temp->next = Temp->next->next;
        free(Temp->next->prev);
        Temp->next->prev = Temp;
    }
}

void Display(PNODE First, PNODE Last)
{
    printf("<=");

    do
    {
        printf("|%d|=>", First->data);
        First = First->next;
    } while (First != (Last->next));
    printf("\n");
}

int Count(PNODE First, PNODE Last)
{
    int iCnt = 0;

    do
    {
        iCnt++;
        First = First->next;
    } while (First != (Last->next));

    return iCnt;
}

int main()
{
    int iRet = 0;

    PNODE Head = NULL;
    PNODE Tail = NULL;

    InsertFirst(&Head, &Tail, 51);
    InsertFirst(&Head, &Tail, 41);
    InsertFirst(&Head, &Tail, 31);
    InsertFirst(&Head, &Tail, 21);
    InsertFirst(&Head, &Tail, 11);
    Display(Head, Tail);
    iRet = Count(Head, Tail);
    printf("Elements in linked list are: %d\n", iRet);
    printf("\n");

    InsertLast(&Head, &Tail, 71);
    InsertLast(&Head, &Tail, 81);
    InsertLast(&Head, &Tail, 91);
    InsertLast(&Head, &Tail, 101);
    InsertLast(&Head, &Tail, 111);
    Display(Head, Tail);
    iRet = Count(Head, Tail);
    printf("Elements in linked list are: %d\n", iRet);
    printf("\n");

    InsertAtPos(&Head, &Tail, 61, 6);
    Display(Head, Tail);
    iRet = Count(Head, Tail);
    printf("Elements in linked list are: %d\n", iRet);
    printf("\n");

    DeleteAtPos(&Head, &Tail, 6);
    Display(Head, Tail);
    iRet = Count(Head, Tail);
    printf("Elements in linked list are: %d\n", iRet);
    printf("\n");

    DeleteFirst(&Head, &Tail);
    Display(Head, Tail);
    iRet = Count(Head, Tail);
    printf("Elements in linked list are: %d\n", iRet);
    printf("\n");

    DeleteLast(&Head, &Tail);
    Display(Head, Tail);
    iRet = Count(Head, Tail);
    printf("Elements in linked list are: %d\n", iRet);
    printf("\n");

    return 0;
}