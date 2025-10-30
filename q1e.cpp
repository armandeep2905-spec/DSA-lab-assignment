#include <iostream>
using namespace std;

int partition(int a[], int low, int high) {
    int p = a[high], i = low - 1;
    for (int j = low; j < high; j++)
        if (a[j] < p)
            swap(a[++i], a[j]);
    swap(a[i + 1], a[high]);
    return i + 1;
}

void quickSort(int a[], int low, int high) {
    if (low < high) {
        int pi = partition(a, low, high);
        quickSort(a, low, pi - 1);
        quickSort(a, pi + 1, high);
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int a[n];

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> a[i];

    quickSort(a, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) cout << a[i] << " ";
}
