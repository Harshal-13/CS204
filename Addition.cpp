#include <iostream>
#include <string>

using namespace std;

string rev(string a){
	string b;
	for(int i=a.length()-1;i>=0;i--){
		b.push_back(a[i]);
	}
	return b;
}

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t>=1){
		string a,b;
		string ans;

		cin>>a;
		cin>>b;

		a=rev(a);
		b=rev(b);

		int n1=a.length(),n2=b.length();

		if(n1<n2){
			swap(a,b);
		}

		int carry=0,i;
		for(i=0;i<n1;i++){
			int sum=((a[i]-'0')+(b[i]-'0')+carry);
			ans.push_back(sum%10+'0');
			carry=sum/10;
		}
		for(i=n1;i<n2;i++){
			int sum=((a[i]-'0')+carry);
			ans.push_back(sum%10+'0');
			carry=sum/10;
		}
		if(carry) ans.push_back(carry+'0');

		ans=rev(ans);
		for(int i=0;i<ans.length();i++){
			cout<<ans[i];
		}
		cout<<endl;
		t--;
	}
	return 0;
}
