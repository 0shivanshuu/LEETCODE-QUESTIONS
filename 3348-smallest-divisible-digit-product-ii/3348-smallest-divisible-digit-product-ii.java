class Solution {

    int[][] factors = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {1, 0, 0, 0},
        {0, 1, 0, 0},
        {2, 0, 0, 0},
        {0, 0, 1, 0},
        {1, 1, 0, 0},
        {0, 0, 0, 1},
        {3, 0, 0, 0},
        {0, 2, 0, 0}
    };

    public String smallestNumber(String num, long t) {

        int[] need = new int[4];
        int[] primes = {2, 3, 5, 7};

        for (int i = 0; i < 4; i++) {
            while (t % primes[i] == 0) {
                need[i]++;
                t /= primes[i];
            }
        }

        if (t != 1) return "-1";

        int n = num.length();
        int[][] prefix = new int[n + 1][4];
        int[] zeroPrefix = new int[n + 1];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 4; j++) {
                prefix[i + 1][j] = prefix[i][j];
            }

            int digit = num.charAt(i) - '0';
            zeroPrefix[i + 1] = zeroPrefix[i];

            if (digit == 0) {
                zeroPrefix[i + 1]++;
            } else {
                for (int j = 0; j < 4; j++) {
                    prefix[i + 1][j] += factors[digit][j];
                }
            }
        }

        if (zeroPrefix[n] == 0 && covers(prefix[n], need)) {
            return num;
        }

        for (int position = n - 1; position >= 0; position--) {

            if (zeroPrefix[position] > 0) continue;

            int currentDigit = num.charAt(position) - '0';

            for (int digit = Math.max(1, currentDigit + 1);
                 digit <= 9;
                 digit++) {

                int[] remaining = new int[4];

                for (int j = 0; j < 4; j++) {
                    remaining[j] = Math.max(
                        0,
                        need[j] - prefix[position][j] - factors[digit][j]
                    );
                }

                int suffixLength = n - position - 1;

                if (minimumDigits(
                    remaining[0],
                    remaining[1],
                    remaining[2],
                    remaining[3]
                ) <= suffixLength) {

                    StringBuilder answer = new StringBuilder();

                    answer.append(num, 0, position);
                    answer.append(digit);
                    answer.append(buildSuffix(suffixLength, remaining));

                    return answer.toString();
                }
            }
        }

        int requiredLength = minimumDigits(
            need[0], need[1], need[2], need[3]
        );

        int newLength = Math.max(n + 1, requiredLength);

        return buildSuffix(newLength, need);
    }

    private boolean covers(int[] available, int[] need) {
        for (int i = 0; i < 4; i++) {
            if (available[i] < need[i]) return false;
        }

        return true;
    }

    private String buildSuffix(int length, int[] need) {

        StringBuilder suffix = new StringBuilder();
        int[] remaining = need.clone();

        for (int i = 0; i < length; i++) {

            int positionsLeft = length - i - 1;

            for (int digit = 1; digit <= 9; digit++) {

                int two = Math.max(
                    0, remaining[0] - factors[digit][0]
                );

                int three = Math.max(
                    0, remaining[1] - factors[digit][1]
                );

                int five = Math.max(
                    0, remaining[2] - factors[digit][2]
                );

                int seven = Math.max(
                    0, remaining[3] - factors[digit][3]
                );

                if (minimumDigits(two, three, five, seven)
                    <= positionsLeft) {

                    suffix.append(digit);

                    remaining[0] = two;
                    remaining[1] = three;
                    remaining[2] = five;
                    remaining[3] = seven;

                    break;
                }
            }
        }

        return suffix.toString();
    }

    private int minimumDigits(
        int two,
        int three,
        int five,
        int seven
    ) {

        int answer = five + seven;
        int minimum = Integer.MAX_VALUE;

        for (int sixes = 0;
             sixes <= Math.min(two, three);
             sixes++) {

            int remainingTwo = two - sixes;
            int remainingThree = three - sixes;

            int digitsForTwo = (remainingTwo + 2) / 3;
            int digitsForThree = (remainingThree + 1) / 2;

            minimum = Math.min(
                minimum,
                sixes + digitsForTwo + digitsForThree
            );
        }

        return answer + minimum;
    }
}