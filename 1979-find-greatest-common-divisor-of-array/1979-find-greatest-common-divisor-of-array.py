class Solution:
    def findGCD(self, nums: List[int]) -> int:
        
        new_arr= sorted(nums)

        n=new_arr[0]
        m=new_arr[len(nums)-1]

        ans=math.gcd(n,m)

        return ans