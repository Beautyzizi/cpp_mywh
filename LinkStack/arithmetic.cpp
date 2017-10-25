/*只实现了简单的四则运算..练习练习栈.做之前我还美滋滋以为可以两位数..
结果以为for(char a:hexpress),如果是两位数也会单独被压到栈中,还想解决浮点数的问题.
感觉这两个问题应该靠栈解决不了.
*/
#include<iostream>
#include<string>
#include<vector>
#include"LinkStack.h"
using namespace std;
string change(string zexpress);//中缀表达式变后缀表达式
bool opIsHigher(char a, char c)//比较操作符的优先级
{
	switch (a)
	{
	case '+':case '-':
		return (c == '*' || c == '/' ? -1 : 0);
		break;
	case '*':case '/':
		return(c == '+' || c == '-' ? 1 : 0);
	}
}
bool isOperator(char c) {
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return true;
	else
		return false;
}
string  change(string zexpress)
{
	LinkStack<char>operators, hexpress;//保存操作符和后缀表达式;
	for(char a:zexpress)
	{
		if (isdigit(a))//如果是数字进栈
		{
			hexpress.push(a);
			continue;
		}
		else if (isOperator(a))//如果是操作符
		{
			if (operators.isEmpty() || operators.top() == '(')
				operators.push(a);
			else if (a=='*'||a=='/')//无论栈底时什么运算符都不会比乘除优先
				operators.push(a);
			else //栈顶元素依次出栈并输出，并将当前符号进栈，
			{
				while (1)
				{
					hexpress.push(operators.top());//出栈..
					operators.pop();//删除..
					if (operators.isEmpty() || operators.top() == '(') //若栈空或栈顶为(
					{
						operators.push(a); break;
					}
					else if (opIsHigher(a, operators.top()) > 0) {
						operators.push(a);
						break;
					}
				}
			}
		}
		else if (a == '(')
			operators.push(a);
		else if (a == ')')
		{
			while (operators.top() != '(')//将括号中的运算符依次出栈
			{
				hexpress.push(operators.top());
				operators.pop();
			}
			operators.pop();//将)出栈
		}
		else
		{
			cout << "错误表达式." << endl;
			exit(-1);
		}
	}
	while (!operators.isEmpty()) {//栈中进入优先级相同的运算符不会出栈,所以用while出栈
		hexpress.push(operators.top());
		operators.pop();
	}
	string he;
	while (!hexpress.isEmpty())
	{
		he.push_back(hexpress.top());
		hexpress.pop();
	}
	reverse(he.begin(), he.end());
	return he;
}
int caculation(string hexpress)
{
	LinkStack<int>number;
	for (char c : hexpress)
	{
		if (isdigit(c))
		{
			number.push(c-'0');//数值0:0x00，字符'0':0x30
			cout << number.top() << endl;
		}
		else if (isOperator(c))
		{
			int a, b;
			b = number.top();
			number.pop();
			a = number.top();
			number.pop();
			int sum;
			switch (c)
			{
			case '+':sum = a + b; break;
			case '-':sum = a - b; break;
			case '*':sum = a * b; break;
			case '/':sum = a / b; break;
			}
			number.push(sum);
		}
	}
		return number.top();
}
int main()
{
	string a;
	cout << "输入要计算的值" << endl;
	cin >> a;
	a = change(a);
	cout <<"后缀表达式为:"<< a << endl;
	cout <<"结果为:"<<caculation(a)<<endl;
	system("pause");
}
