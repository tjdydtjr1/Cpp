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
	// 구조체 --> 클래스

	// 객체지향 언어 특징
	// 1. 캡슐화
	// 기능을 수행하기 위해 필요한 멤버 선언, 묶음, 은닉성
	// 멤버 함수들

	// 2. 상속

	// 3. 다형성

	// 4. 추상화

	// C++ 동적할당 new, delete

	// 구조체 버전 가변배열 --> 클래스 버전
	// 구조체 방식
	//tArr arr = {};
	//InitArr(&arr);

	//PushBack(&arr, 10);
	//PushBack(&arr, 20);
	//
	//ReleaseArr(&arr);

	//// class 방식
	//CArr carr;
	//carr.push_back(10);
	//carr.push_back(20);
	//
	//int iData = carr[1];
	//carr[1] = 100;


	// 함수 템플릿
	int i = Add<int>(10, 20);

	// 클래스 템플릿
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