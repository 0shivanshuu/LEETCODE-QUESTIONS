class Solution:
    def shortestBeautifulSubstring(self, s: str, k: int) -> str:
        ans = ""

        for i in range(len(s)):
            count = 0

            for j in range(i, len(s)):
                if s[j] == '1':
                    count += 1

                if count == k:
                    current = s[i:j + 1]

                    if ans == "" or len(current) < len(ans):
                        ans = current

                    elif len(current) == len(ans) and current < ans:
                        ans = current

                    break

        return ans