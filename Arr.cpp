#include "Arr.h"
#include <iostream>

void InitArr(tArr* _pArr)
{
	_pArr->pInt = (int*)malloc(sizeof(int) * 2);
	_pArr->iCount = 0;
	_pArr->iMaxCount = 2;
}

// �޸� ���Ҵ� �Լ�
void Reallocate(tArr* _pArr)
{
	// 1. 2�� ū ������ �����Ҵ�
	int* pNew = (int*)malloc((_pArr->iMaxCount * 2) * sizeof(int));

	// 2. ���� ������ �ִ� �����͵��� ���� �Ҵ��� �������� ����
	for (int i = 0; i < _pArr->iCount; ++i)
	{
		pNew[i] = _pArr->pInt[i];
	}

	// 3. ���� ������ �޸� ����
	free(_pArr->pInt);

	// 4. �迭�� ���� �Ҵ�� ������ ����Ű�� �Ѵ�.
	_pArr->pInt = pNew;

	// 5. iMaxCount ������ ����
	_pArr->iMaxCount *= 2;

}


void PushBack(tArr* _pArr, int _iData)
{
	// 1. ���� ������ �ִ� ������ ������ Ȯ��
	if (_pArr->iMaxCount <= _pArr->iCount)
	{
		// ���Ҵ�
		Reallocate(_pArr);

	}
	// 2. ������ �߰�
	_pArr->pInt[_pArr->iCount++] = _iData;

}


void ReleaseArr(tArr* _pArr)
{
	free(_pArr->pInt);
	_pArr->iCount = 0;
	_pArr->iMaxCount = 0;
}

void Sort(tArr* _pArr, void(*SortFunc)(int*, int))
{
	SortFunc(_pArr->pInt, _pArr->iCount);
}

