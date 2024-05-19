#include"seqlist.h"

//��ʼ���ռ�
void SLInit(SL* ps)
{
	ps->arr = NULL;
	ps->size = ps->space = 0;
}
//�ͷſռ� �������� ֻ�ǲ���ʹ����Ƭ�ռ�
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
////��ӡ����
//void SLPrint(SL s)
//{
//	for (int i = 0; i < s.size; i++)
//	{
//		printf("%d ", s.arr[i]);
//	}
//	printf("\n");
//}
//�жϿռ��Ƿ��� ���������Ԫ�� ����Ԫ�ط���
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
		//�ռ�����ɹ�
		ps->arr = temp;
		ps->space = Newspace;
	}
}
//��ͷ���
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
//��β���
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
//����ָ������
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
//ɾ��ָ������
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