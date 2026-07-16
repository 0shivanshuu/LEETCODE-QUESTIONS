class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        vector<int> prefixGcd;
        vector<int> mxi;
        int maxi=0;
        for(int i=0; i<nums.size(); i++){
            maxi=max(nums[i],maxi);
            mxi.push_back(maxi);
        }
        for(int i=0; i<nums.size(); i++){
            int gcdi=gcd(nums[i],mxi[i]);
            prefixGcd.push_back(gcdi);
        }
        sort(prefixGcd.begin(),prefixGcd.end());
        int i=0;
        int j=prefixGcd.size()-1;

        long long sum=0;
        while(i<j){
            sum=sum+ gcd(prefixGcd[i],prefixGcd[j]);
            i++;
            j--;
        }
        return sum;
    }

};