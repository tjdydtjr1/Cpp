#include <iostream>

// �����迭
#include <vector>
// ���Ḯ��Ʈ
#include <List>	

#include "CList.h"

// namespace <�̸�>
// �ߺ��Ǵ� ����, �Լ������ �����ϰ��� �̸������� ����

// std ��ü ���
using namespace std;

// Ư����ɸ� ����
using std::cin;
using std::cout;
using std::wcout;
using std::vector;
using std::list;

void MyEndL()
{
	wprintf(L"\n");
}

// IOStream ����
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

// ��������� ���� Ŭ������ ������ ������ ��� 1Byte�� �Ҵ�
CMyOstream mycout;

int main(void)
{
	CList<float> List;

	for (int i = 0; i < 4; ++i)
	{
		List.push_back(i);
	}
	
	// �ѱ� ����
	setlocale(LC_ALL, "korean");
	_wsetlocale(LC_ALL, L"korean");
	//

	mycout << L"�ȳ�" << MyEndL;

	vector<int> vecInt;
	vecInt.push_back(10);
	vecInt.push_back(20);

	vecInt[0] = 100;
	vecInt.at(0);			// �ε����� ������ ���� ���۷����� ��ȯ
	vecInt.data();			// ���� �ּҰ�
	vecInt.size();			// ���� � �� �ִ���
	vecInt.capacity();		// �ִ� ��뷮

	for (size_t i = 0; i < vecInt.size(); ++i)
	{
		cout << vecInt[i] << endl;
	}


	list<int> listInt;
	listInt.push_back(10);
	listInt.push_back(100);

	listInt.size();			// capacity�� ���� ���� ������ ���� ����


	return 0;
}