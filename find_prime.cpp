#include <iostream>

using namespace std;

int main(){
	int t;
	cin>>t;
	while(t>=1){
		long long a;
		cin>>a;

		int check =0;
		for(int i=2;i<=sqrt(a);i++){
			if(a%i==0){check=1;break;}
		}
		if(check==1)cout<<"Not a prime"<<endl;
		else cout<<"Prime"<<endl;
		t--;
	}
	return 0;
}
