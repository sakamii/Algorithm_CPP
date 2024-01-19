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
    int priority;
    Node* next;
    Node(int p, int i){item=i; priority=p; next=nullptr;}

};
class PriorityQueue{
    public:
    int size = 0;
    Node* head;

    PriorityQueue() : head(nullptr), size(0) {}

    ~PriorityQueue() {
        while (head != nullptr) {
            pop();
        }
    }

    void push(int priority, int item){
        Node *newNode = new Node(priority,item);
        if(head == nullptr || head->priority > priority){
            /*
            만일 head가 비어있거나, head보다 priority가 높다면
            head를 newNode로 교체한다. 여기서는 priority값이 작으면 높은 우선순위를 가진다고 가정한다.
            */
            newNode->next = head;
            head = newNode;
        }
        else{
            Node* current = head;
            //newNode의 우선순위가 current보다 커지는(priority의 값이 더 작아지는)구간의 current를 탐색.
            while(current->next != nullptr && current->next->priority <= newNode->priority){
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
        size += 1;
    }
    void pop() {
        if (head == nullptr) {
            std::cout << "Queue is empty." << std::endl;
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;
        size -= 1;
    }
    int front() {
        if (head == nullptr) {
            std::cout << "Queue is empty." << std::endl;
            return -1;
        }
        return head->item;
    }
    int getSize(){
        return size;
    }

};
int main(){
    PriorityQueue pq;
    pq.push(3, 1);
    pq.push(2, 2);
    pq.push(4, 3);
    pq.push(1, 4);

    cout << "Front item: " << pq.front() << endl;
    cout << "Size: " << pq.getSize() << endl;
    pq.pop();
    cout << "Front item after one pop: " << pq.front() << endl;
    cout << "Size: " << pq.getSize() << endl;
    return 0;
}