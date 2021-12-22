// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        22 Dec 2021
//  @Detail  :        H-Index (LeetCode)
//  ============================
//  -->

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int low = 0, high = n - 1;
        sort(citations.begin(), citations.end());
        while(low <= high)
        {
            int mid = low + ((high - low) >> 1);
            if(citations[mid] >= n - mid)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return n - low;
    }
};
