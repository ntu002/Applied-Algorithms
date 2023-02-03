// Hash Over Strings
// AC - 100/100


#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
int n, m;

struct Hash {
    //int p;
    long long hash_value;

    Hash(const string& s) {
        long long hash_so_far; 
        long long p_pow ;

        hash_so_far = 0;
        p_pow = 1;

        const int s_size = s.length();

        for(int i = s_size - 1; i >= 0; --i) {
            hash_so_far = (hash_so_far + (s[i])*p_pow) % m;
            p_pow = (p_pow*256) % m;
        }

        hash_value = hash_so_far;
    }

    bool operator==(const Hash& other) {
        return (hash_value == other.hash_value);
    }

};

int Solve(string s) {
    int p = 1;
    int hash_value = 0;
    
    for(int i = s.length()-1; i >= 0; --i) {
        //hash_value = (hash_value + (s[i] - 'a' + 1)*p) % m;
        hash_value = (hash_value + (s[i])*p) % m;
        p = (p*256)%m;
    }

    return hash_value;
}


int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        string s;
        cin >> s;
        //Hash h(s);
        //cout << h.hash_value << '\n';
        cout << Solve(s) << '\n';
    }
    return 0;

}