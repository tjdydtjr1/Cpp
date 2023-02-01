#pragma once

typedef struct _tagArr
{
	int*	pInt;
	int		iCount;
	int		iMaxCount;
}tArr;

// 가변배열 초기화
void InitArr(tArr* _pArr);

// 데이터 추가 함수
void PushBack(tArr* _pArr, int _iData);

// 메모리 해제
void ReleaseArr(tArr* _pArr);

// 데이터 정렬 함수
void Sort(tArr* _pArr, void(*SortFunc)(int*, int));