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
	  //递归终止函数
};

template<typename T,typename... Types>
void pritf(const T& firstArg,const Types&... args) {
	cout << firstArg << endl;
	pritf(args...);   //  递归   ...就是一个暂开操作符
}
// pritf(18,'h',"abcd",99);

//**********************************************************


template<typename T>
using Vec = vector<T, allocator<T>>;  //取别名  allocator<T> 必加，底层代码

/*测试
	Vec<string> ss = {"ad","asdasd"};
	for (auto var : ss)
	{
		cout << var << endl;
	}
*/

template<typename T,template<class T> typename Con>  // T和Con是TTT的两个模板参数。但是Con又是一个模板，所以Con是TTT的模板模板参数。
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
	TTT<int, Vec> myTTT; // 实例化TTT类，T为int，Con为vector
    myTTT.add(1);
    myTTT.add(2);
    myTTT.add(3);
    myTTT.print(); // 输出: 1 2 3

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

//二元谓词
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

 //求最大值
template<typename T>
T mymax(initializer_list<T> list) {
	 return *_max_element(list.begin(), list.end());
}

//cout << mymax<int>({5,6,1,10,9,2});

//**********************************************************


//通用模板
template<typename... Ages> class tuples {
public:
	tuples(){}
	tuples(Ages...) { cout << "通用" << endl; }

};  //前置声明   

//特化模板
template<> class tuples<>{};

//特化模版
template<typename Head, typename... Ages> 
class tuples<Head,Ages...> : private tuples<Ages...>{
public:	
	Head x;
	tuples() {};
	tuples(Head v, Ages... ages) :x(v), tuples<Ages...>(ages...) { 
		cout << "特化" << endl; 
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


// function使用  类的非静态成员函数指针
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


// 类的成员变量指针
class A1 {
public:
	A1():x(1) {}
	A1(int a) :x(a) {}
	int x;

	A1(const A1& a) {
		cout << "赋值拷贝" << endl;

	}


	A1(A1 && a) {
		cout << "右值拷贝"<<endl;

	}



};

/*  测试1
	A1 b;
	A1 a = move(b);  //调用右值拷贝

	shared_ptr<A1> p = make_shared<A1>();  //  shared_ptr是个模板类
	
	shared_ptr<A1> p1 = move(p);  //因为是对p使用了move资源转换，共享资源对象p存储的地址交给了p1。  
                                    p.use_count()等于0；p1.use_count()等于1。

*/



/*  测试2
	using p = int A1::*;  //  int A::*ptr = &A::x;
	p ptr = &A1::x;

	A1 a;
	a.*ptr = 100;
	cout << a.x << endl; // 打印100
*/

A1 pt1() {
	A1 a;
	return a;
}

A1 pt2() {
	return A1();
}

/*  测试3
	A1 a = pt1();  //右值拷贝   pt1()返回的是临时对象，属于右值
	
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
	//构造函数
	MyClass1(size_t size=0):size(size),data(size ? new int[size] : nullptr){
		cout << "拷贝构造函数,size:" << size << endl;
	}

	//析构函数
	~MyClass1() {
		delete[]data;
	}
	
	//拷贝构造函数
	MyClass1(const MyClass1 & other):size(other.size),data(other.size ? new int[other.size] : nullptr) {
		copy(other.data,other.data+other.size,data);  //数组赋值
	}

	//移动构造函数
	MyClass1(MyClass1 && other):size(other.size),data(other.data) {
		cout << "移动构造函数" << endl;
		other.data = nullptr;
		other.size = 0;
	}

	//拷贝赋值运算符
	MyClass1& operator=(const MyClass1& other){
		if (this != &other) {
			cout << "拷贝赋值运算符" << endl;
			if (data)  delete[] data;
			size = other.size;
			data = other.size ? new int[other.size] : nullptr;
		}
		return *this;
	}

	//移动赋值运算符
	MyClass1& operator=(MyClass1&& other) {
		if (this != &other) {
			cout << "移动赋值运算符" << endl;
			if (data)  delete[] data;
			size = other.size;
			data = other.data;
			other.size = 0;
			other.data = nullptr;
		}
		return *this;
	}

	// 工具函数，用于输出状态
	void print() const {
		cout << "Size: " << size << ", Data Address: " << data << endl;
	}

};
/*
	MyClass1 a(10);  // 创建一个大小为 10 的对象
	MyClass1 b;      // 创建一个空对象

	b = std::move(a);  // 使用移动赋值

	cout << "After move assignment:" << std::endl;
	a.print();  // a 应该是空的
	b.print();  // b 现在拥有原本 a 的资源

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
	~MyUnion() { // 可以定义析构函数来处理清理
		
	}
};

/*
	MyUnion nu;
	//new(&nu.s) string;
	nu.s = "hello123456";
	std::cout << nu.s << std::endl;
	std::cout << nu.t.name << std::endl;
	
	nu.x = 100;
	//new(&nu.x) int(99);  // 使用定位 new 来构造 int
	std::cout << nu.x << std::endl;
	
*/

//********************************************************** 



//   Per类中的匿名联合体和强制枚举类型
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
		cout << "类型:" << (int)type << endl;
			switch (type)
			{
			case Cate::Student:
				cout << "学生学号：" << number<< endl;
				break;
			case Cate::Local:
				cout << "本村人身份证号：" << id << endl;
				break;
			case Cate::For:
				cout << "外村人地址：" << fo.addr <<"，手机号：" <<fo.phone<< endl;
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
	Per p3("地球村","12312654");
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
		cout << "我是子线程" << this_thread::get_id() << endl;
	}
	
}


void func1() {
	for (int i = 0; i < 3; i++) {
		duration<int, ratio<1>> d(1);
		this_thread::sleep_for(d);
		cout << "我是主线程:" << this_thread::get_id() << endl;
	}
}


class AA {
public:
	void increment(int count) {
		for (int i = 0; i < count;++i) {
			

			{
				lock_guard<mutex> lock(mx); // 确保加锁
				++number;
				cout << "increament，number,数量：" << number << endl;
			}
			
			
			this_thread::sleep_for(chrono::milliseconds(500));
			//this_thread::yield();
		}
		
	}

