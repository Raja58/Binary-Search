// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        17 Nov 2021
//  @Detail  :        PRATA - Roti Prata (SPOJ)
//  ============================
//  -->

#include <bits/stdc++.h>
using namespace std;
#define int long long
 
bool isPossible(int &x, int &p, vector<int> &rank)
{
    int result = 0;
    for(int &r : rank)
    {
        int tim = 0, paro = 0;
        while(tim < x)
        {
            if((paro + 1) * r + tim <= x)
            {
                tim += (paro + 1) * r;
                paro++;
            }
            else
                break;
        }
        result += paro;
    }
    return result >= p;
}
 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t;  cin>>t;
    while(t--)
    {
        int p, l, maxi = 0;   cin>>p>>l;
        vector<int> rank(l);
        for(int i = 0; i < l; i++)
        {
            cin>>rank[i];
            if(maxi < rank[i])
                maxi = rank[i];
        }
 
        int low = 0, high = maxi * ((p * (p + 1)) / 2);
        while(low <= high)
        {
            int mid = low + ((high - low) >> 1);
            if(isPossible(mid, p, rank))
                high = mid - 1;
            else
                low = mid + 1;
        }
        cout<<low<<"\n";
    }
    return 0;
}
