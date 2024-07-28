#include<bits/stdc++.h>
using namespace std;


// giải bài toán cặp nghịch thế bằng cây fenwich
#define maxn 1000009
long long result;

int bit[maxn];

void update(int idx)
{
	while(idx <= maxn)
	{
		bit[idx] += 1;
		idx += (idx & -idx);
	}
}

long long get(int idx)
{
	long long ans = 0;
	while(idx)
	{
		ans += bit[idx];
		idx -= (idx & -idx);
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t, n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		memset(bit, 0, sizeof(bit));
		int a[n+5];
		for(int i = 1; i <= n; i++)
			cin>>a[i];
		
		result = 0;
		for(int i = n; i >= 1; i--)
		{
			result += get(a[i]-1);
			update(a[i]);
		}
		
		cout<<result<<endl;
	}


	return 0;
}
