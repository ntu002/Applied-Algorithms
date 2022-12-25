#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#define task "count_cycle."

using namespace std;
const int MAX = 1e5 + 6;

const int maxn = 1e5 + 5;
typedef int arr[maxn];
vector < int > adj[maxn];

typedef struct {
    string from_account;
    string to_account;
    int money;
}transaction;
vector<string> x;
map <string, int> total_money_from_account;
map <string, int> total_from_account;
map <string, int> total_account;
int dd;
int tgchoi;
int choiss;
arr visited;
    

bool comparator(string a,string b)
{
    return a < b;
}

void dfs(int start, int k, int u, vector < int > adj[],
         arr visited, int &total_cycle, int choi)
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
        {
            cout << tgchoi << " ";
            if (tgchoi == choi) {
                choiss = 1;
                return;
            }
        }
        return;
    }

    // Tìm các đường đi có thể bằng DFS. Mục tiêu là tạo được đường đi 
    // có độ dài bằng k - 1.
    for(int v = 0; v < adj[u].size(); ++v)
    //for (int v: adj[u])
    {
        if (visited[adj[u][v]])
            continue;

        dfs(start, k - 1, adj[u][v], adj, visited, total_cycle, choi);
    }

    // Loại bỏ đỉnh u khỏi chu trình để chọn một đường đi khác.
    visited[u] = 0;
}

void solution(int n, int k, vector < int > adj[], int choi)
{
    fill(visited, visited + n, 0);

    int total_cycle = 0;
    for (int u = 0; u < n - (k - 1); ++u)
        if (!visited[u])
        {
            tgchoi = u;
            // Nếu u chưa thăm thì dựng tất cả các chu trình độ dài
            // n xuất phát từ u.
            dfs(u, k - 1, u, adj, visited, total_cycle, choi);

            // Đánh dấu lại u đã sử dụng rồi, từ sau đây sẽ không tìm
            // thêm các chu trình chứa u nữa -> tránh lặp lại.
            visited[u] = 1;
        }

    // Chia 2 kết quả vì số chu trình đã đếm bị lặp lại hai lần.
    //cout << total_cycle / 2;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int error_Num =0;
    int call_Num = 0;
    // string type;
    
    int totalMoney = 0;
    string from_account,to_account,time_point,atm;
    int money;
    transaction data[MAX];
    int number_of_transaction = 0;
    do {
        cin >> from_account;
        if(from_account != "#"){
            cin >> to_account >> money >> time_point >> atm;
            data[number_of_transaction].from_account = from_account;
            data[number_of_transaction].to_account = to_account;
            data[number_of_transaction].money = money;
            number_of_transaction++;
            totalMoney += money;

            // if (total_account[from_account] == 0) x.push_back(from_account);
            // if (total_account[to_account] == 0) x.push_back(to_account);

            // total_from_account[from_account]++;
            // total_account[from_account]++;
            // total_account[to_account]++;

            if (total_account[from_account] == 0) {
                x.push_back(from_account);
                dd++;
                total_account[from_account] = dd;
            }

            if (total_account[to_account] == 0) {
                x.push_back(to_account);
                dd++;
                total_account[to_account] = dd;
            }

            adj[total_account[from_account]].push_back(total_account[to_account]);

            //a[total_account[from_account]][total_account[to_account]] = 1;


            total_money_from_account[from_account] += money;

            //cout << total_money_from_account[from_account] << " " << total_from_account[from_account] << endl;


        }
        //cout << from_account <<"  "<< to_account <<"  "<< money <<"  "<< time_point <<"  "<< atm << endl; 
    }while (from_account != "#");

    sort(x.begin(), x.end(), comparator);

    string Type;
    do {
        cin >> Type;
        if (Type == "#")
            continue;
        else if (Type == "?number_transactions")
        {
            cout << number_of_transaction << endl;
        }
        else if (Type == "?total_money_transaction")
    {
      cout << totalMoney << endl;
    }
    else if (Type == "?list_sorted_accounts")
    {
        for(int i = 0; i < x.size(); ++i) cout << x[i] << " ";
        cout << endl;
    
    }
    else if (Type == "?total_money_transaction_from")
    {
        cin >> Type;
        cout << total_money_from_account[Type] << endl;
        
        //cout << Type << " " << total_money_from_account[Type] << endl;
        //cout << money_account[type] << endl;
    }
    else if (Type == "?inspect_cycle") {
        for (int i = 1; i <= maxn; ++i) visited[i] = 0; 
        cin >> Type; 
        int tmp;
        cin >> tmp;
        choiss = 0;
        cout << total_account[Type] << " " << endl;
        solution(dd, tmp, adj, total_account[Type]);
        cout << choiss << endl;
    }
    else
      continue;


    } while(Type != "#");
    
    return 0;
}