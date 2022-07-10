class Solution {
  public:
    int canJump(std::vector<int>& nums) {
      std::vector<int> memo (nums.size(), false);
      int valid = nums.size()-1;
      memo[nums.size()-1] = 1;
      for (int i=nums.size()-2; i >=0; i--) {
        // printf("%d + %d > %d\n", nums[i], i, valid);
        if (nums[i] + i >= valid) {
          valid = i;
          memo[i] = 1;
        } else {
          memo[i] = 0;
        }
      }
      return memo[0];
    }
};
