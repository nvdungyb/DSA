#include<bits/stdc++.h>
using namespace std;

int n, k, a[20], b[20];

void genNext()
{
	int i = k;
	while(a[i] == n-k+i)
	{
		i--;
	}
	if(i == 0)
		return;
	a[i]++;
	for(int j = i+1; j <= k; j++)
		a[j] = a[j-1]+1;
}

bool check()
{
	for(int i = 1; i <= n; i++)
	{
		if(a[i] != b[i])
			return false;
	}
	return true;
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
		cin>>n>>k;
		for(int i = 1; i <= k; i++)
		{
			cin>>b[i];
			a[i] = i;
		}
		
		int cnt = 1;
		while(!check())
		{
			genNext();
			cnt++;
		}
		cout<<cnt<<endl;
	}
	
	return 0;
}