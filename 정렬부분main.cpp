#include <iostream>
#include <time.h>

#include "Arr.h"
#include "LinkedList.h"

// 버블정렬 함수
void BubbleSort(int* _pData, int _iCount)
{
	// 데이터가 1개 이하면 졍렬하지 않음
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

	// 함수포인터 변수 선언
	// callback 내가 하고나서 원하면 호출해줄게
	// 분기검사에 따른 함수 호출
	void(*pFunc)(void) = nullptr;
	pFunc = Test;
	pFunc();

	InitArr(&s1);

	// 난수(랜덤)
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
	printf("정렬 후\n");
	for (int i = 0; i < s1.iCount; ++i)
	{

		printf("%d\n", s1.pInt[i]);
	}



	ReleaseArr(&s1);

	// 연결형 리스트
	// Node : 데이터와 다음 주소를 가짐


	return 0;
}