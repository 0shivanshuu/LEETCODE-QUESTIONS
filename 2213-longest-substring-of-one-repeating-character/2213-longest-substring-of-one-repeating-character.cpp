class Solution {
public:
    struct Node {
        int len;
        int prefix;
        int suffix;
        int longest;
        char leftChar;
        char rightChar;
    };

    int n;
    string s;
    vector<Node> tree;

    Node mergeNode(Node left, Node right) {
        Node ans;

        ans.len = left.len + right.len;
        ans.leftChar = left.leftChar;
        ans.rightChar = right.rightChar;

        ans.prefix = left.prefix;

        if (left.prefix == left.len &&
            left.rightChar == right.leftChar) {
            ans.prefix = left.len + right.prefix;
        }

        ans.suffix = right.suffix;

        if (right.suffix == right.len &&
            left.rightChar == right.leftChar) {
            ans.suffix = right.len + left.suffix;
        }

        ans.longest = max(left.longest, right.longest);

        if (left.rightChar == right.leftChar) {
            ans.longest = max(ans.longest,
                              left.suffix + right.prefix);
        }

        return ans;
    }

    void build(int index, int low, int high) {
        if (low == high) {
            tree[index] = {1, 1, 1, 1, s[low], s[low]};
            return;
        }

        int mid = low + (high - low) / 2;

        build(2 * index, low, mid);
        build(2 * index + 1, mid + 1, high);

        tree[index] = mergeNode(tree[2 * index],
                                tree[2 * index + 1]);
    }

    void update(int index, int low, int high,
                int position, char ch) {
        if (low == high) {
            s[position] = ch;
            tree[index] = {1, 1, 1, 1, ch, ch};
            return;
        }

        int mid = low + (high - low) / 2;

        if (position <= mid) {
            update(2 * index, low, mid, position, ch);
        } else {
            update(2 * index + 1, mid + 1, high, position, ch);
        }

        tree[index] = mergeNode(tree[2 * index],
                                tree[2 * index + 1]);
    }

    vector<int> longestRepeating(
        string s,
        string queryCharacters,
        vector<int>& queryIndices
    ) {
        this->s = s;
        n = s.size();

        tree.resize(4 * n);

        build(1, 0, n - 1);

        vector<int> lengths;

        for (int i = 0; i < queryIndices.size(); i++) {
            int position = queryIndices[i];
            char ch = queryCharacters[i];

            update(1, 0, n - 1, position, ch);

            lengths.push_back(tree[1].longest);
        }

        return lengths;
    }
};