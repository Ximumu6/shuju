#include "F:/f/shujujiegou/vector/vector_fun.h"


class Complex {
protected:
    double real; // ����ʵ��
    double imag; // �����鲿

public:
    Complex(double r = 0.0, double i = 0.0) {
        real = r;
        imag = i;
    }

    double abs() const {
        return sqrt(real * real + imag * imag);
    }

    friend ostream &operator<<(ostream &os, const Complex &c) {
        return os << c.real << '+' << c.imag << "i";
    }

    bool operator==(const Complex &other) const {
        return ((this->real == other.real) && (this->imag == other.imag));
    }

    bool operator!=(const Complex &other) const {
        return (this->real != other.real) || (this->imag != other.imag);
    }

    bool operator<(const Complex &c) const {
        if (abs() == c.abs()) {
            return real < c.real;
        }
        return abs() < c.abs();
    }

    bool operator>(const Complex &c) const {
        return c < *this;
    }

    bool operator<=(const Complex &c) const {
        return !(c < *this);
    }

    bool operator>=(const Complex &c) const {
        return !(*this < c);
    }
};

void Randomize(Vector<Complex> &v) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 200);
    for (unsigned i = 0; i < v.size(); i++) {
        double real = double(dis(gen)) / 10.0;
        double imag = double(dis(gen)) / 10.0;
        Complex c(real, imag);
        v[i] = c;
    }
}

Vector<Complex> Abssort(Vector<Complex> &v, double l, double h) {
    int k = 0;
    Vector<Complex> cv;
    for (Rank i = 0; i < v.size(); i++) {
        if (l <= v[i].abs() && v[i].abs() < h)
            cv.insert(k++, v[i]);
    }
    return cv;
}

int main() {
	//������Ŀ����Ҫ��1 
    double a, b;
    Rank i;
    Vector<Complex> complex(100, 100);
    Randomize(complex);
    cout << "���ɵ�������:" << endl;//������ɵ����� 
    complex.print();
    complex.unsort();
    cout << "���Һ��������:" << endl;//������Һ������ 
    complex.print();
    cout << "���Ҹ�����Ȼ�������ʽ:<ʵ��> <�鲿>" << endl;
    cin >> a >> b;
    Complex key(a, b);
    if (complex.find(key) == -1)
        cout << "����ʧ��" << endl;
    else
        cout << "λ���±�" << complex.find(key) << endl;
    cout << "����Ԫ�أ�Ȼ�������ʽ:<�±�> <ʵ��> <�鲿>" << endl;
    cin >> i >> a >> b;
    Complex ins(a, b);
    complex.insert(i, ins);
    cout << "������������" << endl;//������������� 
    complex.print();
    cout << "�����ɾ����Ԫ���±���:";
    cin >> i;
    complex.remove(i);
    cout << "ɾ�����������" << endl;//���ɾ��������� 
    complex.print();
    cout << "ȥ�غ��������" << endl;//���ȥ�غ������ 
    complex.deduplicate();
    complex.print();
    complex.sort('m');
    //��������2��Ҫ��2 
	//��������
    auto time_a = 0; 
    time_a = complex.sort('a');
    //�鲢����
    auto time_b = 0;
     complex.reverse();
    time_a = complex.sort('a');
    complex.reverse();
    time_b = complex.sort('b');
    cout << "�������������ʱΪ:    " << time_a << "ns" << endl
         << "����鲢�����ʱΪ:    " << time_b << "ns" << endl;
    time_b = complex.sort('b');
    cout << "˳�����������ʱΪ:    " << time_a << "ns" << endl
         << "˳��鲢�����ʱΪ:    " << time_b << "ns" << endl;
   complex.unsort();
    Vector<Complex> bak(complex);
    time_a = complex.sort('a');
    time_b = bak.sort('b');
    cout << "�������������ʱΪ:    " << time_a << "ns" << endl
         << "����鲢�����ʱΪ:    " << time_b << "ns" << endl;
    //��������2��Ҫ��3 
    cin >> a >> b;
    bak = Abssort(complex, a, b);
    bak.print();
    cout << "����ģ��������ң������ʽ:<�����½�> <�����Ͻ�>" << endl;
    return 0;
}
