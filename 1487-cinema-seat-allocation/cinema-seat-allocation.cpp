class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {

        unordered_map<int, int> rows;

        // Store reserved seats as a bitmask for each row
        for (auto seat : reservedSeats)
        {
            int row = seat[0];
            int col = seat[1];

            // We only care about seats 2 to 9
            if (col >= 2 && col <= 9)
            {
                rows[row] |= (1 << col);
            }
        }

        // Initially assume every row can fit 2 groups
        int ans = 2 * n;

        for (auto [row, mask] : rows)
        {
            bool left = true;
            bool middle = true;
            bool right = true;

            // Seats 2,3,4,5
            for (int seat = 2; seat <= 5; seat++)
            {
                if (mask & (1 << seat))
                {
                    left = false;
                    break;
                }
            }

            // Seats 4,5,6,7
            for (int seat = 4; seat <= 7; seat++)
            {
                if (mask & (1 << seat))
                {
                    middle = false;
                    break;
                }
            }

            // Seats 6,7,8,9
            for (int seat = 6; seat <= 9; seat++)
            {
                if (mask & (1 << seat))
                {
                    right = false;
                    break;
                }
            }

            // We initially counted 2 groups for this row.
            // Determine how many groups this row can actually fit.

            if (left && right)
            {
                // Can use both sides
                continue;
            }
            else if (left || middle || right)
            {
                // Can fit one group
                ans--;
            }
            else
            {
                // Cannot fit any group
                ans -= 2;
            }
        }

        return ans;
    }
};