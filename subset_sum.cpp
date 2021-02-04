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

int n,sum,i,j;
cin>>n>>sum;
ll arr[n+1];
for(i=1;i<=n;i++)
    cin>>arr[i];
/// f(i,j)-> considered till i th element, sum=j
bool dp[n+1][sum+1];
for(i=0;i<=n;i++)
    dp[i][0]=true;
for(i=1;i<=sum;i++)
    dp[0][i]=false;
for(i=1;i<=n;i++)
{
    for(j=1;j<=sum;j++)
    {
        ///  if i th element is excluded
        dp[i][j]=dp[i-1][j];
        if(arr[i]<=j)
            dp[i][j]|=dp[i-1][j-arr[i]];
        ///here we are taking dp[i-1][j-arr[i]] instead of dp[i][j-arr[i]]
        /// repetation is not allowed.
    }
}
cout<<dp[n][sum];






   ///runtime estimation to avoid TLE
   #ifndef ONLINE_JUDGE
        cout << "\nTime Elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " sec\n";
   #endif
}

