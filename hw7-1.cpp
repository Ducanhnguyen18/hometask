#include <iostream>
using namespace std;

void bubble_sort(int n, int* a) {
    for (int j = n-1; j > 0; j--) { 
        for (int i = 0; i < j; i++) { 
            if (a[i] > a[i+1]) {
                int x = a[i];
                a[i] = a[i+1];
                a[i+1] = x;
            }
        }
    }
}

void disp(const int n, const int* a) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main() {
    cout << "Input number of elements: ";
    int n; cin >> n;
    if (n <= 0) {
        cout << "Error: invalid number of elements" << endl;
        return -1;
    }
    cout << "Input array: ";
    int *a = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    
    bubble_sort(n, a);
    
    disp(n, a);
    delete[] a;
    return 0;
}