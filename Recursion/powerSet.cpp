// TC - O(2^n * n)
// SC - O(1)

#include<bits/stdc++.h>
using namespace std;

void printSubset(int n, string &s) {
	for(int num = 0;num<(1<<n);num++) {
		string ans = "";
		for(int i = 0;i<n;i++) {
			if(num & (1<<i)) {
				ans += s[i];
			}
		}
		if(ans.empty()) cout << "[]";
		cout << ans << " ";
	}
}

int main() {
	int n = 3;
	string s = "abc";
	printSubset(n, s);
}