	void decrement(int count) {
		for (int i = 0; i < count; ++i) {
			{
				lock_guard<mutex> lock(mx); // 确保加锁
				--number;
				cout << "decreament, number数量：" << number << endl;
			}
				
			this_thread::yield();
			//this_thread::sleep_for(chrono::milliseconds(500));
		}
	}
private:
	int number = 0;
	mutex mx;  //互斥锁对象
};

//********************************************************** 

once_flag g_flag;


//任务队列

class TaskQueue {

public:


	//添加数据
	void _put(const int & task) {
		unique_lock<mutex> locker(myMutex);
		while (taskQueue.size() == maxSize) {
			notFull.wait(locker);
		}
		taskQueue.push(task); 
		cout << "添加任务：" << task << ",线程ID：" << this_thread::get_id() << endl;
		notEmpty.notify_one();
	}


	//取数据
	void _take() {
		unique_lock<mutex> locker(myMutex);
		while (taskQueue.empty()) {
			notEmpty.wait(locker);
		}
		int node = taskQueue.front();
		taskQueue.pop();
		cout << "删除任务：" << node << ",线程ID：" << this_thread::get_id() << endl;
		notFull.notify_all();
	}


	bool _isFull() {
		lock_guard<mutex> locker(myMutex); // 确保加锁
		return maxSize == taskQueue.size();
	}

	bool _isEmpty() {
		lock_guard<mutex> locker(myMutex); // 确保加锁
		return taskQueue.size() == 0;
	}

	int _taskSize() {
		lock_guard<mutex> locker(myMutex); // 确保加锁
		return taskQueue.size();
	}

private:
	int maxSize = 5;
	queue<int> taskQueue;
	mutex myMutex;
	condition_variable notFull;   //生产者
	condition_variable notEmpty;  //消费者

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

//线程异步单向传值
#include<future>

void func2(promise<string> & p) {
	this_thread::sleep_for(chrono::seconds(3));

	p.set_value("你好！");
	this_thread::sleep_for(chrono::seconds(1));


}
/*
	promise<string> pro;

	//---全局函数---
	//thread t1(func2,ref(pro));
	
	//---匿名函数---
	thread t2([=](promise<string>& p) {
		this_thread::sleep_for(chrono::seconds(3));
		p.set_value("大家好！");
		this_thread::sleep_for(chrono::seconds(1));
		}, ref(pro));

	future<string> f = pro.get_future();
	string str = f.get();
	cout << "子线程返回的数据：" << str << endl;
	//t1.join();
	t2.join();
*/

//********************************************************** 
//线程异步单向传值 
int func3(int x) {

	return x += 100;
}

/*
	packaged_task<int(int)> p(func3);
	thread t3(ref(p), 200);
	cout << p.get_future().get() << endl;
	t3.join();
	打印 300
*/

//********************************************************** 



int main6() {
	
	

	return 0;
}
