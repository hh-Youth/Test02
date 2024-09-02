 #include <iostream>
#include < cstring >
#include<time.h>
#include <stack>
#include <queue>
#include <set>
#include <list>
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#include <numeric>
#include <vector>
#include <deque>
#include <algorithm>
#include <thread>

#include <bitset>

#include<functional>

#include<fstream>



template<class T1,class T2>
class Person {
public:
	Person() {

	}
	Person(T1 name ,T2 age) {
		this->name = name;
		this->age = age;
	}
	virtual void showPerson() {
		cout << "name:" << this->name << endl << "age:"<<this->age<<endl;
		cout << (this) << endl;
	}

	T1 name;
	T2 age;

}; 


template<class T1, class T2 >
class son :public Person<T1, T2> {

public:
	son() {

	}
	son(T1 name, T2 age) {
		this->name = name;
		this->age = age;
	}
	void showPerson() {
		cout << "sonname:" << this->name << endl << "age:" << this->age << endl;
		cout << (this) << endl;
	}
	T1 name;
	T2 age;
};



void priPerson01(Person<string,int> &p) {
	p.showPerson();
}


template<typename T>
void priPerson02(T &p) {

	p.showPerson();
}

template<typename T1,typename T2>
void priPerson03(Person<T1,T2>& p) {

	p.showPerson();
}

void test01() {

	Person<string, int> p("孙悟空",999);
	//priPerson01(p);
}

void test02() {
	Person<string, int> p("猪八戒", 666);
	priPerson03(p);
}

void test03() {
	son<string, int> s("张三",18);
	priPerson01(s);
}



void prinv(vector<int> v) {
	cout << v[0]<<"  "<<v[1]<<"  "<<v[2]<<endl;
}

void test04() {

	vector<vector<int>> v = { {1,1,1},{1,1,0},{1,0,1} };
	vector<int> v1 = { 1,1,0 };

	vector<vector<int>>::iterator it = v.end();

	if (find(v.begin(), v.end(), v1) != v.end())
	{
		cout << "找到了" << endl;
	}
	for_each(v.begin(), v.end(), prinv);
}
typedef int status;
typedef char ElemType;
#define ok 1
#define error -1
typedef struct BiTNode {
	ElemType data;
	struct BiTNode* lchild, * rchild;
}BiTNode, * BiTree;
int m_size, e;

//先序遍历创建二叉树

status CreateBiTree(BiTree* T, int size) {

	m_size = size;    //全局变量控制可输入结点个数的值不被递归影响



	if (m_size > 0) {
		printf("还有%d个结点待输入", m_size);
	}
	else
	{
		return ok;
	}

	//BiTree p=T;
	char e;
	e = getchar();
	getchar();  //专吃回车
	if (e == '#')
	{
		*T = NULL;      //空节点


	}
	else
	{
		*T = (BiTree)malloc(sizeof(BiTNode));   //开辟空间
		(*T)->data = e;    //赋值

		(*T)->lchild = NULL;
		(*T)->rchild = NULL;

		m_size--;

		CreateBiTree(&(*T)->lchild, m_size);
		CreateBiTree(&(*T)->rchild, m_size);



	}

	return  ok;
}





//先序遍历
status PreOrderTraverse(BiTree T) {
	if (T != NULL) {
		printf("%c", T->data);
		PreOrderTraverse(T->lchild);
		PreOrderTraverse(T->rchild);;
	}

	return ok;
}




int main1() {

	
	BiTree T = (BiTree)malloc(sizeof(BiTNode));
	//InitTree(T);
	//CreateBiTree(&T, m_node);          //创建二叉树
	BiTree x;
	BiTree y;
	BiTree z;
	BiTree s;
	BiTree t;
	BiTree h;
	x = (BiTree)malloc(sizeof(BiTNode));
	y = (BiTree)malloc(sizeof(BiTNode));
	z = (BiTree)malloc(sizeof(BiTNode));
	s = (BiTree)malloc(sizeof(BiTNode));
	t = (BiTree)malloc(sizeof(BiTNode));
	h = (BiTree)malloc(sizeof(BiTNode));
	
	T->lchild = x;
	T->rchild = y;

	x->lchild = z;
	x->rchild = s;

	y->lchild = NULL;
	y->rchild = NULL;

	z->lchild = NULL;
	z->rchild = NULL;

	s->lchild = NULL;
	s->rchild = NULL;

	t->lchild = NULL;
	t->rchild = NULL;

	h->lchild = NULL;
	h->rchild = NULL;

	T->data = 'A';
	x->data = 'B';
	y->data = 'C';
	z->data = 'D';
	s->data = 'E';
	t->data = 'F';
	h->data = 'H';

	//printf("先序遍历二叉树：");
	
	
	test01();
	//test02();
	//test03();
	//test04();
	

	return 0;
} 





//
//3.2.设计缓存(复杂10)(选做)描述:
//设计一个缓存，缓存大小为指定大小n, 最近最少使用的值应自动被缓存替换掉。(类及类的方法已经定义好)
//Class Cache{
//public:
//explict Cache(int n); bool put(int,int); int get(int);
//) }
//要求:
//1.缓存支持键值对存取，即支持插入键值对put(key, val)及读取某键对应的值
//get(key)，如果存在该键，则返回其对应的值，否则返回 - 1;
//2.键值对可以支持整型。
//要求 : 尽量使用时间复杂度最小的方法实现。
//请用中文说明算法思想(5)
//请给出算法例程，可使用c++ / golang实现(5)


