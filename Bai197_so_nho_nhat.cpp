#include<bits/stdc++.h>
using namespace std;

int s, d;

void minNum()
{
	int a[d];
	for(int i = 0; i < d; i++)
	{
		if(s >= 9)
		{
			a[i] = 9;
			s -= 9;
		}else{
			int ans = max(s, 0);
			a[i] = ans;
			s -= ans;
		}
	}
	
	if(a[d-1] == 0){
		int j = d-1;
		while(a[j] == 0)
		{
			j--;
		}
		a[j]--;
		a[d-1] = 1;
	}
	
	for(int i = d-1; i >= 0; i--)		
		cout<<a[i];
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
		cin>>s>>d;
		if(s > 9*d || s <= 0)
			cout<<"-1";
		else
			minNum();
		cout<<endl;
	}
	

	return 0;
}
