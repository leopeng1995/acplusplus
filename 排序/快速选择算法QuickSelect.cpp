int partition(int A[], int left, int right) {
	int pivot = A[left];
	int i = left;
	for (int j = left + 1; j <= right; ++j) {
		if (A[j] <= pivot) {
			i = i + 1;
			swap(A[i], A[j]);
		}
	}
	swap(A[left], A[i]);
	return i;
}

void quicksort(int A[], int left, int right) {
	if (left < right) {
		int r = partition(A, left, right);
		quicksort(A, left, r - 1);
		quicksort(A, r + 1, right);
	}
}

int quickselect(int A[], int left, int right, int k) {
	if (left == right) return A[left];

	int r = partition(A, left, right);

	if (r == k) return A[k];
	if (r > k) return quickselect(A, left, r - 1, k);
	return quickselect(A, r + 1, right, k);
}

int main(int argc, char const *argv[])
{
	int A[6] = {3, 2, 1, 5, 6, 4};
	printf("%d\n", quickselect(A, 0, 6, 0));		// 找第 1 小的值
	printf("%d\n", quickselect(A, 0, 6, 6 - 2));	// 找第 2 大的值
	return 0;
}