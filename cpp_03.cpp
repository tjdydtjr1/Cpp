#include <iostream>

#include "CList.h"

int main(void)
{
	CList<float> list;

	for (int i = 0; i < 4; ++i)
	{
		list.push_back(i);
	}

	std::cout << "test" << 3.14f << std::endl;
	int i = 0;
	std::cin >> i;

	return 0;
}