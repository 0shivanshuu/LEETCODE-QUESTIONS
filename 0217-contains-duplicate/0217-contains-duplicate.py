class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:

        x=len(set(nums))

        y=len(nums)

        return x!=y


        