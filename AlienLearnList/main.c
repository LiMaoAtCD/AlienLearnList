

#include <stdio.h>
#include <malloc/malloc.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct node{
    ElemType value;
    struct node *next;
}Node;
typedef struct node *Ptr;


Ptr createList(int num)
{
    Ptr m;
    
    m = (Ptr)malloc(sizeof(Node));
    
    m->next = NULL;
    m->value = 0;
    printf("malloc success\n");
    for (int i=0; i<num; i++) {
        Ptr n = (Ptr)malloc(sizeof(Node));
       
        n->value = i;
        
        n->next = m ->next;
        m->next =n;
        printf("malloc success!\n");
        
        
    }
    return m;
}

void VisitList(Ptr p)
{

    if (p != NULL) {
         printf("m->value:%d\n",p->value);

        while (p->next != NULL) {
            p = p->next;
            printf("m->value:%d\n",p->value);
        }
        
    
    }else{
        printf("p is NULL");
    }
}

void deleteList(Ptr p)
{
    Ptr m;
    int i =0;
    if (p != NULL) {
        while (p->next != NULL) {
            m =p->next;
            free(p);
            i++;
            printf("free %d times\n",i);
            p = m;
        }
        free(p);
        printf("free %d times\n",++i);
        
    }else{
        printf("list is null");
    }
}
Ptr InsertElementAtHead(Ptr header,ElemType n)
{
    Ptr temp = (Ptr)malloc(sizeof(Node));
    
    temp->value = n;
    temp->next = header;
    header = temp;
    return header;
}

Ptr InsertElementAtTail(Ptr header,ElemType n)
{
    Ptr temp = (Ptr)malloc(sizeof(header));
    temp->value = n;
    temp->next = NULL;
    
    if (header != NULL) {
        if (header->next != NULL) {
            Ptr ptr = header->next;
            while (ptr->next !=NULL) {
                ptr = ptr -> next;
            }
            ptr->next = temp;
            
        }else{
            header->next = temp;
        }
        
    }else{
        printf("insert failed");
    }
    return header;
}

int insertElementSomewhere(Ptr header, int index, ElemType n)
{
    int i;
    if (header != NULL) {
         i =1;
        if (header->next != NULL) {
            Ptr p =header;
            while (p->next != NULL) {
                p= p->next;
                i++;
            }
        }
    }
    if (index >i) {
        printf("beyond number of node");
        return 0;
    }else{
        Ptr temp = (Ptr)malloc(sizeof(Node));
        temp ->value = n;
        temp ->next = NULL;
        
         Ptr p = header;
        for(int j=1;j<index;j++)
        {
            p=p->next;
            
        }
        temp->next = p->next;
        p->next = temp;
    }
    return 1;
}

void deleteElementAtIndex(Ptr a, int index)
{
    if (a == NULL) {
        return;
    }
    int i=1;
    Ptr temp = a;
    while (temp ->next != NULL) {
        temp =temp ->next;
        i++;
    }
    if (index >i) {
        printf("beyond scope");
        return;
    }
     temp =a;
    Ptr temp1 = NULL;
    for (int j=1; j<index; j++) {
        temp1 = temp;
        temp = temp->next;
    }
    temp1->next =temp ->next;
    free(temp);
    
}


int main()
{
    Ptr a;
    printf("createList\n");
    a = createList(2);
    
    VisitList(a);
    ElemType b = 3;
    printf("insert at head\n");
    a =InsertElementAtHead(a,b);
    VisitList(a);
    
    printf("insert at tail\n");
    a= InsertElementAtTail(a, 4);
    VisitList(a);
    
    int isInsert = insertElementSomewhere(a, 1, 10);
    if (isInsert) {
        printf("insert success\n");
        VisitList(a);
    }else
        printf("insert failed");
    
    
    printf("deleteElementAtIndex\n");
    deleteElementAtIndex(a, 2);
    VisitList(a);
    
    printf("deleteList\n");
    deleteList(a);
    
    return 0;
}