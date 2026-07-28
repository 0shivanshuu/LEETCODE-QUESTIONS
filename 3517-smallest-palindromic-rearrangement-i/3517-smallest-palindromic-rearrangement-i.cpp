class Solution {
public:
    string smallestPalindrome(string s) {

        string s1 = s;

        sort(s1.begin(), s1.end());

        string s2(s.size(), ' ');

        int i = 0;
        int j = s1.size() - 1;

        int k = 0;

        while(k < s1.size()){

            if(k + 1 < s1.size() && s1[k] == s1[k + 1]){

                s2[i] = s1[k];
                s2[j] = s1[k];

                i++;
                j--;

                k = k + 2;
            }
            else{

                s2[s1.size() / 2] = s1[k];

                k++;
            }
        }

        return s2;
    }
};