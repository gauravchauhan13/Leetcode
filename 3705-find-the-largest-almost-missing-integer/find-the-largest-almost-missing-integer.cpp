class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {

        int n = nums.size();

        // count[x] = number of size-k subarrays containing x
        int count[51] = {0};

        for (int i = 0; i <= n - k; i++)
        {
            set<int> st;

            // Create the current window
            for (int j = i; j < i + k; j++)
            {
                st.insert(nums[j]);
            }

            // Each distinct number occurs in this subarray
            // exactly once as a "contained in this window" event
            for (int x : st)
            {
                count[x]++;
            }
        }

        // Find the largest almost missing integer
        for (int x = 50; x >= 0; x--)
        {
            if (count[x] == 1)
                return x;
        }

        return -1;
    }
};