template <typename T>
class Node {
public:
	Node() = default;
	Node(T t) :value(t), next(nullptr) {};
public:
	T value;
	Node<T> *next;
};
template <typename T>
class LinkQueue {
public:
	LinkQueue();
	~LinkQueue();
	void push(T t);
	bool pop();
	int size();
	bool isEmpty();
	T front();
private:
	Node<T>* phead;
	Node<T>* pend;
	int count;
};
template <typename T>
LinkQueue<T>::LinkQueue()
{
	phead = new Node<T>();
	pend = phead;
	count = 0;
}
template <typename T>
LinkQueue<T>::~LinkQueue()
{
	while (phead->next != nullptr)
	{
		Node<T>*pnode=phead;
		phead=phead->next;
		delete pnode;
	}
}
template <typename T>
void LinkQueue<T>::push(T t)
{
	Node<T>* pnode = new Node<T>(t);
	pend->next = pnode;
	pend = pnode;
	++count;
}
template <typename T>
bool LinkQueue<T>::pop()
{
	if (count == 0)
		return false;
	Node<T>* pnode= phead->next;
	pnode->next = phead->next->next;
	phead->next = pnode->next;
	delete pnode;
	--count;
	return 1;
}
template <typename T>
int LinkQueue<T>::size()
{
	return count;
}
template <typename T>
bool LinkQueue<T>::isEmpty()
{
	return count == 0;
}
template <typename T>
T LinkQueue<T>::front()
{
	return phead->next->value;
}