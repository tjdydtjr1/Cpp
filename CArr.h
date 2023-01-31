#pragma once
#include <assert.h>

// 템플릿은 헤더에 만들어져 있어야함.
// 타입을 정해준 함수가 생성되어야 하기 때문
template<typename T>
class CArr
{
	// 아무것도 적지 않으면 기본적으로 private
	// 하지만 명시 해주자
private:
	T*		m_pData;
	int		m_iCount;
	int		m_iMaxCount;
	
public:
	void push_back(const T& _iData);
	void resize(int _iResizeCount);

	T& operator[](int idx);

public:
	// 생성자는 객체 생성시 자동 호출되므로 공개해야한다.
	CArr();
	~CArr();

};


template<typename T>
CArr<T>::CArr()
	: m_pData(nullptr)	// 이니셜라이즈 함수 메모리 순서대로 초기화 하자
	, m_iCount(0)
	, m_iMaxCount(2)
{
	m_pData = new T[2];	// C++ 동적할당 키워드 new

}
template<typename T>
CArr<T>::~CArr()
{
	delete[] m_pData;		// 동적할당 지울때 사용
	// 여러개 일경우 delete[] 배열형태
}
template<typename T>
void CArr<T>::push_back(const T& _iData)
{

	// 1. 현재 개수와 최대 개수가 같은지 확인
	if (m_iMaxCount <= m_iCount)
	{
		// 재할당
		resize(m_iMaxCount * 2);

	}
	// 2. 데이터 추가
	m_pData[m_iCount++] = _iData;
}
template<typename T>
void CArr<T>::resize(int _iResizeCount)
{
	// 현재 최대 수용량 보다 더 적은 수치로 확장하려는 경우
	if (m_iMaxCount >= _iResizeCount)
	{
		printf("TEST\n");
	}

	// 1. resize 시킬 개수만큼 동적할당 한다.
	T* pNew = new T[_iResizeCount];

	// 2. 기존 공간에 있던 데이터들을 새로 할당한 공간으로 복사
	for (int i = 0; i < m_iCount; ++i)
	{
		pNew[i] = m_pData[i];
	}

	// 3. 기존 공간은 메모리 해제
	delete[] m_pData;

	// 4. 배열이 새로 할당된 공간을 가르키게 한다.
	m_pData = pNew;

	// 5. iMaxCount 변경점 적용
	m_iMaxCount = _iResizeCount;
}

template<typename T>
T& CArr<T>::operator[](int idx)
{
	return m_pData[idx];
}
