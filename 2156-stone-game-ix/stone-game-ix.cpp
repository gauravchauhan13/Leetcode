class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {

        int cnt[3] = {0, 0, 0};

        for (int x : stones)
        {
            cnt[x % 3]++;
        }

        // Stones divisible by 3 don't change the remainder.
        // They simply switch the turn.
        if (cnt[0] % 2 == 0)
        {
            return cnt[1] > 0 && cnt[2] > 0;
        }
        else
        {
            return abs(cnt[1] - cnt[2]) > 2;
        }
    }
};