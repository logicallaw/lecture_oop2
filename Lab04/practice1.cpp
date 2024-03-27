#include <iostream>
#include <cstring>
using namespace std;
class Server{
private:
    char *modelName;
    int serialNumber;
    int OSVersion;
    int lastMaintanceDay;
    static int lastOSUpdateDay;
public:
    Server(char* name, int serial, int version, int lastday);

    void updateMaintanceDay(int day);
    int getOSUpdateDay();

    static void updateOSUpdateDay(int day);

};

int Server::lastOSUpdateDay{ 0 };
void Server::updateOSUpdateDay(int day) { lastOSUpdateDay = day; }

Server::Server(char *name, int serial, int version, int lastday)
    : modelName{ new char[strlen(name) + 1] }, serialNumber{ serial }, OSVersion{ version }, lastMaintanceDay{ lastday }{
    for (int i{ 0 }; i < strlen(name); i++){
        modelName[i] = name[i];
    }
    modelName[strlen(name)] = '\0';
}

void Server::updateMaintanceDay(int day) {
    lastMaintanceDay = day;
}

int Server::getOSUpdateDay() { return lastOSUpdateDay; }

int main(){
    Server s1{"server0", 0, 10, 1};
    Server s2{"server1", 1, 10, 1};
    Server s3{"server3", 2,20,1};

    s1.updateMaintanceDay(3);
    s3.updateMaintanceDay(5);
    s3.updateOSUpdateDay(5);
    cout << "The last day OS was updated is "
        << s1.getOSUpdateDay() << endl;
    return 0;
}