#include<bits/stdc++.h>
using namespace std;

int a[30], visited[30], n, sum, cnt;
int prime[40000];

void sive()
{
	prime[1] = 1, prime[0] = 1;
	for(int i = 2; i <= 200; i++)
	{
		for(int j = i*i; j <= 40000; j+=i)
			prime[j] = 1;	
	}	
}

void insert(vector<int> vt[], int k)
{
	cnt++;
	for(int i = 1; i <= k; i++)
		vt[cnt].push_back(a[visited[i]]);
}

void Try(vector<int> vt[], int i)
{
	for(int j = 1; j <= visited[i-1]-1; j++)
	{
		sum += a[j];
		visited[i] = j;
		
		if(!prime[sum])
			insert(vt,i);
		
		if(i < n)
			Try(vt, i+1);
		
		sum -= a[j];
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	sive();
	
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i = 1; i <= n; i++)
			cin>>a[i];
		
		sort(a+1,a+n+1);
		
		vector<int> vt[10005];
		sum = 0, cnt = 0;
		visited[0] = n+1;
		
		Try(vt,1);
		
		for(int i = 1; i <= cnt; i++)
		{
			for(int x:vt[i])
				cout<<x<<" ";
			cout<<endl;
		}
	}


	return 0;
}
