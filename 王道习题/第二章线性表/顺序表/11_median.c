/*有两个等长的升序序列A和B，试设计一个在时间和空间都高效
 * 的算法，找出两个序列的中位数(median)*/

#include "sqlist.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

ElementType median1(Sqlist *L1, Sqlist *L2);
ElementType median2(Sqlist *L1, Sqlist *L2);

int main()
{
    Sqlist L1, L2;
    Sqlist *Lptr1 = &L1;
    Sqlist *Lptr2 = &L2;
    init(Lptr1);
    init(Lptr2);

    for(int i = 11, j = 1; i <= 19; j++)
    {
        insert_i(Lptr1, j, i);
        i += 2;
    }
    
    for(int i = 2, j = 1; i <= 8; j++)
    {
        insert_i(Lptr2, j, i);
        i += 2;
    }

    insert_i(Lptr2, 5, 20);

    printf("median = %d\n", median1(Lptr1, Lptr2));
    printf("median = %d\n", median2(Lptr1, Lptr2));
    return 0;

}

//这个算法时间复杂度为O(n)，空间复杂度为O(1)
ElementType median1(Sqlist *L1, Sqlist *L2)
{
    int i = 0;
    int j = 0;
    int k = 1;

    while(k < ceil((L1->length + L2->length)/2) && i < L1->length && j <L2->length) {
        if(L1->data[i] < L2->data[j])
        {
            i++;
            k++;
        } else {
            j++;
            k++;
        }
    }

    if(k == ceil((L1->length + L2->length)/2))
    {
        if(L1->data[i] < L2->data[j])
            return L1->data[i];
        else
            return L2->data[j];
    }
    
    while(k < ceil((L1->length + L2->length)/2) && i < L1->length)
    { 
        i++;
        k++;
    }

    while(k < ceil((L1->length + L2->length)/2) && j <L2->length)
    {
        j++;
        k++;
    }

    if(L1->data[i] < L2->data[j])
        return L2->data[j];
    else
        return L1->data[i];
}

//这个算法利用折半的思想，时间复杂度为O(log2n)，空间复杂度为O(1)
ElementType median2(Sqlist *L1, Sqlist *L2)
{
    int s1 = 0, m1, d1 = L1->length-1;
    int s2 = 0, m2, d2 = L2->length-1;

    while(s1 != d1 || s2 != d2)
    {
        m1 = (s1 + d1)/2;
        m2 = (s2 + d2)/2;
        
        if(L1->data[m1] == L2->data[m2])
            return L1->data[m1];

        if(L1->data[m1] < L2->data[m2])
        {
            if((s1 + d1)%2 == 0)
            {
                s1 = m1;
                d2 = m2;
            } else {
                s1 = m1 + 1;
                d2 = m2;
            }
        } else {
            if((s2 + d2)%2 == 0)
            {
                d1 = m1;
                s2 = m2;
            } else {
                d1 = m1;
                s2 = m2 + 1;
            }
        }
    }

    return (L1->data[s1] < L2->data[s2]) ? L1->data[s1] : L2->data[s2];
}
