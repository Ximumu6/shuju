#include<iostream>
#include<ctime>
using namespace std;
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}
int main() {
    int n = 10000;
    int* a = new int[n];
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        a[i] = rand() % n;
    }
    //测试顺序数组
    bubbleSort(a, n);
    //测试逆序数组
    for (int i = 0; i < n / 2; i++) {
        swap(a[i], a[n - i - 1]);
    }
    bubbleSort(a, n);
    //测试随机序列数组
    for (int i = 0; i < n; i++) {
        a[i] = rand() % n;
    }
    bubbleSort(a, n);
    delete[]a;
    return 0;
}

