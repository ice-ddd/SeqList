#include"seqlist.h"
#include"Contact.h"
//void SLtest()
//{
//	SL s;
//	SLInit(&s);
//	//----------------------------
//	//前面加
//	SLPushfront(&s,2);
//	SLPushfront(&s, 3);
//	SLPushfront(&s, 4);
//	SLPushfront(&s, 5);
//	SLPushfront(&s, 6);
//	//后面加
//	SLPushback(&s, 11);
//	SLPushback(&s, 22);
//	SLPushback(&s, 33);
//	SLPushback(&s, 44);
//	SLPrint(s);
//	//前面减
//	SLPopfront(&s);
//	SLPopfront(&s);
//	SLPopfront(&s);
//	SLPrint(s);
//	//后面减
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
//		printf("找到了下标为：%d\n", find);
//	}
//	else {
//		printf("没有找到！\n");
//	}
//	//销毁空间---------------------
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
	printf("-----------------通讯录----------------\n");
	printf("------1.添加联系人   2.删除联系人------\n");
	printf("------3.修改联系人   4.查找联系人------\n");
	printf("------5.展示联系人   0.	  退出---------\n");
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
		printf("请输入你的选择:\n");
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
			printf("已退出....");
			break;
		default:
			printf("输入格式错误，请重新输入：\n");
			break;
		}
	} while (option!=0);
	ContactDestroy(&con);
	return 0;
}