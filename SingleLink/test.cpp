#include<iostream>
#include"SingleLink.h"
using namespace std;
int main()
{
	SingleLink<int> lin;
	if (lin.isEmpty())
		cout << "ÊÇ¿ÕÁ´±í" << endl;
	for (int i = 0; i < 10; i++)
		lin.Insert_1(i, i);

	lin.Delect(5);
	lin.Insert(6, 90);
	auto ptr = lin.Find(0);
	while (ptr != nullptr)
	{
		cout << ptr->value << endl;
		ptr = ptr->next;
	}
}