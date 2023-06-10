#include<bits/stdc++.h>
using namespace std;

void generateAllString(string s, int k, vector<string> &ans) {
	if(s.size() == k) {
		ans.push_back(s);
		return;
	}
	if(s[s.size()-1] == '1') generateAllString(s+'0', k, ans);
	else {
		generateAllString(s+'0', k, ans);
		generateAllString(s+'1', k, ans);
	}
}

vector<string> func(int k) {
	vector<string> ans;
	string s = "";
	s.push_back('0');
	generateAllString(s, k, ans);
	s[0] = '1';
	generateAllString(s, k, ans);
	return ans;
}

int main() {
	int k = 4;
	// func(k);
	vector<string> allStr = func(k);
	for(string s : allStr) cout << s << " "; 
}
