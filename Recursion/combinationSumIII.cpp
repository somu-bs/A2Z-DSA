// TC - O(2^n * k)
// SC - O(m * k) + O(9)

class Solution {
private:
    void generateAllSumEqualN(int index, int sum, int n, int k, vector<int> &arr, vector<int> &singleCombo, vector<vector<int>> &allCombo) {
  
        if(index >= 9) return;
        if(singleCombo.size() == k) {
            if(sum == n) {
                allCombo.push_back(singleCombo);
            }
            return;
        }
    
        // Pick the current element
        singleCombo.push_back(arr[index]);
        generateAllSumEqualN(index+1, sum+arr[index], n, k, arr, singleCombo, allCombo);
        singleCombo.pop_back(); 
        
        // Not pick the current element and move forward
        generateAllSumEqualN(index+1, sum, n, k, arr, singleCombo, allCombo);
}
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        vector<vector<int>> allCombo;
        vector<int> singleCombo;
        generateAllSumEqualN(0, 0, n, k, arr, singleCombo, allCombo);
        return allCombo;
    }
};


// Minor optimization
// As the element are from 1-9 so we dont need the array
// We just increment the value by 1 and reach 9
// TC - O(2^9 * k)
// SC - O(m * k)

class Solution {
private:
    void generateAllSumEqualN(int value, int sum, int n, int k, vector<int> &singleCombo, vector<vector<int>> &allCombo) {
  
        if(value > 9) return;
        if(singleCombo.size() == k) {
            if(sum == n) {
                allCombo.push_back(singleCombo);
            }
            return;
        }
    
        // Pick the current element
        singleCombo.push_back(value);
        generateAllSumEqualN(value+1, sum+value, n, k, singleCombo, allCombo);
        singleCombo.pop_back(); 
        
        // Not pick the current element and move forward
        generateAllSumEqualN(value+1, sum, n, k, singleCombo, allCombo);
}
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> allCombo;
        vector<int> singleCombo;
        generateAllSumEqualN(1, 0, n, k, singleCombo, allCombo);
        return allCombo;
    }
};
