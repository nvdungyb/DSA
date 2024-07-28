#include<bits/stdc++.h>
using namespace std;
 
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

 	int t, n;
 	cin>>t;
 	while(t--)
 	{
 		cin>>n;
 		int a[n+5];
 		for(int i = 0; i < n; i++)
 			cin>>a[i];
 		
 		sort(a,a+n);
 		
		long long num1 = 0, num2 = 0;
		for(int i = 0; i < n; i+=2)
			num1 = num1*10 + a[i];
		
		for(int i = 1; i < n; i+=2)
			num2 = num2*10 + a[i];
		
		cout<<num1+num2;	
		
		cout<<endl;		
	}
	
	return 0;
}

// Tổng số được tạo từ vị trí lẻ và số được tạo từ vị trí chẵn của mảng đã sắp xếp cho ra số nhỏ nhất.
