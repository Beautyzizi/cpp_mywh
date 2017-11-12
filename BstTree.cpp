#include<iostream>
using namespace std;
template <typename T>
class BsNode {
public:

	BsNode(T t): value(t), lchild(nullptr), rchild(nullptr) {}
	BsNode() = default;

	BsNode<T>* parent;
	BsNode<T>* lchild;
	BsNode<T>* rchild;
	T value;
};
template <typename T>
class BsTree
{
public:
	BsTree() :root(nullptr) {};
	~BsTree();
	void Insert(T key);	//插入指定值节点
	void remove(T key);	//删除指定值节点
	void preOrder();//前序遍历
	void inOrder();//中序遍历
	void postOrder();//后序遍历
	T search_max();//找最大值
	T search_min();//找最小值
	void destory();
private:
	BsNode<T>* root; //根节点
	void remove(BsNode<T>* p, T key);
	void translate(BsNode<T>* p1, BsNode<T>* p2);
	void preOrder(BsNode<T>* p);
	void inOrder(BsNode<T>* p);
	void postOrder(BsNode<T>* p);
	T search_max(BsNode<T>* p);
	T search_min(BsNode<T>* p);
	void destory(BsNode<T>* &p);
};
template <typename T>
BsTree<T>::~BsTree()
{
	destory(root);
}
template <typename T>
void BsTree<T>::preOrder()
{
	inOrder(root);
}
template <typename T>
void BsTree<T>::preOrder(BsNode<T>* p)
{
	if (p != nullptr)
	{
		cout<<p->value << endl;
		preOrder(p->lchild);
		preOrder(p->rchild);
	}
}
template <typename T>
void BsTree<T>::inOrder()
{
	inOrder(root);
}
template <typename T>
void BsTree<T>::inOrder(BsNode<T>* p)
{
	if (p != nullptr)
	{
		inOrder(p->lchild);
		cout << p->value << endl;
		inOrder(p->rchild);
	}
}
template <typename T>
void BsTree<T>::postOrder()
{
	postOrder(root);
};
template <typename T>
void BsTree<T>::postOrder(BsNode<T>* p)
{
	if (p != nullptr)
	{
		postOrder(p->lchild);
		postOrder(p->rchild);
		cout << p->value << endl;
	}
}
template <typename T>
void BsTree<T>::translate(BsNode<T>* p1, BsNode<T>* p2)
{
	if (p1->parent->lchild==p1)
		p1->parent->lchild = p2;
	else
		p1->parent->rchild = p2;
	//p2->parent = p1->parent;
}
template <typename T>
void BsTree<T>::Insert(T key)
{
	BsNode<T>* pnode=root;
	BsNode<T>* par = root;
	while (pnode != nullptr)//找到插入的位置
	{
		par = pnode;
		if (key > pnode->value)
			pnode = pnode->rchild;
		else
			pnode = pnode->lchild;
	}
	pnode = new BsNode<T>(key);
	if (root == nullptr)
		root=pnode;
	else
	{
		if (key > par->value)
			par->rchild = pnode;
		else
			par->lchild = pnode;
	}
	pnode->parent = par;
}
template <typename T>
void BsTree<T>::remove(T key)
{
	remove(root, key);
}
template <typename T>
void BsTree<T>::remove(BsNode<T>* p, T key)
{
	if (key == p -> value)
	{
		BsNode<T>* pnode;
		pnode = p;
		if (pnode->lchild != nullptr)//被删除节点只有一个孩子
			translate(p, pnode->lchild);
		else if (pnode->rchild != nullptr)
			translate(p, pnode->rchild);
		else
		{
			pnode = p->lchild;
			while (pnode->rchild != nullptr)
				pnode = pnode->rchild;
			if (p->rchild == pnode)
				translate(p, pnode);
			pnode->parent->rchild = nullptr;
			translate(p, pnode);
		}
		pnode->lchild = p->lchild;
		pnode->parent = p->parent;
		pnode->rchild = p->rchild;
	}
	else if (key > p->value)
		remove(p->rchild,key);
	else
		remove(p->lchild,key);
}
template <typename T>
T BsTree<T>::search_max()
{
	return search_max(root);
}
template <typename T>
T BsTree<T>::search_max(BsNode<T>* p)
{
	while (!p->rchild)
		p = p->rchild;
	return p->value;
}
template <typename T>
T BsTree<T>::search_min()
{
	return search_min(root);
};
template <typename T>
T BsTree<T>::search_min(BsNode<T>* p)
{
	/*while (!p->lchild)
		p = p->lchild;*/
	if (p->lchild != nullptr)
		return search_min(p->lchild);
	return p->value;
};
template<typename T>
void BsTree<T>::destory()
{
	destory(root);
};
template <typename T>
void BsTree<T>::destory(BsNode<T>* &p)
{
	if (p != nullptr)
	{
		if (p->lchild != nullptr)
			destory(p->lchild);
		if (p->rchild != nullptr)
			destory(p->rchild);
		delete p;
		p = nullptr;
	}
};
