#include <cstdio>
#include <iostream>
#include <algorithm>
#include <random>

#define KRED  "\x1B[31m"
#define RESET "\x1B[0m"

using namespace std;

void print(int *arr, int sz, int left, int right)
{
    int i = 0;
    while (i < sz) {
        if (i == left || i == right)
            printf(KRED "%d" RESET " ", arr[i++]);
        else
            printf("%d ", arr[i++]);
    }
    cout << endl;
}

int partition(int* arr, int left, int right)
{
    int pivot = left;
    int i = left + 1;
    int j = right;
    while (i < j) {
        while (i <= j && arr[i] <= arr[pivot]) i++;
        while (i <= j && arr[j] > arr[pivot]) j--;
        if (i < j) swap(arr[i], arr[j]);
    }
    swap(arr[i - 1], arr[pivot]);

    return i - 1;
}

void quicksort(int *arr, const int left, const int right, const int sz)
{
    if (left >= right) return;

    printf("left: %d, right: %d | ", left, right);
    print(arr, sz, left, right);
    int part = partition(arr, left, right);

    quicksort(arr, left, part - 1, sz);
    quicksort(arr, part + 1, right, sz);
}

int main()
{
    int arr[8] = {110, 5, 10,3 ,22, 100, 1, 23};
    int sz = sizeof(arr) / sizeof(arr[0]);
    cout << "before: "; print(arr, sz, 0, sz - 1); cout << "\n";

    quicksort(arr, 0, sz - 1, sz);

    cout << "\nafter : "; print(arr, sz, 0, sz - 1);

}