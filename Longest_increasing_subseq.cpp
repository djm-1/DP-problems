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
ll arr[n+1],dp[n+1];
for(i=1;i<=n;i++)
    cin>>arr[i];

dp[0]=0;
dp[1]=1;

for(i=2;i<=n;i++)
{
    dp[i]=1;
    for(j=1;j<=i;j++)
    {
        if(arr[i]>arr[j])
        {
            dp[i]=max(dp[i],dp[j]+1);
        }
    }
}

/// LIS(n) indicates longest increasing subsequence ending at n
/// hence find the max among all of them
ll LIS=-1;
for(i=1;i<=n;i++)
    LIS=max(LIS,dp[i]);
cout<<LIS;


   ///runtime estimation to avoid TLE
   #ifndef ONLINE_JUDGE
        cout << "\nTime Elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " sec\n";
   #endif
}

