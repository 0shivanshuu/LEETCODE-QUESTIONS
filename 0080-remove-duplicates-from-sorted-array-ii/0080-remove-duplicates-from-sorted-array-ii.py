class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:

        n=2

        for i in range(2,len(nums)):
            if(nums[i]!=nums[n-2]):
                nums[n]=nums[i]
                n+=1
            
        
        return n
        