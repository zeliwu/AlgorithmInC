#include <stdio.h>
#include <stdlib.h>
#include "sqlist.h"

void init(Sqlist *L)
{
    L->MaxSize = InitialSize;
    L->length = 0;
    L->data = (ElementType*) malloc(InitialSize*sizeof(ElementType));

    if(L->data == NULL)
    {
        printf("Error: malloc fail!\n");
        exit(1);
    }
}

void construct(Sqlist *L)
{
    L->MaxSize *= 2;

    ElementType *tempPtr = L->data;//暂存原先指向的数组
    L->data = (ElementType*) malloc(L->MaxSize*sizeof(ElementType));
 
    if(L->data == NULL)
    {
        printf("Error: malloc fail!\n");
        exit(1);
    }

    //将原先数组的值进行复制
    for(int i = 0; i < L->length; i++)
    {
        L->data[i] = tempPtr[i]; 
    }

    free(tempPtr); //释放掉不用的指针，避免野指针，和资源的浪费 
}

int insert_i(Sqlist *L, int i, ElementType e)
{
    //判断i值是否有效
    if(i < 1 || i > L->length+1)
    {
        return 1;
    }

    for(int j = L->length; i <= j; j--)
    {
        L->data[j] = L->data[j-1];
    }
    L->data[i-1] = e;

    L->length++;

    //若长度将大于容量，调用construct函数，对顺序表进行扩容
    if(L->length >= L->MaxSize)
    {
        construct(L);
    }

    return 0;
}


//复杂度为O(n)
int delete_i(Sqlist *L, int i)
{
    //判断i值是否有效
    if(i < 1 || i > L->length)
    {
        return 1;
    }

    for(int j = i; j < L->length; j++)
    {
        L->data[j-1] = L->data[j];
    }

    L->length--;
    return 0;
}

int locate_e(Sqlist *L, ElementType e)
{
    int i;
    for(i = 0; i < L->length; i++)
    {
        if(L->data[i] == e)
        {
            return i+1;
        }
    }

    //没有相等的元素
    return 0;
}

void printSql(Sqlist *L)
{
    for(int i = 0; i < L->length; i++)
        printf("%d ", L->data[i]);
    
    printf("\n");
}
