#include <iostream>
using namespace std;

int factorial(int n) {
    if(n > 1) return n * factorial(n - 1);
    else return 1;
}

int main() {
    int num;
    cin >> num;

    int sum = factorial(num);
    cout << sum;
    return 0;
}
