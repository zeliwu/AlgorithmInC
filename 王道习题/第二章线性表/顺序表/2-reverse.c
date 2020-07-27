/*设计一个高效的算法，将顺序表的所有元素逆置，要求算法的空间复杂度为O(1)*/

#include "sqlist.h"

void reverse(Sqlist *L);

int main()
{
    Sqlist L;
    Sqlist *Lptr = &L;
    init(Lptr);

    //实例化一个顺序表
    for(int i = 0; i < 10; i++)
    {
        insert_i(Lptr, i+1, i);
    }

    printSql(Lptr);

    reverse(Lptr);
    printSql(Lptr);

    return 0;
}

void reverse(Sqlist *L)
{
    //只用到了这一辅助空间
    ElementType temp;

    for(int i = 0; i < L->length/2; i++)
    {
        temp = L->data[i];
        L->data[i] = L->data[L->length-1-i];
        L->data[L->length-1-i] = temp;
    }
}