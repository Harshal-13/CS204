#include <bits/stdc++.h>
#define lli long long int
#define f(a, b, c) for (lli a = b; a < c; a++)
using namespace std;
unordered_map<string,lli> variable;
int eq=-1;
int term=0;
vector<string> Str_to_Vec(string s)
{
    vector<string> str;
    int len = s.length();
    for(int i = 0; i<len;i++)
    {
        string t="";
        int check=1;
        if((s[i] >= '0' && s[i] <= '9'))
        {
            int k = i;
            for(;(s[k] >= '0' && s[k] <= '9');k++)
            {
                t+=s[k];
            }
            i = k-1;
        }
        else if((s[i] >= 'a' && s[i] <= 'z')||(s[i] >= 'A' && s[i] <= 'Z'))
        {
          int k = i;
          for(;(s[k] >= 'a' && s[k] <= 'z')||(s[k] >= 'A' && s[k] <= 'Z');k++)
          {
              t+=s[k];
          }
          i = k-1;

          if(variable.find(t)!=variable.end())
          {
            auto itr=variable.find(t);
            t=to_string(itr->second);
            if(t[0]=='-') {
              check=0;
              str.push_back("(");
              t=t.substr(1,t.length()-1);
              str.push_back("$");
            }
          }
          else
          {
            term=1;
            cout<<"CANT BE EVALUATED\n";
          }
        }
        else
        {
            t+=s[i];
        }
        str.push_back(t);
        if(check==0) str.push_back(")");
    }
    return str;
}

bool Is_Operator(char o)
{
  if(o=='+'||o=='-'||o=='^'||o=='*'||o=='/')
  {
    return true;
  }
  return false;
}

int Precede(string s)
{
    if(s=="$")
      return 4;
    else if(s == "^")
    return 3;
    else if(s == "*" || s == "/")
    return 2;
    else if(s == "+" || s == "-")
    return 1;
    else
    return -1;
}

vector<string> In_to_Post(vector<string> str)
{
    stack<string> stk;
    stk.push("~");
    int len = str.size();
    vector<string> n;
    for(int i = 0; i < len; i++)
    {
        if((str[i][0] >= '0' && str[i][0] <= '9'))
            n.push_back(str[i]);
        else if(str[i] == "(")
            stk.push("(");
        else if(str[i] == ")")
        {
            while(stk.top() != "~" && stk.top() != "(")
            {
                string c = stk.top();
                stk.pop();
                n.push_back(c);
            }
            if(stk.top() == "(")
            {
                string c = stk.top();
                stk.pop();
            }
        }
        else{
            while(stk.top() != "~" && Precede(str[i]) <= Precede(stk.top()))
            {
                if(str[i]=="^"&&stk.top()=="^") break;
                string c = stk.top();
                stk.pop();
                n.push_back(c);
            }
            stk.push(str[i]);
        }

    }
    while(stk.top() != "~")
    {
        string c = stk.top();
        stk.pop();
        n.push_back(c);
    }
    return n;
}

struct node
{
  string s;
  node* left=NULL,*right=NULL;
};

node* ct(vector <string> st)
{
       node *root=NULL;
       vector <node*> stack1;
       int i=0;
       while(i!=st.size())
       {
         if(st[i]!="+" && st[i]!="-" && st[i]!="*" && st[i]!="/" && st[i]!="^" && st[i]!="$")
           {

                 node *temp=(node *)malloc(sizeof(node));

                 temp->s=st[i];

                 stack1.push_back(temp);
           }
         else if(st[i]!="$")
         {
               if(stack1.size()<2)return NULL;

               node *s1=stack1.back();

               stack1.pop_back();

               node *s2=stack1.back();

               stack1.pop_back();

               node *temp=(node *)malloc(sizeof(node));

               temp->s=st[i];

               temp->left=s2;

               temp->right=s1;

               stack1.push_back(temp);
         }
         else
         {
                if(stack1.size()<1)return NULL;
                node *s1=stack1.back();
                stack1.pop_back();
                node *temp=(node *)malloc(sizeof(node));
                temp->left=s1;
                temp->s="$";
                stack1.push_back(temp);
         }
         i++;
       }
    if(stack1.size()!=1)
          return NULL;
    return stack1.back();
}

lli evaluate(node *root)
{
   string s=root->s;
   lli answer=0;
   if(s!="+" && s!="-" && s!="*" && s!="/" && s!="^" && s!="$")
   return stoi(s);
   else
   {
     int lanswer=evaluate(root->left),ranswer=0;
     if(s!="$")
      ranswer = evaluate(root->right);

     if(s=="+")
       answer=lanswer+ranswer;
     else if(s=="-")
       answer=lanswer-ranswer;
     else if(s=="*")
       answer=lanswer*ranswer;
     else if(s=="/")
       {
          if(ranswer==0)
          {
            answer = std::numeric_limits<lli>::max();
          }
          else answer=lanswer/ranswer;
        }
     else if(s=="^")
     {
       answer=1;
       if(ranswer<0) answer=0;
       else f(i,0,ranswer)answer*=lanswer;
     }
     else
     {
       answer=-evaluate(root->left);
     }
   }
   return answer;
}

bool checkeq(string s)
{
  int i=0;
  for(;i<s.length();i++)
  {
    if(s[i]=='=')break;
  }
  if(i<s.length())
  {
    eq=i;
    return true;
  }
  else return false;
}

int main()
{
  int q;
  cin>>q;
  while(q--)
  {
    int n;
    cin>>n;
    for(lli i = 0;i<n;i++)
    {
      string s,s1;
      cin>>s;

      if(!checkeq(s))
      {
    		for(int i = 0; i<s.size() ; i++)
    		{
    		  if(s[i]=='-')
    		  {
        		if(i==0||s[i-1]=='('||Is_Operator(s[i-1]))
        		{
            		s1.push_back('$');
        			 continue;
        		}
        	  }
        	  s1.push_back(s[i]);
    		}

    		vector <string> newv=Str_to_Vec(s1);
        if(term==1){
          term=0;
          continue;
        }
    		newv=In_to_Post(newv);
    		node* root=ct(newv);

    		if(root!=NULL)
        	{
        		if(evaluate(root)==std::numeric_limits<lli>::max())
        		 	cout<<"CANT BE EVALUATED\n";
        		else
            		cout<<evaluate(root)<<"\n";
        	}
    		else
    		{
        		cout<<"CANT BE EVALUATED\n";
    		}

      }
      else
      {
        string var=s.substr(0,eq);
      	for(int i = eq+1; i<s.size() ; i++)
    		{
    		  if(s[i]=='-')
    		  {
        		if(i==1+eq||s[i-1]=='('||Is_Operator(s[i-1]))
        		{
            		s1.push_back('$');
        			 continue;
        		}
        	  }
        	  s1.push_back(s[i]);
    		}

    		vector <string> newv=Str_to_Vec(s1);
        if(term==1){
          term=0;
          continue;
        }
    		newv=In_to_Post(newv);
    		node* root=ct(newv);

    		if(root!=NULL)
        {
          if(variable.find(var)==variable.end()) variable.insert(pair<string, lli>(var,evaluate(root)));
          else
          {
            auto itr=variable.find(var);
            itr->second=evaluate(root);
          }
        }
      }
      eq=-1;
    }
    variable.clear();
  }
  return 0;
}
