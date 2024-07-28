#include<bits/stdc++.h>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t, n, m, k;
	cin>>t;
	while(t--)
	{
		cin>>n>>m>>k;
		
		string s, ss, sss;
		cin>>s>>ss>>sss;
		
		// cách đưa chỉ số của xâu về chỉ số của mảng 3 chiều.
		s = " "+s;
		ss = " "+ss;
		sss = " "+sss;
		 
		int a[n+5][m+5][k+5];
		memset(a, 0 , sizeof(a)); 
	
		for(int i = 1;  i <= n; i++)
		{
			for(int j = 1; j <= m; j++)
			{
				for(int h = 1; h <= k; h++)
				{
					if(s[i] == ss[j] && s[i] == sss[h])
						a[i][j][h] = a[i-1][j-1][h-1]+1;
					else{
						a[i][j][h] = max(max(a[i-1][j][h], a[i][j-1][h]),a[i][j][h-1]);
					}
				}
			}
		}
		cout<<a[n][m][k]<<endl;
	}
	

	return 0;
}

// Tư tưởng của ba xâu con chung dài nhất: cũng giống như hai xâu con chung dài nhất.
/*
+ sử dụng mảng 3 chiều để lưu độ lớn xâu con của i kí tự đầu tiên của xâu 1 và j kí tự đầu tiên của xâu 2 và h kí tự đầu tiên của xâu 3.

*/