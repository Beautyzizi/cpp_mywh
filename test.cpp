#include<iostream>
#include<string>
#include"LinkStack.h"
int main()
{
	LinkStack<string> lin;
	lin.push("i'am");
	lin.push(" ");
	lin.push("cool");
	cout << "ջ��Ԫ��" << lin.top()<<endl;
	cout << "ջ�Ĵ�С" << lin.size()<<endl;
	while(!lin.isEmpty())
	{
		lin.pop();
	}
	cout << "ջ�Ĵ�С" << lin.size() << endl;
	return 0;
}
