#include<bits/stdc++.h>
using namespace std;

// This problem is not like the minimum of swap to sorted array with give an array of n distinct elements.
// This problem is give an array of n element (indistinct).

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >>t ; 
	while(t--)
	{
		int n, dem = 0 ;
		cin >> n ;
		int a[n] ; 
		for(int i = 0 ; i < n ; i++)
		{
   		 	cin >> a[i] ;
    	}
		for(int i = 0 ; i < n ; i++)
		{
			int min = a[i] ;
	  	 	int m = 0; 
			for(int j = i + 1 ; j < n ; j++)
			{
				if(a[j] < min)
				{
			  		min = a[j] ;
			   		m = j;
				}
			}
			if(a[i] > min )
			{ 
				swap(a[i],a[m]); 
				dem++; 
			}	  
		}
		cout << dem << endl ; 
	} 	
	
	return 0;
}