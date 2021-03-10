# include <bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t;
	cin>>t;
	for(int k=1;k<=t;k++)
	{
		int n;
		cin>>n;
		int a[n+5][n+5];
		for(int i=0;i<n;i++)
		  for(int j=0;j<n;j++)
		   cin>>a[i][j];
		int sum=0;
		for(int i=0;i<n;i++) sum+=a[i][i];
		int count_column=0;
		int count_row=0;
		int temp=(n)*(n+1)/2;
	    for(int i=0;i<n;i++)
	    {
	    	int luu_vet[105]={0};
	    	for(int j=0;j<n;j++)
	    	{
	    		luu_vet[a[i][j]]++;
			}
			for(int i=1;i<=n;i++)
			{
				if(luu_vet[i]!=1)
				{
					count_row++;
					break;
				}
			}
		}
		for(int i=0;i<n;i++)
	    {
	    	int luu_vet[105]={0};
	    	for(int j=0;j<n;j++)
	    	{
	    		luu_vet[a[j][i]]++;
			}
			for(int i=1;i<=n;i++)
			{
				if(luu_vet[i]!=1)
				{
					count_column++;
					break;
				}
			}
		}
		cout<<"Case #"<<k<<": ";
		cout<<sum<<" "<<count_row<<" "<<count_column;
		cout<<"\n";
	}
}
