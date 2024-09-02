#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<map>
#include<sstream>
#include <regex>
#include <functional>
#include <algorithm>
#include<chrono>
#include<condition_variable>
#include <mutex>
using namespace std;
using namespace chrono;

void fun1(){

	initializer_list<int> vals{ 1,2,3,4,5,6 };

	for (auto var : vals)
	{
		cout << var << endl;
	}

	using vec = int;
	vec x = 5;
	cout << x << endl;
}

//**********************************************************

void pritf() {
	  //�ݹ���ֹ����
};

template<typename T,typename... Types>
void pritf(const T& firstArg,const Types&... args) {
	cout << firstArg << endl;
	pritf(args...);   //  �ݹ�   ...����һ���ݿ�������
}
// pritf(18,'h',"abcd",99);

//**********************************************************


template<typename T>
using Vec = vector<T, allocator<T>>;  //ȡ����  allocator<T> �ؼӣ��ײ����

/*����
	Vec<string> ss = {"ad","asdasd"};
	for (auto var : ss)
	{
		cout << var << endl;
	}
*/

template<typename T,template<class T> typename Con>  // T��Con��TTT������ģ�����������Con����һ��ģ�壬����Con��TTT��ģ��ģ�������
class TTT {
public:
	Con<T> container;

	void add(const T& value) {
		container.push_back(value);
	}

	void print() {
		for (auto& item : container) {
			std::cout << item << " ";
		}
		std::cout << std::endl;
	}
	 
};

/*
	TTT<int, Vec> myTTT; // ʵ����TTT�࣬TΪint��ConΪvector
    myTTT.add(1);
    myTTT.add(2);
    myTTT.add(3);
    myTTT.print(); // ���: 1 2 3

*/

//**********************************************************

template<typename T, typename Comper>
T __max_element(T first,T end,Comper comp) {

	if (first == end) { return first; }
	T _result = first;
	while (++first != end) {
		if(comp(_result, first)) {
			_result = first;
		}
	}
	return _result;
	
}

//��Ԫν��
struct _Iter_less_iter {

	template<typename _Iterat>
	bool operator()(_Iterat it1, _Iterat it2) const{

	return *it1 < *it2;
	}
};


template<typename T>
 T _max_element(T first, T end) {
	 return __max_element(first,end, _Iter_less_iter());
}

 //�����ֵ
template<typename T>
T mymax(initializer_list<T> list) {
	 return *_max_element(list.begin(), list.end());
}

//cout << mymax<int>({5,6,1,10,9,2});

//**********************************************************


//ͨ��ģ��
template<typename... Ages> class tuples {
public:
	tuples(){}
	tuples(Ages...) { cout << "ͨ��" << endl; }

};  //ǰ������   

//�ػ�ģ��
template<> class tuples<>{};

//�ػ�ģ��
template<typename Head, typename... Ages> 
class tuples<Head,Ages...> : private tuples<Ages...>{
public:	
	Head x;
	tuples() {};
	tuples(Head v, Ages... ages) :x(v), tuples<Ages...>(ages...) { 
		cout << "�ػ�" << endl; 
	};
	   
	Head head() {
		return x;
	}
	tuples<Ages...>& tail() {
		return *this;
	}

};

/*
tuples<int, float, string,string,int>t(41,6.3,"nico","jsl",6);
cout << t.head()<<endl;
cout << t.tail().head()<<endl;
*/

//**********************************************************


// functionʹ��  ��ķǾ�̬��Ա����ָ��
class A {
public:
	A(){}
	A(double x):d(x){}

	void  fun(int x) {

		cout << "Afun" << endl;
	}

private:
	double d;

};

/*
	void(A::*p)(int) = &A::fun;
	p(1);
	
	A a;
	function<void(int)> p1 = bind(&A::fun, a,placeholders::_1);
	p1(2);
*/

//**********************************************************


// ��ĳ�Ա����ָ��
class A1 {
public:
	A1():x(1) {}
	A1(int a) :x(a) {}
	int x;

	A1(const A1& a) {
		cout << "��ֵ����" << endl;

	}


	A1(A1 && a) {
		cout << "��ֵ����"<<endl;

	}



};

/*  ����1
	A1 b;
	A1 a = move(b);  //������ֵ����

	shared_ptr<A1> p = make_shared<A1>();  //  shared_ptr�Ǹ�ģ����
	
	shared_ptr<A1> p1 = move(p);  //��Ϊ�Ƕ�pʹ����move��Դת����������Դ����p�洢�ĵ�ַ������p1��  
                                    p.use_count()����0��p1.use_count()����1��

*/



