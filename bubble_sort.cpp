TC - O(n*n) worst/average
TC - O(n) Best

void bubble_sort(int arr[], int n) {
	for(int i = n-1;i>=1;i--) {
		for(int j = 0;j<i;j++) {
			if(arr[j] > arr[j+1]) {
				swap(arr[j], arr[j+1]);
			}
		}
	}
}
