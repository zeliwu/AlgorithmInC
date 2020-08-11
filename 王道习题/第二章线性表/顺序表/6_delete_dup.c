/*从有序顺序表中删除所有其值重复的元素，使表中各值都不相同*/

#include "sqlist.h"
#include <stdio.h>
#include <stdlib.h>

void delete_dup(Sqlist *);

int main()
{
    Sqlist L;
    Sqlist *Lptr = &L;

    init(Lptr);
    int k = 1;
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            insert_i(Lptr, k, i);
            k++;
        }
    }

    printSql(Lptr);

    delete_dup(Lptr);
    printSql(Lptr);

    return 0;

}

void delete_dup(Sqlist *L)
{
    if(L->length < 1)
    {
        printf("Error: Deleting empty sequential list\n");
        exit(1);
    }
        
    ElementType temp = L->data[0];
    int k = 0; //用来记录有多少个重复值元素

    int i;
    for(i = 1;i < L->length; i++)
    {
        if(temp != L->data[i])
        {
            temp = L->data[i];
            L->data[i-k] = L->data[i];
        }
        else
            k++;
    }

    L->length -= k;   
}
