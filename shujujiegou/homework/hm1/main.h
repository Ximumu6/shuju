#include "F:/f/shujujiegou/vector/vector_fun.h"


class Complex {
protected:
    double real; // 定义实部
    double imag; // 定义虚部

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
	//对于题目二的要求1 
    double a, b;
    Rank i;
    Vector<Complex> complex(100, 100);
    Randomize(complex);
    cout << "生成的数组是:" << endl;//输出生成的数组 
    complex.print();
    complex.unsort();
    cout << "置乱后的数组是:" << endl;//输出置乱后的数组 
    complex.print();
    cout << "查找复数，然后输入格式:<实部> <虚部>" << endl;
    cin >> a >> b;
    Complex key(a, b);
    if (complex.find(key) == -1)
        cout << "查找失败" << endl;
    else
        cout << "位于下标" << complex.find(key) << endl;
    cout << "插入元素，然后输入格式:<下标> <实部> <虚部>" << endl;
    cin >> i >> a >> b;
    Complex ins(a, b);
    complex.insert(i, ins);
    cout << "插入后的数组是" << endl;//输出插入后的数组 
    complex.print();
    cout << "输入待删除的元素下标是:";
    cin >> i;
    complex.remove(i);
    cout << "删除后的数组是" << endl;//输出删除后的数组 
    complex.print();
    cout << "去重后的数组是" << endl;//输出去重后的数组 
    complex.deduplicate();
    complex.print();
    complex.sort('m');
    //对于问题2的要求2 
	//起泡排序
    auto time_a = 0; 
    time_a = complex.sort('a');
    //归并排序
    auto time_b = 0;
     complex.reverse();
    time_a = complex.sort('a');
    complex.reverse();
    time_b = complex.sort('b');
    cout << "逆序起泡排序耗时为:    " << time_a << "ns" << endl
         << "逆序归并排序耗时为:    " << time_b << "ns" << endl;
    time_b = complex.sort('b');
    cout << "顺序起泡排序耗时为:    " << time_a << "ns" << endl
         << "顺序归并排序耗时为:    " << time_b << "ns" << endl;
   complex.unsort();
    Vector<Complex> bak(complex);
    time_a = complex.sort('a');
    time_b = bak.sort('b');
    cout << "乱序起泡排序耗时为:    " << time_a << "ns" << endl
         << "乱序归并排序耗时为:    " << time_b << "ns" << endl;
    //对于问题2的要求3 
    cin >> a >> b;
    bak = Abssort(complex, a, b);
    bak.print();
    cout << "复数模的区间查找，输入格式:<区间下界> <区间上界>" << endl;
    return 0;
}
