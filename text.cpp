#include<iostream>
#include<string>
#include"LinkStack.h"
int main()
{
	LinkStack<string> lin;
	lin.push("i'am");
	lin.push(" ");
	lin.push("cool");
	cout << "栈顶元素" << lin.top()<<endl;
	cout << "栈的大小" << lin.size()<<endl;
	while(!lin.isEmpty())
	{
		lin.pop();
	}
	cout << "栈的大小" << lin.size() << endl;
	return 0;
}
