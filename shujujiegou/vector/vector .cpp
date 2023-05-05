#pragma once

#include <iostream>
#include <random>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <chrono>
using Rank = int; //������
#define DEFAULT_CAPACITY  3 
using namespace std;

template<typename T>
class Vector { //��������ģ����
protected:
    Rank _size;
    Rank _capacity;
    T *_elem; 
    void copyFrom(T const *A, Rank lo, Rank hi); //������������A[lo, hi)
    void expand(); //�ռ䲻��ʱ����
    void shrink(); //��Сʱѹ��
    bool bubble(Rank lo, Rank hi); //����
    void bubbleSort(Rank lo, Rank hi); //��������
    Rank maxItem(Rank lo, Rank hi); //ѡȡ���Ԫ��
    void selectionSort(Rank lo, Rank hi); //ѡ������
    void merge(Rank lo, Rank mi, Rank hi); //�鲢
    void mergeSort(Rank lo, Rank hi); //�鲢����
    void heapSort(Rank lo, Rank hi); 
    Rank partition(Rank lo, Rank hi); 
    void quickSort(Rank lo, Rank hi); 
    void shellSort(Rank lo, Rank hi);
public:
    // ���캯��
    Vector(Rank c = DEFAULT_CAPACITY, Rank s = 0, T v = 0) //����Ϊc����ģΪs������Ԫ�س�ʼΪv
    {
        _elem = new T[_capacity = c];
        for (_size = 0; _size < s; _elem[_size++] = v);
    }

    Vector(T const *A, Rank n) { copyFrom(A, 0, n); } 
    Vector(T const *A, Rank lo, Rank hi) { copyFrom(A, lo, hi); } //����
    Vector(Vector<T> const &V) { copyFrom(V._elem, 0, V._size); }
    Vector(Vector<T> const &V, Rank lo, Rank hi) { copyFrom(V._elem, lo, hi); } //����
  
    ~Vector() { delete[] _elem; } //�ͷ��ڲ��ռ�

    Rank size() const { return _size; } 
    bool empty() const { return !_size; } 
    Rank find(T const &e) const { return find(e, 0, _size); } // ���������������
    Rank find(T const &e, Rank lo, Rank hi) const; //���������������
    Rank search(T const &e) const //���������������
    { return (0 >= _size) ? -1 : search(e, 0, _size); }

    void print();//�������
    Rank search(T const &e, Rank lo, Rank hi) const; //���������������
    T &operator[](Rank r); 
    Vector<T> &operator=(Vector<T> const &); //���ظ�ֵ������
    T remove(Rank r); //ɾ����Ϊr��Ԫ��
    Rank remove(Rank lo, Rank hi); //ɾ����������[lo, hi)֮�ڵ�Ԫ��
    Rank insert(Rank r, T const &e); //����Ԫ��
    Rank insert(T const &e) { return insert(_size, e); } //Ĭ����ΪĩԪ�ز���
    void sort(Rank lo, Rank hi); //��[lo, hi)����
    auto sort(char x)-> std::size_t;//��������
    Rank deduplicate(); //����ȥ��
    void unsort();//����
    void reverse();//��ת����
    Rank uniquify(); //����ȥ��
    void traverse(void (* )(T &)); 
    template<typename VST>
    void traverse(VST &); 

};















