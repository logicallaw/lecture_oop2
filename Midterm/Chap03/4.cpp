#include <iostream>
//static 예제.
using namespace std;
class CreateAndDestroy{
private:
    int objectID;
    string message;
public:
    CreateAndDestroy(int objectID, string message);
    ~CreateAndDestroy();
};
CreateAndDestroy::CreateAndDestroy(int objectID, string message)
    : objectID{ objectID }, message{ message }{
    cout << "constructor | " << objectID << ", " << message << endl;
}
CreateAndDestroy::~CreateAndDestroy() {
    cout << "destructor | " << objectID << ", " << message << endl;
}
void create();

CreateAndDestroy first{1, "first"};
int main(void){
    cout << "메인 함수 시작" << endl;
    CreateAndDestroy second{2, "second"};
    static CreateAndDestroy third{3, "third"};
    create();
    CreateAndDestroy fourth{4, "fourth"};
    cout << "메인 함수 종료" << endl;
    return 0;
    //나중에 들어온게 먼저 나간다. 후입선출
    //stack,heap 따로 고려. non static먼저, static다음. 먼저 들어온게 나중에.
    //1,2,3,5,6,7,7,5,4,4,2,6,3,1
    //1,3,6,
}

void create(){
    cout << "create함수 호출" << endl;
    CreateAndDestroy fifth{5, "fifth"};
    static CreateAndDestroy sixth{6, "sixth"};
    CreateAndDestroy seventh{7, "seventh"};
    cout << "create함수 종료" << endl;
}