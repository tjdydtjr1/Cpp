#include <iostream>
#include "Arr.h"

struct tMy
{

};

class CMy
{
	// ���� ���� ������
	// private, protected(���), public

private:
	int m_i;
	float m_f;
public:
	void SetInt(int i) // C ��� : SetInt(CMy* _this, int i)
	{				   //         _this->m_i = i;
		this->m_i = i;
	}
	
	// ���� ������
	CMy& operator = (const CMy& _Other)
	{
		// c3 = c2
		//
		this->m_i = _Other.m_i;
		this->m_f = _Other.m_f;
		return *this;
	}


public:
	// ������ : ��ü ���� �� �ڵ����� ȣ���.
	// �̴ϼȶ����� : ��ü ������ �ٷ� �ʱ�ȭ ��Ű�� �Լ�
	CMy()
		: m_i(100)
		, m_f(0.f)
	{
		
	}

	// �Ҹ���
	~CMy()
	{

	}

};


int main(void)
{
	// C++ Ŭ���� Ư¡
	// �������� ������
	// Ŭ���� ���� ������� or ����Լ� �� ���� ��� ����
	
	// ������, �Ҹ���
	// ��ü ����, �Ҹ� �� �ڵ����� ȣ��
	// ���� ������ ������ �⺻ ������, �⺻ �Ҹ��ڰ� �������

	// ����Լ�
	// �ش� Ŭ������ ����ϴ� ���� �Լ�
	// �ش� Ŭ������ ��ü�� �ʿ���
	// ����Լ��� ��ü�� ���ؼ� ȣ���ϸ� �ش� ��ü�� �ּҰ� 
	// this �����ͷ� ���޵ȴ�.

	{
		// ���۷���
		// �ڷ��� *������;		= �ش� �ڷ��� ������ ����
		// *�����ͺ���;			= �����ͷ� �ּҸ� ������
		// &����;				= ������ �ּҰ�
		// �ڷ���& ������;		= ���۷��� ���� ���� 

		// C++�� �߰��� ���
		// �����Ϳ� ����
		// ������ �����Ѵ�.
		// ���������� ���ؼ� ���������� ������ ���� �� �� �ִ�.

		int a = 10;
		
		int* const p = &a;
		*p = 100;

		int& iRef = a;
		iRef = 100;
		/*					*/	

		const int* p2 = &a;
		//*p2 = 10; �ȵ�
		
		const int& iReConst = a;
		//iRefConst = 10; �ȵ�

	}



	CMy c;
		
	c.SetInt(10);
	CMy c2;
	CMy c3;

	c3 = c2;
	
	return 0;
}