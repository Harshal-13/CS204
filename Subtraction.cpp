#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

int smaller(string a,string b){
    if(a.length()<b.length())return 1;
    if(a.length()>b.length())return 0;

    for(int i=0;i<a.length();i++){
        if(a[i]<b[i])return 1;
        else if(a[i]>b[i])return 0;
    }
    return 0;
}

int main(){
    string a,b;
    cin>>a>>b;
    string ans;
    int change=0;
    if(smaller(a,b)){
        swap(a,b);
        change=1;
    }

    int l1=a.length(),l2=b.length();
    int diff=l1-l2,carry=0;

    for(int i=l2-1;i>=0;i--){
        int temp=(a[diff+i]-'0')-(b[i]-'0')-carry;
        if(temp<0){
            temp+=10;
            carry=1;
            ans.push_back(temp+'0');
        }
        else{
            ans.push_back(temp+'0');
            carry=0;
        }
    }
    for(int i=diff-1;i>=0;i--){
        if(a[i]=='0'&& carry){
            ans.push_back('9');
            continue;
        }
        int temp=(a[i]-'0')-carry;
        if( i>0 || temp>0){
            ans.push_back(temp+'0');
        }
    }
    if(change){ans.append("-");}

    reverse(ans.begin(),ans.end());
    cout<<ans;
    return 0;
}
