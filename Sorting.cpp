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

// 차례대로 분할, 병합 함수
int arr[1000001], arr2[1000001];
void merge(int left, int right)
{
    int mid = (left + right) / 2;

    int i = left;
    int j = mid + 1;
    int k = left;
    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
            arr2[k++] = arr[i++];
        else
            arr2[k++] = arr[j++];
    }

    int tmp = i>mid ? j : i;

    while(k<=right) arr2[k++] = arr[tmp++];

    for (int i=left;i<=right;i++) arr[i] = arr2[i];
}

void partition(int left,int right)
{
    int mid;
    if (left < right)
    {
        mid = (left + right) / 2;
        partition(left, mid);
        partition(mid + 1, right);
        merge(left, right);
    }
}

int countarr[10001] = { 0 };
void countSort(int n) {
    for (int i=0; i < n; i++)
        countarr[arr[i]]++;
    for (int i=0; i <= 10000; i++)
        while(countarr[i] != 0) {
            cout << i << "\n";
            countarr[i]--;
        }
}

int main() {
    int n, i, a;
    vector<int> v;

    cin >> n;
    for (i=0; i < n; i++) {
        cin >> a;
        v.push_back(a);
        arr[i] = a;
    }

    int choice;
    cout << "1. selectionSort\n" << "2. insertinSort\n" << "3. bubbleSort\n" << "4. quickSort\n" << "5. mergeSort\n" << "6. countSort(숫자 범위 <= 10000)";
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
        case 5:
            cout << "mergeSort\n";
            partition(0, n-1);
            break;
        case 6:
            cout << "countSort\n";
            countSort(n);
            break;
        default:
            cout << "정렬 취소" << endl;
            break;
    }
    if (choice < 5) {
        for (int i=0; i < n; i++)
            cout << v[i] << " ";
        cout << endl;
    } else if (choice == 5){
        for (int i=0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    return 0;
}

/* input ex
5
20 10 35 30 7
 */
