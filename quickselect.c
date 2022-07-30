#include <stdio.h>

void swap(int* arr, int i, int j)
{
	int t = arr[i];
	arr[i] = arr[j];
	arr[j] = t;
}

int partition(int* arr, int left_idx, int right_idx)
{
	int pivot = arr[right_idx];

	int i = left_idx - 1;
	for (int j = left_idx; j < right_idx; ++j)
		if (arr[j] < pivot)
			swap(arr, ++i, j);
	swap(arr, ++i, right_idx);

	return i;
}

int __quickselect(int* arr, int k, int left_idx, int right_idx)
{
	int pivot_idx = partition(arr, left_idx, right_idx);

	if (pivot_idx + 1 == k)
		return arr[pivot_idx];
	else if (left_idx == right_idx)
		return arr[left_idx];
	else if (pivot_idx + 1 > k)
		return __quickselect(arr, k, left_idx, pivot_idx - 1);
	return __quickselect(arr, k, pivot_idx + 1, right_idx);
}

int quickselect(int* arr, int n, int k)
{
	return __quickselect(arr, k, 0, n - 1);
}

int main()
{

	int x[16] = {0, 5, 1, 6, 2, 7, -2, -5, 9, -3, 4, -1, 12, 14, 15, -20};

	printf("Largest elements in ascending order using quickselect:\n\n");
	for (int k = 1; k <= 16; ++k)
	{
		// create a copy each time since x is modified inplace
		int x_cpy[16];
		for (int i = 0; i < 16; ++i)
			x_cpy[i] = x[i];

		printf("%d: %d\n", k, quickselect(x_cpy, 16, k));
	}

	return 0;
}
