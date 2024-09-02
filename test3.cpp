#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include <regex>
using namespace std;

class As {
public:
    int x, y;
    As():x(0), y(0) {
        cout << "默认构造" << endl;
    }
   
    As(int a,int b) :x(a), y(b) {
        cout << "有参构造" << endl;
        x = a;
        y = b;
    }
    int getX() {
        return x;
    }
    As  operator+=(const As & as01) {
        this->x += as01.x;
        this->y += as01.y;
        return *this;  
    }
};

As operator+(const As & as1,int x) {

    return As(as1.x+x,as1.y);
}

//单例模式
class Bw {
public:
    static Bw& getBw_instance() {

        return b;
    }
    void pr() {
        cout << this;
    }


private:
    Bw() {
        cout << "Bw的无参构造被调用了。"<<endl;
    }
    Bw(const Bw &b) {

    }
    static Bw b;  //只是声明
};
Bw Bw::b;  //静态变量要定义 


//类模板
template<class T>
class t3c {
public:
   
    t3c(T x_,T y_) :x(x_), y(y_) {}
    t3c& operator+=(const t3c & t) {
        this->x += t.x;
        this->y += t.y;
        return *this;
    }
    
    T getx() const{
        return x;
    }
    T gety() const {
        return y;
    }
    

private:
    T x, y;

};

template<typename T>
const T& min_(const T& t1,const T& t2) {
    return t1 < t2 ? t1 : t2;
}

template<class T>
bool operator<(const t3c<T>& t1,const t3c<T>& t2) {
    return t1.getx() < t2.getx();
}


class Comp {
    int value;
public:
    Comp(int val):value(val) {};
    virtual void add(Comp *) {};
    int getValue() const { cout<<"父类的getValue()"; return value; };
 };

class Prim :public Comp {
public:
    Prim(int val) :Comp(10) { xd = val; };
    //int getValue() const { cout << "子类的getValue()"; return xd; };
protected:
    int xd;
};

class ffff {
public:
    static ffff* peroto[10];
    static void add(ffff* f1) {
        peroto[0] = f1;
    }
    virtual void funa() {
        cout << "fffff";
    }
    virtual ffff* clone() = 0;
     ffff* fg() {
        cout << "ffff的fg()" << endl;
        return peroto[0]->clone();
    }
};
ffff* ffff::peroto[];
class skas:public ffff {

public:
    
    ffff* clone() {
        cout << "skas的clone()" << endl;
        return new skas(1);
    }

    void funa() {
        cout << "skas";
    }

private:
    skas() { add(this); };
    skas(int x) {};
    static skas s1;
};
skas skas::s1;

//ffff::peroto[0]->fg()->funa();


//转换函数  operator typename() const{}

class Fraction {
public:
    Fraction(int num, int den = 1) :m_numerator(num),m_denominator(den){}
    operator double() const {
        return (double)(m_numerator*1.0 / m_denominator);
    }

private:
    int m_numerator;     //分子
    int m_denominator;  //分母

};

//仿函数
 template<class pair>
 struct select1st {

     const typename pair::first_type& operator()(const pair& x) const {
         return x.first;
     }
 };
 //pair<int, int> p(100,10);
 //cout << ( select1st<pair<int, int>>() ).operator()(p) << endl << p.second;



 class vts {
 public:
     void print(){}

     template<typename T,typename... Ts>
     void  print(const T& firstArg,const Ts&... args) {
         cout << firstArg << endl;
         print(args...);
     }
 };
 //vts().print(1, "abcd",2.6,'g');


 //重载new、delete关键字
 class Foo {
 public:
     virtual void f1() {
         cout << "a1"<<endl;
     }
     void* operator new(size_t size) {  // 底层是编译器调用，size是告诉编译器 自定义类的大小 ，必须要写这个参数
         Foo* p = (Foo*)malloc(size);
         cout << "new" << endl;
         return p;
     }
     void* operator new[](size_t size) {
         Foo* p = (Foo*)malloc(size);
         cout << "new[]" << endl;
         return p;
     }

     void operator delete(void* p,size_t size) {
         cout << "delete" << endl;
         free(p);
     }
     void operator delete[](void* p, size_t size) {
         cout << "delete[]" << endl;
         free(p);
     }
    
 };

 namespace name1
 {
     void fun1() {
         cout << "这是name1的namespace"<<endl;
     }
 }

 namespace name2
 {
     void fun1() {
         cout << "这是name2的namespace" << endl;
     }
 }
 //name1::fun1();
 //name2::fun1();
 

 //模拟文件操作
 void fileTeas() {

    /*
     
     ifstream file(filename);
     if (file.is_open()) {
         while (getline(file, line)) {
          stringstream ss;
          ss<<line;
           // 从字符串流中读取数据
          std::string str1;
          std::string str2;
          std::string str3;
          std::getline(ss, str1, ',');
          std::getline(ss, str2, ',');
          std::getline(ss, str3);
  
          std::cout << str1 << std::endl;
          std::cout << str2 << std::endl;
          std::cout << str3 << std::endl;
         }

     }
      */
    

   
 }

 class Aa {

 public:
     
     Aa(int x_):x(x_) {

     }
     int& getx() {

         return x;
     }
    
 private:

     int x;
 };

 void fund(Aa& a) {
     int s = 10;
     a.getx() = s;

 }
 /*
    Aa a(20);
    fund(a);
    cout << a.getx();
 */

 


int main3()
{
    
    //Foo* p = new Foo ;
    //delete p;
    //
    
   

    return 1;

}
