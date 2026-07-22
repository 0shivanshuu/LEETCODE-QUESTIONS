class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int maxi = *max_element(nums.begin(), nums.end());

        vector<int> frequency(maxi + 1, 0);

        for (int number : nums) {
            frequency[number]++;
        }

        vector<long long> exactGCD(maxi + 1, 0);

        for (int d = maxi; d >= 1; d--) {
            long long divisibleCount = 0;

            for (int multiple = d; multiple <= maxi; multiple += d) {
                divisibleCount += frequency[multiple];
            }

            exactGCD[d] = divisibleCount * (divisibleCount - 1) / 2;

            for (int multiple = 2 * d; multiple <= maxi; multiple += d) {
                exactGCD[d] -= exactGCD[multiple];
            }
        }

        vector<long long> prefix(maxi + 1, 0);

        for (int d = 1; d <= maxi; d++) {
            prefix[d] = prefix[d - 1] + exactGCD[d];
        }

        vector<int> answer;

        for (long long query : queries) {

            int gcdValue = lower_bound(
                prefix.begin() + 1,
                prefix.end(),
                query + 1
            ) - prefix.begin();

            answer.push_back(gcdValue);
        }

        return answer;
    }
};