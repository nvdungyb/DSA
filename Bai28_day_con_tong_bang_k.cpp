#include<bits/stdc++.h>
using namespace std;

int n, k, ok;
int ans, a[15];
int b[15];

void display(int n)
{
	cout<<"[";
	for(int i = 1; i < n; i++)
	 	cout<<b[i]<<" ";
	cout<<b[n];
	cout<<"] ";
}

void Try(int i)
{
	for(int j = i; j <= n; j++)
	{
		if(a[j] > b[i-1] || a[1] == 0 && i == 1)
		{
			ans += a[j];
			b[i] = a[j];
			if(ans == k)
			{
				display(i);
				ok = 1;
			}
			else if(ans < k)
				Try(i+1);
			ans -= a[j];
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
 		for(int i = 1; i <= n; i++)
 			cin>>a[i];
 		
 		sort(a+1,a+n+1);
 		//memset(b, 0, sizeof(b));
 		ans = 0;
 		ok = 0;
 		Try(1);
 		if(!ok)
 			cout<<"-1";
 		cout<<endl;
	}
 	
	
	return 0;
}