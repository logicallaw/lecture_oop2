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
#헷갈린 개념
 1.Tmp t1();
 t1.print(); 가능
 Tmp* pt1 = &t1;
 t1->print(); 가능
 (*t1).print(); 가능

 */