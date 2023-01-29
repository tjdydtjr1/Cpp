#include <iostream>
#include "LinkedList.h"

void InitList(tLinkedList* _pList)
{
	_pList->pHeadNode = nullptr;
	_pList->iCount = 0;
}

void PushBack(tLinkedList* _pList, int _iData)
{
	// �����͸� ������ ��� ����
	// ������ ����
	tNode* pNode = (tNode*)malloc(sizeof(tNode));

	pNode->iData = _iData;
	pNode->pNextNode = nullptr;

	// �߰��� �����Ͱ� ó������ �ƴ��� üũ
	if (nullptr == _pList->pHeadNode)
	{
		_pList->pHeadNode = pNode;
	}
	else
	{
		// ���� ���� ������ ���
		// �ش� ����� pNext�� �����ð� ����� �ּҷ� ä��
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
	// ����Լ� ����� �޸� ����
	//Release(_pList->pHeadNode);

	// while �ݺ����� �̿��� �޸� ����
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
	// ���� ������Ų ����� ������ ������ ���� �����Ѵ�.
	tNode* pNewNode = (tNode*)malloc(sizeof(tNode));
	pNewNode->iData = _iData;
	pNewNode->pNextNode = _pList->pHeadNode;

	// ����Ʈ�� ����� �����͸� �����Ѵ�.
	_pList->pHeadNode = pNewNode;

	// ������ ī���� ����
	++_pList->iCount;

}
