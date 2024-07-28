#include<bits/stdc++.h>
using namespace std;


int n, k, a[15],
	ans, cnt;
	
void Try(int i, int start)
{
	if(i > k)
	{
		if(start == n)
			cnt++;
		return;
	}
	
	int sum = 0;
	for(int j = start; j < n; j++)
	{
		sum += a[j];
		if(sum == ans)
		{
			Try(i+1,j+1);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t;
	t = 1;
	while(t--)
	{
		cin>>n>>k;
		int sum = 0;
		for(int i = 0; i < n; i++){
			cin>>a[i];
			sum += a[i];
		}
		
		cnt = 0;
		if(sum%k == 0)
		{
			ans = sum/k;
			Try(1,0);
		}
		
		cout<<cnt<<endl;
	}


	return 0;
}