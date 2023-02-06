#include <iostream>

// 가변배열
#include <vector>
// 연결리스트
#include <List>	

#include "CList.h"

// namespace <이름>
// 중복되는 변수, 함수명등을 예방하고자 이름공간을 만듦

// std 전체 사용
using namespace std;

// 특정기능만 해제
using std::cin;
using std::cout;
using std::wcout;
using std::vector;
using std::list;

void MyEndL()
{
	wprintf(L"\n");
}

// IOStream 구현
class CMyOstream
{
public:
	// std::cout
	CMyOstream& operator << (int _idata)
	{
		printf("%d", _idata);
		return *this;
	}
	// std::cout
	CMyOstream& operator << (const wchar_t* _pString)
	{
		wprintf(L"%s", _pString);
		return *this;
	}
	// std::endl
	CMyOstream& operator << (void(*_pFunc)(void))
	{
		_pFunc();
		return *this;
	}

	// std::cin
	CMyOstream& operator >> (int& _idata)
	{
		scanf_s("%d", &_idata);
		return *this;
	}
};

// 멤버변수가 없는 클래스의 변수를 선언할 경우 1Byte가 할당
CMyOstream mycout;

int main(void)
{
	CList<float> List;

	for (int i = 0; i < 4; ++i)
	{
		List.push_back(i);
	}
	
	// 한글 설정
	setlocale(LC_ALL, "korean");
	_wsetlocale(LC_ALL, L"korean");
	//

	mycout << L"안녕" << MyEndL;

	vector<int> vecInt;
	vecInt.push_back(10);
	vecInt.push_back(20);

	vecInt[0] = 100;
	vecInt.at(0);			// 인덱스로 접근해 값을 레퍼런스로 반환
	vecInt.data();			// 시작 주소값
	vecInt.size();			// 지금 몇개 들어가 있는지
	vecInt.capacity();		// 최대 허용량

	for (size_t i = 0; i < vecInt.size(); ++i)
	{
		cout << vecInt[i] << endl;
	}


	list<int> listInt;
	listInt.push_back(10);
	listInt.push_back(100);

	listInt.size();			// capacity는 없음 넣을 때마다 공간 생성


	return 0;
}