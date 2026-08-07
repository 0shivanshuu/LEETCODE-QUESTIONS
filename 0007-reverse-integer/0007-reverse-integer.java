class Solution {
    public int reverse(int x) { 
        long rev=0;   
        boolean neg=false;
        if(x<0){
            neg=true;
            x=Math.abs(x);
        }   
        while(x>0){
            int d=x%10;
            rev=rev*10+d;
            x=x/10;
        }
        if (rev < Integer.MIN_VALUE || rev > Integer.MAX_VALUE) {
            return 0;
        }

        if(neg){
            rev=-rev;
        }


        return (int) rev;
    }
}