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
        int key = v[i], j = i-1;
        while(j >= 0 && key < v[j]) {
            swap(v[j], v[j+1]);
            j--;
        }
        v[j+1] = key;
    }
}

void bubbleSort(vector<int> &v) {
    cout << "bubbleSort" << endl;
    for(int i=0; i<v.size()-1; i++) {
        for(int j = 0; j < v.size()-i; j++) {
            if(v[j-1] > v[j])
                swap(v[j-1],v[j]);
        }
    }
}

void qsort(vector<int> &v, int s, int e) {
    int pivot = v[s];
    int bs = s, be = e;
    while (s<e) {
        while (pivot <= v[e]&&s<e) e--;
        if (s>e) break;
        while (pivot >= v[s]&&s<e) s++;
        if (s>e) break;
        swap(v[s], v[e]);
    }
    swap(v[bs], v[s]);
    if(bs<s)
        qsort(v,bs,s-1);
    if(be>e)
        qsort(v,s+1,be);
}

int main() {
    int n, i, a;
    vector<int> v;

    cin >> n;
    for (i=0; i < n; i++) {
        cin >> a;
        v.push_back(a);
    }

//    selectionSort(v);
//    insertionSort(v);
//    bubbleSort(v);
    qsort(v, 0, v.size()-1);

    for (int i=0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;

    return 0;
}

