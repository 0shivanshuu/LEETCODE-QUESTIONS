class Solution:
    def minOperations(self, nums: List[int], k: int) -> int:
        
        mp={}

        for i in nums:
            mp[i]=mp.get(i,0)+1

        
        operation=0      

        for key,value in mp.items():
            if(key<k):
                operation=operation+value
            
        
        return operation
