#include <iostream>
#include <cmath>
#include <vector>
#include <queue>

using namespace std;

class Solution {
  public:
    int maxResult(std::vector<int>& nums, int k) {
      std::vector<int> memo (nums.size(), 0);
      std::priority_queue<pair<int, int>> pq;
      memo[nums.size()-1] = nums.back();
      pq.push({memo.back(), nums.size()-1});
      for (int i=nums.size()-2; i >=0; i--) {
        while (pq.size() && pq.top().second > (i+k))
          pq.pop();
        memo[i] = nums[i] + pq.top().first;
        pq.push({memo[i], i});
      }
      return memo[0];
    }
};


int main(){

  // std::vector<int> nums = {1, -1, -2, 4, -7, 3};
  std::vector<int> nums = {1, -5, -20, 4, -1, 3, -6, -3};
  int k = 2;
  int s = Solution().maxResult(nums, k);
  std::cout << "solution: " << s << endl;

  return 0;
}
