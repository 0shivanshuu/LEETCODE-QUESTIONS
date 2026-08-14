class Solution:
    def maximumLengthSubstring(self, s: str) -> int:
        
        mp = {}
        left = 0
        maxi = 0

        for right in range(len(s)):
            
            mp[s[right]] = mp.get(s[right], 0) + 1

            while mp[s[right]] > 2:
                mp[s[left]] -= 1
                left += 1

            maxi = max(maxi, right - left + 1)

        return maxi