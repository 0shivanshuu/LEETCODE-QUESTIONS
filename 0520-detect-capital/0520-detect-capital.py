class Solution:
    def detectCapitalUse(self, word: str) -> bool:

        count=0
        n=len(word)

        for i  in range(n):

          
            if(word[i]>='A' and word[i]<='Z'):
                count+=1
            
        

        if(count==n):
            return True
        elif(count==0):
            return True
        elif(word[0]>='A' and word[0]<='Z' and count==1):
            return True
        

        return False