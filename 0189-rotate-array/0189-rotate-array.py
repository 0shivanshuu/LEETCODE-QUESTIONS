class Solution:
    def rotate(self, nums: list[int], k: int) -> None:

        num=nums.copy()
        k = k % len(nums)

        n=len(nums)-k

        for i in range(k):
            nums[i]=num[n]
            n+=1
        
        j=0

        for i in range(k,len(nums)):
            nums[i]=num[j]
            j+=1
