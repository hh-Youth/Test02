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
        cout << "Ĭ�Ϲ���" << endl;
    }
   
    As(int a,int b) :x(a), y(b) {
        cout << "�вι���" << endl;
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

//����ģʽ
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
        cout << "Bw���޲ι��챻�����ˡ�"<<endl;
    }
    Bw(const Bw &b) {

    }
    static Bw b;  //ֻ������
};
Bw Bw::b;  //��̬����Ҫ���� 


//��ģ��
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
    int getValue() const { cout<<"�����getValue()"; return value; };
 };

class Prim :public Comp {
public:
    Prim(int val) :Comp(10) { xd = val; };
    //int getValue() const { cout << "�����getValue()"; return xd; };
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
        cout << "ffff��fg()" << endl;
        return peroto[0]->clone();
    }
};
ffff* ffff::peroto[];
class skas:public ffff {

public:
    
    ffff* clone() {
        cout << "skas��clone()" << endl;
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


//ת������  operator typename() const{}

class Fraction {
public:
    Fraction(int num, int den = 1) :m_numerator(num),m_denominator(den){}
    operator double() const {
        return (double)(m_numerator*1.0 / m_denominator);
    }

private:
    int m_numerator;     //����
    int m_denominator;  //��ĸ

};

//�º���
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


 //����new��delete�ؼ���
 class Foo {
 public:
     virtual void f1() {
         cout << "a1"<<endl;
     }
     void* operator new(size_t size) {  // �ײ��Ǳ��������ã�size�Ǹ��߱����� �Զ�����Ĵ�С ������Ҫд�������
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
         cout << "����name1��namespace"<<endl;
     }
 }

 namespace name2
 {
     void fun1() {
         cout << "����name2��namespace" << endl;
     }
 }
 //name1::fun1();
 //name2::fun1();
 

 //ģ���ļ�����
 void fileTeas() {

    /*
     
     ifstream file(filename);
     if (file.is_open()) {
         while (getline(file, line)) {
          stringstream ss;
          ss<<line;
           // ���ַ������ж�ȡ����
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
