#include<bits/stdc++.h>
using namespace std;


int a[20], sum , n, x[20];

void display(int k)
{
	for(int i = 1; i <= k; i++)
		cout<<a[x[i]]<<" ";
	cout<<endl;
}

void Try(int i)
{
	for(int j = 1; j < x[i-1]; j++)				// đây là kiểu xét theo thứ tự giảm dần.	
	{
		sum += a[j];
		x[i] = j;
		
		if(sum%2 == 1){
			display(i);
		}
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
		cin>>n;
		for(int i = 1; i <= n; i++)
			cin>>a[i];
		
		sort(a+1,a+n+1);
		
		x[0] = n+1;
		Try(1);
		
	}

	return 0;
}
