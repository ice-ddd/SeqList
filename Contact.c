#include"Contact.h"
#include"seqlist.h"
//ͨѶ¼�ĳ�ʼ��
void ContactInit(Contact* con)
{
	//ʵ����Ҫ���е���˳���ĳ�ʼ��
	SLInit(con);
}
//ͨѶ¼������
void ContactDestroy(Contact* con)
{
	SLdestory(con);
}

//ͨѶ¼�������
void ContactAdd(Contact* con)
{
	assert(con);
	SLcheckspace(&con);
	Sldatatype s;
	printf("��������Ҫ��ӵ�����\n");
	scanf("%s", s.name);
	printf("��������Ҫ��ӵ��Ա�\n");
	scanf("%s", s.gender);
	printf("��������Ҫ��ӵ�����\n");
	scanf("%d", &s.age);
	printf("��������Ҫ��ӵĵ绰\n");
	scanf("%s", s.tel);
	printf("��������Ҫ��ӵĵ�ַ\n");
	scanf("%s", s.addr);
	SLPushback(con, s);
}
//�ж�Ԫ���Ƿ���� ---������Ϊ��λ��ѯ
int FindByName(Contact* con, char* str)
{
	assert(con);
	for (int i = 0; i < con->size; i++)
	{
		if (strcmp(con->arr[i].name, str) == 0)
		{
			return i;
		}
	}
	return -1;
}
//ɾ������
void ContactDel(Contact* con)
{
	char name[NAME_MAX];
	//ɾ��Ԫ����Ҫ�ȼ���Ƿ���ڸ�Ԫ��
	printf("������Ҫɾ��������\n");
	scanf("%s",name);
	int find = FindByName(con, name);
	if (find >= 0)
	{
		SLErase(con, find);
		printf("ɾ���ɹ���\n");
	}
	else {
		printf("Ҫɾ������ϵ�˲����ڣ�\n");
	}
}
//չʾ����
// ����    �Ա�    ����    �绰    ��ַ
// zhang    nan     19      123     999
// yuan     nv      20      555     666
void ContactShow(Contact* con)
{
	printf("%s	  %s	  %s	  %s     %s\n", "����", "�Ա�", "����", "�绰", "��ַ");
	for (int i = 0; i < con->size; i++)
	{
		printf("%s\t  %s\t   %d\t    %s\t    %s\t\n", con->arr[i].name, 
			con->arr[i].gender, 
			con->arr[i].age, 
			con->arr[i].tel, 
			con->arr[i].addr);
	}printf("\n");
}
//�޸�����
void ContactModify(Contact* con)
{
	char name[NAME_MAX];
	printf("��������Ҫ�޸ĵ��û�����:\n");
	scanf("%s", name);
	//Ҳ��Ҫ�Ȳ�ѯ�����Ƿ�����ٽ����޸�
	int find = FindByName(con, name);
	if (find < 0)
	{
		printf("Ҫ�޸ĵ���ϵ�˲����ڣ�\n");
		return;
	}
	printf("�������µ�����:\n");
	scanf("%s", con->arr[find].name);

	printf("�������µ��Ա�:\n");
	scanf("%s", con->arr[find].gender);

	printf("�������µ�����:\n");
	scanf("%d", &con->arr[find].age);

	printf("�������µĵ绰:\n");
	scanf("%s", con->arr[find].tel);

	printf("�������µ�סַ:\n");
	scanf("%s", con->arr[find].addr);
}
//��ѯ����
void ContactFind(Contact* con)
{
	//���ж��Ƿ����
	char name[NAME_MAX];
	printf("��������Ҫ��ѯ���û�����:\n");
	scanf("%s", name);
	int find = FindByName(con, name);
	if (find < 0)
	{
		printf("Ҫ��ѯ����ϵ�˲����ڣ�\n");
		return;
	}
	printf("������%s,�Ա�%s,���䣺%d,�绰��%s,סַ��%s\n", con->arr[find].name,
		con->arr[find].gender,
		con->arr[find].age,
		con->arr[find].tel,
		con->arr[find].addr);
}
