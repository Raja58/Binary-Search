// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        03 Nov 2021
//  @Detail  :        Roy and Coin Boxes (HackerEarth)
//  ============================
//  -->

#include <bits/stdc++.h>
using namespace std;
#define int long long
 
int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n, m;	cin>>n>>m;
	vector<int> input(n), update(n + 1);
	for(int i = 0; i < m; i++)
	{
		int l, r;	cin>>l>>r;
		l--;	r--;
		update[l]++;	update[r + 1]--;
	}
	int scan = 0;
	for(int i = 0; i < n; i++)
	{
		scan += update[i];
		input[i] = scan;
	}
	sort(input.begin(), input.end());
	int q;	cin>>q;
	for(int i = 0; i < q; i++)
	{
		int x;	cin>>x;
		cout<<n - (upper_bound(input.begin(), input.end(), x - 1) - input.begin())<<"\n";
	}
	return 0;
}
