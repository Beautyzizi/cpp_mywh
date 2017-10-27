template <typename T>
class Node {
public:
	Node() :value(0), next(nullptr) {};
	Node(T t,Node *p) : value(t), next(p) {}
	Node(T t) :value(t) ,next(nullptr){};
	T value;
	Node *next;
};
template <typename T>
class SingleLink {
public:
	SingleLink();
	~SingleLink();
	bool isEmpty();//是否为一个空链表
	bool isLast(Node<T>* p);//是否是链表中的最后一个元素
	Node<T>* Find(T x);//查找x并返回在表中的位置
	Node<T>* FindPrevious(T x);//查找x的前驱元素并返回
	void Delect(T t);//删除元素
	void Insert(T t, T x);//x插入到t元素的后面
	void Insert_1(int n, T x);//x插入到n位置后面
	Node<T> * getNode(int n);//获取第n个节点
private:
	Node<T> *phead;
	int count;
};

template <typename T>
SingleLink<T>::SingleLink()
	:count(0), phead(nullptr)
{
	phead = new Node<T>();
	phead->next = nullptr;
};

template <typename T>
SingleLink<T>::~SingleLink()
{
	Node<T>* pnode;
	pnode = phead->next;
	while (pnode!=nullptr)
	{
		Node<T>* temp=pnode;
		pnode = pnode->next;
		delete temp;
	}
}

template <typename T>
bool SingleLink<T>::isEmpty()
{

	return count==0;
}

template <typename T>
bool SingleLink<T>::isLast(Node<T>* p)
{
	return count==0;
}

template <typename T>
Node<T>* SingleLink<T>::Find(T x)
{
	Node<T>* pnode;
	pnode = phead->next;
	while (pnode != NULL&&pnode->value != x)
	{
		pnode = pnode->next;
	}
	return pnode;
}

template <typename T>
Node<T>* SingleLink<T>::FindPrevious(T t)
{
	Node<T>* pnode;
	pnode = phead->next;
	while (pnode != NULL&&pnode->next->value != t)
		pnode = pnode->next;//pnode->next=pnode->next->next;
	return pnode;
}

template <typename T>
void SingleLink<T>::Delect(T t)
{
	if (isEmpty())
		exit(0);
	Node<T>* pnode;
	pnode = FindPrevious(t);
	Node<T>* temp;
	temp = pnode->next;
	pnode->next = temp->next;
	delete temp;
	--count;
}

template <typename T>
void SingleLink<T>::Insert(T t,T x)
{
	Node<T>* pnode = new Node<T>(x);
	Node<T>* temp;
	temp = FindPrevious(t);
	pnode->next = temp->next;
	temp->next = pnode;
	++count;
}

template <typename T>
void SingleLink<T>::Insert_1(int n, T t)
{
	Node<T>* pnode=getNode(n);
	Node<T>* temp=new Node<T>(t);
	temp->next = pnode->next;
	pnode->next = temp;
	++count;
}
template <typename T>
Node<T>* SingleLink<T>::getNode(int n)
{
	if (n > count || n < 0)
		return nullptr;
	int temp = 0;
	Node<T>* pNode = phead;
	while (temp != n)
	{
		temp++;
		pNode = pNode->next;
	}
	return pNode;
}
