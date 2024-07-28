#include<bits/stdc++.h>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n,s;
	cin>>n>>s;
	int a[n+5], b[n+5];
	
	if(s > 9*n || s <= 0)
		cout<<"-1 -1";
	else{
		for(int i = 1; i <= n; i++)
		{
			if(s >= 9)
				a[i] = 9;
			else
				a[i] = s;
			s = max(s-9,0);
		}
		
		for(int i = 1; i <= n; i++)
		{
			b[i] = a[n-i+1];
		}
		
		if(b[1] == 0)
		{
			b[1]++;
			int j = 2;
			while(b[j] == 0){
				j++;
			}
			b[j]--;
		}
		
		for(int i = 1; i <= n; i++)
			cout<<b[i];
		cout<<" ";
		for(int i = 1; i <= n; i++)
			cout<<a[i];
	}


	return 0;
}
