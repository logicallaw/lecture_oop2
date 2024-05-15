#include <iostream>
using namespace std;
class Node{
private:
    int element;
    Node* next;
    friend class S_LinkedList;
};
class S_LinkedList{
public:
    S_LinkedList();
    int List_size();
    bool Empty();
    void Print();
    void Append(int elem);
    int Delete(int idx);
    void Insert(int idx, int elem);
private:
    Node* head;
    Node* tail;
};
S_LinkedList::S_LinkedList() {
    head = NULL;
    tail = NULL;
}
int S_LinkedList::List_size(){
    int list_size = 0;
    if(!Empty()){
        Node* cur_node = head;
        while(cur_node->next != NULL){
            list_size++;
            cur_node = cur_node->next;
        }
        list_size++;
        return list_size;
    }
    else{
        return list_size;
    }
}
bool S_LinkedList::Empty(){
    return (head == NULL && tail == NULL)
}
void S_LinkedList::Print(){
    if(!Empty()){
        Node* cur_node = head;
        while(cur_node->next != NULL){
            cout << cur_node->element << " ";
            cur_node = cur_node->next;
        }
        cout << cur_node->element << endl;
    }
    else{
        cout << "Empty" << endl;
    }
}
void S_LinkedList::Append(int elem) {
    Node* new_node = new Node();
    new_node->element = elem;
    new_node->next = NULL;
    if(!Empty()){
        tail->next = new_node;
        tail = tail->next;
    }
    else{
        head = new_node;
        tail = new_node;
    }
}
int S_LinkedList::Delete(int idx) {
    int removeNum = 0;
    int cnt = 0;
    Node* cur_node;
    Node* pre_node;
    if(Empty() || List_size() <= idx){
        return -1;
    }
    else if(idx == 0){
        if(List_size() == 1){
            removeNum = head->element;
            tail = NULL;
            head = NULL;
        }
        else {
            cur_node = head;
            removeNum = cur_node->element;
            head = cur_node->next;
        }
    }
    else{
        pre_node = cur_node = head;
        while(cnt != idx){
            pre_node = cur_node;
            cur_node = cur_node->next;
            cnt++;
        }
        removeNum = cur_node->element;
        pre_node->next = cur_node->next;
        if(cur_node == tail){
            tail = pre_node;
        }
    }
    return removeNum;
}
void S_LinkedList::Insert(int idx, int elem) {
    Node* new_node = new Node();
    new_node->element = elem;

    Node* pre_node;
    Node* cur_node;
    int cur_idx = 0;
    if(idx == 0){
        if(Empty()){
            head = new_node;
            tail = new_node;
        }
        else {
            new_node->next = head;
            head = new_node;
        }
    }
    else if(idx < 0 || idx > List_size()){
        cout << "Index Error" << endl;
    }
    else if(idx == List_size()){
        Append(elem);
    }
    else{
        pre_node = cur_node = head;
        while(cur_idx != idx){
            pre_node = cur_node;
            cur_idx = cur_node->next;
            cur_idx++;
        }
        pre_node -> next = new_node;
        new_node -> next = cur_node;
    }
}
int main(void){

}