#include <bits/stdc++.h>
using namespace std;

struct Point
{
    int x, y;
};

Point p0;

Point nextToTop(stack<Point> &choco)
{
    Point p = choco.top();
    choco.pop();
    Point res = choco.top();
    choco.push(p);
    return res;
}

void swap(Point &p1, Point &p2)
{
    Point temp = p1;
    p1 = p2;
    p2 = temp;
}

int distSq(Point p1, Point p2)
{
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

int orientation(Point p, Point q, Point r)
{
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);

    if (val == 0)
        return 0;
    return (val > 0) ? 1 : 2;
}

int compare(const void *vp1, const void *vp2)
{
    Point *p1 = (Point *)vp1;
    Point *p2 = (Point *)vp2;

    int o = orientation(p0, *p1, *p2);
    if (o == 0)
        return (distSq(p0, *p2) >= distSq(p0, *p1)) ? -1 : 1;

    return (o == 1) ? -1 : 1;
}

void Hull(Point coordinates[], int n)
{
    int xmin = coordinates[0].y, min = 0;
    for (int i = 1; i < n; i++)
    {
        int x = coordinates[i].x;

        if (x < xmin || (xmin == x && coordinates[i].y < coordinates[min].y))
            xmin = coordinates[i].x, min = i;
    }

    swap(coordinates[0], coordinates[min]);

    p0 = coordinates[0];
    qsort(&coordinates[1], n - 1, sizeof(Point), compare);

    int m = 1;
    for (int i = 1; i < n; i++)
    {
        while (i < n - 1 && orientation(p0, coordinates[i], coordinates[i + 1]) == 0)
            i++;

        coordinates[m] = coordinates[i];
        m++;
    }
    if (m < 3)
        return;

    stack<Point> choco;
    choco.push(coordinates[0]);
    choco.push(coordinates[1]);
    choco.push(coordinates[2]);

    for (int i = 3; i < m; i++)
    {
        while (orientation(nextToTop(choco), choco.top(), coordinates[i]) != 1)
            choco.pop();
        choco.push(coordinates[i]);
    }
    Point a[m];
    int i = 0;
    while (!choco.empty())
    {
        Point p = choco.top();
        a[i].x = p.x;
        a[i].y = p.y;
        choco.pop();
        i++;
    }
    cout << i << endl;
    for (int j = m - 1; j >= 0; j--)
        cout << a[j].x << " " << a[j].y << endl;
}

int main()
{
    int n;
    cin >> n;
    Point a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i].x >> a[i].y;

    Hull(a, n);
    return 0;
}