class Solution:
    def matrixReshape(self, mat: List[List[int]], r: int, c: int) -> List[List[int]]:
        
        rows = len(mat)
        cols = len(mat[0])

        if(r*c!=len(mat)*len(mat[0])):
            return mat
        

        ans=[[0]*c for i in range(r)]

        index=0
        for i in range(r):
            for j in range(c):
                oldrow=index//cols
                oldcol=index%cols
                ans[i][j]=mat[oldrow][oldcol]
                index+=1
        

        return ans

