/*
*@Author: lwl
*@Date: 2019-12-19
*@Description: 主要是实现桶排序(计数排序和基数排序)
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>

using namespace std;

class CBucketSort {
private:
	int getMaxBits(vector<int>& vec) {
		int max = INT_MIN;
		for (int i : vec) {
			max = max < i ? i : max;
		}
		int bits = 0;
		while (max != 0) {
			bits++;
			max /= 10;
		}
		return bits;
	}

	int getDigit(int num, int digit) {
		for (int i = 1; i < digit; ++i) {
			num /= 10;
		}
		return (num % 10);
	}

public:
	void bucketSortInterface(vector<int>& vec) {
		size_t len = vec.size();
		if (len > 1) {
			int max = INT_MIN;
			for (size_t i = 0; i < len; ++i) {
				max = max >= vec.at(i) ? max : vec.at(i);
			}
			vector<int> tmp(max + 1);
			for (size_t j = 0; j < len; ++j) {
				tmp.at(vec.at(j)) += 1;
			}
			size_t n = 0;
			for (size_t k = 0; k <= max; ++k) {
				while (tmp.at(k)--) {
					vec.at(n++) = k;
				}
			}
		}
	}

	void radixSortInterface(vector<int>& vec) {
		size_t len = vec.size();
		if (len > 1) {
			int digit = getMaxBits(vec);
			vector<int> bucket = vec;
			for (int i = 1; i <= digit; ++i) {
				vector<int> count(10, 0);
				for (int k : vec) {
					count.at(getDigit(k, i))++;
				}
				for (vector<int>::iterator it = (count.begin() + 1); it != count.end(); ++it) {
					*it = *it + *(it - 1);
				}
				for (int j = vec.size() - 1; j >= 0; --j) {
					int bitsData = getDigit(vec.at(j), i);
					bucket.at(--count.at(bitsData)) = vec.at(j);
				}
				vec = bucket;
			}
		}
	}
};

class CComparator {
private:
	int valueMax;
	int testTime;
	int maxSize;
	CBucketSort bucketSort;

private:
	void generalRandomArr(vector<int>& data) {
		for (vector<int>::iterator it = data.begin(); it != data.end(); ++it) {
			*it = rand() % valueMax;
		}
	}

	void print(vector<int>& vec) {
		for (int i : vec) {
			cout << i << " ";
		}
		cout << endl;
	}

	bool isEquel(vector<int>& copyVec, vector<int>& data) {
		return equal(copyVec.begin(), copyVec.end(), data.begin(), data.end());
	}

	void rightMethod(vector<int>& copyVec) {
		sort(copyVec.begin(), copyVec.end());
	}

public:
	CComparator(int max, int testTime, int size) :
		valueMax(max),
		testTime(testTime),
		maxSize(size)
	{
		srand(time(0));
	}

	void runTest() {
		bool res = true;
		while (testTime--) {
			vector<int> data(rand() % maxSize);
			generalRandomArr(data);
			vector<int> copyArr = data;
			bucketSort.bucketSortInterface(data); // 测试计数排序
			// bucketSort.radixSortInterface(data); // 测试基数排序
			rightMethod(copyArr);
			res = res && isEquel(copyArr, data);
		}
		cout << (res == true ? "nice" : "false") << endl;
	}
};

int main() {
	int maxSize = 100;
	int maxValue = 100;
	int testTime = 500000;
	CComparator comparator(maxValue, testTime, maxSize);
	comparator.runTest();
	system("pause");
	return 0;
}