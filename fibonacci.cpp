#include <iostream>
using namespace std;

int fibonacci(int n) {
    if ( n <= 1 )
        return n;
    return fibonacci(n-1) + fibonacci(n-2);
}

int main() {
    int num;
    cin >> num;

    int result = fibonacci(num);
    cout << result;
    return 0;
}
