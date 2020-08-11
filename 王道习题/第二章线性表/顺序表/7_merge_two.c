/*将两个有序顺序表合并成为一个新的有序顺序表，并由函数返回结果顺序表*/

#include "sqlist.h"

void merge_two(Sqlist *, Sqlist *, Sqlist *);

int main()
{
    Sqlist L1, L2, L;
    Sqlist *Lptr1 = &L1;
    Sqlist *Lptr2 = &L2;
    Sqlist *Lptr = &L;

    init(Lptr1);
    init(Lptr2);
    init(Lptr);

    for(int i = 0; i < 10; i++)
    {
        insert_i(Lptr1, i+1, i*2);
    }
    
    for(int i = 0; i < 10; i++)
    {
        insert_i(Lptr2, i+1, i*2+1);
    }

    printSql(Lptr1);
    printSql(Lptr2);

    merge_two(Lptr1, Lptr2, Lptr);
    printSql(Lptr);
    return 0;
}

void merge_two(Sqlist *L1, Sqlist *L2, Sqlist *Lptr)
{
    int i = 0;
    int j = 0;
    int k = 1;
    while(i < L1->length && j < L2->length)
    {
        if(L1->data[i] < L2->data[j])
        {
            insert_i(Lptr, k, L1->data[i]);
            i++;
            k++;
        } else {
            insert_i(Lptr, k, L2->data[j]);
            j++;
            k++;
        }
    }

    while(i < L1->length)
    {
        insert_i(Lptr, k, L1->data[i]);
        i++;
        k++;
    }

    while(j < L2->length)
    {
        insert_i(Lptr, k, L2->data[j]);
        j++;
        k++;
    }
}
