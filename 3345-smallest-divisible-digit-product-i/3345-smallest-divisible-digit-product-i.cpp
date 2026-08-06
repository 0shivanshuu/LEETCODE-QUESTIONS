class Solution {
public:
    int product(int n){

        int prod=1;
        int digit;

        while(n>0){
            digit=n%10;
            prod=prod*digit;
            n=n/10;


        }
        return prod;
    }

    
    int smallestNumber(int n, int t) {
        
        for(int i=n; i ; i++){
            if(product(i)%t==0){
                return i;
            }
        }
        return 0;
    }
};