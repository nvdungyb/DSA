#include<bits/stdc++.h>
using namespace std;

int n, k;

int find(int a[],int l, int r, int key)		// kĩ thuật chặt nhị phân mình nghĩ ra khá hay.
{
	if(l <= r)
	{
		int mid = (l+r)/2;
		if(a[mid] <= key)
		{
			int ans = find(a,mid+1,r,key);
			if(ans != -1)
				return ans;
			else
				return mid;
		}else{
			int ans = find(a,l,mid-1,key);
			if(ans)
				return ans;
		}
	}
	
	return -1;
}

void count(int a[])
{
	long long cnt = 0;
	for(int i = 0; i < n; i++)
	{
		int ans = find(a, i+1, n-1, a[i]+k-1);
		if(ans != -1)
			cnt += (ans-i);
	}
	cout<<cnt;
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
		int a[n+5];
		for(int i = 0; i < n; i++)
			cin>>a[i];
		
		sort(a,a+n);
		
		count(a);
		cout<<endl;
	}


	return 0;
}
