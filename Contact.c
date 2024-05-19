#include"Contact.h"
#include"seqlist.h"
//通讯录的初始化
void ContactInit(Contact* con)
{
	//实际上要进行的是顺序表的初始化
	SLInit(con);
}
//通讯录的销毁
void ContactDestroy(Contact* con)
{
	SLdestory(con);
}

//通讯录添加数据
void ContactAdd(Contact* con)
{
	assert(con);
	SLcheckspace(&con);
	Sldatatype s;
	printf("请输入你要添加的名字\n");
	scanf("%s", s.name);
	printf("请输入你要添加的性别\n");
	scanf("%s", s.gender);
	printf("请输入你要添加的年龄\n");
	scanf("%d", &s.age);
	printf("请输入你要添加的电话\n");
	scanf("%s", s.tel);
	printf("请输入你要添加的地址\n");
	scanf("%s", s.addr);
	SLPushback(con, s);
}
//判断元素是否存在 ---以名字为单位查询
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
//删除数据
void ContactDel(Contact* con)
{
	char name[NAME_MAX];
	//删除元素需要先检查是否存在该元素
	printf("请输入要删除的数据\n");
	scanf("%s",name);
	int find = FindByName(con, name);
	if (find >= 0)
	{
		SLErase(con, find);
		printf("删除成功！\n");
	}
	else {
		printf("要删除的联系人不存在！\n");
	}
}
//展示数据
// 名字    性别    年龄    电话    地址
// zhang    nan     19      123     999
// yuan     nv      20      555     666
void ContactShow(Contact* con)
{
	printf("%s	  %s	  %s	  %s     %s\n", "名字", "性别", "年龄", "电话", "地址");
	for (int i = 0; i < con->size; i++)
	{
		printf("%s\t  %s\t   %d\t    %s\t    %s\t\n", con->arr[i].name, 
			con->arr[i].gender, 
			con->arr[i].age, 
			con->arr[i].tel, 
			con->arr[i].addr);
	}printf("\n");
}
//修改数据
void ContactModify(Contact* con)
{
	char name[NAME_MAX];
	printf("请输入想要修改的用户姓名:\n");
	scanf("%s", name);
	//也需要先查询数据是否存在再进行修改
	int find = FindByName(con, name);
	if (find < 0)
	{
		printf("要修改的联系人不存在！\n");
		return;
	}
	printf("请输入新的姓名:\n");
	scanf("%s", con->arr[find].name);

	printf("请输入新的性别:\n");
	scanf("%s", con->arr[find].gender);

	printf("请输入新的年龄:\n");
	scanf("%d", &con->arr[find].age);

	printf("请输入新的电话:\n");
	scanf("%s", con->arr[find].tel);

	printf("请输入新的住址:\n");
	scanf("%s", con->arr[find].addr);
}
//查询数据
void ContactFind(Contact* con)
{
	//先判断是否存在
	char name[NAME_MAX];
	printf("请输入想要查询的用户姓名:\n");
	scanf("%s", name);
	int find = FindByName(con, name);
	if (find < 0)
	{
		printf("要查询的联系人不存在！\n");
		return;
	}
	printf("姓名：%s,性别：%s,年龄：%d,电话：%s,住址：%s\n", con->arr[find].name,
		con->arr[find].gender,
		con->arr[find].age,
		con->arr[find].tel,
		con->arr[find].addr);
}
