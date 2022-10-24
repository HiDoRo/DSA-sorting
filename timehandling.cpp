#include <algorithm>
#include <chrono>
#include <iostream>
#include<vector>
#include <map>
#include <string>
using namespace std;
using namespace std::chrono;
void bubbleSort(int a[], int n) {
    cout<<"Bubble Sort"<<endl;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

void selectionSort(int a[], int n) {
    cout<<"Selection Sort"<<endl;
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[min]) {
                min = j;
            }
        }
        int temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
}

auto TimeCalculate(void (*sort)(int[], int), int a[], int n) {
    auto start = chrono::high_resolution_clock::now();
    sort(a, n);
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    return duration.count();
}  

int main()
{
    map<string, void(*)(int[], int)> m;
    m["selection_sort"] = selectionSort;
    m["bubble_sort"] = bubbleSort;
    int a[100000];
    int n=1000;
    for (int i = 0; i < n; i++)
    {
        a[i]=n-i;
    }
    cout<<TimeCalculate(m["selection_sort"],a,n);

}