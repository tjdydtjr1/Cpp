#include <iostream>
#include <time.h>

#include "Arr.h"
#include "LinkedList.h"

// �������� �Լ�
void BubbleSort(int* _pData, int _iCount)
{
	// �����Ͱ� 1�� ���ϸ� �������� ����
	if (_iCount <= 1)
	{
		return;
	}

	while (true)
	{
		bool bFinish = true;

		int iLoop = _iCount - 1;
		for (int i = 0; i < iLoop; ++i)
		{
			if (_pData[i] > _pData[i + 1])
			{
				int iTemp = _pData[i];
				_pData[i] = _pData[i + 1];
				_pData[i + 1] = iTemp;

				bFinish = false;
			}
		}

		if (bFinish)
		{
			break;
		}
	}
}

void Test()
{

}

int main(void)
{
	tArr s1;

	// �Լ������� ���� ����
	// callback ���� �ϰ��� ���ϸ� ȣ�����ٰ�
	// �б�˻翡 ���� �Լ� ȣ��
	void(*pFunc)(void) = nullptr;
	pFunc = Test;
	pFunc();

	InitArr(&s1);

	// ����(����)
	srand(time(nullptr));


	for (int i = 0; i < 10; ++i)
	{
		int iRand = rand() % 100 + 1;
		PushBack(&s1, iRand);
	}

	for (int i = 0; i < s1.iCount; ++i)
	{

		printf("%d\n", s1.pInt[i]);
	}

	Sort(&s1, &BubbleSort);
	printf("���� ��\n");
	for (int i = 0; i < s1.iCount; ++i)
	{

		printf("%d\n", s1.pInt[i]);
	}



	ReleaseArr(&s1);

	// ������ ����Ʈ
	// Node : �����Ϳ� ���� �ּҸ� ����


	return 0;
}