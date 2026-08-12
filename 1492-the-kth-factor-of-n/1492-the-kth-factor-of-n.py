class Solution:
    def kthFactor(self, n: int, k: int) -> int:
        arr=[]

        for i in range(1,n+1):
            if(n%i==0):
                arr.append(i)
        
        if(k<=len(arr)):
            return arr[k-1]
        
        else:
            return -1