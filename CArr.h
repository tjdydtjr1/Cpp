#pragma once
#include <assert.h>

// ���ø��� ����� ������� �־����.
// Ÿ���� ������ �Լ��� �����Ǿ�� �ϱ� ����
template<typename T>
class CArr
{
	// �ƹ��͵� ���� ������ �⺻������ private
	// ������ ��� ������
private:
	T*		m_pData;
	int		m_iCount;
	int		m_iMaxCount;
	
public:
	void push_back(const T& _iData);
	void resize(int _iResizeCount);

	T& operator[](int idx);

public:
	// �����ڴ� ��ü ������ �ڵ� ȣ��ǹǷ� �����ؾ��Ѵ�.
	CArr();
	~CArr();

};


template<typename T>
CArr<T>::CArr()
	: m_pData(nullptr)	// �̴ϼȶ����� �Լ� �޸� ������� �ʱ�ȭ ����
	, m_iCount(0)
	, m_iMaxCount(2)
{
	m_pData = new T[2];	// C++ �����Ҵ� Ű���� new

}
template<typename T>
CArr<T>::~CArr()
{
	delete[] m_pData;		// �����Ҵ� ���ﶧ ���
	// ������ �ϰ�� delete[] �迭����
}
template<typename T>
void CArr<T>::push_back(const T& _iData)
{

	// 1. ���� ������ �ִ� ������ ������ Ȯ��
	if (m_iMaxCount <= m_iCount)
	{
		// ���Ҵ�
		resize(m_iMaxCount * 2);

	}
	// 2. ������ �߰�
	m_pData[m_iCount++] = _iData;
}
template<typename T>
void CArr<T>::resize(int _iResizeCount)
{
	// ���� �ִ� ���뷮 ���� �� ���� ��ġ�� Ȯ���Ϸ��� ���
	if (m_iMaxCount >= _iResizeCount)
	{
		printf("TEST\n");
	}

	// 1. resize ��ų ������ŭ �����Ҵ� �Ѵ�.
	T* pNew = new T[_iResizeCount];

	// 2. ���� ������ �ִ� �����͵��� ���� �Ҵ��� �������� ����
	for (int i = 0; i < m_iCount; ++i)
	{
		pNew[i] = m_pData[i];
	}

	// 3. ���� ������ �޸� ����
	delete[] m_pData;

	// 4. �迭�� ���� �Ҵ�� ������ ����Ű�� �Ѵ�.
	m_pData = pNew;

	// 5. iMaxCount ������ ����
	m_iMaxCount = _iResizeCount;
}

template<typename T>
T& CArr<T>::operator[](int idx)
{
	return m_pData[idx];
}
