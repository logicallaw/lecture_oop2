#include <iostream>
#include <cstring>
using namespace std;
class Server{
private:
    char *modelName;
    int serialNumber;
    int OSVersion;
    int lastMaintanenceDay;
    static int lastOSUpdateDay;
public:
    Server(char* name, int serial, int version, int lastday);
    void updateMaintanenceDay(int day);
    int getOSUpdateDay();
    static void updateOSUpdateDay(int day);
};

int Server::lastOSUpdateDay{ 0 };
void Server::updateOSUpdateDay(int day) { lastOSUpdateDay = day; }

Server::Server(char *name, int serial, int version, int lastday)
        : modelName{ new char[strlen(name) + 1] }, serialNumber{ serial }, OSVersion{ version }, lastMaintanenceDay{ lastday }{
    for (int i{ 0 }; i < strlen(name); i++){
        modelName[i] = name[i];
    }
    modelName[strlen(name)] = '\0';
}
void Server::updateMaintanenceDay(int day) {
    lastMaintanenceDay = day;
}
int Server::getOSUpdateDay() { return lastOSUpdateDay; }

int main(){
    Server s1{"server0", 0, 10, 1};
    Server s2{"server1", 1, 10, 1};
    Server s3{"server3", 2,20,1};

    s1.updateMaintanenceDay(3);
    s3.updateMaintanenceDay(5);
    s3.updateOSUpdateDay(5);
    cout << "The last day OS was updated is "
         << s1.getOSUpdateDay() << endl;
    return 0;
}