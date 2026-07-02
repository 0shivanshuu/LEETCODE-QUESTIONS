class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int low=0;
        int ans=0;

        unordered_map<int,int> mp;
        

        for(int high=0; high<s.size(); high++){
            mp[s[high]]++;          
            while(mp[s[high]]>1){
                mp[s[low]]--;
                low++;


            } 

            ans=max(ans, high-low+1);
        }

        return ans;

        
    }
};