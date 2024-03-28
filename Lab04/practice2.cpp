#include <iostream>
#include <cstring>
using namespace std;
class Server{
private:
    char* modelName;
    int serialNumber;
    int OSVersion;
    int lastMaintanenceDay;
    static int lastOSUpdateDay;
public:
    Server(const char* name, int serial, int version, int lastday);
    Server& updateMaintanenceDay(int day);
    void updateSerialNumber(int serialNumber);
    static void updateOSUpdateDay(int day);
    int getOSUpdateDay();
};

int Server::lastOSUpdateDay{ 0 };
void Server::updateOSUpdateDay(int day) {
    lastOSUpdateDay = day;
}

Server::Server(const char *name, int serial, int version, int lastday)
    : modelName{ new char[strlen(name) + 1]}, serialNumber{ serial }, OSVersion{ version}, lastMaintanenceDay{ lastday } {
    for (int i{0}; i < strlen(name); i++) {
        modelName[i] = name[i];
    }
    modelName[strlen(name)] = '\0';
}
Server& Server::updateMaintanenceDay(int day) {
    this->lastMaintanenceDay = day;
    return *this;
}
void Server::updateSerialNumber(int serialNumber) { this->serialNumber = serialNumber; }
int Server::getOSUpdateDay() { return lastOSUpdateDay; }

int main(){
    Server s1{ "server0", 0, 10, 1};
    Server s2{ "server1", 1, 10, 1};
    Server s3{ "server2", 2, 20, 1};

    s1.updateMaintanenceDay(3);
    s2.updateSerialNumber(4);
    s3.updateMaintanenceDay(3).updateOSUpdateDay(5);
    cout << "The last day OS was updated is "
         << s1.getOSUpdateDay() << endl;
    return 0;
}