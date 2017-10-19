#include <string>    
#include <iostream>
using namespace std;
template <typename T>
struct Node
{
	Node(T t) :value(t), next(nullptr) {};
	Node() :next(nullptr) {};
	T value;//栈中元素的值
	Node<T>* next;//链表节点指针
};
template <typename T>
class LinkStack {
public:
	LinkStack() :count(0), phead(new Node<T>()) {};
	~LinkStack();
	int size();
	void pop();
	void push(T t);
	T top();
	bool isEmpty();
private:
	Node<T> *phead;//栈的头指针
	int count=0;
};
template <typename T>
LinkStack<T>::~LinkStack()
{
	while (phead->next != nullptr)
	{
		Node<T>*pnode = phead->next;
		phead->next = phead->next;
		delete pnode;
	}
	phead = nullptr;
};
template <typename T>
bool LinkStack<T>::isEmpty()
{
	return count == 0;
}
template <typename T>
int LinkStack<T>::size()
{
	return count;
}
template<typename T>
void LinkStack<T>::push(T t)
{
	Node <T> *pnode = new  Node<T>(t);
	pnode->next = phead->next;
	phead->next = pnode;
	count++;
}
template <typename T>
void LinkStack<T>::pop()
{
	if (phead->next != nullptr)
	{
		phead->next = phead->next->next;
		--count;
	}
}
template <typename T>
T LinkStack<T>::top()
{
	if (phead->next != nullptr)
		return phead->next->value;
	
}

