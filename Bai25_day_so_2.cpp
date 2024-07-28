#include<bits/stdc++.h>
using namespace std;

#include<bits/stdc++.h>
using namespace std;

int n, a[15];
int b[15][15];

void Try(int n)
{
	for(int i = 1; i < n; i++)
	{
		b[n][i] = a[i];
		a[i] += a[i+1];
	}
	b[n][n] = a[n];
	if(n>=2)
		Try(n-1);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i = 1; i <= n; i++)
		{
			cin>>a[i];
		}
		
		Try(n);
		
		for(int i = 1; i <= n; i++)
		{
			cout<<"[";
			for(int j = 1; j < i; j++)
			{
				cout<<b[i][j]<<' ';
			}
			cout<<b[i][i];
			cout<<"] ";
		}
		cout<<endl;
	}
		
	return 0;
}