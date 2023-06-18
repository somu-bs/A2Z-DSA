// TC - O(2^n * n * k)
// TC - O(k * x)

class Solution {
private:
    bool isPalindrome(string s, int i, int j) {
        while(i <= j) {
            if(s[i++] != s[j--]) return false;
        }
        return true;
    }

    void possiblePartition(int index, string s, vector<string> &singlePartition,
    vector<vector<string>> &allPartition) {

        if(index == s.size()) {
            allPartition.push_back(singlePartition);
            return;
        }

        for(int i = index;i<s.size();i++) {
            if(isPalindrome(s, index, i)) {
                singlePartition.push_back(s.substr(index, i - index + 1));
                possiblePartition(i+1, s, singlePartition, allPartition);
                singlePartition.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> allPartition;
        vector<string> singlePartition;
        possiblePartition(0, s, singlePartition, allPartition);
        return allPartition;
    }
};
