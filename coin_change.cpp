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

    ///m->coins n->target value

    ll m,n,i,j;
    cin>>m>>n;
    ll coin[m+1];
    for(i=1;i<=m;i++)
    {
        cin>>coin[i];
    }
    ///f(i,j)-> i=considered coin, j=target value
    ll dp[m+1][n+1];

    for(i=1;i<=m;i++)
        dp[i][0]=1;
    for(i=0;i<=n;i++)
        dp[0][i]=0;
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            dp[i][j]=dp[i-1][j];
            /// i is never included in sum
            if(coin[i]<=j)
            {
                dp[i][j]+=dp[i][j-coin[i]];
                /// because, i may be already present in the sum
            }
        }
    }

    cout<<dp[m][n];

//for(i=0;i<=m;i++)
//{
//    for(j=0;j<=n;j++)
//    {
//        cout<<dp[i][j]<<" ";
//    }
//    cout<<"\n";
//}

   ///runtime estimation to avoid TLE
   #ifndef ONLINE_JUDGE
        cout << "\nTime Elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " sec\n";
   #endif
}

