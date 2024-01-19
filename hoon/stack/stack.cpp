#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <deque>
#include <math.h>
#include <string>
#include <iostream>

using namespace std;

class Node{
    public:
    int item;
    Node* next;
    Node(){item=0; next=nullptr;}

};
class Stack{
    private:
        int stackSize;
        Node* top;
    public:
    Stack(){
        top = nullptr;
        stackSize = 0;
    }
    void push(int x){
        Node* newNode = new Node();
        if(!newNode){
            cout << "Heap overflow";
            exit(1);
        }

        newNode->item = x;
        newNode->next = top;
        top = newNode;
        stackSize++;
    }

    void pop() {
        if(isEmpty()){
            cout << "Stack underflow!" << endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
        stackSize--;
    }

    int getTop(){
        if(!isEmpty()){
            return top->item;
        }
        else{
            cout << "Stack is empty!" << endl;
            exit(1);
        }
    }

    bool isEmpty() {
        return top == nullptr;
    }

    int size() {
        return stackSize;
    }
};
int main(){
    Stack S;
    S.push(2); S.push(5); S.push(10);
    cout << "Size: " << S.size() << "\n";
    while(!S.isEmpty()) {
        cout << S.getTop() << "\n";
        S.pop();
    }
    cout << "Size: " << S.size() << "\n";
}