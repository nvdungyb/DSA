#include<bits/stdc++.h>
using namespace std;

struct job{
	int stt, dead, profit;
};

bool cmp(job a, job b)
{
	return a.profit > b.profit;
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
		job a[n+5];
		for(int i = 0; i < n; i++)
		{
			cin>>a[i].stt>>a[i].dead>>a[i].profit;
		}
		
		sort(a,a+n,cmp);
		
		int visited[1001] = {0};
		long long sum = 0;
		int cnt = 0;
		for(int i = 0; i < n; i++)
		{
			while(visited[a[i].dead] && a[i].dead > 0){
				a[i].dead--;
			}
			
			if(!visited[a[i].dead] && a[i].dead > 0)
			{
				visited[a[i].dead] = 1;
				sum += a[i].profit;
				cnt++;
			}
		}
		cout<<cnt<<" "<<sum;
		cout<<endl;
	}


	return 0;
}
