#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Brand {
private:
    int* pId = new int{ 0 }; //integer pointer; deep copy
    string brandName{ "noname" };
    string modelName{ "noname" };
public:
    Brand() = default;
    Brand(int* pId, string brandName, string modelName)
            : brandName{ brandName }, modelName{ modelName } {
        *(this->pId) = *pId;
    }
    ~Brand() {
        delete[] pId;
    }

    void setId(int* pId) { *(this->pId) = *pId; }
    void setBrandName(string brandName) { this->brandName = brandName; }
    void setModelName(string modelName) { this->modelName = modelName; }

    int* getId() const { return pId; } //return pointer.
    string getBrandName() const { return brandName; }
    string getModelName() const { return modelName; }

};

class Information {
private:
    int year{ 0 };
    double kilometers{ 0.0 };
    int* pPrice = new int{ 0 }; //integer pointer; deep copy
public:
    Information() = default;
    Information(int year, double kilometers, int* pPrice)
            : year{ year }, kilometers{ kilometers } {
        *(this->pPrice) = *pPrice;
    }
    ~Information() {
        delete[] pPrice;
    }

    void setYear(int year) { (this->year) = year; }
    void setKilometers(double kilometers) { (this->kilometers) = kilometers; }
    void setPrice(int* pPrice) { *(this->pPrice) = *pPrice; }

    int getYear() const { return year; }
    double getKilometers() const { return kilometers; }
    int* getPrice() const { return pPrice; } //return pointer.

};

class Car {
private:
    Brand _brand; //default constructor
    Information _info; //default constructor
public:
    Car(const Brand& brand, const Information& info) {
        _brand.setId(brand.getId());
        _brand.setBrandName(brand.getBrandName());
        _brand.setModelName(brand.getModelName());

        _info.setYear(info.getYear());
        _info.setKilometers(info.getKilometers());
        _info.setPrice(info.getPrice());
    }

    Car(const Car& origin) {
        _brand.setId((origin._brand).getId());
        _brand.setBrandName((origin._brand).getBrandName());
        _brand.setModelName((origin._brand).getModelName());

        _info.setYear((origin._info).getYear());
        _info.setKilometers((origin._info).getKilometers());
        _info.setPrice((origin._info).getPrice());
    }

    void printBrand() const {
        cout << "Brand | Id = " << *(_brand.getId())
             << ", brandName = " << _brand.getBrandName()
             << ", modelName = " << _brand.getModelName() << endl;
    }
    void printInformation() const {
        cout << "Information | Year = " << _info.getYear()
             << ", kilometers = " << _info.getKilometers()
             << ", price = " << *(_info.getPrice()) << endl;
    }
};

int menu();
void createNewRecord(vector<Car>& record);
void printAllTheRecords(const vector<Car>& record);

int main(void) {
    //create a record vector.
    vector<Car> record;

    int inputNumber = menu();
    while (inputNumber != 3) {
        switch (inputNumber) {
            case 1:
                createNewRecord(record);
                break;
            case 2:
                printAllTheRecords(record);
                break;
        }
        inputNumber = menu();
    }
    cout << "The program is over." << endl;
    return 0;
}

int menu() {
    int inputNumber;
    cout << "1. Create a new record.\n";
    cout << "2. Print all the records.\n";
    cout << "3. Exit\n";
    cout << ">> ";
    cin >> inputNumber;
    return inputNumber;
}

void createNewRecord(vector<Car>& record) {
    cout << "You chose the menu 1." << endl;
    /*input information about Brand object*/
    //declare variables
    int* pId = new int{ 0 };
    string brandName;
    string modelName;
    //input
    cout << "input ID(int): ";
    cin >> *pId;
    cout << "input brand name(string): ";
    cin >> brandName;
    cout << "input model name(string): ";
    cin >> modelName;

    //create Brand object by using parameter constructor.
    Brand brand{ pId, brandName, modelName };

    /*input information about Information object*/
    //declare variables
    int year;
    double kilometers;
    int* pPrice = new int{ 0 }; //integer pointer
    //input
    cout << "input year(int): ";
    cin >> year;
    cout << "input kilometers(double): ";
    cin >> kilometers;
    cout << "input price(int): ";
    cin >> *pPrice;
    //create Information object by using parameter constructor.
    Information info{ year, kilometers, pPrice };

    /*---*/
    //pass-by-value; copy-constructor.
    Car car = Car{ brand, info };
    record.push_back(car);

    /*delete[] pId, pPrice*/
    delete[] pId;
    delete[] pPrice;
}

void printAllTheRecords(const vector<Car>& record) {
    //print all elements in the record vector printing out the attributes of Brand and Information objects
    //by using for-loop.
    for (int i{ 0 }; i < record.size(); i++) {
        if (i == 0) { cout << "--------------------" << endl; }
        cout << "record[" << i << "]" << endl;
        record[i].printBrand();
        record[i].printInformation();
        cout << "--------------------" << endl;
    }
}