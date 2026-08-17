class Solution:
    def rowAndMaximumOnes(self, mat: List[List[int]]) -> List[int]:
        
        n=len(mat)
        m=len(mat[0])
        row=0
        ans=0

        for i in range(0,n):
            count=0

            for j in range(m):

                if(mat[i][j]==1):

                    count=count+1
            if(count>ans):
                ans=count
                row=i
            
        
        return [row,ans]

