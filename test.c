#include"seqlist.h"
#include"Contact.h"
//void SLtest()
//{
//	SL s;
//	SLInit(&s);
//	//----------------------------
//	//ǰ���
//	SLPushfront(&s,2);
//	SLPushfront(&s, 3);
//	SLPushfront(&s, 4);
//	SLPushfront(&s, 5);
//	SLPushfront(&s, 6);
//	//�����
//	SLPushback(&s, 11);
//	SLPushback(&s, 22);
//	SLPushback(&s, 33);
//	SLPushback(&s, 44);
//	SLPrint(s);
//	//ǰ���
//	SLPopfront(&s);
//	SLPopfront(&s);
//	SLPopfront(&s);
//	SLPrint(s);
//	//�����
//	SLPopback(&s);
//	SLPopback(&s);
//	SLPopback(&s);
//	SLPrint(s);
//
//	SLInsert(&s, 2, 100);
//	SLInsert(&s, 3, 1000);
//	SLPrint(s);
//
//	SLErase(&s, 2);
//	SLPrint(s);
//
//	int find  = SLFind(&s, 0);
//	if (find > 0)
//	{
//		printf("�ҵ����±�Ϊ��%d\n", find);
//	}
//	else {
//		printf("û���ҵ���\n");
//	}
//	//���ٿռ�---------------------
//	SLdestory(&s);
//}

//void SLtest1()
//{
//	Contact con;
//	ContactInit(&con);
//
//	ContactAdd(&con);
//	ContactAdd(&con);
//	ContactAdd(&con);
//
//	ContactDel(&con);
//	ContactShow(&con);
//
//	ContactModify(&con);
//	ContactShow(&con);
//
//	ContactFind(&con);
//	ContactDestroy(&con);
//}

void manu()
{
	printf("-----------------ͨѶ¼----------------\n");
	printf("------1.�����ϵ��   2.ɾ����ϵ��------\n");
	printf("------3.�޸���ϵ��   4.������ϵ��------\n");
	printf("------5.չʾ��ϵ��   0.	  �˳�---------\n");
}

int main()
{
	//SLtest();
	//SLtest1();
	int option = -1;
	Contact con;
	ContactInit(&con);
	do {
		manu();
		printf("���������ѡ��:\n");
		scanf("%d", &option);
		switch (option)
		{
		case 1:
			ContactAdd(&con);
			break;
		case 2:
			ContactDel(&con);
			break;
		case 3:
			ContactModify(&con);
			break;
		case 4:
			ContactFind(&con);
			break;
		case 5:
			ContactShow(&con);
			break;
		case 0:
			printf("���˳�....");
			break;
		default:
			printf("�����ʽ�������������룺\n");
			break;
		}
	} while (option!=0);
	ContactDestroy(&con);
	return 0;
}