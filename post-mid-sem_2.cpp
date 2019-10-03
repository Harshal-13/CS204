#include <bits/stdc++.h>
using namespace std;

struct Point
{
	int x, y;
};

Point P0;



void swap_by_pointers(Point &p1, Point &p2)
{
	Point temp=p1;
	p1=p2;
	p2=temp;
}

int Dist_Square(Point p1, Point p2)
{
	int ans=(p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y);
	return ans;
}

int orientation(Point p, Point q, Point r)
{
	int value=(q.y-p.y)*(r.x-q.x)-(q.x-p.x)*(r.y-q.y);
	if(value==0)return 0; //colinear
	else if(value>0)return 2; //clockwise
	return 1; //anticlockwise
}

int compare(const void *vp1, const void *vp2)
{
	Point *p1=(Point *)vp1;
	Point *p2=(Point *)vp2;

	int orient=orientation(P0, *p1, *p2);
	if(orient==0)
	{
		if(Dist_Square(P0, *p2)>=Dist_Square(P0, *p1))return -1;
		else return 1;
	}
	if(orient==2) return -1;
	return 1;
}
Point Next_to_Top_in_stack(stack <Point> &s)
{
	Point p=s.top();
	s.pop();
	Point answer=s.top();
	s.push(p);
	return answer;
}

void Convex_Hull(Point pt[], int n)
{
	int x_min=pt[0].x;
	int min=0;
	for(int i=1;i<n;++i)
	{
		if( pt[i].x<x_min || (pt[i].x==x_min && pt[i].y<pt[min].y) )
			{
				min=i;
				x_min=pt[i].x;
			}
	}

	swap_by_pointers(pt[0], pt[min]);

	P0=pt[0];
	qsort(&pt[1], n-1, sizeof(Point), compare);
	int m=1;
	for(int i=1;i<n;++i)
	{
		while(i<n-1 && orientation(P0, pt[i], pt[i+1])==0)
			i++;
		pt[m]=pt[i];
		m++;
	}

	if(m<3)
	{
		cout<<"Convex Hull not possible"<<endl;
		return;
	}

	stack <Point> s;
	s.push(P0);
	s.push(pt[1]);
	s.push(pt[2]);

	for(int i=3;i<m;++i)
	{
		while(orientation(Next_to_Top_in_stack(s), s.top(), pt[i])!=2)
			s.pop();
		s.push(pt[i]);
	}
	cout<<s.size()<<endl;
	vector <Point> ans;
	while(!s.empty())
	{
		Point p=s.top();
		ans.push_back(p);
		s.pop();
	}
	for(int i=ans.size()-1;i>=0;--i)
		cout<<ans[i].x<<" "<<ans[i].y<<endl;
}

int main()
{
	int n;
	cin>>n;
	Point p[n];
	for(int i=0;i<n;++i)
	{
		cin>>p[i].x>>p[i].y;
	}
	Convex_Hull(p, n);
	return 0;
}
