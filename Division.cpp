#include <bits/stdc++.h>

using namespace std;

int compare(string str,string str2){
    int x = str.size();
    int y= str2.size();
    if(y>x){
        return 1;
    }
    else{
        int comi=0;
        if(x==y){
            while(str[comi]==str2[comi]){
                comi++;
            }
            if(comi>x){return 0;}
            if(str2[comi]>str[comi]){
                return 1;
            }
        }
    }
    return 0;
}

string subtract(string a,string b){
 string ans;
    int change=0;
    if(compare(a,b)){
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
            ans += to_string(temp);
        }
        else{
            ans += to_string(temp);
            carry=0;
        }
    }
    for(int i=diff-1;i>=0;i--){
        if(a[i]=='0'&& carry){
            ans += to_string(9);
            continue;
        }
        int temp=(a[i]-'0')-carry;
        if( i>0 || temp>0){
            ans += to_string(temp);
        }
    }
    if(change){ans.append("-");}

    reverse(ans.begin(),ans.end());

    return ans;
}

int main()
{
    int t;
    cin>>t;
    while(t>=1){
      string str;
      string str2;
      cin>>str;
      cin>>str2;
      if(compare(str,str2)){
          cout<<0<<endl<<str;
          return 0;
      }
      int lol=str.length()-str2.length()+1;
      char arr[lol];
      for(int i=0;i<lol;i++){
          arr[i]='0';
      }
      while(!compare(str,str2)){
          int n=str.length()-str2.length();
          string temp=str2;
          if(str[0]<str2[0]){
              for(int i=1;i<n;i++)temp.push_back('0');
              int qui=0;
              while(!compare(str,temp)){
                   str = subtract(str,temp);
                  qui++;
              }
              arr[lol-n]=qui+'0';
          }
          else{
              for(int i=0;i<n;i++)temp.push_back('0');
              int qui=0;
              while(!compare(str,temp)){
                   str = subtract(str,temp);
                  qui++;
              }
              arr[lol-1-n]=qui+'0';
          }

      }
      int y = 0;
      while(arr[y]=='0'){
          y++;
      }
      for(int i = y;i<lol;i++){
              if(arr[i]<49 || arr[i]>58){cout<<'0';}
          else{cout<<arr[i];}
      }
      cout<<endl<<str<<endl;
      t--;
    }
    return 0;
}
