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
		
		int resul = n;
		int i = (n/2)-1, j = n-1;
		while(j > (n/2)-1 && i >= 0)
		{
			if(a[j] >= 2*a[i])
			{
				resul--;
				i--, j--;
			}else{
				i--;
			}
		}
		
		cout<<resul<<endl;
	}
	

	return 0;
}

// Tư tưởng của bài này là nếu có thế ghép cặp thì số cặp tối đa có thể ghép được là n/2 với n là số con kanguru.
// Vậy ta cần chia mảng thành hai nửa và thực thi ghép cặp với lần lượt số lớn nhất của hai nửa.




