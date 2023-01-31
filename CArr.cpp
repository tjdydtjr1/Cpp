// 템플릿 방식으로 하면 헤더에 모두 작성해야 한다.
//#include "CArr.h"
//#include <assert.h>
//
//
//CArr::CArr()
//	: m_pData(nullptr)	// 이니셜라이즈 함수 메모리 순서대로 초기화 하자
//	, m_iCount(0)
//	, m_iMaxCount(0)
//{
//	m_pData = new int[2];	// C++ 동적할당 키워드 new
//
//}
//
//CArr::~CArr()
//{
//	delete[] m_pData;		// 동적할당 지울때 사용
//	// 여러개 일경우 delete[] 배열형태
//}
//
//void CArr::push_back(int _iData)
//{
//
//	// 1. 현재 개수와 최대 개수가 같은지 확인
//	if (m_iMaxCount <= m_iCount)
//	{
//		// 재할당
//		resize(m_iMaxCount * 2);
//
//	}
//	// 2. 데이터 추가
//	m_pData[m_iCount++] = _iData;
//}
//
//void CArr::resize(int _iResizeCount)
//{
//	// 현재 최대 수용량 보다 더 적은 수치로 확장하려는 경우
//	if (m_iMaxCount >= _iResizeCount)
//	{
//		assert(nullptr);
//	}
//
//	// 1. resize 시킬 개수만큼 동적할당 한다.
//	int* pNew = new int[_iResizeCount];
//
//	// 2. 기존 공간에 있던 데이터들을 새로 할당한 공간으로 복사
//	for (int i = 0; i < m_iCount; ++i)
//	{
//		pNew[i] = m_pData[i];
//	}
//
//	// 3. 기존 공간은 메모리 해제
//	delete[] m_pData;
//
//	// 4. 배열이 새로 할당된 공간을 가르키게 한다.
//	m_pData = pNew;
//
//	// 5. iMaxCount 변경점 적용
//	m_iMaxCount = _iResizeCount;
//}
//
//int& CArr::operator[](int idx)
//{
//	return m_pData[idx];
//}
