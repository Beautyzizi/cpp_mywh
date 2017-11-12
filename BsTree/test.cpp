#include<iostream>
#include"BsTree.h"
using namespace std;
int main()
{
	BsTree<int> t;
	t.Insert(62);
	t.Insert(58);
	t.Insert(47);
	t.Insert(35);
	t.Insert(37);
	t.Insert(88);
	t.Insert(79);
	t.Insert(100);
	t.Insert(93);
	t.Insert(95);

	cout << endl << "中序遍历：" << endl;
	t.inOrder();
	cout << "最大元素:" << t.search_max() << endl;
	cout << "最小元素:" << t.search_min() << endl;
	cout << "删除元素99" << endl;
	t.remove(100);
	cout << "最大元素:" << t.search_max() << endl;
	t.destory();
	return 0;
}