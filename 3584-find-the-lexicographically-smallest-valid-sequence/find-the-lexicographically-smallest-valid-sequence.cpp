class Solution {
public:
    vector<int> validSequence(string word1, string word2) {

        int n = word1.size();
        int m = word2.size();

        vector<int> ans(m);

        // last[j] = position in word1 where word2[j]
        // can be matched while matching the suffix from right to left.
        vector<int> last(m, -1);

        int i = n - 1;
        int j = m - 1;

        // Build the right-side matching information
        while (i >= 0 && j >= 0) {

            if (word1[i] == word2[j]) {
                last[j] = i;
                j--;
            }

            i--;
        }

        // We are allowed to use at most one mismatch.
        bool canSkip = true;

        j = 0;

        // Greedily choose the smallest possible indices.
        for (i = 0; i < n; i++) {

            if (j == m)
                break;

            // Exact match
            if (word1[i] == word2[j]) {
                ans[j] = i;
                j++;
            }

            // Use our one allowed mismatch
            else if (canSkip &&
                     (j == m - 1 || i < last[j + 1])) {

                ans[j] = i;
                j++;

                canSkip = false;
            }
        }

        // If we matched all characters, return the answer.
        if (j == m)
            return ans;

        return {};
    }
};