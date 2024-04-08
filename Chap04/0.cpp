/*
#Polymorphism
#새로 알게된 개념
 1.cout << (t1+=3).getA() << endl;와 같이 역참조 포인터를 리턴하고 멤버함수로 접근해서 cout 으로 바로 출력이 가능.
 2.    Tmp t{ 4 };
    (t+=3)+=5;
    t.display(); 이러한 문법이 가능하다는 것을 알아야한다.
 3.
 explicit Tmp(int a = 0) //conversion 방지.
        : a{ a } {}
 와 같이 explicit되어있으면 =로 int에서 Tmp로 불가. 오직 {}만 가능
 4.Tmp t1{2,4};와 같이 해당 매개변수 리스트와 대응되는 생성자가 없으면
 초기화 불가능해서 컴파일 에러가 발생함!
#강의 개념정리
 1.예를 들면 makeSound()를 호출할 때 서로 다른 클래스의 객체에서 각각 다르게 반응하여
 moow를 출력하거나 meow를 출력할 수 있게 된다.
 2.Compile-Time 다형성
 :함수오버로딩과 연산자 오버로딩
 3.함수 오버로딩은 반드시
 (강의) 같은 이름, 같은 매개변수 타입, 같은 리턴타입, 서로 다른 종류의 인자.
 4.연산자 오버로딩
 이항 연산자(Binary Operator)와 단항 연산자(Unary operator)
 이항 연산자는 2개를 피연산자로 하여금 계산하는 연산자이다.
 이항 연산자는 스코프에 따라서 전역 오버로딩과 클래스 멤버 오버로딩으로 나누어져있다.
 전역 오버로딩이 클래스 private 멤버를 사용시 클래스 내부에 friend 선언이 필요하다.
 클래스 멤버 오버로딩은 클래스 자기 자신과 매개변수로 하나만 받게된다.

 이항 연산자 전역 오버로딩
 friend return-type operator 연산자 (arg1, arg2);선언
 return-type operator 연산자 (arg1, arg2){} 정의
 이항 연산자 클래스 멤버 오버로딩
 class-type operator 연산자 (const class-type& arg1)
 5.연산자 오버로딩 리턴타입

 Tmp operator+(const Tmp& right) { return Tmp{a + right.a}; }
 Tmp operator-(const Tmp& right} { return Tmp{a - right.x}; }
 bool operator==(const Tmp& right} { return (x == right.x); }
 bool operator!=(const Tmp& right} { return (x != right.x); }
 Tmp& operator++(){ ++x; return *this; } //자기자신, prefix
 Tmp& operator+=(){ x += right.x; return *this; } //자기자신
 Tmp operator++(int) { Tmp temp{*this}; x++; return temp; } // postfix

 friend ostream& operator<<(ostream& out, const Tmp& right){
        out << right.x << "-" << right.y << endl;
        return out;
    }
 (여기서 Tmp가 const가 아님!)
 friend istream& operator>>(istream& in, Tmp& right){
        in >> right.x;
        in.ignore(10,'-');
        in >> right.y;
        return in;
    }
 int& operator[](int index){ return p[index]; }
 int operator[](int index){ return p[index]; }




 5.단항 연산자
 :피연산자 1개를 갖는 연산자를 의미한다.
 단항 연산자 오버로딩은
#헷갈린 개념
 1.Tmp t1();
 t1.print(); 가능
 Tmp* pt1 = &t1;
 t1->print(); 가능
 (*t1).print(); 가능

 */