#include<iostream>
#include<string>
#include"LinkQueue.h"
using namespace std;
int main()
{
	LinkQueue<string> lin;
	lin.push("wo");
	lin.push(" ");
	lin.push("hen");
	lin.push("cool");
	cout << "���еĴ�С��:" << lin.size();
	while (!lin.isEmpty())
	{
		cout << lin.front() << endl;
		lin.pop();
	}
	return 0;
}