#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef struct lec {
    int p;
    int d;

    bool operator<(const lec& temp) const {
        if( d == temp.d) {
            return p < temp.p;
        }
        return d > temp.d;
    }
}lec;

int main()
{
    int n;
    cin >> n;

    priority_queue<lec> lecs;
    priority_queue<int,vector<int>,greater<int>> pays;

    for(int i = 0; i < n; i++)
    {
        int p, d;
        cin >> p >> d;
        lecs.push({p, d});
    }


    int day = 1;
    pays.push(0);

    while(!lecs.empty())
    {
        lec l = lecs.top();
        if(day == l.d)
        {
            if(l.p > pays.top())
            {
                pays.pop();
                pays.push(l.p);
            }
            lecs.pop();
        }
        else
        {
            pays.push(0);
            day++;
        }

    }

    int sum = 0;
    while(!pays.empty())
    {
        sum += pays.top();
        pays.pop();
    }

    cout <<sum ;
}

