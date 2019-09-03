#include <bits/stdc++.h>
#include <math.h>
#define io ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define REP(i,a,b) for (ll i = a; i < b; i++)
typedef long long int ll;

using namespace std;

ll search(ll arr[], ll n, ll k){        //search function to return position to number n in array.
    ll u = k;
    ll l = 0;
    while(u>=l){
        if(arr[(u+l)/2] == n) return (u+l)/2;
        else if(arr[(u+l)/2] > n) u = (u+l)/2 - 1;
        else l = (u+l)/2 + 1;
    }
    return -1;
}

int main(){
    io
    int u,q;
    cin>>u>>q;
    ll a[q],b[q],c[q];                    //array to save first number of each input.
    ll d[q];                    //array to save the user-ids. Might also include repeated entries.
    ll k=0;
    REP(i,0,q){                 //whole input is first saved using three arrays.
        cin>>a[i];
        if(a[i]==1){            //if first term is 1 then nnext two inputs are saved in arrays b,c.
            cin>>b[i]>>c[i];
            d[k]=b[i];          //second input defining userid is saved in array d.
            k++;
        }
        else{                   //else entries in b,c are saved as -1.
            b[i]=-1;
            c[i]=-1;
        }
    }
    sort(d,d+k);                //sort the array d. Now userids are in non-decreasing order.
    ll users[k];                //another array for userids, all distinct entries.
    users[0]=d[0];
    ll k2=1;

    REP(i,1,k){
        if(d[i]==d[i-1])continue;
        else{
            users[k2]=d[i];
            k2++;
        }
    }                           //k2=total number of distinct users.
    ll val[k2]={0};             //array for money stored by users.
    ll maxm=-1,maxindex=-1;

    REP(i,0,q){
        if(a[i]==1){
            ll temp=search(users,b[i],k2);
            val[temp]+=c[i];                //recharge is added to val at position of user in array users
            if(val[temp]>maxm){             //if current user's recharge is max, it is saved.
                maxm=val[temp];
                maxindex=temp;
            }
        }
        else{
            if(maxindex==-1)cout<<"No data available."<<endl;
            else cout<<users[maxindex]<<endl;   //userid of user with max recharge is printed.
        }
    }
    return 0;
}
