// TC - O(N * K)
// SC - O(N * K)

class Solution {
  private:
  bool checkOneSubset(int index, int n, vector<int> &arr, int sum, int k, vector<vector<int>> &dp) {
        if(sum > k) return false;
        if(index == n) {
            if(sum == k) {
                return true;
            }
            return false;
        }

        if(dp[index][sum] != -1) return dp[index][sum];

        if(checkOneSubset(index+1, n, arr, sum + arr[index], k, dp) == true) return true;

        if(checkOneSubset(index+1, n, arr, sum, k, dp) == true) return true;

        return dp[index][sum] = false;
    }
    public:
    bool checkSubsequenceSum(int n, vector<int>& arr, int k) {
        // Code here
        vector<vector<int>> dp(n, vector<int>(k+1, -1));
        return checkOneSubset(0, n, arr, 0, k, dp);
    }
};
