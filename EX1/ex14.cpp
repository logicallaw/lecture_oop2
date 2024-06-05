    #include <iostream>
    using namespace std;
    template<typename T>
    class MyData{
    private:
        T data;
    public:
        explicit MyData(T value) : data { value } {}
        T getData() const { return data; }
    };

    template<>
    class MyData<char*>{
    private:
        char* data;
    public:
        explicit MyData(const char* value) : data{ new char[strlen(value) + 1]} {
            strcpy(data, value);

        }
        const char* getData() const { return data; }
        ~MyData() { delete[] data; }
    };

    int main(void){
        cout << MyData<int>(5).getData() << endl;
        cout << MyData<char*>("dlwlrma").getData() << endl;
    }