/*  ����2
	using p = int A1::*;  //  int A::*ptr = &A::x;
	p ptr = &A1::x;

	A1 a;
	a.*ptr = 100;
	cout << a.x << endl; // ��ӡ100
*/

A1 pt1() {
	A1 a;
	return a;
}

A1 pt2() {
	return A1();
}

/*  ����3
	A1 a = pt1();  //��ֵ����   pt1()���ص�����ʱ����������ֵ
	
*/



//**********************************************************



void pro(int & i) {
	cout << "pro(int & i):" << i << endl;

}
void pro(int&& i) {
	cout << "pro(int && i):" << i << endl;

}

template<typename T>
void forwards(T && i) {
	pro(forward<T>(i));
}

/*
	int x = 10;
	forwards(10);
*/

//**********************************************************

class MyClass1 {
private:
	int* data;
	size_t size;
public:
	//���캯��
	MyClass1(size_t size=0):size(size),data(size ? new int[size] : nullptr){
		cout << "�������캯��,size:" << size << endl;
	}

	//��������
	~MyClass1() {
		delete[]data;
	}
	
	//�������캯��
	MyClass1(const MyClass1 & other):size(other.size),data(other.size ? new int[other.size] : nullptr) {
		copy(other.data,other.data+other.size,data);  //���鸳ֵ
	}

	//�ƶ����캯��
	MyClass1(MyClass1 && other):size(other.size),data(other.data) {
		cout << "�ƶ����캯��" << endl;
		other.data = nullptr;
		other.size = 0;
	}

	//������ֵ�����
	MyClass1& operator=(const MyClass1& other){
		if (this != &other) {
			cout << "������ֵ�����" << endl;
			if (data)  delete[] data;
			size = other.size;
			data = other.size ? new int[other.size] : nullptr;
		}
		return *this;
	}

	//�ƶ���ֵ�����
	MyClass1& operator=(MyClass1&& other) {
		if (this != &other) {
			cout << "�ƶ���ֵ�����" << endl;
			if (data)  delete[] data;
			size = other.size;
			data = other.data;
			other.size = 0;
			other.data = nullptr;
		}
		return *this;
	}

	// ���ߺ������������״̬
	void print() const {
		cout << "Size: " << size << ", Data Address: " << data << endl;
	}

};
/*
	MyClass1 a(10);  // ����һ����СΪ 10 �Ķ���
	MyClass1 b;      // ����һ���ն���

	b = std::move(a);  // ʹ���ƶ���ֵ

	cout << "After move assignment:" << std::endl;
	a.print();  // a Ӧ���ǿյ�
	b.print();  // b ����ӵ��ԭ�� a ����Դ

*/

//**********************************************************

enum class MyEnum:int
{
	x, y, z
};

enum MyEnum1
{
	x, y, z
};

/*
	MyEnum e = MyEnum::y;
	cout << static_cast<int>(e);
*/

//**********************************************************


class Te {
public:
	Te() {};
	string name;
};


union MyUnion
{
	MyUnion():s() {
		
	};
	/*
	MyUnion(){
		new(&nu.s) string;
	};
	*/

	int x;
	string s;
	Te t;
	~MyUnion() { // ���Զ���������������������
		
	}
};

/*
	MyUnion nu;
	//new(&nu.s) string;
	nu.s = "hello123456";
	std::cout << nu.s << std::endl;
	std::cout << nu.t.name << std::endl;
	
	nu.x = 100;
	//new(&nu.x) int(99);  // ʹ�ö�λ new ������ int
	std::cout << nu.x << std::endl;
	
*/

//********************************************************** 



//   Per���е������������ǿ��ö������
struct For {
	For(string s ,string ph):addr(s),phone(ph){}
	string addr;
	string phone;
};


class Per {
public:
	enum class Cate:char{Student, Local, For};
	Per(int num):number(num),type(Cate::Student){}
	Per(string _id):id(_id),type(Cate::Local){}
	Per(string _addr,string ph):fo(_addr,ph),type(Cate::For){}

	~Per(){}

	void Perprint() {
		cout << "����:" << (int)type << endl;
			switch (type)
			{
			case Cate::Student:
				cout << "ѧ��ѧ�ţ�" << number<< endl;
				break;
			case Cate::Local:
				cout << "���������֤�ţ�" << id << endl;
				break;
			case Cate::For:
				cout << "����˵�ַ��" << fo.addr <<"���ֻ��ţ�" <<fo.phone<< endl;
				break;	
			}
	}

private:
	Cate type;
	union 
	{
		int number;
		string id;
		For fo;
	};

};

