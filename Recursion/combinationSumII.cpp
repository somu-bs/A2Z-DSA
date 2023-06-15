// Brute Force
// TC - O(2^n * klog(set size))
// SC - (k * x)

class Solution {
private:
    void generateAllUniqueCombination(int index, int n, vector<int>& candidates, int target, vector<int> &singleCombo, set<vector<int>> &allCombo) {

            if(index == n) {
                if(target == 0) {
                    allCombo.insert(singleCombo);
                }
                return;
            }

            if(candidates[index] <= target) {
                singleCombo.push_back(candidates[index]);
                generateAllUniqueCombination(index+1, n, candidates, target - candidates[index], singleCombo, allCombo);
                singleCombo.pop_back();
            }
            generateAllUniqueCombination(index+1, n, candidates, target, singleCombo, allCombo);
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(begin(candidates), end(candidates));
        set<vector<int>> st;
        vector<int> singleCombo;
        generateAllUniqueCombination(0, candidates.size(), candidates, target, singleCombo, st);
        vector<vector<int>> ans;
        for(auto &it : st) {
            ans.push_back(it);
        }
        return ans;
    }
};



// Optimized version
// TC - O(2^n * k)
// SC - O(k * x)

class Solution {
private:
    void generateAllUniqueCombination(int index, int n, vector<int>& candidates, int target, vector<int> &singleCombo, vector<vector<int>> &allCombo) {

            if(target == 0) {
                allCombo.push_back(singleCombo);
                return;
            }
            for(int i = index;i<candidates.size();i++) {
                if(i > index && candidates[i] == candidates[i-1]) continue;
                if(candidates[i] > target) break;
                singleCombo.push_back(candidates[i]); // 1
                generateAllUniqueCombination(i+1, n, candidates, target - candidates[i], singleCombo, allCombo);
                singleCombo.pop_back();
            }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(begin(candidates), end(candidates));
        vector<vector<int>> ans;
        vector<int> singleCombo;
        generateAllUniqueCombination(0, candidates.size(), candidates, target, singleCombo, ans);
        return ans;
    }
};
