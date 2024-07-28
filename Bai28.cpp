#include<bits/stdc++.h>
using namespace std;

int n, a[40], sum, k, ok;
int visited[100];

void display(int ans)
{
	ok = 1;
	cout<<"[";
	for(int i = 1; i < ans; i++)
		cout<<a[visited[i]]<<" ";
	cout<<a[visited[ans]];
	cout<<"] ";
}

void Try(int i)
{
	for(int j = visited[i-1]+1; j < n; j++)
	{
		sum += a[j];
		visited[i] = j;
		
		if(sum == k)
			display(i);
		else if(sum < k)
			Try(i+1);
			
		sum -= a[j];
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
		for(int i = 0; i < n; i++)
			cin>>a[i];
		
		sort(a,a+n);
		
		sum = 0, ok = 0;
		visited[0] = -1;
		
		Try(1);
		
		if(!ok)
			cout<<"-1";
		cout<<endl;
	}
	

	return 0;
}