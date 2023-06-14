// TC - O(2^t * k)
// Here K is the len of average combination, t is the how many times element is picked to reach target
// SC - Depend on the number of combination we have O(k * x) x is number of combination and k is avg length of combination

class Solution {
private:
    void generateAllUniqueCombination(int index, int n, vector<int>& candidates, int target, vector<int> &singleCombo, vector<vector<int>> &allCombo) {

            if(index == n) {
                if(target == 0) {
                    allCombo.push_back(singleCombo);
                }
                return;
            }

            if(candidates[index] <= target) {
                singleCombo.push_back(candidates[index]);
                generateAllUniqueCombination(index, n, candidates, target - candidates[index], singleCombo, allCombo);
                singleCombo.pop_back();
            }
            generateAllUniqueCombination(index+1, n, candidates, target, singleCombo, allCombo);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> allCombo;
        vector<int> singleCombo;
        generateAllUniqueCombination(0, candidates.size(), candidates, target, singleCombo, allCombo);
        return allCombo;
    }
};
