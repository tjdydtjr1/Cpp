#include "Arr.h"
#include <iostream>

void InitArr(tArr* _pArr)
{
	_pArr->pInt = (int*)malloc(sizeof(int) * 2);
	_pArr->iCount = 0;
	_pArr->iMaxCount = 2;
}

// 메모리 재할당 함수
void Reallocate(tArr* _pArr)
{
	// 1. 2배 큰 공간을 동적할당
	int* pNew = (int*)malloc((_pArr->iMaxCount * 2) * sizeof(int));

	// 2. 기존 공간에 있던 데이터들을 새로 할당한 공간으로 복사
	for (int i = 0; i < _pArr->iCount; ++i)
	{
		pNew[i] = _pArr->pInt[i];
	}

	// 3. 기존 공간은 메모리 해제
	free(_pArr->pInt);

	// 4. 배열이 새로 할당된 공간을 가르키게 한다.
	_pArr->pInt = pNew;

	// 5. iMaxCount 변경점 적용
	_pArr->iMaxCount *= 2;

}


void PushBack(tArr* _pArr, int _iData)
{
	// 1. 현재 개수와 최대 개수가 같은지 확인
	if (_pArr->iMaxCount <= _pArr->iCount)
	{
		// 재할당
		Reallocate(_pArr);

	}
	// 2. 데이터 추가
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

