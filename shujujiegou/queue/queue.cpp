#include"F:/f/shujujiegou/list/list.cpp"

#include<iostream>

using namespace std;

template <typename T> class Queue : public List<T> { //����ģ���ࣨ�̳�Listԭ�нӿڣ�
public: //size()��empty()�Լ��������Žӿھ���ֱ������
	void enqueue(T const& e) { this->insertAsLast(e); } //��ӣ�β���I��
	T dequeue() { return this->remove(this->first()); } //���ӣ��ײ�����
	T & front() { return this->first()->data; } //����
	
};//����4.14 
