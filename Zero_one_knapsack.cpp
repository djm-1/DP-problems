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


ll n,i,j,weight;
cin>>n>>weight;
vector<ll>val(n+1),w(n+1);
for(i=1;i<=n;i++)
    cin>>val[i];

for(i=1;i<=n;i++)
    cin>>w[i];

ll dp[n+1][weight+1];

for(i=0;i<=n;i++)
{
    for(j=0;j<=weight;j++)
    {
        if(i==0||j==0)
            dp[i][j]=0;
        else
        {
            if(w[i]<=j)
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i]]+val[i]);
            else
                dp[i][j]=dp[i-1][j];
        }
    }
}

cout<<dp[n][weight];




   ///runtime estimation to avoid TLE
   #ifndef ONLINE_JUDGE
        cout << "\nTime Elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " sec\n";
   #endif
}

