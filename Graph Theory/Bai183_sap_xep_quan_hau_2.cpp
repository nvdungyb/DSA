#include<bits/stdc++.h>
using namespace std;

int a[9][9];
int sum, fopt;
int xuoi[20], nguoc[20], dong[10];

// chỉ số của mảng bắt đầu từ (1,1) -> (n,n).
// xuoi:  1 <= i+j-1 <= 2n-1.
// nguoc: 1 <= i-j+n <= 2n-1.

void Try(int i)
{
	for(int j = 1; j <= 8; j++)
	{
		if(!xuoi[i+j-1] && !nguoc[i-j+8] && !dong[j])
		{
			sum += a[i][j];
			xuoi[i+j-1] = 1;
			nguoc[i-j+8] = 1;
			dong[j] = 1;
			
			if(i == 8)
			{
				if(sum > fopt)
					fopt = sum;
			}else if(i < 8){
				Try(i+1);
			}
			
			sum -= a[i][j];
			xuoi[i+j-1] = 0;
			nguoc[i-j+8] = 0;
			dong[j] = 0;
		}
	}
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
		for(int i = 1; i <= 8; i++)
		{
			for(int j = 1; j <= 8; j++)
				cin>>a[i][j];
		}
		
		sum = 0, fopt = 0;
		memset(xuoi, 0, sizeof(xuoi));
		memset(nguoc, 0, sizeof(nguoc));
		memset(dong, 0, sizeof(dong));
		
		Try(1);
		cout<<fopt<<endl;
	}


	return 0;
}
