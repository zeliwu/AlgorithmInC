/*题目描述：一个长度为n的顺序表L，删除所有值等于x的元素，要求时间复杂度为O(n)，空间复杂度为O(1)*/

#include <stdlib.h>
#include <time.h>
#include "sqlist.h"

void delete_all_x(Sqlist *L, ElementType x);

int main()
{
    Sqlist L;
    Sqlist *Lptr = &L;

    init(Lptr);

    int a;
    //用随机数，来实例化顺序表
    for(int i = 0; i < 50; i++)
    {
        srand(time(NULL));
        a = rand()%10;

        insert_i(Lptr, i+1, a);
    }

    printSql(Lptr);
    delete_all_x(Lptr, 3);
    printSql(Lptr);

    return 0;
}

//用k来记录L中值不等于x的元素个数
void delete_all_x(Sqlist *L, ElementType x)
{
    int k = 0;
    for(int i = 0; i < L->length; i++)
    {
        if(L->data[i] != x)
        {
            L->data[k] = L->data[i];
            k++;
        }
    }

    L->length = k;
}

