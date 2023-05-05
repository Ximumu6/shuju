#include<iostream>
#ifndef _TEST_H_
#define _TEST_H_

using namespace std;

typedef int Rank; //��

#define ListNodePosi(T) ListNode<T> * //�б�ڵ�λ��

template <typename T> struct ListNode { //�б�ڵ�ģ���ࣨ��˫��������ʽʵ�֣�
// ��Ա
	T data;//��ֵ

	ListNodePosi(T) pred;//ǰ��

	ListNodePosi(T) succ; //���

// ���캯��
	ListNode() {} //���header��trailer�Ĺ���

	ListNode(T e, ListNodePosi(T) p = NULL, ListNodePosi(T) s = NULL)
		: data(e), pred(p), succ(s) {} //Ĭ�Ϲ�����
// �����ӿ�
	ListNodePosi(T)
		insertAsPred(T const& e) {
		ListNodePosi(T) x = new ListNode(e, pred, this); //�����½ڵ�
		pred->succ = x; pred = x; //ک����������
		return x; //ކ���½ڵ�mλ��
		}//������ǰ�ڵ�֮ǰ�����½ڵ�

	ListNodePosi(T)
		insertAsSucc(T const& e); //���浱ǰ�ڵ�֮������½ڵ�
	
};//����3.1 





template <typename T> class List { //�б�ģ����

private:
	int _size;//��ģ
	ListNodePosi(T) header;//ͷ�ڱ�
	ListNodePosi(T) trailer; //β�ڱ�
	
protected:
	void init(); //�б���ʱ�ĳ�ʼ��

	int clear(); //������нڵ�

	void copyNodes(ListNodePosi(T), int); //�����б�����λ��p���n��

	void merge(ListNodePosi(T)&, int, List<T>&, ListNodePosi(T), int); //�鲢

	void mergeSort(ListNodePosi(T)&, int); //�Դ�p��ʼ������n���ڵ�鲢����

	void selectionSort(ListNodePosi(T), int); //�Դ�p��ʼ������n���ڵ�ѡ������

	void insertionSort(ListNodePosi(T), int); //�Դ�p��ʼ������n���ڵ��������
	
public:
	// ���캯��
	List() {
		init();
	} //Ĭ��
	List(List<T> const& L); //���帴���б�L
	List(List<T> const& L, Rank r, int n); //�����б�L���Ե�r�����n��
	List(ListNodePosi(T) p, int n); //�����б�����λ��p���n��
	// ��������
	~List(); //�ͷţ�����ͷ��β�ڱ����ڵģ����нڵ�
	// ֻ�����ʽӿ�
	Rank size() const {
		return _size;
	} //��ģ

	bool empty() const {
		return _size <= 0;
	} //�п�

	T & operator[] (Rank r) const; //���أ�֧��ѭ��ڪ�ʣ�Ч�ʵͣ�

	ListNodePosi(T) first() const {
		return header->succ;
	} //�׽ڵ�λ��

	ListNodePosi(T) last() const {
		return trailer->pred;
	} //ĩ�ڵ�λ��

	bool valid(ListNodePosi(T) p) /*�ж�λ��p�Ƿ����Ϸ�*/{
		return p && (trailer != p) && (header != p);
	} //��ͷ��β�ڵ��ͬءNULL

	int disordered() const; //�ж��б��Ƿ�������

	ListNodePosi(T) find(T const& e) const {
		return find(e, _size, trailer);
	}//�����б����

	ListNodePosi(T) find(T const& e, int n, ListNodePosi(T) p) const; //�����������

	ListNodePosi(T) search(T const& e) const {
		return search(e, _size, trailer);
	}//�����б����

	ListNodePosi(T) search(T const& e, int n, ListNodePosi(T) p) const; //�����������

	ListNodePosi(T) selectMax(ListNodePosi(T) p, int n); //��p����n-1�������ѡ�������

	ListNodePosi(T) selectMax() {
		return selectMax(header->succ, _size);
	} //���������

	// ��д���ʽӿ�
	ListNodePosi(T) insertAsFirst(T const& e){
		_size++; return header->insertAsSucc(e);
	}//��e�����׽ڵ����

	ListNodePosi(T) insertAsLast(T const& e) { 
		_size++; return trailer->insertAsPred(e);
	} //��e����ĩ�ڵ����

	ListNodePosi(T) insertA(ListNodePosi(T) p, T const& e) {
		_size++; return p->insertAsSucc(e);
	}//��e����p�ĺ�̲���

	ListNodePosi(T) insertB(ListNodePosi(T) p, T const& e); //��e����p��ǰ������

	T remove(ListNodePosi(T) p) { //ɾ���Ϸ��ڵ�p����������ֵ
		T e = p->data; //���ݴ�ɾ���ڵ����ֵ���ٶ�T���Ϳ�ֱ�Ӹ�ֵ��
		p->pred->succ = p->succ; p->succ->pred = p->pred; //��̡�ǰ��
		delete p; _size--; //�ͷŽڵ㣬���¹�ģ
		return e; //���ر��ݵ���ֵ
		
	}

	void merge(List<T>&L) {
		merge(first(), size, L, L.first(), L._size);
	} //ȫ�б�鲢

	void sort(ListNodePosi(T) p, int n); //�б���������

	void sort() {
		sort(first(), _size);
	} //�б���������

	int deduplicate(); //����ȥ��

	int uniquify(); //����ȥ��

	void reverse(); //ǰ���ã�ϰ�⣩
	// ����

	void traverse(void (*) (T&)); //����������ʵ��visit����������ָ�룬ֻ����ֲ����޸ģ�

	template < typename VST> //������

	void traverse(VST&); //����������ʵʩvisit�������������󣬿�ȫ�����޸ģ�
	
}; //List//����3.2 
#endif
