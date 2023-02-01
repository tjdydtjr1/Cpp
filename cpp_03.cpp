#include <iostream>

#include "CList.h"



int main(void)
{
	CList<float> list;

	for (int i = 0; i < 4; ++i)
	{
		list.push_back(i);
	}

	


	return 0;
}