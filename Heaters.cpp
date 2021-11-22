// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        22 Nov 2021
//  @Detail  :        Heaters (LeetCode)
//  ============================
//  -->

class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(), heaters.end());
        int result = 0, n = heaters.size();
        for(int &x : houses)
        {
            int cur = INT_MAX;
            int idx = lower_bound(heaters.begin(), heaters.end(), x) - heaters.begin();
            if(idx >= 0 && idx < n && heaters[idx] == x)
                continue;            
            if(idx < n)
                cur = min(cur, heaters[idx] - x);
            if(idx - 1 >= 0)
                cur = min(cur, x - heaters[idx - 1]);
            if(result < cur)
                result = cur;
        }
        return result;
    }
};
