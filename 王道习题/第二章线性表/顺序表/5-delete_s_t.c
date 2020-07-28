/* 题目描述：从顺序表（表中元素为任意次序）中
 * 删除其值在给定值s到t之间的所有元素（包含s和t，要求s<t），
 * 如果s或t值不合理或者顺序表为空
 * 则显示错误信息并退出程序 */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "sqlist.h"


void delete_s_t(Sqlist *L, ElementType s, ElementType t);

int main()
{
    Sqlist L;
    Sqlist *Lptr = &L;
    init(Lptr);

    srand(time(NULL));
    int a;
    for(int i = 0; i < 50; i++)
    {
        a = rand()%10;

        insert_i(Lptr, i+1, a);
    }

    printSql(Lptr);
    delete_s_t(Lptr, 3, 7);
    printSql(Lptr);
    return 0;
}

void delete_s_t(Sqlist *L, ElementType s, ElementType t)
{
    if(s > t)
    {
        printf("Error: s is not smaller than t!\n");
        exit(1);
    }

    if(L->length == 0)
    {
        printf("Error: delete elements from empty sequencial list!\n");
        exit(1);
    }

    int i;
    int k = 0;

    for(i = 0; i < L->length; i++)
    {
        if(s <= L->data[i] && L->data[i] <= t)
        {
            k++;
        } else {
            L->data[i-k] = L->data[i];
        }
    }

    L->length -= k;
}
