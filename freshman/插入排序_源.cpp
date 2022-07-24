void InsertionSort(int a[], int size)
{
	for (int i = 1; i < size; ++i) {
		//a[i]是最左的无序元素，每次循环将a[i]放到合适位置
		for(int j = 0; j < i; ++j)
			if (a[j] > a[i]) {
			//要把a[i]放到位置j，原下标j到	i-1的元素都往后移一个位子
			int tmp = a[i];
			for (int k = i; k > j; --k)
				a[k] = a[k - 1]; 
			a[j] = tmp;
			break;
		}
	}
}