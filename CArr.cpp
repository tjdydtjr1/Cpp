#include "CArr.h"
#include <assert.h>


CArr::CArr()
	: m_pInt(nullptr)	// �̴ϼȶ����� �Լ� �޸� ������� �ʱ�ȭ ����
	, m_iCount(0)
	, m_iMaxCount(0)
{
	m_pInt = new int[2];	// C++ �����Ҵ� Ű���� new
	
}

CArr::~CArr()
{
	delete[] m_pInt;		// �����Ҵ� ���ﶧ ���
							// ������ �ϰ�� delete[] �迭����
}

void CArr::push_back(int _iData)
{

	// 1. ���� ������ �ִ� ������ ������ Ȯ��
	if (m_iMaxCount <= m_iCount)
	{
		// ���Ҵ�
		resize(m_iMaxCount * 2);

	}
	// 2. ������ �߰�
	m_pInt[m_iCount++] = _iData;
}

void CArr::resize(int _iResizeCount)
{
	// ���� �ִ� ���뷮 ���� �� ���� ��ġ�� Ȯ���Ϸ��� ���
	if (m_iMaxCount <= _iResizeCount)
	{
		assert(nullptr);
	}

	// 1. resize ��ų ������ŭ �����Ҵ� �Ѵ�.
	int* pNew = new int[_iResizeCount];

	// 2. ���� ������ �ִ� �����͵��� ���� �Ҵ��� �������� ����
	for (int i = 0; i < m_iCount; ++i)
	{
		pNew[i] = m_pInt[i];
	}

	// 3. ���� ������ �޸� ����
	delete m_pInt;

	// 4. �迭�� ���� �Ҵ�� ������ ����Ű�� �Ѵ�.
	m_pInt = pNew;

	// 5. iMaxCount ������ ����
	m_iMaxCount = _iResizeCount;
}

int& CArr::operator[](int idx)
{
	return m_pInt[idx];
}
