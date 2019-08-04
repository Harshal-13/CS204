#include <iostream>
#include <string>

using namespace std;

int main()
{
    int t;
		cin>>t;
		while(t>=1){
			string s1,s2;
	    cin>>s1>>s2;
	    int l1=s1.length(),l2=s2.length();

	    int arr[l1+l2]={0};
	    int carry1=0,carry2=0;

	    for(int i=l2-1;i>=0;i--){
	        for(int j=l1-1;j>=0;j--){
	            int m=((s1[j]-'0')*(s2[i]-'0')+carry1+carry2);
	            arr[j+i+1]+=m%10;
	            carry2=arr[j+i+1]/10;
	            arr[j+i+1]=arr[j+i+1]%10;
	            carry1=m/10;
	        }
	        arr[i]+=carry1+carry2;
	        carry1=0;
	    }
	    if(arr[0]==0){
	        for(int i=1;i<l1+l2;i++){
	            cout<<arr[i];
	        }
	    }
	    else{
	        for(int i=0;i<l1+l2;i++){
	            cout<<arr[i];
	        }
	    }
			cout<<endl;
			t--;
		}
		return 0;
}
