#include <iostream>
using namespace std;
class Node{
private:
    int element;
    Node* next;
    friend class S_LinkedList;
};
class S_LinkedList{
private:
    Node* head;
    Node* tail;
public:
    S_LinkedList(){
        head = NULL;
        tail = NULL;
    }
    void Print(){
        if(Empty()){
            cout << "empty" << endl;
        }
        else {
            Node* cur_node = head;
            while(cur_node->next != NULL){
                cout << cur_node->element << " ";
                cur_node = cur_node->next;
            }
            cout << cur_node->element << endl;
        }
    }
    bool Empty(){
        return head == NULL && tail == NULL;
    }
    void AddFront(int x){
        Node* new_node = new Node();
        new_node->element = x;
        if (Empty()){
            head = new_node;
        }
        else {
            new_node->next = head;
            head = new_node;
        }
    }
    void RemoveFront(){
        if(Empty()){
            cout << "empty" << endl;
        } else{
            int removeNum = head->element;
            head = head->next;
            cout << removeNum << endl;
        }
    }
    int List_size(){
        if(Empty()){
            return 0;
        }
        else{
            int size = 0;
            Node* cur_node = head;
            while(cur_node->next != NULL) {
                cur_node = cur_node->next;
                size++;
            }
            size++;
            return size;
        }
    }
    void Update(int i, int x){
        if(Empty() || i >= List_size()){
            cout << "error" << endl;
        }
        else {
            Node* cur_node = head;
            int cur_index = 0;
            while(cur_index < i){
                cur_node = cur_node->next;
                cur_index++;
            }
            cur_node -> element = x;
        }
    }
    void Min(){
        int minIndex = 0;
        if(Empty()){
            cout << "empty" <<endl;
        }
        else{
            int cur_Index = 0;
            int minValue = head->element;
            Node* cur_node = head->next;
            while(cur_node->next != NULL){
                cur_Index++;
                if (minValue > cur_node->element){
                    minValue = cur_node->element;
                    minIndex = cur_Index;
                }
            }
            cur_Index++;
            if (minValue > cur_node->element){
                minValue = cur_node->element;
                minIndex = cur_Index;
            }
            cout << minIndex << " " << minValue << endl;
        }
    }
};
int main(void){
    int m;
    cin >> m;
    S_LinkedList list{};
    while(m--){
        string userInput;
        cin >> userInput;
        if(userInput == "Print"){
            list.Print();
        }
        else if(userInput == "AddFront"){
            int temp;
            cin >> temp;
            list.AddFront(temp);
        }
        else if(userInput == "Min"){
            list.Min();
        }
        else if(userInput == "RemoveFront"){
            list.RemoveFront();
        }
        else if(userInput == "Update"){
            int i, x;
            cin >> i >> x;
            list.Update(i,x);
        }
        else{
            cout << "userInput Error" << endl;
        }
    }
}