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
		int a[n+5], b[m+5], c[k+5];
		
		for(int i = 0; i < n; i++)
			cin>>a[i];
		for(int j = 0; j < m; j++)
			cin>>b[j];
		for(int i = 0; i < k; i++)
			cin>>c[i];
		
		int i = 0, j = 0, g = 0;
		int check = 0;
		while(i < n && j < m && g < k)
		{
			if(a[i] > b[j])
			{
				j++;
			}else if( a[i] < b[j]){
				i++;	
			}else{
				if(a[i] > c[g]){
					g++;
				}else if(a[i] < c[g]){
					i++;
				}else{
					cout<<a[i]<<" ";
					check = 1;
					i++, j++, g++;
				}
			}
		}
		if(!check)
			cout<<"NO";
		cout<<endl;
	}


	return 0;
}
