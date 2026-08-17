class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        
        mp={}

        for i in nums:
            mp[i]=mp.get(i,0)+1
        
        maxi=0
        ans=0


        for key,value in mp.items():
            if(value>maxi):
                ans=key
                maxi=value
            
        
        return ans

