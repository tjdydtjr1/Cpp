#pragma once
class CArr
{
	// �ƹ��͵� ���� ������ �⺻������ private
	// ������ ��� ������
private:
	int*	m_pInt;
	int		m_iCount;
	int		m_iMaxCount;
	
public:
	void push_back(int _iData);
	void resize(int _iResizeCount);

	int& operator[](int idx);

public:
	// �����ڴ� ��ü ������ �ڵ� ȣ��ǹǷ� �����ؾ��Ѵ�.
	CArr();
	~CArr();

};

