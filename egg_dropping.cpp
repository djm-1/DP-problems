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

ll e,n,i,j;
/// n= number of floors and e=number of eggs
cin>>e>>n;
///f(e,k) state when we have e eggs and k floors to be considered
///if egg breaks, we have to go down to check threshold floor -> f(e-1,k-1)
///otherwise, we have to go up -> f(e,n-k)

ll dp[e+1][n+1];
ll val;

for(i=1;i<=n;i++)
    dp[1][i]=i;

for(i=1;i<=e;i++)
    dp[i][0]=0,dp[i][1]=1;

for(i=2;i<=e;i++)
{
    for(j=2;j<=n;j++)
    {
        dp[i][j]=INT_MAX;
        for(ll p=1;p<=j;p++)
        {
            val=max(dp[i-1][p-1],dp[i][j-p])+1;
            if(val<dp[i][j])
                dp[i][j]=val;
        }
    }
}
cout<<dp[e][n];






   ///runtime estimation to avoid TLE
   #ifndef ONLINE_JUDGE
        cout << "\nTime Elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " sec\n";
   #endif
}

