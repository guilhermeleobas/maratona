class Solution {
  public:
    int jump(std::vector<int>& nums) {
      int n = nums.size();
      vector<int> memo (n, 0);
      for (int i=n-2; i >= 0; i--) {
        int m = 0x3f3f3f3f;
        for (int j=i+1; j<=min(i+nums[i], n-1); j++){
          m = min(m, memo[j]);
        }
        memo[i] = m + 1;
      }
      return memo[0];
    }
};
