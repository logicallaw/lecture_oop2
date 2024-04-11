//vector에 업캐스팅한 자식클래스를 담고
//오버라이딩된 함수를 통일성 있게 호출한다.
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;
class Tmp{
private:
    int age;
    string name;
    string city;
public:
    Tmp(int age, string name, string city)
        : age{ age }, name{ name }, city{ city } {}

    virtual string getInfo() const{
        ostringstream output;
        output << "age: " << age << endl;
        output << "name: " << name << endl;
        output << "city: " << city << endl;
        return output.str();
    }
};

class School:public Tmp{
private:
    string schoolName;
public:
    School(int age, string name, string city, string schoolName)
        : Tmp{ age, name, city }, schoolName{ schoolName }{}

    string getSchoolName() const{ return "school: "+ schoolName; }
    virtual string getInfo() const override{
        return Tmp::getInfo() + getSchoolName();
    }
};
class SubTmp: public Tmp{
private:
    string subName;
public:
    SubTmp(int age, string name, string city, string subName)
        : Tmp{ age, name, city }, subName{ subName } {}

    string getSubName() const{ return "subName: " + subName; }
    virtual string getInfo() const override{
        return Tmp::getInfo() + getSubName();
    }
};
class Sub1Tmp: public Tmp{
private:
    string sub1Name;
public:
    Sub1Tmp(int age, string name, string city, string sub1Name)
            : Tmp{ age, name, city }, sub1Name{ sub1Name } {}

    string getSub1Name() const{ return "sub1Name: " + sub1Name; }
    virtual string getInfo() const override{
        return Tmp::getInfo() + getSub1Name();
    }
};
int main(void){
    vector<Tmp*> v1;

    School s1{ 20, "junho", "incheon", "inha"};
    SubTmp s2{ 25, "kim", "seoul", "john"};
    Sub1Tmp s3{ 23, "jji", "busan", "kd"};

    v1.push_back(&s1);
    v1.push_back(&s2);
    v1.push_back(&s3);

    for(const Tmp* v : v1)
        cout << (v->getInfo()) << endl << endl;

    return 0;
}