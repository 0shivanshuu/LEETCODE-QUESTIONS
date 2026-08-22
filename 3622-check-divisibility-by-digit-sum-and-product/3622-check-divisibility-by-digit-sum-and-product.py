class Solution:
    def checkDivisibility(self, n: int) -> bool:

        t=n
        s=n
        digit_sum=0
        product_sum=1


        while(t>0):
            rem=t%10
            digit_sum=digit_sum+rem
            t=t//10
        
        while(n>0):
            rem=n%10
            product_sum= product_sum *rem
            n=n//10
        
        ans=product_sum+digit_sum

        if(s%ans==0):
            return True
        
        else:
            return False

            

        


        