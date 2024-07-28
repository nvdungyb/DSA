#include<bits/stdc++.h>
using namespace std;

int n, a[15];

void Try(int n)
{
	if(n == 1)
		cout<<"[";
	for(int i = 1; i < n; i++)
	{
		if(i == 1)	
			cout<<"[";
		cout<<a[i]<<" ";
		a[i] += a[i+1];
	}
	cout<<a[n]<<"]" <<endl;
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
			cin>>a[i];
		Try(n);
		cout<<endl;
	}
		
	return 0;
}