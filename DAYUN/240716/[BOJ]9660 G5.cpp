#include <iostream>

using namespace std;

int main() {
    long long int input;
    cin >> input;
    int m = input % 7;
    if(m == 0 || m == 2) cout << "CY\n";
    else cout << "SK\n";
}
