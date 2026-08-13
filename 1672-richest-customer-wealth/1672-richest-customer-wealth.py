class Solution:
    def maximumWealth(self, accounts: List[List[int]]) -> int:
        
        maxi=0

        for row in range(len(accounts)):
            sum=0
            for col in range(len(accounts[0])):
                sum=sum+accounts[row][col]

            maxi=max(sum,maxi)
        
        return maxi