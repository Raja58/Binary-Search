// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        19 Jul 2021
//  @Detail  :        Aggressive Cows (SPOJ)
//  ============================
//  -->

#include <bits/stdc++.h>
using namespace std;
#define int long long

bool isPossible(int x, int &n, int &c, vector<int> &a)
{
    int cowsPlaced = 1, lastIdx = a.front();
    for(int i = 1; i < n; i++)
        if(a[i] - lastIdx >= x)
        {
            lastIdx = a[i];
            cowsPlaced++;
            if(cowsPlaced == c)
                return true;
        }
    return cowsPlaced >= c;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t;  cin>>t;
    while(t--)
    {
        int n, c, mini = INT_MAX;   cin>>n>>c;
        vector<int> a(n);
        for(int i = 0; i < n; i++)
            cin>>a[i];
        sort(a.begin(), a.end());
        for(int i = 1; i < n; i++)
            if(mini > a[i] - a[i - 1])
                mini = a[i] - a[i - 1];
        int low = mini, high = a.back() - a.front();
        while(low <= high)
        {
            int mid = low + ((high - low) >> 1);
            if(isPossible(mid, n, c, a))
                low = mid + 1;
            else
                high = mid - 1;
        }
        cout<<high<<"\n";
    }
    return 0;
}
