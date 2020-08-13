/*
求一个元素值为整数的顺序表的主元素，主元素即频率大于顺序表长度一半的元素
(0,5,5,3,5,7,5,5)的主元素为5,而(0,5,5,3,5,1,5,7)没有主元素
*/

#include "sqlist.h"
#include <stdio.h>

void find_mainElem(Sqlist *L);

int main()
{
    Sqlist L1;
    Sqlist L2;

    Sqlist *Lptr1 = &L1;
    Sqlist *Lptr2 = &L2;

    init(Lptr1);
    init(Lptr2);

    insert_i(Lptr1, 1, 0);
    insert_i(Lptr1, 2, 5);
    insert_i(Lptr1, 3, 5);
    insert_i(Lptr1, 4, 3);
    insert_i(Lptr1, 5, 5);
    insert_i(Lptr1, 6, 7);
    insert_i(Lptr1, 7, 5);
    insert_i(Lptr1, 8, 5);
    printSql(Lptr1);
    find_mainElem(Lptr1);

    insert_i(Lptr2, 1, 0);
    insert_i(Lptr2, 2, 5);
    insert_i(Lptr2, 3, 5);
    insert_i(Lptr2, 4, 3);
    insert_i(Lptr2, 5, 5);
    insert_i(Lptr2, 6, 1);
    insert_i(Lptr2, 7, 5);
    insert_i(Lptr2, 8, 7);
    printSql(Lptr2);
    find_mainElem(Lptr2);

    return 0;
}

void find_mainElem(Sqlist *L)
{
    int mark;
    int counter;//记录mark出现的频率，下一元素相同则加一，反之减一
    int freq = 0;//记录最后得出mark出现的频率


    mark = L->data[0];
    counter = 1;

    for(int i = 1; i < L->length; i++)
    {
        if(counter > 0)
        {
            if(mark == L->data[i])
                counter++;
            else
                counter--;
        }
        else
        {
            mark = L->data[i];
            counter = 1;
        }
    }

    if(counter > 0)
    {
        for(int i = 0; i < L->length; i++)
        {
            if(mark == L->data[i])
                freq++;
        }

        if(freq > L->length/2)
            printf("此顺序表的主元素为： %d\n", mark);
        else
        {
            printf("此顺序表没有主元素！\n");
        }
        
    }
    else
    {
        printf("此顺序表没有主元素！\n");
    }
}