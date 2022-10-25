#include <iostream>
using namespace std;
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

void heapsort(int a[],int n,int& count_cmp,int& count_as){
	count_cmp = count_as = 0;
	// heapsort
	int pos = n / 2 - 1; ++count_as;
	while (++count_cmp && pos >= 0) {
		bool isheap = false; ++count_as;
		int x = pos; ++count_as;
		while (++count_cmp && isheap == false && ++count_cmp && 2 * x + 1 < n) {
			int j = 2 * x + 1; ++count_as;
			if (++count_cmp && j < n - 1 && ++count_cmp && a[j] < a[j + 1]) {
				j++; ++count_as;
			}
			if (++count_cmp && a[x] >= a[j]) {
				isheap = true; ++count_as;
			}
			else {
				swap(a[x], a[j]); count_as += 3;
				x = j; ++count_as;
			}
		}
		pos--; ++count_as;
	}
	int m = n - 1; ++count_as;
	while (++count_cmp && m > 0) {
		swap(a[0], a[m]); count_as += 3;
		bool isheap = false; ++count_as;
		pos = 0; ++count_as;
		while (++count_cmp && isheap == false && ++count_cmp && 2 * pos + 1 < m) {
			int j = 2 * pos + 1; ++count_as;
			if (++count_cmp && j < m - 1 && ++count_cmp && a[j] < a[j + 1])  j++;
			if (++count_cmp && a[pos] >= a[j]) {
				isheap = true; ++count_as;
			}
			else {
				swap(a[pos], a[j]); count_as += 3;
				pos = j; ++count_as;
			}
		}
		m--;
	}
}
