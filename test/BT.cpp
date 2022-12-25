// Bank Transaction
#include <iostream>
#include <string>
#include <map>
#include <stdlib.h>

using namespace std;
map<string, int> tmp_account, money_account;
int total_money;
int totalCalls;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(NULL); cout.tie(NULL);

  string type;
  
  do
  {
    string from_account, to_account, time_point, atm;
    string money;
    
    cin >> type;
    if (type == "#")
      continue; else from_account = type;
    
    ++totalCalls;
    
    cin >> to_account >> money >> time_point >> atm;
    //cout << from_account << to_account << money << time_point << atm << endl;

    tmp_account[from_account]++;
    int tg = stoi(money);
    money_account[from_account] = tg;
    total_money += tg;

 } while (type != "#");
  
  do
  {
    cin >> type;
    if (type == "#")
      continue;
    else if (type == "?count_total_transactions")
    {
      cout << totalCalls;
    }
    else if (type == "?count_total_money")
    {
      cout << total_money;
    }
    else if (type == "?list_sorted_account")
    {
    
    }
    else if (type == "?amount_money_trans_from")
    {
      cin >> type;
      cout << money_account[type] << endl;
    }
    else if (type == "?inspect_cycle") {
        int k;
        cin >> type >> k;
        if (tmp_account[type] == k) cout << "1"; else cout << "0";
        cout << endl;
    }
    else
      continue;
  } while (type != "#");
  return 0;
}
