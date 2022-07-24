#include<cstdio>
#include<iostream>
using namespace std;
int n;
int ori[100010];
void swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void BubbleSort(int arr[], int low, int high){
	for (int i = low; i <= high; ++i) {
		for (int j = high; j > i; --j) {
			if (arr[j - 1] > arr[j])
				swap(arr[j - 1], arr[j]);
		}
	}
}
/*�������ã�ȡ������������low��mid��high����λ�������ݣ�ѡȡ�����м���Ǹ�������Ϊ����*/
int SelectPivotMedianOfThree(int arr[], int low, int high)
{
	int mid = low + ((high - low) >> 1);//���������м��Ԫ�ص��±�

	//ʹ������ȡ�з�ѡ������
	if (arr[mid] > arr[high])//Ŀ��: arr[mid] <= arr[high]
		swap(arr[mid], arr[high]);
	if (arr[low] > arr[high])//Ŀ��: arr[low] <= arr[high]
		swap(arr[low], arr[high]);
	if (arr[mid] > arr[low]) //Ŀ��: arr[low] >= arr[mid]
		swap(arr[mid], arr[low]);
	//��ʱ��arr[mid] <= arr[low] <= arr[high]
	return arr[low];
	//low��λ���ϱ���������λ���м��ֵ
	//�ָ�ʱ����ֱ��ʹ��lowλ�õ�Ԫ����Ϊ���ᣬ�����øı�ָ����
}
void QSort(int arr[], int low, int high)
{
	int first = low;
	int last = high;

	int left = low;
	int right = high;

	int leftLen = 0;
	int rightLen = 0;

	if (high - low + 1 < 10)
	{
		BubbleSort(arr, low, high);
		return;
	}

	//һ�ηָ�
	int key = SelectPivotMedianOfThree(arr, low, high);//ʹ������ȡ�з�ѡ������

	while (low < high)
	{
		while (high > low && arr[high] >= key)
		{
			if (arr[high] == key)//�������Ԫ��
			{
				swap(arr[right], arr[high]);
				right--;
				rightLen++;
			}
			high--;
		}
		arr[low] = arr[high];
		while (high > low && arr[low] <= key)
		{
			if (arr[low] == key)
			{
				swap(arr[left], arr[low]);
				left++;
				leftLen++;
			}
			low++;
		}
		arr[high] = arr[low];
	}
	arr[low] = key;

	//һ�ο��Ž���
	//��������key��ͬ��Ԫ���Ƶ���������λ����Χ
	int i = low - 1;
	int j = first;
	while (j < left && arr[i] != key)
	{
		swap(arr[i], arr[j]);
		i--;
		j++;
	}
	i = low + 1;
	j = last;
	while (j > right && arr[i] != key)
	{
		swap(arr[i], arr[j]);
		i++;
		j--;
	}
	QSort(arr, first, low - 1 - leftLen);
	QSort(arr, low + 1 + rightLen, last);
}
int main() {
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> ori[i];
	QSort(ori, 0, n - 1);
	for (int i = 0; i < n; ++i)
		printf("%d ", ori[i]);
}