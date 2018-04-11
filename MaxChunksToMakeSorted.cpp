class Solution {
    public:
        int maxChunksToSorted(vector<int>& arr) {
            int max_num = 0;
            int ans = 0;
            for (int i = 0; i < arr.size(); ++i) {
                max_num = max(max_num, arr[i]);
                if (max_num == i) ++ans;

            }
            return ans;

        }

};
