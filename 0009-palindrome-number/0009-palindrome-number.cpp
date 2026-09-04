class Solution {
public:
    int reverse(int n){
        long long ans=0;
        while(n>0){
            int rem=n%10;
            ans=ans*10+rem;
            n=n/10;

        }
        return ans;
    }

    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }

        // string s= to_string(x);

        // int i=0;
        // int j=s.size()-1;

        // while(i<j){
        //     if(s[i]!=s[j]){
        //         return false;
        //     }
        //     i++;
        //     j--;
        // }

        if(x==reverse(x)){
            return true;
        }

        else{
            return false;
        }

        
    }
};