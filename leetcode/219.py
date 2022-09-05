class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        k += 1
        s = set()
        for i in range(0, min(k, len(nums))):
            if nums[i] in s:
                return True
            s.add(nums[i])
        
        for i in range(k, len(nums)):
            s.remove(nums[i-k])
            if nums[i] in s:
                return True
            s.add(nums[i])
        return False
