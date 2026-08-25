class Solution:
    def missingMultiple(self, nums: List[int], k: int) -> int:

        mp = {}

        for num in nums:
            mp[num] = 1

        multiple = k

        while multiple in mp:
            multiple += k

        return multiple