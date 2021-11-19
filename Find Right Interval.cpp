// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        19 Nov 2021
//  @Detail  :        Find Right Interval (LeetCode)
//  ============================
//  -->

class Solution {
public:
    
    struct detail{
        vector<int> vec;
        int idx;
        bool operator<(const detail &x) const{
            return vec[0] < x.vec[0];
        }
    };
    
    
    int getIdx(int i, vector<detail> &input)
    {
        int x = input[i].vec[1];
        int low = i , high = input.size() - 1;
        while(low <= high)
        {
            int mid = low + ((high - low) >> 1);
            if(input[mid].vec[0] < x)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return low < input.size() && input[low].vec[0] >= x ? low : -1;
    }
    
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int> result(n, -1), temp(n, -1);
        vector<detail> input(n);
        for(int i = 0; i < n; i++)
            input[i] = {intervals[i], i};
        sort(input.begin(), input.end());
        
        for(int i = 0; i < n; i++)
            temp[i] = getIdx(i, input);
        
        for(int i = 0; i < n; i++)
            if(temp[i] != -1)
                result[input[i].idx] = input[temp[i]].idx;
        
        return result;
    }
};
