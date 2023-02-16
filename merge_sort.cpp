#include<bits/stdc++.h>
using namespace std;

void merge(int arr[], int low, int mid, int high) {
	int start = low, end = mid+1;
	vector<int> temp;
	while(start <= mid && end <= high) {
		if(arr[start] <= arr[end]) {
			temp.push_back(arr[start]);
			start++;
		}
		else {
			temp.push_back(arr[end]);
			end++;	
		}
	}
	while(start <= mid) {
		temp.push_back(arr[start]);
		start++;
	}
	while(end <= high) {
		temp.push_back(arr[end]);
		end++;
	}
	for(int i = low;i<=high;i++) {
		arr[i] = temp[i-low];
	}
}


void mergeSort(int arr[], int low, int high) {
	if(low >= high) return;
	int mid = (low+high)/2;
	mergeSort(arr, low, mid);
	mergeSort(arr, mid+1, high);
	merge(arr, low, mid, high);
}
