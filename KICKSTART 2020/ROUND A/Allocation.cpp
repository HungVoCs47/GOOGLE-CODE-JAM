# include <bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t;
	cin>>t;
	for(int k=1;k<=t;k++)
	{
		int n,m;
		cin>>n>>m;
		int a[n+10];
		for(int i=0;i<n;i++) cin>>a[i];
		sort(a,a+n);
		int sum=0;
		int cnt=0;
		for(int i=0;i<n;i++)
		{
			if(sum+a[i]<=m)
			{
				sum+=a[i];
				cnt++;
			}
		}
		cout<<"CASE #"<<k<<": "<<cnt<<"\n";
	}
	return 0;
}
