// TC - O(2^n)
// SC - ~O(n)

class Solution {
private:
  void allSubsetSum(int index, int sum, vector<int> &arr, int n, vector<int> &allSum) {
          // When we hit after the last index means the end of the array
          if(index == arr.size()) {
              allSum.push_back(sum);
              return;
          }
          
          // Pick that particular index and move forward
          allSubsetSum(index+1, sum+arr[index], arr, n, allSum);
          
          // Not pick the current element move ahead
          allSubsetSum(index+1, sum, arr, n, allSum);
    }
public:
    vector<int> subsetSums(vector<int> arr, int n)
    {
        // Write Your Code here
        vector<int> allSum;
        allSubsetSum(0, 0, arr, n, allSum);
        return allSum;
    }
};
