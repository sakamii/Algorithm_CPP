#include <iostream>
#include <queue>

using namespace std;

#define MAX 1000000001

struct node {
    int num;
    node *prev;
    node *next;
};

long long ret;
priority_queue< pair<int, node *> > s;
node nodeList[1010];
int cnt;




int find(int index);
int main() {
    int n;
    ret  = 0;
    cin >> n;

    int k;
    cin >> k;
    nodeList[cnt].num = k;
    nodeList[cnt].prev = nullptr;
    nodeList[cnt].next = nullptr;

    pair<int, node*> p;
    p.first = -k;
    p.second = &nodeList[cnt];
    s.push(p);
    node *pr = &nodeList[cnt++];
    for(int i = 1; i < n; ++i) {
        int kk;
        cin >> kk;
        if(k != kk) {
            nodeList[cnt].num = kk;
            nodeList[cnt].prev = pr;
            nodeList[cnt].next = nullptr;
            
            pr->next = &nodeList[cnt];
            pair<int, node *> p;
            p.first = -kk;
            p.second  = &nodeList[cnt];
            s.push(p);
            k = kk;
            pr = &nodeList[cnt++];
        }
    }

    while(!s.empty()) {
        int temp = -s.top().first;
        node *n = s.top().second;
        // cout << temp << "t ";
        // cout << ret << "r ";
        s.pop();

        int left = MAX;
        int right = MAX;
        if(n->prev != nullptr){
          left = n->prev->num;
        //   cout << left << "l ";  
        } 
        if(n->next != nullptr){
            right = n->next->num;
            // cout << right << "rr ";  
        
        }
        if(left < right) {
            ret += (left - temp);
            if(right == MAX) {
                n->prev->next = nullptr;
                continue;
            }
            else {
                n->prev->next = n->next;
                n->next->prev = n->prev;
            }
        }
        else if(right < left) {
            ret += (right - temp);
            if(left == MAX) {
                // cout << temp << ". ";
                n->next->prev = nullptr;
                continue;
            }
            else {
                n->prev->next = n->next;
                n->next->prev = n->prev;
            }
        }
        else {
            if(left == MAX) continue;
            ret += (left - temp);
            n->prev->next = n->next;
            n->next->prev = n->prev;
        }
    }

    cout << ret;
}