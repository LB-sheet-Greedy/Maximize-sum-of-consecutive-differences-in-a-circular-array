/*
Sort karo and smallest largest aise swap karte jaao

Time Complexity: O(nlogn). 
Auxiliary Space : O(1)


use 2 pointers and a vector to modify array

i/p >> 1  2  3  4  5  6
o/p >> 1  6  2  5  3  4

i/p >> 1  2  3  4  5  6  temp = 2
       |             |

       1  6  2  4  5    temp = 3

ex:

a1 a2 a3 a4 a5

1, 2, 3, 4, 5

1, 5, 2, 4, 3 => a1a5a2a4a3

ex:

a1 a2 a3 a4 a5 a6

1  2  3  4  5  6

1  6  2  5  3  4 => a1a6a2a5a3a4

TASKS:

>> upar jaise arrange karo (use 2 pointer aproach)
>> baad me calclate karo alag func() bnaake


*/

#include <bits/stdc++.h>
using namespace std;

int sum(int arr[], int n)
{
	int sum=0,diff;
	
	for(int i=0;i<n-1;i++)  
	{
		
		diff=(arr[i]-arr[i+1]);
		//cout<<"\n"<<"( "<<arr[i]<<"-"<<arr[i+1]<<" )"<<" => "<<diff;
		sum=sum+abs(diff);
	}
	
	//ab circular array hai to last term ka first term ke saath bhi difference lo
	sum=sum+abs(arr[n-1]-arr[0]);
	
	return sum;
}

int maxSum(int arr[], int n)
{
    int Sum = 0;
 
    // Sorting the array.
    sort(arr, arr + n);
 	
 	int l=0;
 	int r=n-1;
    
    vector<int> v;
    
    //traverse karo array ko and vector me fill karo values ek ek karke
    
    //agar array length even hai to koi dikkat nhi but agar odd hai to mid element ko vector ke last me insert karna hoga
    if(n%2==0)
    {
    	while(l<r)
    	{
    		v.push_back(arr[l]);
    		v.push_back(arr[r]);
    		l++;
    		r--;
		}
	}
	else if(n%2==1)
	{
		while(l<r)
    	{
    		v.push_back(arr[l]);
    		v.push_back(arr[r]);
    		l++;
    		r--;
		}
		if(l==r)
		{
			v.push_back(arr[n/2]);
		}
	}
	
	//copying vectors's values
	for(int i=0;i<n;i++)
	{
		arr[i]=v[i];
	}
	
	Sum=sum(arr,n);
 
    return Sum;
}

// Driver Program
int main()
{
    int arr[] = { 4, 2, 1, 8 };
    //1 8 2 4
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "\n "<<maxSum(arr, n) << endl;
    return 0;
}
