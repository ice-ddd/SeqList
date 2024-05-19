#pragma once

#define NAME_MAX 20
#define GENDER_MAX 10
#define TEL_MAX 20
#define ADDR_MAX 50

//Contact �ṹ���д���� �ṹ��peoInfo ������size ������space��
//����ͷ�ļ����ܻ������ so��seqlist.h��������ļ��Ժ�  ����ļ������Ҫ��seqlist ֻ�ܽ���������ʹ��

typedef struct personInfo
{
	char name[NAME_MAX];
	char gender[GENDER_MAX];
	int age;
	char tel[TEL_MAX];
	char addr[ADDR_MAX];
}peoInfo;

//��˳���ĸ����� ��ͨѶ¼  
//ע��Ҫʹ��ͨѶ¼�ķ��� ������Ϊ���ܻ������ͷ�ļ� ����Ҫ����������������ʹ��
typedef struct seqlist Contact;

//ͨѶ¼��صķ���

//ͨѶ¼�ĳ�ʼ��
void ContactInit(Contact* con);
//ͨѶ¼������
void ContactDestroy(Contact* con);
//ͨѶ¼�������
void ContactAdd(Contact* con);
//ͨѶ¼ɾ������
void ContactDel(Contact* con);
//ͨѶ¼���޸�
void ContactModify(Contact* con);
//ͨѶ¼����
void ContactFind(Contact* con);
//չʾͨѶ¼����
void ContactShow(Contact* con);
