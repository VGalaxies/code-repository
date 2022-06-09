void SelectionSort(int a[], int size)
{
	for (int i = 0; i < size - 1; ++i) {//每次循环后将第i小的元素放好

		int tmpMin = i;
		//用来记录从第i个到第size-1个元素中，最小的那个元素的下标
		for (int j = i + 1; j < size; ++j) {
			if (a[j] < a[tmpMin])
				tmpMin = j;
		}
		//下面将第i小的元素放在第i个位子上，并将原来占着第i个位子的元素挪到后面
		int tmp = a[i];
		a[i] = a[tmpMin];
		a[tmpMin] = tmp;
	}
}
