#pragma once//动态顺序表 属于线性表的一种
#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include"Contact.h"
////可以对函数重命名更方便使用
//#define SLInit init

/*typedef int Sldatatype;*///这里可以更方便以后的部分数据类型更改 
typedef peoInfo Sldatatype;
//typedef struct seqlist
//{
//	Sldatatype* arr;
//	Sldatatype size;//有效元素个数
//	Sldatatype space;//空间大小
//}SL;
typedef struct seqlist
{
	Sldatatype* arr;
	int size;
	int space;
}SL;
//创建空间并初始化 
void SLInit(SL* ps);
//<<<------------空间的释放------------->>>
void SLdestory(SL* ps);
//<<<--------------打印--------------->>>
//void SLPrint(SL s);

void SLcheckspace(SL* ps);
//<<<------------增加元素------------->>>
//开头/结尾添加
void SLPushfront(SL* ps, Sldatatype x);
void SLPushback(SL* ps, Sldatatype x);
//指定位置插入数据
void SLInsert(SL* ps, int pos, Sldatatype x);
//<<<------------删除元素------------->>>
//开头/结尾删除
void SLPopfront(SL* ps);
void SLPopback(SL* ps);
//指定删除
void SLErase(SL* ps, int pos);
//查找
//Sldatatype SLFind(SL* ps, Sldatatype x);

