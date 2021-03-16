# include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=105;
int a[MAXN][MAXN];
int sum[MAXN][MAXN];
int dp[55][1555];
int ans;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t;
	cin>>t;
	for(int l=1;l<=t;l++)
	{
		int n,k,p;
		cin>>n>>k>>p;
		for(int i=1;i<=n;i++)
		  for(int j=1;j<=k;j++)
		  {
		    cin>>a[i][j];
		    sum[i][j]=sum[i][j-1]+a[i][j];
		   }
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=k;j++)
		{
			for(int q=j;q<=p;q++)
			{
				dp[i][q]=max(dp[i][q],max(dp[i-1][q],dp[i-1][q-j]+sum[i][j]));
			}
		}
	}
	cout<<"CASE #"<<l<<": "<<dp[n][p]<<"\n";
    }
	return 0;
}
