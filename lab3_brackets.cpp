#include<bits/stdc++.h>

using namespace std;

bool isBalanced(string expr)
{
	stack<char> s;
	char x;
  if(expr[0]!='(' && expr[0]!='[' && expr[0]!='{' && expr[0]!='<' && expr[0]!='|') return false;

	for(int i = 0; i < expr.length(); i++)
	{
    if(expr[i] =='(' || expr[i] =='[' || expr[i] =='<' || expr[i] =='{' || expr[i] =='|' || expr[i] ==')' || expr[i] =='}' || expr[i] ==']' || expr[i] =='>' )
    {
		if(expr[i] == '(' || expr[i] == '{' || expr[i] == '[' || expr[i] == '<' || expr[i] == '|')
		{
      if(s.size()==0){
        s.push(expr[i]);
        continue;
      }
      if(expr[i] == '|' && i>0){
        if(s.top()=='|'){
          s.pop();
        }
        else s.push(expr[i]);
      }
			else s.push(expr[i]);
		}

    if(s.empty() && i!= expr.length()-1)
			return false;

    switch(expr[i])
		{
			case ')':
				x = s.top();
				s.pop();
				if(x != '(')
					return false;
				break;
			case '}':
				x = s.top();
				s.pop();
				if(x != '{')
					return false;
				break;
			case ']':
				x = s.top();
				s.pop();
				if(x != '[')
					return false;
				break;
			case '>':
				x = s.top();
				s.pop();
				if(x != '<')
					return false;
				break;

		}

	}

else return false;
}
return (s.empty());
}

int main()
{
	int n;
	cin >> n;
	string expr;
	while(n--)
	{
		cin >> expr;
		if(isBalanced(expr))
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}

