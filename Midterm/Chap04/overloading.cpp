#include <iostream>
using namespace std;
class Tmp{
private:
    int x,y;
    friend ostream& operator<<(ostream& out, const Tmp& right);
    friend istream& operator>>(istream& in, Tmp& right)

public:
    Tmp(){}
    Tmp(int x) : x { x } {}
    Tmp operator+(const Tmp& right){
        return Tmp{x + right.x};
    }
    Tmp operator-(const Tmp& right){
        return Tmp{x - right.x};
    }
    bool operator==(const Tmp& right){
        return (x == right.x);
    }
    bool operator!=(const Tmp& right){
        return (x != right.x);
    }
    Tmp& operator+=(const Tmp& right){
        x += right.x;
        return *this;
    }
    Tmp& operator++(){ //전위증가
        ++x;
        return *this;
    }
    Tmp operator++(int){ //후위증가
        Tmp temp{*this};
        x++;
        return temp;
    }
    int getX() const { return x; }
};

ostream& operator<<(ostream& out, const Tmp& right){
    out << right.x << " " << right.y << endl;
    return out;
}

istream& operator>>(istream& in, Tmp& right){
    in >> right.x;
    in >> right.y;
    return in;
}

int main(void){
    Tmp t;
    cin >> t;
    cout << t;
    return 0;
}