#include<bits/stdc++.h>
using namespace std;

int a[1005], k, n;

void previous()
{
	int i = k;
	a[i]--;
	while(a[i-1] == a[i] && i >= 1)
	{
		i--;
		a[i]--;
	}
	
	for(int j = i+1; j <= k; j++)		// sinh tổ hợp lớn nhất nhỏ hơn tổ hợp đã cho.
		a[j] = n-k+j;
			
	for(int i = 1; i <= k; i++)
		cout<<a[i]<<" ";
	
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
		for(int i = 1; i <= k; i++)
			cin>>a[i];
			
		previous();
		cout<<endl;
	}
	

	return 0;
}
