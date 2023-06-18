#include<bits/stdc++.h>
using namespace std;
const int M = 1e9+7;
#define ll long long
#define lli long long int
#define IOS ios::sync_with_stdio(0); cin.tie(0);


// T.C => O(n+k)
// S.C => O(max(arr))

void countSort(int arr[], int n) {
	// find the max element in this arr[]
	int k = 0;
	for(int i = 0;i<n;i++) {
		k = max(k, arr[i]);     // 9
	}

	// take a aux array of size (max+1) ans initialized to 0, take a space of O(k+1);
	vector<int> aux(k+1, 0);

	// store the frequency of all distinct element of the array arr[]
	for(int i = 0;i<n;i++) {
		aux[arr[i]]++;
	}

	
	vector<int> ans;
	for(int i = 0;i<=k;i++) {
		int temp = aux[i];
		while(temp--) {
			ans.push_back(i);
			// j++;
		}
	}

	for(int i = 0;i<n;i++) {
		arr[i] = ans[i];
	}
}

int main() {
    IOS;
    
    int arr[] = {5,4,1,1,4,7,8,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    countSort(arr, n);
    for(int i = 0;i<n;i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}
