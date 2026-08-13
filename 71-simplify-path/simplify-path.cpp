class Solution {
public:
    string simplifyPath(string path) {

        stack<string> st;

        string current = "";

        for (int i = 0; i <= path.size(); i++)
        {
            // If we reach '/' or the end, we have one token
            if (i == path.size() || path[i] == '/')
            {
                if (current == "" || current == ".")
                {
                    // Ignore
                }
                else if (current == "..")
                {
                    if (!st.empty())
                        st.pop();
                }
                else
                {
                    st.push(current);
                }

                current = "";
            }
            else
            {
                current += path[i];
            }
        }

        string ans = "";

        while (!st.empty())
        {
            ans = "/" + st.top() + ans;
            st.pop();
        }

        if (ans == "")
            return "/";

        return ans;
    }
};