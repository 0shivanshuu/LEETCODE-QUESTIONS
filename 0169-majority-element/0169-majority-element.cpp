class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;

        for(int i : nums){
            mp[i]++;
        }

        int maxi=0;
        int ans=0;

        for(auto it: mp){
            if(it.second>maxi){
                maxi=it.second;
                ans=it.first;
            }
            
        }

        return ans;
    }
};