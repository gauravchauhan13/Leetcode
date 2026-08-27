class Solution {
public:
    string lexGreaterPermutation(string s, string target) {

        int n = s.size();

        // Count characters in s
        vector<int> freq(26, 0);

        for (char c : s)
        {
            freq[c - 'a']++;
        }

        string ans = "";

        for (int i = 0; i < n; i++)
        {
            int x = target[i] - 'a';

            // Try to keep the current character equal to target[i]
            if (freq[x] > 0)
            {
                ans += target[i];
                freq[x]--;
                continue;
            }

            // We cannot use target[i].
            // Find the smallest character greater than target[i].
            int bigger = -1;

            for (int c = x + 1; c < 26; c++)
            {
                if (freq[c] > 0)
                {
                    bigger = c;
                    break;
                }
            }

            if (bigger != -1)
            {
                ans += char('a' + bigger);
                freq[bigger]--;

                // Put all remaining characters in sorted order
                for (int c = 0; c < 26; c++)
                {
                    while (freq[c] > 0)
                    {
                        ans += char('a' + c);
                        freq[c]--;
                    }
                }

                return ans;
            }

            /*
             * We cannot make this position greater.
             * We need to backtrack to an earlier position.
             */
            while (!ans.empty())
            {
                int last = ans.back() - 'a';
                ans.pop_back();
                freq[last]++;

                int targetValue = target[ans.size()] - 'a';

                for (int c = targetValue + 1; c < 26; c++)
                {
                    if (freq[c] > 0)
                    {
                        ans += char('a' + c);
                        freq[c]--;

                        for (int x = 0; x < 26; x++)
                        {
                            while (freq[x] > 0)
                            {
                                ans += char('a' + x);
                                freq[x]--;
                            }
                        }

                        return ans;
                    }
                }
            }

            return "";
        }

        // s itself was exactly equal to target.
        // We need the next larger permutation.
        while (!ans.empty())
        {
            int last = ans.back() - 'a';
            ans.pop_back();
            freq[last]++;

            int targetValue = target[ans.size()] - 'a';

            for (int c = targetValue + 1; c < 26; c++)
            {
                if (freq[c] > 0)
                {
                    ans += char('a' + c);
                    freq[c]--;

                    for (int x = 0; x < 26; x++)
                    {
                        while (freq[x] > 0)
                        {
                            ans += char('a' + x);
                            freq[x]--;
                        }
                    }

                    return ans;
                }
            }
        }

        return "";
    }
};