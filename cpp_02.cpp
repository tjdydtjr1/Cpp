#include <iostream>

#include "Arr.h"
#include "CArr.h"

int Add(int a, int b)
{
	return a + b;
}

float Add(float f, float f1)
{
	return f + f1;
}

template<typename T>
T Add(T a, T b)
{
	return a + b;
}


int main(void)
{
	// ����ü --> Ŭ����

	// ��ü���� ��� Ư¡
	// 1. ĸ��ȭ
	// ����� �����ϱ� ���� �ʿ��� ��� ����, ����, ���м�
	// ��� �Լ���

	// 2. ���

	// 3. ������

	// 4. �߻�ȭ

	// C++ �����Ҵ� new, delete

	// ����ü ���� �����迭 --> Ŭ���� ����
	// ����ü ���
	//tArr arr = {};
	//InitArr(&arr);

	//PushBack(&arr, 10);
	//PushBack(&arr, 20);
	//
	//ReleaseArr(&arr);

	//// class ���
	//CArr carr;
	//carr.push_back(10);
	//carr.push_back(20);
	//
	//int iData = carr[1];
	//carr[1] = 100;


	// �Լ� ���ø�
	int i = Add<int>(10, 20);

	// Ŭ���� ���ø�
	CArr<int> carr;
	carr.push_back(10);
	carr.push_back(20);
	carr.push_back(30);

	int iData = carr[1];

	CArr<float> carr2;
	carr2.push_back(3.14f);
	carr2.push_back(5.14f);
	carr2.push_back(7.14f);

	float fData = carr2[1];

	return 0;
}