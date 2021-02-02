/*

    ******          *********        ***     ***
    *******         *********        ****   ****
    **    ***              **        ** ** ** **
    **     ***             **        **  ***  **
    **    ***       **     **        **   *   **
    *******          ********        **       **
    ******            *******        **       **




/*******Author:djm_boss*******/


#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll mod=1000000007;
ll inf=INT_MAX;
int main()
{
    ///fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ///file I/O
//   #ifndef ONLINE_JUDGE
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
//   #endif

   ///test cases(optional)
   ///code starts here.....BE CAREFUL!!!


ll n,i,j;
cin>>n;
vector<ll>arr(n+1);

for(i=1;i<=n;i++)
    cin>>arr[i];

/// length: 1   2   3   4   5   6   7   8
/// price:  1   5   8   9  10  17  17  20

/*
According to the problem condition, we can take a piece multiple times.
Similar to unbounded knapsack or coin change problem.

dp[i]=max(dp[i],dp[i-arr[j]]) for all j's st. arr[j]<=i

*/

ll dp[n+1];

dp[0]=0;
for(i=1;i<=n;i++)
{
    dp[i]=INT_MIN;
    for(j=0;j<i;j++)
    {
        dp[i]=max(dp[i],dp[j]+arr[i-j]);
    }
}

cout<<dp[n];


   ///runtime estimation to avoid TLE
   #ifndef ONLINE_JUDGE
        cout << "\nTime Elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " sec\n";
   #endif
}


