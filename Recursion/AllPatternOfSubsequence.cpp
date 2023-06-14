#include<bits/stdc++.h>
using namespace std;

// Print all the subsequences of given array

void printAllSubseqence(int arr[], int n, vector<int>& ds, int ind) {
	if(ind == n) {
		for(auto it : ds) {
			cout << it << " ";
		}
		if(ds.size() == 0) cout << "{}";
		cout << "\n";
		return;
	}

	// Not pick the current index
	printAllSubseqence(arr, n, ds, ind+1);

	// Pick the current index
	ds.push_back(arr[ind]);
	printAllSubseqence(arr, n, ds, ind+1);
	ds.pop_back();
}


// Print those subsequences whose sum is equal to the given sum

void printKEqualSubsequence(int arr[], int n, vector<int>& ds, int ind, int sum, int k) {
	if(ind == n) {
		if(sum == k) {
			for(auto it : ds) {
				cout << it << " ";
			}
			cout << "\n";
		}
		return;
	}

	printKEqualSubsequence(arr, n, ds, ind+1, sum, k);

	ds.push_back(arr[ind]);
	sum += arr[ind];
	printKEqualSubsequence(arr, n, ds, ind+1, sum, k);
	sum -= arr[ind];
	ds.pop_back();
}


// Print only one subsequence whose sum is equal to the given sum


bool printOneSubsequence(int arr[], int n, vector<int>& ds, int ind, int sum, int k) {
	if(ind == n) {
		if(sum == k) {
			for(auto it : ds) cout << it << " ";
			return true;
		}
		else return false;
	}

	if(printOneSubsequence(arr, n, ds, ind+1, sum, k) == true) return true;

	ds.push_back(arr[ind]);
	sum += arr[ind];
	if(printOneSubsequence(arr, n, ds, ind+1, sum, k) == true) return true;
	sum -= arr[ind];
	ds.pop_back();	

	return false;
}


// Count the number of subsequence whose sum is equal to the given sum


int countSubsequence(int arr[], int n, int ind, int sum, int k) {
	if(ind == n) {
		if(sum == k) {
			return 1;
		}
		else return 0;
	}

	int left = countSubsequence(arr, n, ind+1, sum, k);

	sum += arr[ind];
	int right = countSubsequence(arr, n, ind+1, sum, k);
	sum -= arr[ind];

	return left + right;
}



int main() {
	int arr[] = {2, 1,3};
	int n = 3;
	vector<int> ds;
	int k = 3;
	cout << countSubsequence(arr, n, 0, 0, k);
}
