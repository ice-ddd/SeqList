#include"seqlist.h"

//初始化空间
void SLInit(SL* ps)
{
	ps->arr = NULL;
	ps->size = ps->space = 0;
}
//释放空间 而非销毁 只是不再使用这片空间
void SLdestory(SL* ps)
{
	if (ps->arr)
	{
		free(ps->arr);
	}
	/*ps->arr = NULL;
	ps->space = ps->size = 0;*/
	SLInit(ps);
}
////打印数组
//void SLPrint(SL s)
//{
//	for (int i = 0; i < s.size; i++)
//	{
//		printf("%d ", s.arr[i]);
//	}
//	printf("\n");
//}
//判断空间是否够用 够用则添加元素 否则将元素翻倍
void SLcheckspace(SL* ps)
{
	if (ps->size == ps->space)
	{
		int Newspace = ps->space == 0 ? 4 : ps->space * 2 ;
		Sldatatype* temp = (Sldatatype*)realloc(ps->arr, Newspace * sizeof(Sldatatype));
		if (temp == NULL)
		{
			perror("realloc error!");
			exit(1);
		}
		//空间申请成功
		ps->arr = temp;
		ps->space = Newspace;
	}
}
//开头添加
void SLPushfront(SL* ps,Sldatatype x) 
{
	assert(ps);
	SLcheckspace(ps);

	for (int i = ps->size; i > 0; i--)
	{
		ps->arr[i] = ps->arr[i - 1];
	}
	ps->arr[0] = x;
	ps->size++;
}
//结尾添加
void SLPushback(SL* ps, Sldatatype x)
{
	assert(ps);
	SLcheckspace(ps);

	ps->arr[ps->size] = x;
	ps->size++;
}
void SLPopfront(SL* ps) 
{
	assert(ps);
	for (int i = 0; i < ps->size; i++)
	{
		ps->arr[i] = ps->arr[i + 1];
	}
	ps->size--;
}
void SLPopback(SL* ps)
{
	assert(ps);
	ps->size--;
}
//插入指定数据
void SLInsert(SL* ps, int pos, Sldatatype x)
{
	assert(ps);
	assert(pos >= 0 && pos <= ps->size);
	SLcheckspace(ps);
	for (int i = ps->size; i > pos; i--)
	{
		ps->arr[i] = ps->arr[i - 1];
	}
	ps->arr[pos] = x;
	ps->size++;
}
//删除指定数据
void SLErase(SL* ps, int pos)
{
	assert(ps);
	assert(pos >= 0 && pos <= ps->size);
	SLcheckspace(ps);
	for (int i = pos; i < ps->size - 1; i++)
	{
		ps->arr[i] = ps->arr[i + 1];
	}
	ps->size--;
}
//Sldatatype SLFind(SL* ps, Sldatatype x)
//{
//	assert(ps);
//	for (int i = 0; i < ps->size; i++)
//	{
//		if (x == ps->arr[i])
//		{
//			return i;
//		}
//	}
//	return -1;
//}