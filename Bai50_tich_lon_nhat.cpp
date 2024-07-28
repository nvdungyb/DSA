#include<bits/stdc++.h>
using namespace std;
 
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t = 1, n;
	while(t--)
	{
		cin>>n;
		int a[n+5];
		for(int i = 0; i < n; i++)
			cin>>a[i];
		
		sort(a,a+n);
		
		long long ans1 = a[0]*a[1];		
		long long ans2 = ans1*a[n-1];	// Giả sử hai số đầu tiên âm => max = âm*âm*dương_max
		long long ans3 = a[n-1]*a[n-2];	// So sánh với tích của 3 số lớn nhất.
		long long ans4 = ans3*a[n-3];
		
		long long tam1 = max(ans1, ans2);
		long long tam2 = max(ans3, ans4);
		cout<<max(tam1,tam2);
	}
  
	
	return 0;
}