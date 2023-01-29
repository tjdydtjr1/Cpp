#include <iostream>
#include "LinkedList.h"

void InitList(tLinkedList* _pList)
{
	_pList->pHeadNode = nullptr;
	_pList->iCount = 0;
}

void PushBack(tLinkedList* _pList, int _iData)
{
	// 데이터를 저장할 노드 생성
	// 데이터 복사
	tNode* pNode = (tNode*)malloc(sizeof(tNode));

	pNode->iData = _iData;
	pNode->pNextNode = nullptr;

	// 추가한 데이터가 처음인지 아닌지 체크
	if (nullptr == _pList->pHeadNode)
	{
		_pList->pHeadNode = pNode;
	}
	else
	{
		// 현재 가장 마지막 노드
		// 해당 노드의 pNext를 생성시간 노드의 주소로 채움
		tNode* pCurFinalNode = _pList->pHeadNode;;
		while (pCurFinalNode->pNextNode)
		{
			pCurFinalNode->pNextNode = pNode;
		}

		pCurFinalNode->pNextNode = pNode;

	}
	++_pList->iCount;

}

void Release(tNode* _pNode)
{
	if (nullptr == _pNode)
	{
		return;
	}

	Release(_pNode->pNextNode);
	free(_pNode);
}

void ReleaseList(tLinkedList* _pList)
{
	// 재귀함수 방식의 메모리 해제
	//Release(_pList->pHeadNode);

	// while 반복문을 이용한 메모리 해제
	tNode* pDeletNode = _pList->pHeadNode;

	while (pDeletNode)
	{
		tNode* pNext = pDeletNode->pNextNode;
		free(pDeletNode);
		pDeletNode = pNext;
	}
}

void PushFront(tLinkedList* _pList, int _iData)
{
	// 새로 생성시킨 노드의 다음을 기존의 헤드로 지정한다.
	tNode* pNewNode = (tNode*)malloc(sizeof(tNode));
	pNewNode->iData = _iData;
	pNewNode->pNextNode = _pList->pHeadNode;

	// 리스트의 헤드노드 포인터를 갱신한다.
	_pList->pHeadNode = pNewNode;

	// 데이터 카운터 증가
	++_pList->iCount;

}
