class Solution {
  public:
    int canJump(std::vector<int>& nums) {
      int valid = nums.size()-1;
      for (int i=nums.size()-2; i >=0; i--) {
        // printf("%d + %d > %d\n", nums[i], i, valid);
        if (nums[i] + i >= valid)
          valid = i;
      }
      return (valid == 0);
    }
};
