class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        n=0
        for i in range(0,len(nums)):
            if(nums[i]!=val):
                nums[n]=nums[i]
                n=n+1
        
        return n