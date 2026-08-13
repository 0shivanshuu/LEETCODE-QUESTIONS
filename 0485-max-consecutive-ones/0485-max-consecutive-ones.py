class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        maxi=0
        count=0

        for i in range(0,len(nums)):
            if(nums[i]==1):
                count=count+1
            
            else:
                count=0
            maxi=max(count,maxi)
        
        return maxi