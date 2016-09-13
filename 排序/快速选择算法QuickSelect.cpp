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
		r = partition(A, left, right);
		quicksort(A, left, r - 1);
		quicksort(A, r + 1, right);
	}
}

int quickselect(int A[], int left, int right, int k) {
	if (left == right) return A[left];

	r = partition(A, left, right);

	if (r == k) return A[k];
	if (r > k) return quickselect(A, left, r - 1, k);
	return quickselect(A, r + 1, right, k);
}