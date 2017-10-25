#include<iostream>
#include<string>
#include<vector>
#include"LinkStack.h"
using namespace std;
string change(string zexpress);//��׺���ʽ���׺���ʽ
bool opIsHigher(char a, char c)//�Ƚϲ����������ȼ�  ��������д������
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
	LinkStack<char>operators, hexpress;//����������ͺ�׺���ʽ;
	for(char a:zexpress)
	{
		if (isdigit(a))//��������ֽ�ջ
		{
			hexpress.push(a);
			continue;
		}
		else if (isOperator(a))//����ǲ�����
		{
			if (operators.isEmpty() || operators.top() == '(')
				operators.push(a);
			else if (a=='*'||a=='/')//����ջ��ʱʲô�����������ȳ˳�����
				operators.push(a);
			else //ջ��Ԫ�����γ�ջ�������������ǰ���Ž�ջ��
			{
				while (1)
				{
					hexpress.push(operators.top());//��ջ..
					operators.pop();//ɾ��..
					if (operators.isEmpty() || operators.top() == '(') //��ջ�ջ�ջ��Ϊ(
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
			while (operators.top() != '(')//�������е���������γ�ջ
			{
				hexpress.push(operators.top());
				operators.pop();
			}
			operators.pop();//��)��ջ
		}
		else
		{
			cout << "������ʽ." << endl;
			exit(-1);
		}
	}
	while (!operators.isEmpty()) {//ջ�н������ȼ���ͬ������������ջ,������while��ջ
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
			number.push(c-'0');//��ֵ0:0x00���ַ�'0':0x30
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
	cout << "����Ҫ�����ֵ" << endl;
	cin >> a;
	a = change(a);
	cout <<"��׺���ʽΪ:"<< a << endl;
	cout <<"���Ϊ:"<<caculation(a)<<endl;
	system("pause");
}