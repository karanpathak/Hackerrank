#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <limits>
using namespace std;


int main() {


	int t,n,i,k,temp_min;
	unsigned int res[5],T[1000],temp[3],_a=numeric_limits<unsigned int>::max(),min;
    T[0]=0;T[1]=1;T[2]=1;
	
    for(i=3;i<1000;i++){
		temp[0] = T[i-1];
		temp[1] = T[i-2];
		temp[2] = i>4 ? T[i-5]:_a;

		T[i] = *min_element(temp,temp+3)+1;
	}
    
unsigned int a[10000],_t,a_i;
	cin>>t;
	
    while(t--)
	{
		cin>>n;		
        min=_a;
		for(i=0;i<n;cin>>a[i],min = a[i]<min?a[i]:min,i++);        
        unsigned int res[5]={0};  
        
        for(k=0;k<5;k++)
		{
			temp_min = min-k;
            
            if(temp_min<0)
            {res[k] = _a;continue;}
    		for(i=0;i<n;res[k]+=T[a[i]-temp_min],i++);
		}
		
        cout<<*min_element(res,res+5)<<endl;
    }
    return 0;
}
