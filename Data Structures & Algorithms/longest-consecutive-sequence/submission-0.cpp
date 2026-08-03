class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        map<int, bool> nt;
        for (int i = 0; i < n; i++) {
            nt[nums[i]] = true;
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (nt[nums[i] - 1]) continue;
            int len = 0, start = nums[i];
            while(nt[start]){
                len++;
                start++;
            }

            ans = max(ans,len);
        }
        return ans;
    }
};
