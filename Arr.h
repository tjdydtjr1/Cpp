#pragma once

typedef struct _tagArr
{
	int*	pInt;
	int		iCount;
	int		iMaxCount;
}tArr;

// �����迭 �ʱ�ȭ
void InitArr(tArr* _pArr);

// ������ �߰� �Լ�
void PushBack(tArr* _pArr, int _iData);

// �޸� ����
void ReleaseArr(tArr* _pArr);

// ������ ���� �Լ�
void Sort(tArr* _pArr, void(*SortFunc)(int*, int));