#include <iostream>

#include "LinkedList.h"

int main(void)
{
	tLinkedList list = {};

	InitList(&list);

	PushBack(&list, 100);
	PushBack(&list, 200);
	PushBack(&list, 300);

	ReleaseList(&list);


	return 0;
}