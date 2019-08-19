#include <bits/stdc++.h>
#include <math.h>

using namespace std;

long long int powerrr(long long int a, long long int b)
{
    long long int ans = 1;
    for(long long int i = 0; i < b; i++)
    {
        ans*= a;
    }
    return ans;
}

stack<char>brac;
long long int flag;
set<char> charc;

struct node
{
  char c;
  long long int n;
  struct node *left;
  struct node *right;
};

struct node *createNode(){

    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->c='o';
    temp->n=-12345;

    return temp;

}

void build(string s,struct node *start)
{
  for(long long int i=s.length()-1; i>=0; i--)
  {
      if(charc.find(s[i])==charc.end())flag++;
      if(s[i] == ')')brac.push(s[i]);
      if(s[i] == '(')brac.pop();

      if(!(brac.empty()))continue;

      if(s[i]=='+' || s[i]=='-')
      {
          start->c=s[i];
          string s1=s.substr(0,i);
          string s2=s.substr(i+1, s.length()-1-i);

          start->left=createNode();
          start->right=createNode();
          build(s1, start->left);
          build(s2, start->right);

          return;

      }
    }

    for(long long int i=s.length()-1; i>=0; i--)
    {
        if(charc.find(s[i])==charc.end())flag++;
        if(s[i] == ')')brac.push(s[i]);
        if(s[i] == '(')brac.pop();

        if(!(brac.empty()))continue;

        if(s[i]=='*' || s[i]=='/'){
            start->c=s[i];
            string s1=s.substr(0,i);
            string s2=s.substr(i+1, s.length()-1-i);

            start->left=createNode();
            start->right=createNode();
            build(s1, start->left);
            build(s2, start->right);

            return;
        }
    }

    for(int i=0;i<s.length();i++)
    {
        if(charc.find(s[i])==charc.end())flag++;
        if(s[i] == '(')brac.push(s[i]);
        if(s[i] == ')')brac.pop();

        if(!(brac.empty()))continue;

        if(s[i]=='^'){

            start->c='^';
            string s1=s.substr(0,i);
            string s2=s.substr(i+1, s.length()-1-i);

            start->left=createNode();
            start->right=createNode();
            build(s1, start->left);
            build(s2, start->right);

            return;
        }
    }

    for(int i=0;i<s.length();i++)
    {
        if(charc.find(s[i])==charc.end())flag++;
        if(s[i]=='(')
        {
            stack<char> st;
            st.push('(');

            for(int j=i+1;j<s.length();j++)
            {
                if(s[j]=='(')st.push('(');
                if(s[j]==')')
                {
                    st.pop();
                }
                if(st.empty())
                {
                    string b=s.substr(i+1, j-1-i);
                    build(b, start);
                    return;
                }
            }
        }
    }
    start->n=stoll(s);
}

long long int evaluate(struct node *start)
{
  if(start->c != 'o'){
      if(start->c == '^')
      {
          return powerrr(evaluate(start->left), evaluate(start->right));
      }
      else if(start->c == '*')
      {
          return evaluate(start->left)*evaluate(start->right);
      }
      else if(start->c == '/')
      {
          return evaluate(start->left)/evaluate(start->right);
      }
      else if(start->c=='+')
      {
          return evaluate(start->left)+evaluate(start->right);
      }
       else
      {
          return evaluate(start->left)-evaluate(start->right);
      }
  }
  else
  {
      return start->n;
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  charc.insert('^');
  charc.insert('+');
  charc.insert('-');
  charc.insert('*');
  charc.insert('/');
  charc.insert('0');
  charc.insert('1');
  charc.insert('2');
  charc.insert('3');
  charc.insert('4');
  charc.insert('5');
  charc.insert('6');
  charc.insert('7');
  charc.insert('8');
  charc.insert('9');
  charc.insert('(');
  charc.insert(')');

  long long int t;
  cin>>t;
  while(t--){
    flag=0;
    string s;
    cin>>s;
    struct node *start=createNode();

    build(s,start);
    long long int x=evaluate(start);
    if(flag) cout<<"CAN'T BE EVALUATED"<<endl;
    else cout<<x<<endl;
  }
}
