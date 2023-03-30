#include "vector.h"

template<typename T>
void Vector<T>::copyFrom(T const *A, Rank l, Rank h) {
    _elem = new T[_capacity = 2 * (h - l)];
    _size = 0;
    while (l < h)
        _elem[_size++] = A[l++];
}

template<typename T>
void Vector<T>::expand() {
    if (_size < _capacity) return;
    if (_capacity < DEFAULT_CAPACITY) _capacity = DEFAULT_CAPACITY;
    T *oldElem = _elem;
    _elem = new T[_capacity <<= 1];
    for (int i = 0; i < _size; i++)
        _elem[i] = oldElem[i];
}

template<typename T>
void Vector<T>::shrink() {
    if (_capacity < DEFAULT_CAPACITY << 1) return;
    if (_size << 2 > _capacity) return;
    T *oldElem = _elem;
    _elem = new T[_capacity >>= 1];
    for (int i = 0; i < _size; i++) _elem[i] = oldElem[i];
    delete[] oldElem;
}

template<typename T>
Vector<T> &Vector<T>::operator=(Vector<T> const &V) {
    delete[] _elem;
    copyFrom(V._elem, 0, V.size());
    return *this;
}

template<typename T>
T &Vector<T>::operator[](Rank r) { return _elem[r]; }

template<typename T>
void Vector<T>::print() {
    for (Rank i = 0; i < _size; i++)
        cout << _elem[i] << ' ';
    cout << endl;
}

template<typename T>
Rank Vector<T>::find(T const &e, Rank l, Rank h) const {
    while ((l < h--) && (e != _elem[hi]));
    return h;
}

template<typename T>
void Vector<T>::unsort() {
    for (int i = this->size(); i > 0; i--)
        swap(this->_elem[i - 1], this->_elem[rand() % i]);
}

template<typename T>
Rank Vector<T>::insert(Rank r, T const &e) {
    expand();
    for (int i = _size; i > r; i--) _elem[i] = _elem[i - 1];
    _elem[r] = e;
    _size++;
    return r;
}


template<typename T>
Rank Vector<T>::remove(Rank l, Rank h) {
    if (l == h) return 0;
    while (h < _size) _elem[l++] = _elem[h++];
    _size = l;
    shrink();
    return h - l;
}

template<typename T>
T Vector<T>::remove(Rank r) {
    T e = _elem[r];
    remove(r, r + 1);
    return e;
}

template<typename T>
Rank Vector<T>::deduplicate() {
    int oldSize = _size;
    Rank i = 1;
    while (i < _size)
        (find(_elem[i], 0, i) < 0) ?
        i++ : remove(i);
    return oldSize - _size;
}

template<typename T>
void Vector<T>::bubbleSort(Rank l, Rank h) { 
    while (l < --h)
        for (Rank i = l; i < h; i++)
            if (_elem[i] > _elem[i + 1])
                swap(_elem[i], _elem[i + 1]);
}

template<typename T>
bool Vector<T>::bubble(Rank l, Rank h) {
    bool sorted = true;
    while (++lo < h)
        if (_elem[l - 1] > _elem[l]) {
            sorted = false;
            swap(_elem[l - 1], _elem[l]);
        }
    return sorted;
}

template<typename T>
void Vector<T>::sort(Rank l, Rank h) {
    this->bubbleSort(l, h);
}

template<typename T>
void Vector<T>::merge(Rank l, Rank m, Rank h) {
    T *A = _elem + l;
    int lb = m - l;
    T *B = new T[lb];
    for (Rank i = 0; i < lb; B[i] = A[i++]);
    int lc = h - m;
    T *C = _elem + m;
    for (Rank i = 0, j = 0, k = 0; (j < lb) || (k < lc);) {
        if ((j < lb) && (k >= lc || (B[j] <= C[k]))) A[i++] = B[j++];
        if ((k < lc) && (j >= lb || (C[k] < B[j]))) A[i++] = C[k++];
    }
    delete[] B;
}

template<typename T>
void Vector<T>::mergeSort(Rank l, Rank h) {
    if (h - lo < 2) return;
    int mi = (l + h) / 2;
    mergeSort(l, m);
    mergeSort(m, h);
    merge(l, m, h);
}

template<typename T>
auto Vector<T>::sort(char x)-> std::size_t {
    auto time = 0;
    switch (x) {
        case 'b': {
            auto start_b = chrono::steady_clock::now();
            this->bubbleSort(0, _size);
            auto end_b = chrono::steady_clock::now();
            time = chrono::duration_cast<chrono::nanoseconds>(end_b - start_b).count();
            break;
        }
        case 'm': {
            auto start_m = chrono::steady_clock::now();
            this->mergeSort(0, _size);
            auto end_m = chrono::steady_clock::now();
            time = chrono::duration_cast<chrono::nanoseconds>(end_m - start_m).count();
            break;
        }
    }
    return time;
}

template<typename T>
void Vector<T>::reverse() {
    for (Rank i = 0; i < int(_size / 2); i++)
        swap(_elem[i], _elem[_size - i - 1]);
}
