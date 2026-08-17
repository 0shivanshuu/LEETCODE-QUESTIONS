class Solution:
    def majorityElement(self, nums: List[int]) -> List[int]:
        
        n=len(nums)
        mp={}

        arr=[]

        for i in nums:
            mp[i]=mp.get(i,0)+1
        

        for key,value in mp.items():
            if(value>n/3):
                arr.append(key)
            
        
        return arr

