class Solution:
    def mostFrequentEven(self, nums: List[int]) -> int:
        
        mp={}

        for i in nums:
            mp[i]=mp.get(i,0)+1
        
        ans=-1
        maxi=0       

        for key,value in mp.items():
            if((key%2==0 and maxi<value) or (key%2==0 and value==maxi and key<ans)):
                ans=key
                maxi=value

        
        return ans
