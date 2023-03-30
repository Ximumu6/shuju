#pragma once

#include <iostream>
#include <random>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <chrono>
using Rank = int; //定义秩
#define DEFAULT_CAPACITY  3 
using namespace std;

template<typename T>
class Vector { //定义向量模板类
protected:
    Rank _size;
    Rank _capacity;
    T *_elem; 
    void copyFrom(T const *A, Rank lo, Rank hi); //复制数组区间A[lo, hi)
    void expand(); //空间不足时扩容
    void shrink(); //过小时压缩
    bool bubble(Rank lo, Rank hi); //交换
    void bubbleSort(Rank lo, Rank hi); //起泡排序
    Rank maxItem(Rank lo, Rank hi); //选取最大元素
    void selectionSort(Rank lo, Rank hi); //选择排序
    void merge(Rank lo, Rank mi, Rank hi); //归并
    void mergeSort(Rank lo, Rank hi); //归并排序
    void heapSort(Rank lo, Rank hi); 
    Rank partition(Rank lo, Rank hi); 
    void quickSort(Rank lo, Rank hi); 
    void shellSort(Rank lo, Rank hi);
public:
    // 构造函数
    Vector(Rank c = DEFAULT_CAPACITY, Rank s = 0, T v = 0) //容量为c、规模为s、所有元素初始为v
    {
        _elem = new T[_capacity = c];
        for (_size = 0; _size < s; _elem[_size++] = v);
    }

    Vector(T const *A, Rank n) { copyFrom(A, 0, n); } 
    Vector(T const *A, Rank lo, Rank hi) { copyFrom(A, lo, hi); } //区间
    Vector(Vector<T> const &V) { copyFrom(V._elem, 0, V._size); }
    Vector(Vector<T> const &V, Rank lo, Rank hi) { copyFrom(V._elem, lo, hi); } //区间
  
    ~Vector() { delete[] _elem; } //释放内部空间

    Rank size() const { return _size; } 
    bool empty() const { return !_size; } 
    Rank find(T const &e) const { return find(e, 0, _size); } // 乱序向量整体查找
    Rank find(T const &e, Rank lo, Rank hi) const; //乱序向量区间查找
    Rank search(T const &e) const //有序向量整体查找
    { return (0 >= _size) ? -1 : search(e, 0, _size); }

    void print();//输出数组
    Rank search(T const &e, Rank lo, Rank hi) const; //有序向量区间查找
    T &operator[](Rank r); 
    Vector<T> &operator=(Vector<T> const &); //重载赋值操作符
    T remove(Rank r); //删除秩为r的元素
    Rank remove(Rank lo, Rank hi); //删除秩在区间[lo, hi)之内的元素
    Rank insert(Rank r, T const &e); //插入元素
    Rank insert(T const &e) { return insert(_size, e); } //默认作为末元素插入
    void sort(Rank lo, Rank hi); //对[lo, hi)排序
    auto sort(char x)-> std::size_t;//整体排序
    Rank deduplicate(); //无序去重
    void unsort();//置乱
    void reverse();//倒转数组
    Rank uniquify(); //有序去重
    void traverse(void (* )(T &)); 
    template<typename VST>
    void traverse(VST &); 

};















