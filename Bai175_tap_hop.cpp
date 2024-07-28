#include<bits/stdc++.h>
using namespace std;

int n, k, s;
int a[25];
int OK;

void genNext()
{
	int i = n;
	while(a[i] == 1)
	{
		a[i] = 0;
		i--;
	}
	if(i == 0){
		OK = 1;
	}
	else
		a[i] = 1;
}

bool check()
{
	int cnt = 0;
	for(int i = 1; i <= n; i++)
	{
		if(a[i] == 1)
			cnt++;
	}	
	if(cnt == k)
	{
		int ans = 0;
		for(int i = 1; i <= n; i++)
		{
			ans += a[i]*(n-i+1);
		}
		if(ans == s)
			return true;
		 
	}
	return false;
}	 
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin>>n>>k>>s;
	while(n != 0 || k != 0 || s != 0)
	{
		memset(a, 0, sizeof(a));
		int cnt = 0;
		OK = 0;
		while(!OK)
		{
			if(check())
				cnt++;
			genNext();
		}
		cout<<cnt<<endl;
		cin>>n>>k>>s;
	}
	 
	 
	return 0;
}

// Nghe giang hồ đồn đại là bài này còn cách làm hay hơn rất nhiều.

//int n, k, s, cnt, sum, 
//			x[100];
//
//void Try(int i)
//{
//	for(int j = x[i-1]+1; j <= n; j++)
//	{
//		x[i] = j;
//		sum += j;
//		if(i == k){
//			if(sum == s)
//				cnt++;
//		}else if(sum < s){
//			Try(i+1);
//		}
//		
//		sum -= j;
//	}
//}
//
//int main()
//{
//	ios_base::sync_with_stdio(0);
//	cin.tie(NULL);
//	cout.tie(NULL);
//
//	while(cin>>n>>k>>s)
//	{
//		if(n || k || s)
//		{
//			cnt = 0;
//			Try(1);
//			cout<<cnt<<endl;
//		}else{
//			break;
//		}
//	}
//
//
//	return 0;
//}
