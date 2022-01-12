#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int> &v) {
    cout << "selectionSort" << endl;
    for(int i = 0; i < v.size()-1; i++) {
        int tmp = i;
        for (int j = i+1; j < v.size(); j++)
            if (v[tmp] > v[j]) tmp = j;
        swap(v[i], v[tmp]);
    }
}

void insertionSort(vector<int> &v) {
    cout << "insertionSort" << endl;
    for (int i = 1; i < v.size(); i++) {
        int key = v[i], c = i-1;
        while(key < v[c] && c >= 0) {
            swap(v[c], v[c+1]);
            c--;
        }
    }
}

void bubbleSort(vector<int> &v) {
    cout << "bubbleSort" << endl;
    for (int i = 1; i < v.size(); i++) {
        for (int j = 0; j < v.size()-i; j++) {
            if (v[j]>v[j+1])    swap(v[j], v[j+1]);
        }
    }
}

void qsort(vector<int> &v, int l, int r) {
    int pivot = v[l];
    int bl = l, br = r;
    while (l<r) {
        while (pivot <= v[r]&&l<r) r--;
        if (l>r) break;
        while (pivot >= v[l]&&l<r) l++;
        if (l>r) break;
        swap(v[l], v[r]);
    }
    swap(v[bl], v[l]);
    if(bl<l)
        qsort(v,bl,l-1);
    if(br>r)
        qsort(v,l+1,br);
}

int main() {
    int n, i, a;
    vector<int> v;

    cin >> n;
    for (i=0; i < n; i++) {
        cin >> a;
        v.push_back(a);
    }

    int choice;
    cout << "1. selectionSort\n" << "2. insertinSort\n" << "3. bubbleSort\n" << "4. quickSort\n";
    cout << "정렬 알고리즘 선택 >>> ";
    cin >> choice;

    switch (choice) {
        case 1:
            selectionSort(v);
            break;
        case 2:
            insertionSort(v);
            break;
        case 3:
            bubbleSort(v);
            break;
        case 4:
            cout << "quickSort\n";
            qsort(v, 0, v.size()-1);
            break;
        default:
            cout << "정렬 취소" << endl;
            break;
    }

    for (int i=0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;

    return 0;
}

/* input ex
5
20 10 35 30 7
 */
