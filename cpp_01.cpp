#include <iostream>
#include "Arr.h"

struct tMy
{

};

class CMy
{
	// 접근 제한 지정자
	// private, protected(상속), public

private:
	int m_i;
	float m_f;
public:
	void SetInt(int i) // C 방식 : SetInt(CMy* _this, int i)
	{				   //         _this->m_i = i;
		this->m_i = i;
	}
	
	// 대입 연산자
	CMy& operator = (const CMy& _Other)
	{
		// c3 = c2
		//
		this->m_i = _Other.m_i;
		this->m_f = _Other.m_f;
		return *this;
	}


public:
	// 생성자 : 객체 생성 시 자동으로 호출됨.
	// 이니셜라이져 : 객체 생성시 바로 초기화 시키는 함수
	CMy()
		: m_i(100)
		, m_f(0.f)
	{
		
	}

	// 소멸자
	~CMy()
	{

	}

};


int main(void)
{
	// C++ 클래스 특징
	// 접근제한 지정자
	// 클래스 내의 멤버변수 or 멤버함수 의 접근 허용 레벨
	
	// 생성자, 소멸자
	// 객체 생성, 소멸 시 자동으로 호출
	// 직접 만들지 않으면 기본 생성자, 기본 소멸자가 만들어짐

	// 멤버함수
	// 해당 클래스가 사용하는 전용 함수
	// 해당 클래스의 객체가 필요함
	// 멤버함수를 객체를 통해서 호출하면 해당 객체의 주소가 
	// this 포인터로 전달된다.

	{
		// 레퍼런스
		// 자료형 *변수명;		= 해당 자료형 포인터 변수
		// *포인터변수;			= 포인터로 주소를 역참조
		// &변수;				= 변수의 주소값
		// 자료형& 변수명;		= 레퍼런스 변수 선언 

		// C++에 추가된 기능
		// 포인터와 유사
		// 원본을 참조한다.
		// 참조변수를 통해서 직접적으로 원본을 수정 할 수 있다.

		int a = 10;
		
		int* const p = &a;
		*p = 100;

		int& iRef = a;
		iRef = 100;
		/*					*/	

		const int* p2 = &a;
		//*p2 = 10; 안됨
		
		const int& iReConst = a;
		//iRefConst = 10; 안됨

	}



	CMy c;
		
	c.SetInt(10);
	CMy c2;
	CMy c3;

	c3 = c2;
	
	return 0;
}