#include <iostream>
#include <algorithm>
#include <vector>
#define task "count_cycle."

using namespace std;

const int maxn = 101;
typedef int arr[maxn];
vector < int > adj[maxn];
int dd;

void enter(int &n, int &m, int &k, vector < int > adj[])
{
    cin >> n >> m >> k;

    for (int i = 1; i <= m; ++i)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        //adj[v].push_back(u);
    }
}

void dfs(int start, int k, int u, vector < int > adj[],
         arr visited, int &total_cycle)
{
    visited[u] = 1;

    // Đã tìm ra đường đi độ dài k - 1.
    if (k == 0)
    {
        // Loại bỏ đỉnh u khỏi chu trình để chọn đường đi khác.
        visited[u] = 0;

        // Kiểm tra xem đỉnh u có quay về được đỉnh xuất phát ban đầu không.
        // Nghĩa là đỉnh ban đầu nằm trong danh sách kề của đỉnh u.
        if (find(adj[u].begin(), adj[u].end(), start) != adj[u].end())
            ++total_cycle;
        return;
    }

    // Tìm các đường đi có thể bằng DFS. Mục tiêu là tạo được đường đi 
    // có độ dài bằng k - 1.
    for(int v = 0; v < adj[u].size(); ++v)
    //for (int v: adj[u])
    {
        if (visited[adj[u][v]])
            continue;

        dfs(start, k - 1, adj[u][v], adj, visited, total_cycle);
    }

    // Loại bỏ đỉnh u khỏi chu trình để chọn một đường đi khác.
    visited[u] = 0;
}

void solution(int n, int k, vector < int > adj[])
{
    arr visited;
    fill(visited, visited + n, 0);

    int total_cycle = 0;
    for (int u = 0; u < n - (k - 1); ++u)
        if (!visited[u])
        {
            dd = u;
            // Nếu u chưa thăm thì dựng tất cả các chu trình độ dài
            // n xuất phát từ u.
            dfs(u, k - 1, u, adj, visited, total_cycle);

            // Đánh dấu lại u đã sử dụng rồi, từ sau đây sẽ không tìm
            // thêm các chu trình chứa u nữa -> tránh lặp lại.
            visited[u] = 1;
        }

    // Chia 2 kết quả vì số chu trình đã đếm bị lặp lại hai lần.
    cout << total_cycle / 2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;

    enter(n, m, k, adj);
    solution(n, k, adj);

    return 0;
}