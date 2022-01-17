#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int num) {
    if (num==1) return false;
    if (num==2 || num==3) return true;
    int snum = sqrt(num);
    for (int j=2; j<=snum; j++)
        if (num % j == 0)
            return false;
    return true;
}

int main() {
    int count = 0;
    cin >> count;

    int num, result = 0;
    for (int i=0; i<count; i++) {
        cin >> num;
        if (isPrime(num))
            result++;
    }
    cout << result << "\n";
    return 0;
}
