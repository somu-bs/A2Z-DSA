class Solution {
private:
    void allPossibleCombination(int index, string s, vector<string> &ans, string digits, vector<string> &mpp) {
        if(index == digits.size()) {
            if(s != "") ans.push_back(s);
            return;
        }

        string letters = mpp[digits[index] - '0'];
        for(int i = 0;i<letters.size();i++) {
            allPossibleCombination(index+1, s+letters[i], ans, digits, mpp);
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        vector<string> mpp = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ans;
        allPossibleCombination(0, "", ans, digits, mpp);
        return ans;
    }
};
