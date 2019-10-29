#include <iostream>
#include <vector>
using namespace std;

#define M 1000000007
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define MP make_pair
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int n, m, count, max_count, c, m_color;
vector<vi> visited;

void reset_matrix(int m, int n)
{
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            visited[i][j] = 0;
}

bool is_valid(int i, int j, int color, vector<vi>& grid)
{
    return ((i>=0 && j>=0 && i<m && j<n && !visited[i][j] && grid[i][j]==color) ? true : false);
}

void DFS(int i, int j, int color, vector<vi>& grid)
{
    visited[i][j] = true;
    count++;
    vector<pii> sides = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    for(auto itr = sides.begin(); itr != sides.end(); itr++)
    {
        if(is_valid(i + itr -> first, j + itr -> second, color, grid))
            DFS(i + itr -> first, j + itr -> second, color, grid);
    }
}

int component(int m, int n, vector<vi>& grid)
{
    reset_matrix(m, n);
    max_count = 0;
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            count = 0;
            if(!visited[i][j])
                DFS(i, j, grid[i][j], grid);
            if(max_count < count)
            {
                max_count = count;
                m_color = grid[i][j];
            }
        }
    }
    return max_count;
}

int main()
{
    io
    cin >> m >> n >> c;
    visited.reserve(m);
    for(int i = 0; i < m; i++)
        visited[i].reserve(n);
    vector<vi> grid(m, vi(n));
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            cin >> grid[i][j];

    cout << component(m, n, grid) << ' ' << m_color << '\n';
    return 0;
}
