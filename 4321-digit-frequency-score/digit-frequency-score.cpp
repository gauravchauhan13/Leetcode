class Solution {
public:
    int digitFrequencyScore(int n) {
        unordered_map<int, int> freq;
        vector<int> num;

        while (n > 0) {
            int digit = n % 10;
            num.push_back(digit);
            n /= 10;
        }

        for (int i : num) {
            freq[i]++;
        }

        int sum = 0;

        for (auto it : freq) {
            sum += it.first * it.second;
        }

        return sum;
    }
};