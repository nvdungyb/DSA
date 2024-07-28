#include<bits/stdc++.h>
using namespace std;


void nhap(long long a[],int n)
{
	for(int i = 0; i < n; i++)
		cin>>a[i];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t, n1, n2, n3;
	cin>>t;
	while(t--)
	{
		cin>>n1>>n2>>n3;
		long long a[n1], b[n2], c[n3];
		nhap(a,n1),nhap(b,n2),nhap(c,n3);
		
		int i = 0, l = 0, k = 0;
		int check = 0;
		while(i < n1 && l < n2 && k < n3)
		{
			if(a[i] < b[l])
			{
				i++;
			}else if(a[i] > b[l]){
				l++;
			}else{
				if(a[i] < c[k]){
					i++;
				}else if(a[i] > c[k]){
					k++;
				}else{
					cout<<a[i]<<" ";
					i++, l++, k++;
					check = 1;
				}
			}
		}
		if(!check)
			cout<<"-1";
			
		cout<<endl;	
	}
 
	
	return 0;
}