#ifndef SQLIST_H
#define SQLIST_H
/* 定义顺序表的头文件 */

//定义一个数据类型的宏，这样能在想修改数据类型时，只修改此处
#define ElementType int

#define InitialSize 50

//此处是动态分配顺序表的定义
typedef struct 
{
    ElementType *data;
    int MaxSize, length;
} Sqlist;

//对顺序表进行初始化
extern void init(Sqlist *L);

//动态地对顺序表进行构造
extern void construct(Sqlist *L);

//在第i个位置插入新的元素，插入成功返回0,失败返回1
extern int insert_i(Sqlist *L, int i, ElementType e);

//删除第i个位置的元素
extern int delete_i(Sqlist *L, int i);

//按值查找，返回第一个值等于e的元素的位置
extern int locate_e(Sqlist *L, ElementType e);

//顺序打印所有元素
extern void printSql(Sqlist *L);

#endif
