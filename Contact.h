#pragma once

#define NAME_MAX 20
#define GENDER_MAX 10
#define TEL_MAX 20
#define ADDR_MAX 50

//Contact 结构体中存的是 结构体peoInfo ，整形size ，整形space；
//由于头文件不能互相包含 so在seqlist.h包含这个文件以后  这个文件如果想要用seqlist 只能将它重命名使用

typedef struct personInfo
{
	char name[NAME_MAX];
	char gender[GENDER_MAX];
	int age;
	char tel[TEL_MAX];
	char addr[ADDR_MAX];
}peoInfo;

//给顺序表改个名字 叫通讯录  
//注意要使用通讯录的方法 而又因为不能互相包含头文件 所以要给他重新命名才能使用
typedef struct seqlist Contact;

//通讯录相关的方法

//通讯录的初始化
void ContactInit(Contact* con);
//通讯录的销毁
void ContactDestroy(Contact* con);
//通讯录添加数据
void ContactAdd(Contact* con);
//通讯录删除数据
void ContactDel(Contact* con);
//通讯录的修改
void ContactModify(Contact* con);
//通讯录查找
void ContactFind(Contact* con);
//展示通讯录数据
void ContactShow(Contact* con);
