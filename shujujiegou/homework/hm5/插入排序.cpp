#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <chrono>

using namespace std;

// �����������
void generateRandomArray(int arr[], int n) {
    srand(time(0));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % n + 1;
    }
}

// ������������
void generateReverseArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = n - i;
    }
}

// ˳�������Ѿ��ṩ����������

// ��ӡ����ǰn��Ԫ��
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// ��1����������
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// ��2����������
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// ��3��ѡ������
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }
    }
}

// �鲢������Ҫʹ�õݹ�ʵ�֣���Ҫ���丨������merge()
void merge(int arr[], int left, int mid, int right) {
    int len1 = mid - left + 1, len2 = right - mid;
    int* L = new int[len1];
    int* R = new int[len2];
    for (int i = 0; i < len1; i++) {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < len2; j++) {
        R[j] = arr[mid + j + 1];
    }
    int i = 0, j = 0, k = left;
    while (i < len1 && j < len2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }
    while (i < len1) {
        arr[k++] = L[i++];
    }
    while (j < len2) {
        arr[k++] = R[j++];
    }
    delete[] L, R;
}

// �鲢����
void mergeSort(int arr[], int left, int right) {
    if (left >= right) {
        return;  // �����л���ֻ��һ��Ԫ�ص����п���ֱ�ӷ���
    }
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);  // ������벿��
    mergeSort(arr, mid + 1, right);  // �����Ұ벿��
    merge(arr, left, mid, right);  // �����������ֹ鲢
}

// ����������Ҫʹ�õݹ�ʵ�֣���Ҫ���丨������partition()
int partition(int arr[], int left, int right) {
    int pivotIndex = left + rand() % (right - left + 1); // ���ѡ������Ԫ��
    int pivotValue = arr[pivotIndex];
    swap(arr[pivotIndex], arr[right]); // ������Ԫ�طŵ�����ĩβ
    int storeIndex = left;
    for (int i = left; i < right; i++) {
        if (arr[i] < pivotValue) {
            swap(arr[storeIndex], arr[i]);
            storeIndex++;
        }
    }
    swap(arr[right], arr[storeIndex]); // ������Ԫ�ػ���ȥ
    return storeIndex;
}
void mergesort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;
        mergesort(arr, l, m);
        mergesort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}
// ��������
void quickSort(int arr[], int left, int right) {
    if (left >= right) {
        return;
    }
    int pivotIndex = partition(arr, left, right);
    quickSort(arr, left, pivotIndex - 1);
    quickSort(arr, pivotIndex + 1, right);
}

// ��6����������Ҫ���丨������heapify()��buildHeap()
void heapify(int arr[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest]) {
        largest = l;
    }
    if (r < n && arr[r] > arr[largest]) {
        largest = r;
    }
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void buildHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
}

// ������
void heapSort(int arr[], int n) {
    buildHeap(arr, n);
    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}
void reverse(int arr[], int size)
{
    for (int i = 0; i < size / 2; ++i)
    {
        swap(arr[i], arr[size - i - 1]);
    }
}
void bak(int arr[], int arr2[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        arr2[i] = arr[i];
    }
}
int main()
{
    // ����һ������Ϊ1000��?int?����
    int arr[1000];
    // ��������������
    srand(time(NULL));
    for (int i = 0; i < 1000; ++i)
    {
        arr[i] = rand() % 1000;
    }
    // ��������
    int arr2[1000];
    bak(arr, arr2, 1000);
    // �ֱ���ð������ѡ�����򡢲������򡢹鲢���򡢿������������������򣬲����?ÿ�������㷨������ʱ��,��λΪ����
    cout << "����������飺" << endl;
    auto start = chrono::steady_clock::now();
    bubbleSort(arr, 1000);
    auto end = chrono::steady_clock::now();
    cout << "ð��������ʱ��" << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << "ns" << endl;
    bak(arr2, arr, 1000);
    start = chrono::steady_clock::now();
    selectionSort(arr, 1000);
    end = chrono::steady_clock::now();
    cout << "ѡ��������ʱ��" << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << "ns" << endl;
    bak(arr2, arr, 1000);
    start = chrono::steady_clock::now();
    insertionSort(arr, 1000);
    end = chrono::steady_clock::now();
    cout << "����������ʱ��" << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << "ns" << endl;
    bak(arr2, arr, 1000);
    start = chrono::steady_clock::now();
    mergesort(arr, 0, 999);
    end = chrono::steady_clock::now();
    cout << "�鲢������ʱ��" << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << "ns" << endl;
    bak(arr2, arr, 1000);
    start = chrono::steady_clock::now();
    quickSort(arr, 0, 999);
    end = chrono::steady_clock::now();
    cout << "����������ʱ��" << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << "ns" << endl;
    bak(arr2, arr, 1000);
    start = chrono::steady_clock::now();
    heapSort(arr, 999);
    end = chrono::steady_clock::now();
    cout << "��������ʱ��" << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << "ns" << endl;
    // ˳������
    cout << "˳������:" << endl;
    start = chrono::steady_clock::now();
    bubbleSort(arr, 1000);
    end = chrono::steady_clock::now();
    cout << "ð��������ʱ��" << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << "ns" << endl;
    start = chrono::steady_clock::now();
    selectionSort(arr, 1000);
    end = chrono::steady_clock::now();
    cout << "ѡ��������ʱ��" << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << "ns" << endl;
    start = chrono::steady_clock::now();
    insertionSort(arr, 1000);
    end = chrono::steady_clock::now();
    cout << "����������ʱ��" << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << "ns" << endl;
    start = chrono::steady_clock::now();
    mergesort(arr, 0, 999);
    end = chrono::steady_clock::now();
    cout << "�鲢������ʱ��" << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << "ns" << endl;
    start = chrono::steady_clock::now();
    quickSort(arr, 0, 999);
    end = chrono::steady_clock::now();
    cout << "����������ʱ��" << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << "ns" << endl;
    start = chrono::steady_clock::now();
    heapSort(arr, 999);
    end = chrono::steady_clock::now();
    cout << "��������ʱ��" << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << "ns" << endl;
    // ��ת����
    reverse(arr, 1000);
    bak(arr, arr2, 1000);
    // ��������
    cout << "��������:" << endl;
    start = chrono::steady_clock::now();
    bubbleSort(arr, 1000);
    end = chrono::steady_clock::now();
    cout << "ð��������ʱ��" << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << "ns" << endl;
    bak(arr2, arr, 1000);
    start = chrono::steady_clock::now();
    selectionSort(arr, 1000);
    end = chrono::steady_clock::now();
    cout << "ѡ��������ʱ��" << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << "ns" << endl;
    bak(arr2, arr, 1000);
    start = chrono::steady_clock::now();
    insertionSort(arr, 1000);
    end = chrono::steady_clock::now();
    cout << "����������ʱ��" << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << "ns" << endl;
    bak(arr2, arr, 1000);
    start = chrono::steady_clock::now();
    mergesort(arr, 0, 999);
    end = chrono::steady_clock::now();
    cout << "�鲢������ʱ��" << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << "ns" << endl;
    bak(arr2, arr, 1000);
    start = chrono::steady_clock::now();
    quickSort(arr, 0, 999);
    end = chrono::steady_clock::now();
    cout << "����������ʱ��" << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << "ns" << endl;
    bak(arr2, arr, 1000);
    start = chrono::steady_clock::now();
    heapSort(arr, 999);
    end = chrono::steady_clock::now();
    cout << "��������ʱ��" << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << "ns" << endl;
    return 0;
}
