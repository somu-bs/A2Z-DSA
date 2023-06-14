// TC - O(N * sum)
// SC - O(N * sum)

class Solution {
  private:
  int totalCountSum(int index, int arr[], int n, int s, int sum, vector<vector<int>> &dp) {
      if(s > sum) return 0;
      if(index == n) {
          if(s == sum) {
              return 1;
          }
          return 0;
      }

      if(dp[index][s] != -1) return dp[index][s];

      int left = totalCountSum(index+1, arr, n, s+arr[index], sum, dp);
      int right = totalCountSum(index+1, arr, n, s, sum, dp);

      return dp[index][s] = (left%mod + right%mod) % mod;
  } 
	public:
	int mod = 1e9 + 7;
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        vector<vector<int>> dp(n, vector<int>(sum+1, -1));
        return totalCountSum(0, arr, n, 0, sum, dp);
        
	}
};
