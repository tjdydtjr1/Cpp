#pragma once
class CArr
{
	// 아무것도 적지 않으면 기본적으로 private
	// 하지만 명시 해주자
private:
	int*	m_pInt;
	int		m_iCount;
	int		m_iMaxCount;
	
public:
	void push_back(int _iData);
	void resize(int _iResizeCount);

	int& operator[](int idx);

public:
	// 생성자는 객체 생성시 자동 호출되므로 공개해야한다.
	CArr();
	~CArr();

};

