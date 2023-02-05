TC - O(n*n) in all cases

void selection_sort(int arr[], int n) {
	for(int i = 0;i<n-1;i++) {
		int mini = i;
		for(int j = i;j<n;j++) {
			if(arr[j] < arr[mini]) mini = j;
		}
		swap(arr[mini], arr[i]);
	}
}
