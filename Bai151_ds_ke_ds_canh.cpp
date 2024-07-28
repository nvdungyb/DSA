#include<bits/stdc++.h>
using namespace std;


// đọc một dòng dữ liệu vào trong c++.
// getline(cin, string_s);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, t;
	cin>>n;
	t = n;
	int a[55][55];
	memset(a, 0, sizeof(a));
	cin.ignore();
	int i = 1;
	while(t--)
	{
		string s;
		getline(cin,s);
		s+=" ";
		int j = 0;
		int m = s.length();
		for(int k = 0; k < m; k++)
		{
			if(s[k] == ' ')
			{
				a[i][j] = 1; a[j][i] = 1;
				j = 0;
			}else{
				j = j*10 + s[k]-'0';
			}
		}
		i++;		
	}
	
	for(int i = 1; i <= n; i++)
	{
		for(int j = i+1; j <= n; j++)
		{
			if(a[i][j] == 1)
				cout<<i<<" "<<j<<endl;
		}
	}

	return 0;
}