#include <iostream>
#include <algorithm>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <exception>
#include <typeinfo>
using namespace std;
using int_t = unsigned long long int;
const int_t mod = (int_t)1e9 + 7;
//Matrix的前置声明,用于下面两个函数
template <typename ValType>
class Matrix;
//友元函数的声明
//模板类的友元函数必须显式的写明模板
template <typename T>
ostream& operator<<(ostream& os, const Matrix<T>& mat);
template <typename T>
istream& operator>>(istream& os, const Matrix<T>& mat);
//Matrix类,表示一个矩阵
template <typename ValType>
class Matrix {
private:
    ValType* data;
    int_t row;
    int_t col;
    int_t size;
    int_t num;
public:
    //析构函数,释放内存
    ~Matrix() {
        delete[] data;
    }
    //拷贝构造函数
    Matrix(const Matrix<ValType>& other) :
        row(other.row), col(other.col), size(other.size), num(other.num) {
        data = new ValType[other.num];
        memcpy(data, other.data, other.size);
    }
    //默认构造函数,动态分配内存
    Matrix(int_t r, int_t c) :
        row(r), col(c) {
        this->row = r;
        this->col = c;
        num = (row + 1) * (col + 1);
        data = new ValType[num];
        size = sizeof(ValType) * num;
        memset(data, 0, size);
    }
    //访问矩阵的某个元素
    ValType& at(int_t r, int_t c) {
        return data[c + r * col];
    }
    //重载的*运算符,矩阵无法相乘时会抛出异常
    Matrix<ValType> operator*(Matrix<ValType>& mat) throw (const char*) {
        if (this->col != mat.row) throw "Column number of matrix1 doesn't equals that in matrix2";
        Matrix<ValType> result(this->row, mat.col);
        for (int_t i = 1; i <= this->row; i++) {
            for (int_t j = 1; j <= mat.col; j++) {
                int_t sum = 0;
                for (int_t x = 1; x <= this->col; x++) {
                    sum = (sum % mod + at(i, x) % mod * mat.at(x, j) % mod) % mod;
                }
                result.at(i, j) += sum % mod;
            }
        }
        return result;
    }

    int_t getCol() const {
        return col;
    }

    int_t getRow() const {
        return row;
    }
    //赋值构造函数
    Matrix<ValType>& operator=(const Matrix<ValType>& other) {
        this->col = other.col;
        this->num = other.num;
        this->row = other.row;
        this->size = other.size;
        this->data = new ValType[num];
        memcpy(data, other.data, size);
    }
    //友元,函数名后必须写<>以告诉编译器这个友元使用了模板,如果不能从参数中推断模板类型那么还必须在<>内写上模板类型
    //程序写完以后我才发现,这两个函数其实根本不用友元..
    friend ostream& operator<< <>(ostream& os, const Matrix<ValType>& mat);
    friend istream& operator>> <>(istream& os, const Matrix<ValType>& mat);
};
//友元函数的实现
template <typename ValType>
ostream& operator<<(ostream& os, Matrix<ValType>& mat) {
    for (int_t i = 1; i <= mat.getRow(); i++) {
        for (int_t j = 1; j <= mat.getCol(); j++) {
            os << mat.at(i, j) % mod << " ";
        }
        os << endl;
    }
    return os;
}

template <typename ValType>
istream& operator>>(istream& is, Matrix<ValType>& mat) {
    for (int_t i = 1; i <= mat.getRow(); i++) {
        for (int_t j = 1; j <= mat.getCol(); j++) {
            is >> mat.at(i, j);
            mat.at(i, j) %= mod;
        }
    }
    return is;
}
using MatType = Matrix<int_t>;

int main() {
    int_t n, index;
    cin >> n >> index;
    MatType mat(n, n);
    cin >> mat;
    MatType result = mat;
    //普通的快速幂
    //快速幂卡了很长时间,以前写的一直结果错误,然而这样写就对了,具体参考我的提交记录
    for (index--; index; index >>= 1, mat = mat * mat) {
        if (index & 1) result = result * mat;
    }
    cout << result;
    return 0;
}