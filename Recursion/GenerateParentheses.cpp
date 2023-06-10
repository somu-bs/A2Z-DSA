class Solution {
private:
    void generateAllParen(int open, int close, string s, int n, vector<string> &ans) {
        if(s.size() == 2*n) {
            ans.push_back(s);
            return;
        }
        if(open < n) {
            generateAllParen(open + 1, close, s+'(', n, ans);
        }
        if(close < open) {
            generateAllParen(open, close+1, s+')', n, ans);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s = "";
        generateAllParen(0, 0, s, n, ans);
        return ans;
    }
};
