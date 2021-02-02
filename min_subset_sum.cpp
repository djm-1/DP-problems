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
ll sum=0;
for(i=1;i<=n;i++)
    sum+=arr[i];
bool dp[n+1][sum+1];

// 0 sum is always possible
for(i=0;i<=n;i++)
    dp[i][0]=true;

// we can't construct any sum (except 0) taking no element
for(i=1;i<=sum;i++)
    dp[0][i]=false;


for(i=1;i<=n;i++)
{
    for(j=1;j<=sum;j++)
    {
        dp[i][j]=dp[i-1][j];
        if(arr[i]<=j)
            dp[i][j]|=dp[i][j-arr[i]];
    }
}

ll min_diff=INT_MAX;

for(i=0;i<=sum;i++)
    if(dp[n][i])
        min_diff=min(min_diff,abs(sum-2*i));

cout<<min_diff;



   ///runtime estimation to avoid TLE
   #ifndef ONLINE_JUDGE
        cout << "\nTime Elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " sec\n";
   #endif
}

