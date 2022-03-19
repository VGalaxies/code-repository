#include <iostream>
#include <cctype>
#include <cmath>
#include <vector>
#include <string>
#include <stack>
#include <list>
#include <algorithm>
using namespace std;

/* ����ÿ���������Ӧ�����ȼ� */
inline int priority(const char& ch) {
    switch (ch) {
        // �Ӽ������ȼ���ͣ�������Ϊ1
    case '+':
    case '-':
        return 1;
        // �˳������ȼ���Σ���Ϊ2
    case '*':
    case '/':
        return 2;
        // ע�������г˷����㣬��������û�У��ʼ�Ҿ�����������QwQ
        // �˷������ȼ���ߣ���Ϊ3
    case '^':
        return 3;
        // �������ȼ����д���������Բ�д
    case '(':
    case ')':
        return 0;
        // ��ֹ�����������RE��default��д�ɲ�д
    default:
        return -1;
    }
}

/* ����׺���ʽת��Ϊ��׺���ʽ */
inline string toSuffix(const string& s) {
    string ret = "";    // ���ڷ��صĺ�׺���ʽ
    stack<char> st;     // ����ʵ��ת����ջ
    for (register int i = 0; i < s.size(); i++) {  // ö��ÿһλ
        if (isdigit(s[i])) {                // ���Ϊ���֣�ֱ������������
            ret += s[i];
        }
        else if (s[i] == '(') {           // ���Ϊ�����ţ�ֱ�Ӽ���ջ��
            st.push(s[i]);
        }
        else if (s[i] == ')') {           // ���Ϊ�����ţ�
            while (st.top() != '(')         // һֱ���������ֱ�����������ţ�
                ret += st.top(), st.pop();  // ������������
            st.pop();
        }
        else {                            // ����Ϊ��ͨ���������
            while (!st.empty() && priority(st.top()) >= priority(s[i]))
                ret += st.top(), st.pop();  // һֱ���������ֱ�������ȵ�ǰ���ȼ��͵��������
            st.push(s[i]);                  // ���ѵ�ǰ�����ѹ��ջ��
        }
    }
    while (!st.empty())             // ������ջ�л���ʣ����ַ���ֱ�ӵ��������
        ret += st.top(), st.pop();
    return ret;                     // ��󷵻ؽ��
}

/* ���������������Ӧ�������� */
inline int calcNum(const int& a, const int& b, const int& symbol) {
    switch (symbol) {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return a / b;
    case '^':
        return (int)pow(a, b);
    default:    // ������ͬ��default��д�ɲ�д
        return -1;
    }
}

/* ����׺���ʽ���Ͽո����� */
inline void printSuffix(const string& s) {
    for (register int i = 0; i < s.size(); i++)
        cout << s[i] << ' ';
    cout << endl;
}

/* �����׺���ʽ������������ */
inline void calc(const string& s) {
    /**
     * ʵ�ּ��������ջ��Ϊ���������(����Ҫ��ÿ��Ԫ�ص���)
     * ����Ϊ��ʹѹ��͵���������ʱ�临�ӶȽ���O(1)��
     * ����û��ʹ��vector����ʹ����list(����)
     */
    list<int> st;
    printSuffix(s);     // ע��Ҫ�������׺���ʽ����֮ǰ����������QwQ
    for (register int i = 0; i < s.size(); i++) {
        if (isdigit(s[i])) {    // �����������ֱ��ѹ��ջ
            st.push_back(s[i] - '0');
        }
        else {                // �����������ѹ��ջ
            register int a, b;  //ȡ��ջ��������Ԫ��
            a = st.back();
            st.pop_back();
            b = st.back();
            st.pop_back();
            st.push_back(calcNum(b, a, s[i]));  // ע�����˳��
            // ÿ����һ�����һ�μ������
            for (list<int>::iterator it = st.begin(); it != st.end(); ++it)
                cout << *it << ' ';             // ���ջ���Ѽ��������
            for (register int j = i + 1; j < s.size(); j++)
                cout << s[j] << ' ';            // �������δ���������
            cout << endl;
        }
    }
}

int main() {
    string s;
    cin >> s;
    calc(toSuffix(s));
    return 0;
}