/*
	Per p1(9297);
	Per p2("122456121dsad");
	Per p3("�����","12312654");
	p1.Perprint();
	p2.Perprint();
	p3.Perprint();
*/

//********************************************************** 
#include<thread>


void func() {
	for (int i = 0; i < 3;i++) {
	duration<int, ratio<1>> d(1);
	this_thread::sleep_for(d);
		cout << "�������߳�" << this_thread::get_id() << endl;
	}
	
}


void func1() {
	for (int i = 0; i < 3; i++) {
		duration<int, ratio<1>> d(1);
		this_thread::sleep_for(d);
		cout << "�������߳�:" << this_thread::get_id() << endl;
	}
}


class AA {
public:
	void increment(int count) {
		for (int i = 0; i < count;++i) {
			

			{
				lock_guard<mutex> lock(mx); // ȷ������
				++number;
				cout << "increament��number,������" << number << endl;
			}
			
			
			this_thread::sleep_for(chrono::milliseconds(500));
			//this_thread::yield();
		}
		
	}

	void decrement(int count) {
		for (int i = 0; i < count; ++i) {
			{
				lock_guard<mutex> lock(mx); // ȷ������
				--number;
				cout << "decreament, number������" << number << endl;
			}
				
			this_thread::yield();
			//this_thread::sleep_for(chrono::milliseconds(500));
		}
	}
private:
	int number = 0;
	mutex mx;  //����������
};

//********************************************************** 

once_flag g_flag;


//�������

class TaskQueue {

public:


	//�������
	void _put(const int & task) {
		unique_lock<mutex> locker(myMutex);
		while (taskQueue.size() == maxSize) {
			notFull.wait(locker);
		}
		taskQueue.push(task); 
		cout << "�������" << task << ",�߳�ID��" << this_thread::get_id() << endl;
		notEmpty.notify_one();
	}


	//ȡ����
	void _take() {
		unique_lock<mutex> locker(myMutex);
		while (taskQueue.empty()) {
			notEmpty.wait(locker);
		}
		int node = taskQueue.front();
		taskQueue.pop();
		cout << "ɾ������" << node << ",�߳�ID��" << this_thread::get_id() << endl;
		notFull.notify_all();
	}


	bool _isFull() {
		lock_guard<mutex> locker(myMutex); // ȷ������
		return maxSize == taskQueue.size();
	}

	bool _isEmpty() {
		lock_guard<mutex> locker(myMutex); // ȷ������
		return taskQueue.size() == 0;
	}

	int _taskSize() {
		lock_guard<mutex> locker(myMutex); // ȷ������
		return taskQueue.size();
	}

private:
	int maxSize = 5;
	queue<int> taskQueue;
	mutex myMutex;
	condition_variable notFull;   //������
	condition_variable notEmpty;  //������

};

/*
	thread t1[10];
	thread t2[10];
	TaskQueue taskQ;
	for (int i = 0; i < 10; ++i) {
		t1[i] = thread(&TaskQueue::_put,&taskQ,100+i);
		t2[i] = thread(&TaskQueue::_take,&taskQ);
	}

	for (int i = 0; i < 10; ++i) {
		t1[i].join();
		t2[i].join();
	}
*/

//********************************************************** 

//�߳��첽����ֵ
#include<future>

void func2(promise<string> & p) {
	this_thread::sleep_for(chrono::seconds(3));

	p.set_value("��ã�");
	this_thread::sleep_for(chrono::seconds(1));


}
/*
	promise<string> pro;

	//---ȫ�ֺ���---
	//thread t1(func2,ref(pro));
	
	//---��������---
	thread t2([=](promise<string>& p) {
		this_thread::sleep_for(chrono::seconds(3));
		p.set_value("��Һã�");
		this_thread::sleep_for(chrono::seconds(1));
		}, ref(pro));

	future<string> f = pro.get_future();
	string str = f.get();
	cout << "���̷߳��ص����ݣ�" << str << endl;
	//t1.join();
	t2.join();
*/

//********************************************************** 
//�߳��첽����ֵ 
int func3(int x) {

	return x += 100;
}

/*
	packaged_task<int(int)> p(func3);
	thread t3(ref(p), 200);
	cout << p.get_future().get() << endl;
	t3.join();
	��ӡ 300
*/

//********************************************************** 



int main6() {
	
	

	return 0;
}
