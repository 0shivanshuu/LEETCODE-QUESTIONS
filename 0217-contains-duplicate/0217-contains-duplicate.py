class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:

        t={}

        for i in nums:
            t[i]=t.get(i,0)+1

            if(t[i]==2):
                return True
            
        
        return False
        








        