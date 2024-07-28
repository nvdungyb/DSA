#include<bits/stdc++.h>
using namespace std;

// bài này phải xắp sếp theo thứ tự tăng dần của số thứ 2 mới đúng.
// số thứ 2 là số kết thúc, số thứ 1 là số bắt đầu luôn nhỏ hơn số thứ 2.

bool cmp(pair<int,int> a, pair<int,int>b)
{
	return a.second < b.second;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		pair<int,int> a[n+5];
		for(int i = 0; i < n; i++)
		{
			cin>>a[i].first>>a[i].second;
		}
		
		sort(a,a+n,cmp);
		
		int resul = 1, pre = 0;
		for(int i = 1; i < n; i++)
		{
			if(a[i].first > a[pre].second)
			{
				resul++;
				pre = i;
			}
		}
		
		cout<<resul<<endl;		
	}


	return 0;
}
