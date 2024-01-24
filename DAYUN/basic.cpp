#include <iostream>
#include <queue>
#include<stack> 
#include <vector>
#include <algorithm>

using namespace std;

void queue_discription();
void stack_discription();
void vector_discription();
void priorityQueue_discription();
void algorithm_discription();

typedef struct pq_edge {
	int v, c, k;
	bool operator < (const pq_edge& temp) const
	{
		return c > temp.c;
	}
} pq_edge;

typedef struct algorithm_sort_struct {
	int a, b, c;
}algorithm_sort_struct;

bool algorithm_sort_cmp(algorithm_sort_struct& a, algorithm_sort_struct& b)
{
	if (a.a < b.a) return true;
	return false;
}


int main()
{
	priorityQueue_discription();

	return 0;
}

void queue_discription() {
	queue<string> q;
	q.push("first");
	q.push("second");
	q.emplace("third");
	//"third"
	cout << q.back() << endl;
	//3
	cout << q.size() << endl;
	while (!q.empty()) {
		//first second third
		cout << q.front() << " ";
		q.pop();
	}
	cout << endl;


	queue<int> q1, q2;
	q1.push(1);
	q1.push(2);
	q2.push(2);
	q2.push(1);
	// all of queue, sequence 
	if (q1 == q2) {
		cout << "equal" << endl;
	}
	//front() value
	if (q1 < q2) {
		cout << "q2 is bigger" << endl;
	}
	q1.swap(q2);
}

void stack_discription() {
	stack<string> s;
	s.push("one");
	s.emplace("two");
	//2
	cout << s.size() << endl;
	while (!s.empty()) {
		//LIFO :  two , one 
		cout << s.top() << " ";
		s.pop();
	}
	cout << endl;

	stack<string> s1, s2;
	s1.push("a");
	s1.push("b");
	s2.push("c");
	s2.push("d");
	s1.swap(s2);
	//d
	cout << s1.top() << endl;

}

void vector_discription() {
	vector<string> v = { "1", "2" };
	vector<string> vOperation;
	vector<string> vassign;

	// = : copy data from v
	vOperation = v;

	//ASSIGN : vasssign = {"assign", "assign", "assign" };
	vassign.assign(3, "assign");

	// SWAP
	v.swap(vassign);

	// ERASE : 
	v.erase(v.begin() + 1);
	v.erase(v.begin() + 0, v.begin() + 1);

	//PUSH_BACK, EMPLACE_BACK
	v.push_back("puch_back");
	v.emplace_back("emplace_back");
	// INSERT, EMPLACE
	v.insert(v.begin(), "insert");
	v.emplace(v.begin() + 1, "emplace");
	// AT
	v.at(1) = "at";

	// RESIZE
	v.resize(v.size() + 1);
	v[5] = "Resize";


	// POP_BACK, "Resize" pop
	v.pop_back();

	//FRONT, "front" 
	string v_front = v.front();

	// BACK, "emplace_back"
	string v_back = v.back();

	// Empty : v.empty()w
	while (!v.empty())
	{
		cout << v.front() << " ";
		v.erase(v.begin());
	}

	// CLEAR
	v.clear();
}

void priorityQueue_discription() {
	vector<int> data = { 2, 5, 6, 7 ,1 ,8, 9, 0 };
	// auto desc sort c desc
	priority_queue<int> pq;
	// sort : pq_edge operation
	priority_queue<pq_edge> edge_que;
	// ASC
	priority_queue<int, vector<int>, greater<int>> ascq(data.begin(), data.end());


	for (int i : data)
	{
		pq.push(i);
		ascq.push(-i);
	}

	while (!ascq.empty())
	{
		// couut << pq[pq.size() - 1] << " ";
		cout << ascq.top();
		ascq.pop();
	}
}

void algorithm_discription() {
	// vector , array sort
	vector<int> data = { 2, 5, 0, 7 ,1 ,8, 9, 0 };

	// FIND
	// find : return Address not find : return End address 
	// if(find(data.begin(), data.end(), 10) != data.end()) 
	if (binary_search(data.begin(), data.end(), 10))
	{
		cout << "Contain";
	}

	// COPY
	vector<int> copy_vector;
	copy_vector.resize(data.size());
	copy(data.begin(), data.end(), copy_vector.begin());

	// MOVE (C++ 11)
	vector<int> move_vector = { 1, 2, 3 };
	data.resize(data.size() + move_vector.size());
	move(move_vector.begin(), move_vector.end(), data.end() - move_vector.size());

	//SORT
	sort(data.begin(), data.end());
	//SORT  
	vector<algorithm_sort_struct> data2(3);
	data2 = {
		{1, 2, 3},
		{3, 1, 2},
		{2, 3, 1}
	};
	sort(data2.begin(), data2.end(), algorithm_sort_cmp);

	// MAX MIN
	// cout << *min_element(data.begin(), data.end()) << endl;
	// cout << *max_element(data.begin(), data.end()) << endl;

	//INNER PRODUCT {2, 2, 2, 2, 2}
	vector<int> v(5, 2);
	vector<int> v2(20);
	// set_union(data.begin(), data.end(), v.begin(), v.end(), v2.begin()) ;
	// set_intersection(data.begin(), data.end(), v.begin(), v.end(), v2.begin()) ;

	// REVERSE
	reverse(data.begin(), data.end());

	//UNIQUE
	unique(data.begin(), data.end());

	// FILL
	fill(v2.begin(), v2.end(), 1);

	for (int i = 0; i < data.size(); i++)
	{
		cout << data[i] << " ";
	}
	cout << endl;
}