class Solution:
    def singleNumber(self, nums: List[int]) -> int:
       mp={}
       for i in nums:
        mp[i]=mp.get(i,0)+1
        

       for key,value in mp.items():
            if (value==1):
                return key

            
    


        
