#include "F:/f/shujujiegou/vector/vector_fun.h"
#ifndef _BASESMOOTHINGALGORITHM_H_
#define _BASESMOOTHINGALGORITHM_H_

#include "BaseSmoothingAlgorithm.h"



template <typename T> class Stack : public Vector<T> {
public:
    void push(T const& e) { this->insert(this->size(), e); }
    T pop() { return this->remove(this->size() - 1); } 
    T& top() { return (*this)[this->size() - 1]; }
};//参照书上代码4.1 
#endif
