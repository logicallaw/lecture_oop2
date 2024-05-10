/* #문제풀면서 알게된 개념
 * 1.abstract class에서 virtual function 정의시 body{}가 있어야한다.
 * 없으면 컴파일 에러가 발생한다.
 * 2.delegating constructor는 초기화시 생성자 하나만 있어야한다.
 * Car(string model, string color)
 *  : Car{ model } {this->color = color;}
 *  과 같이 하나만 멤버이니셜라이저로 사용해야한다.
 *
 */
