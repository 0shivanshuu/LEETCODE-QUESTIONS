class Solution:
    def maxSubarrayLength(self, nums: List[int], k: int) -> int:
        mp = {}

        i = 0
        ans = 0

        for j in range(len(nums)):
            mp[nums[j]] = mp.get(nums[j], 0) + 1

            while mp[nums[j]] > k:
                mp[nums[i]] -= 1
                i += 1

            ans = max(ans, j - i + 1)

        return ans