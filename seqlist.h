#pragma once//��̬˳��� �������Ա��һ��
#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include"Contact.h"
////���ԶԺ���������������ʹ��
//#define SLInit init

/*typedef int Sldatatype;*///������Ը������Ժ�Ĳ����������͸��� 
typedef peoInfo Sldatatype;
//typedef struct seqlist
//{
//	Sldatatype* arr;
//	Sldatatype size;//��ЧԪ�ظ���
//	Sldatatype space;//�ռ��С
//}SL;
typedef struct seqlist
{
	Sldatatype* arr;
	int size;
	int space;
}SL;
//�����ռ䲢��ʼ�� 
void SLInit(SL* ps);
//<<<------------�ռ���ͷ�------------->>>
void SLdestory(SL* ps);
//<<<--------------��ӡ--------------->>>
//void SLPrint(SL s);

void SLcheckspace(SL* ps);
//<<<------------����Ԫ��------------->>>
//��ͷ/��β���
void SLPushfront(SL* ps, Sldatatype x);
void SLPushback(SL* ps, Sldatatype x);
//ָ��λ�ò�������
void SLInsert(SL* ps, int pos, Sldatatype x);
//<<<------------ɾ��Ԫ��------------->>>
//��ͷ/��βɾ��
void SLPopfront(SL* ps);
void SLPopback(SL* ps);
//ָ��ɾ��
void SLErase(SL* ps, int pos);
//����
//Sldatatype SLFind(SL* ps, Sldatatype x);

