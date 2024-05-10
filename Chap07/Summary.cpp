/*
#강의 노트 정리
(1)void*:type을 지운다.static_cast<void*>()시 가리키는 객체의 주소를 가리킨다.
const char* p1 = "pby";
const char* p2 = "pby";
cout << static_cast<const void*>(p1) << endl;
cout << static_cast<const void*>(p2) << endl;
위 코드 출력결과는 같은 "pby" 메모리 주소를 출력한다.
즉, 포인터 변수의 주소가 아닌 가리키는 객체 주소를 출력한다.
(2)포인터 변수의 메모리 주소 출력하고 싶으면
포인터명 앞에 &를 사용하면 된다.
const char* p1 = "pby";
const char* p2 = "pby";
cout << static_cast<const void*>(p1) << endl; //"pby" 주소
cout << static_cast<const void*>(p2) << endl; //"pby" 주소
cout << &p1 << endl; //포인터 변수 p1의 주소
cout << &p2 << endl; //포인터 변수 p2의 주소
0x1003bbf8c
0x1003bbf8c
0x16fa475b0
0x16fa475a8
(3)포인터 그냥 출력시
char 배열의 포인터면 해당 문자열 바로 출력.
char 배열이 아닌 다른 타입이면 포인터가 담고 있는 가리키는 변수 주소를 출력.
(4)cin 객체
-cin객체는 프로그램 시작되면 자동으로 내부적으로 객체를 생성한다.
-cin객체 메서드
.eof()
.fail()
.bad()
.good()
모두 bool값을 리턴한다.
각 메서드에 대해 문제가 존재하면 true(1)를 리턴한다.

enum io_state{
 goodbit = 0x00, //0
 eofbit = 0x01, //1
 failbit = 0x02, //2
 badbit = 0x03 //3
 cin.rdstate()는 io_state의 현재 bit에 저장된 값을 출력한다.
 만약, 출력시 2이면 현재 statebit가 failbit라고 인식할 수 있다.
 */