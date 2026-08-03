class Solution {
   public:
    string encode(vector<string>& strs) {
        string ans = "";
        for (auto& str : strs) {
            ans += to_string(str.size()) + "#" + str;
        }
        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        string len = "";
        int idx = 0;

        while (idx < s.size()) {
            while (s[idx] != '#') {
                len += s[idx++];
            }

            int l = stoi(len);
            len = "";
            idx++;  

            string str = "";
            for (int i = 0; i < l; i++) str += s[idx++];
            ans.push_back(str);
        }

        return ans;
    }
};
