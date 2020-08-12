/*一维数组A[m+n]中依次存放着两个线性表(a1,a2,a3,...,am)和
 * (b1,b2,b3,...,bn)，写一个函数将两个顺序表的位置进行互换，
 * 即将(b1,b2,b3,...,bn)放在(a1,a2,a3,...,am)前面*/

#include "sqlist.h"
#include <stdio.h>

//将数组第m到n位置的元素进行逆置
int array_reverse(Sqlist *L, int m, int n);

//将两个顺序表的位置进行互换
void array_exchange(Sqlist *L, int m, int n);

int main()
{
    Sqlist L;
    Sqlist *Lptr = &L;
    init(Lptr);

    int i;
    for(i = 1; i <= 10; i++)
    {
        insert_i(Lptr, i, i);
    }

    for(int j = 30; j < 45; j++, i++)
    {
        insert_i(Lptr, i, j);
    }

    printSql(Lptr);

    array_exchange(Lptr, 10, 15);
    printSql(Lptr);

    return 0;
}

int array_reverse(Sqlist *L, int m, int n)
{
    //检查m和n是否在有效区间内
    if(m < 0 || n >= L->length || m > n)
    {
        printf("Error: m或者n的值不在有效区间!\n");
        return 1;
    }

    int i = m;
    int j = n;

    ElementType temp;
    for(;i < j; i++, j--)
    {
        temp = L->data[i];
        L->data[i] = L->data[j];
        L->data[j] = temp;
    }

    return 0;
}

void array_exchange(Sqlist *L, int m, int n)
{
    array_reverse(L, 0, L->length-1);
    array_reverse(L, 0, n-1);
    array_reverse(L, n, L->length-1);
}
