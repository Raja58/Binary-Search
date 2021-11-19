// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        19 Nov 2021
//  @Detail  :        Minimum Garden Perimeter to Collect Enough Apples (LeetCode)
//  ============================
//  -->

class Solution {
public:
    
    bool getApples(long long mid, long long neededApples)
    {
        long long result = 0;
        for(long long i = 1; i <= mid; i++)
        {
            result += 12ll * i * i;
            if(result >= neededApples)
                return true;
        }
        return false;
    }
    
    long long minimumPerimeter(long long neededApples) {
        long long low = 1, high = sqrt(neededApples);
        while(low <= high)
        {
            long long mid = low + ((high - low) >> 1);
            
            if(!getApples(mid, neededApples))
                low = mid + 1;
            else
                high = mid - 1;
        }
        return 1ll * low * 8;
    }
};
