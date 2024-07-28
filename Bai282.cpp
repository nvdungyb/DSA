#include<bits/stdc++.h>
using namespace std;

int n, k, a[30], ans, sum, cnt;
bool visited[30];

void Try(int i)
{
	if(cnt == k)
		return;
	
	for(int j = 1; j <= n; j++)
	{
		if(!visited[j] && sum+a[j] <= ans)
		{
			visited[j] = true;
			sum += a[j];
			
			if(sum == ans)
			{
				cnt++; sum = 0;			// Khởi tạo lại giá trị sum.
				Try(1);
			}else if(sum < ans)
			{
				Try(i+1);
			}
			
			sum -= a[j];
			visited[j] = false;
		}
	}
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
		ans = 0;
		for(int i = 1; i <= n; i++)
		{
			cin>>a[i];
			ans += a[i];
		}
		
		cnt = 0;
		if(ans%k == 0)
		{
			ans /= k;
			sum = 0;
			memset(visited, false, sizeof(false));
			Try(1);
		}
		
		if(cnt == k)
			cout<<"1";
		else
			cout<<"0";
			
		cout<<endl;
	}


	return 0;
}
