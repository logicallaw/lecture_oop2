/*
#3강 강의 정리:this, static
 1.this는 호출되는 객체의 포인터이다.
 따라서, this 사용시 Arrow operator를 사용하여 member에 접근해야한다.
 2.*this는 객체 자기 자신이 된다.
 3.(체크)this 포인터는 static, friend에서 사용불가능하다.
 4.Cascaded Function Calls는 리턴값이 다른 함수를 호출하게 하는 방법이다.
 따라서, *this를 리턴하여 나 자신을 호출하여 다른 멤버함수를 연속해서 사용할 수 있게 된다.
 5.static의 소유권은 class에 있다.
 static 멤버변수는 클래스 밖에서 정의된다!(안에서 정의하면 const int가 아닌이상 컴파일에러가 발생한다.)
 6.static 멤버변수는 단 한번만 초기화된다.
 7.함수호출은 Rvalue가 되어서 어떤 값을 저장할 수가 없다.
 8.int&& a = 5;와 같이 Rvalue를 참조할 수 있는 문법이 있다.
 9.위임생성자: 생성자가 호출될때 다른 생성자로 위임하여 초기화하는 방법이 있다.
 주로, 어떤 객체의 값을 포인터로 초기화할 때 매개변수 생성자를 위임하여 초기화할 수 있다.
 10.


 */