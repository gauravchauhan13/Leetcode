class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int n = words.size();

        int i = 0;

        while (i < n) {
            int j = i;
            int letters = 0;

            // Find the maximum number of words that fit
            while (j < n) {
                if (letters + words[j].size() + (j - i) > maxWidth)
                    break;

                letters += words[j].size();
                j++;
            }

            int wordCount = j - i;
            int gaps = wordCount - 1;

            string line;

            // Last line
            if (j == n) {
                for (int k = i; k < j; k++) {
                    if (k > i)
                        line += ' ';

                    line += words[k];
                }

                while (line.size() < maxWidth)
                    line += ' ';
            }

            // Only one word
            else if (wordCount == 1) {
                line += words[i];

                while (line.size() < maxWidth)
                    line += ' ';
            }

            // Fully justified line
            else {
                int totalSpaces = maxWidth - letters;

                int spacesPerGap = totalSpaces / gaps;
                int extraSpaces = totalSpaces % gaps;

                for (int k = i; k < j; k++) {
                    line += words[k];

                    if (k < j - 1) {
                        int spaces = spacesPerGap;

                        // Leftmost gaps get the extra spaces
                        if (k - i < extraSpaces)
                            spaces++;

                        for (int s = 0; s < spaces; s++)
                            line += ' ';
                    }
                }
            }

            ans.push_back(line);
            i = j;
        }

        return ans;
    }
};