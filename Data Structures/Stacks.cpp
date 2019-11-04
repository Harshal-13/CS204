#include <bits/stdc++.h>
using namespace std;
#define M 1000000007
#define ll long long
#define vi vector<int>
#define pii pair<int, int>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

class STACK{
private:
    vector <int> v;
public:
    int size(){
        return v.size();
    }
    bool isEmpty(){
        return v.size()==0;
    }
    void push(int data){
        v.push_back(data);
        return;
    }
    int pop(){
    	int tmp;
        if(!isEmpty()){
        	tmp=v[v.size()-1];
            v.pop_back();
            return tmp;
        }
        return -1;
    }
    int top(){
        if(!isEmpty()){
            return v[v.size()-1];
        }
        return -1;
    }
};

STACK Sort_Stack(STACK input, int n){
  STACK tmp;
  while (!input.isEmpty())
  {
    int temp = input.top();
    input.pop();
    while (!tmp.isEmpty() && tmp.top() < temp)
    {
        input.push(tmp.top());
        tmp.pop();
    }
    tmp.push(temp);
  }
  return tmp;
}

int main()
{
    io
    int n,a;
  	cout<<"Enter number of Numbers: ";
  	cin>>n;
  	STACK input;
  	cout<<"Enter The Numbers: ";
  	for(int i=0;i<n;i++){
  		cin>>a;
  		input.push(a);
  	}
  	input=Sort_Stack(input,n);
  	for(int i=0;i<n;i++){
  		cout<<input.pop()<<" ";
  	}
  	return 0;
}
