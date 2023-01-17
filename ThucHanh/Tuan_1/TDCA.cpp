// // Telco Data Check & Analyze​
// #include <iostream>
// #include <algorithm>
// #include <string>
// #include <map>

// using namespace std;
// map<string, int> a;
// map<string, int> timeCall;
// int incorrectPhone;
// int dd, dd1;

// bool checkPhone(string s) {
//     if (s.length() != 10) return false;
//     for(int i = 0; i < 10; ++i) {
//         if (!(s[i] >= '0' && s[i] <= '9')) return false;
//     }
//     return true;
// }

// int cTime(string sTime, string eTime) {
//     int StartT = 3600 * ((sTime[0] - '0')*10 + sTime[1] - '0')
//                 + 60 * ((sTime[3] - '0')*10 + sTime[4] - '0') 
//                     + ((sTime[6] - '0') + sTime[7] - '0');
//     int EndT = 3600 * ((eTime[0] - '0')*10 + eTime[1] - '0')
//                 + 60 * ((eTime[3] - '0')*10 + eTime[4] - '0') 
//                     + ((eTime[6] - '0') + eTime[7] - '0');
//     return EndT - StartT;
// }

// int main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(NULL);
//     cout.tie(NULL);

//     dd = 0;
//     string str;
//     do {
//         string call, sdtin, sdtout, Time, timein, timeout;
//         cin >> call;
//         str = call[0];
//         a[call]++;
//         if (call == "#") continue;
//         cin >> sdtin >> sdtout >> Time >> timein >> timeout;
//         if (!(checkPhone(sdtin)) || !(checkPhone(sdtout))) incorrectPhone++;
//         a[sdtin]++;
//         timeCall[sdtin] += cTime(timein, timeout);
        
//     }while (str != "#");

//     string s;
//     do {
//         cin >> s;
//         if (s == "#") continue;

//         if (s == "?check_phone_number") {
//             if (incorrectPhone != 0) cout << "0"; else cout << "1";
//             cout << endl;
//         }

//         if (s == "?number_calls_from") {
//             string sdt;
//             cin >> sdt;
//             cout << a[sdt] << endl; 
//         }

//         if (s == "?number_total_calls") cout << a["call"] << endl;

//         if (s == "?count_time_calls_from") {
//             string sdt;
//             cin >> sdt;
//             cout << timeCall[sdt] << endl;
//         } else continue;
        
//     } while (s != "#");
    

//     return 0;
// }

#include <iostream>
#include <string>
#include <map>

using namespace std;

bool checkPhone(string num)
{
  if (num.length() != 10)
    return false;
  for (int i = 0; i < 10; i++)
    if (num[i] < '0' || num[i] > '9')
      return false;
  return true;
}
int countTime(string ftime, string etime)
{
  return ((((etime[0] - ftime[0]) * 10 + etime[1] - ftime[1]) * 60 + (etime[3] - ftime[3]) * 10 + etime[4] - ftime[4]) * 60 + (etime[6] - ftime[6]) * 10 + etime[7] - ftime[7]);
}

map<string, int> numberCalls, timeCall;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  string type;
  int totalCalls = 0;
  int incorrectPhone = 0;
  do
  {
    cin >> type;
    if (type == "#")
      continue;
    ++totalCalls;
    string fnum, tnum, date, ftime, etime;
    cin >> fnum >> tnum >> date >> ftime >> etime;
    if (!checkPhone(fnum) || !checkPhone(tnum))
      ++incorrectPhone;
    numberCalls[fnum]++;
    timeCall[fnum] += countTime(ftime, etime);
  } while (type != "#");
  do
  {
    cin >> type;
    if (type == "#")
      continue;
    else if (type == "?check_phone_number")
    {
      if (!incorrectPhone)
        cout << 1 << endl;
      else
        cout << 0 << endl;
    }
    else if (type == "?number_calls_from")
    {
      cin >> type;
      cout << numberCalls[type] << endl;
    }
    else if (type == "?number_total_calls")
    {
      cout << totalCalls << endl;
    }
    else if (type == "?count_time_calls_from")
    {
      cin >> type;
      cout << timeCall[type] << endl;
    }
    else
      continue;
  } while (type != "#");
  return 0;
}
