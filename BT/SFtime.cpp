// Starting date-time plus duration equal to Finishing date-time

#include <iostream>
#include <algorithm>
#include <string>
#include <map>

using namespace std;
map<string, int> a;
map<int, string> b;
int dd;

int countTime(string ftime, string etime) {
    return ((((etime[0] - ftime[0]) * 10 + etime[1] - ftime[1]) * 60 + (etime[3] - ftime[3]) * 10 + etime[4] - ftime[4]) * 60 + (etime[6] - ftime[6]) * 10 + etime[7] - ftime[7]);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    dd = 0;
    string s;

    do{
        cin >> s;
        if (s == "*") continue; 
        else {
            dd++;
            a[s] = dd;
            b[dd] = s;
        }
    } while (s != "*");
    

    do {
        cin >> s;
        if (s == "***") continue;
        else {
            string t;
            int x;
            cin >> t >> x;

            int time = countTime(t, "23:59:59") + 1;
            //cout << time << endl;

            if (x <= time) {
                int ts = x % 60;
                int tg1 = (t[6] - 48)*10 + t[7]-48;
                int tg3 = x / 60;
                if (tg1 + ts > 60) {
                    tg3++;
                    ts = ts + tg1 - 60;
                } else ts = ts + tg1;

                int tg2 = (t[3] - 48)*10 + t[4]-48;
                int th = x / 3600;
                int tp = tg3 % 60;
                //int tp = ss;

                if (tg2 + tp > 60) {
                    th++;
                    tp = tp + tg2 - 60;
                } else tp = tp + tg2;

                int tg4 = (t[0] - 48)*10 + (t[1]-48);
                th = th + tg4;
                //cout << tg1 << " " << tg2 << " " << tg4 << endl;
                if (th < 10 && tp < 10 && ts < 10) {
                    cout << s << " 0" << th << ":0" << tp << ":0" << ts << endl;
                } else if (th < 10 && tp < 10) {
                    cout << s << " 0" << th << ":0" << tp << ":" << ts << endl;
                } else if ( th < 10 && ts < 10) {
                    cout << s << " 0" << th << ":" << tp << ":0" << ts << endl;
                } else if (tp < 10 && ts < 10) {
                    cout << s << " " << th << ":0" << tp << ":0" << ts << endl;
                } else if (th < 10) {
                    cout << s << " 0" << th << ":" << tp << ":" << ts << endl;
                } else if (tp < 10) {
                    cout << s << " " << th << ":0" << tp << ":" << ts << endl;
                } else if (ts < 10) {
                    cout << s << " " << th << ":" << tp << ":0" << ts << endl;
                } else cout << s << " " << th << ":" << tp << ":" << ts << endl;
            } else {
                x = x - time;
                int x1 = x / 86400;
                int x2 = x % 86400;

                int ts = x2 % 60;
                int tp = (x2 / 60) % 60;
                int th = x2 / 3600;

                //cout << b[a[s] + x1 + 1] << " " << th << ":" << tp << ":" << ts << endl;
                if (th < 10 && tp < 10 && ts < 10) {
                    cout << b[a[s] + x1 + 1] << " 0" << th << ":0" << tp << ":0" << ts << endl;
                } else if (th < 10 && tp < 10) {
                    cout << b[a[s] + x1 + 1] << " 0" << th << ":0" << tp << ":" << ts << endl;
                } else if ( th < 10 && ts < 10) {
                    cout << b[a[s] + x1 + 1] << " 0" << th << ":" << tp << ":0" << ts << endl;
                } else if (tp < 10 && ts < 10) {
                    cout << b[a[s] + x1 + 1] << " " << th << ":0" << tp << ":0" << ts << endl;
                } else if (th < 10) {
                    cout << b[a[s] + x1 + 1] << " 0" << th << ":" << tp << ":" << ts << endl;
                } else if (tp < 10) {
                    cout << b[a[s] + x1 + 1] << " " << th << ":0" << tp << ":" << ts << endl;
                } else if (ts < 10) {
                    cout << b[a[s] + x1 + 1] << " " << th << ":" << tp << ":0" << ts << endl;
                } else cout << b[a[s] + x1 + 1] << " " << th << ":" << tp << ":" << ts << endl;
            }

        }
    } while (s != "***");

    return 0;
}