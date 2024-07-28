#include<bits/stdc++.h>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t, n, K;
	cin>>t;
	while(t--)
	{
		cin>>n>>K;
		int a[n+5];
		for(int i = 0; i < n; i++)
			cin>>a[i];
		
		sort(a,a+n);
		
		int check = 0;
		for(int i = 0; i < n; i++)
		{
			int j = i+1, k = n-1;		// kĩ thuật hai con trỏ kết hợp với mảng đã sắp xếp.
			while(j < k)
			{
				if(a[i]+a[j]+a[k] > K)
				{
					k--;
				}else if(a[i]+a[j]+a[k] < K){
					j++;	
				}else{
					check = 1;
					break;
				}
			}
			if(check)
				break;
		}
		if(check)
			cout<<"YES";
		else
			cout<<"NO";
		
		cout<<endl;
	}
 
	
	return 0;
}

// độ phức tạp của thuật toán là O(n*n).