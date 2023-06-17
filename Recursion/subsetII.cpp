// TC - O(2^n * mlogm)
// Using set

class Solution {
private:
    void findUniqueSubset(int index, vector<int>& nums, vector<int> &subset,
    set<vector<int>> &st) {

        if(index == nums.size()) { 
          st.insert(subset);
          return;
        }
        subset.push_back(nums[index]);
        findUniqueSubset(index+1, nums, subset, st);
        subset.pop_back();

        findUniqueSubset(index+1, nums, subset, st);
      
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> allUniqueSubset;
        vector<int> subset;
        set<vector<int>> st;
        findUniqueSubset(0, nums, subset, st);
        for(auto &it : st) {
          allUniqueSubset.push_back(it);
        }
        return allUniqueSubset;
    }
};


// Better Approach
// TC - O(2^n * n)
// SC - O(2^n * k)
// Auxiliary - O(n)

class Solution {
private:
    void findUniqueSubset(int index, vector<int>& nums, vector<int> &subset,
    vector<vector<int>> &allUniqueSubset) {

        allUniqueSubset.push_back(subset);
        for(int i = index;i<nums.size();i++) {
            if(i > index && nums[i] == nums[i-1]) continue;
            subset.push_back(nums[i]);
            findUniqueSubset(i+1, nums, subset, allUniqueSubset);
            subset.pop_back();
        }
      
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> allUniqueSubset;
        vector<int> subset;
        findUniqueSubset(0, nums, subset, allUniqueSubset);
        return allUniqueSubset;
    }
};
