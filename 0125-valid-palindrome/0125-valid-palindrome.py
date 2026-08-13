class Solution:
    def isPalindrome(self, s: str) -> bool:

        arr=[]

        for i in range(len(s)):
            if(s[i].isalnum()):
                arr.append(s[i])
        
        for i in range(len(arr)):
            arr[i]=arr[i].lower()


        i=0
        j=len(arr)-1

        while(i<j):
            if(arr[i]!=arr[j]):
                return False
            
            i+=1
            j-=1
        
        return True


        