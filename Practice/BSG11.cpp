// Binary sequences generation without consecutive 11
// AC - 100/100
#include <iostream>
#include <vector>
using namespace std;
 
void Solve(string str,int num)
{
    int len = str.length();
    if(len == num)
    {
        cout << str << endl;
        return;
    }
    // neu truoc do da la 1 -> so tiep theo chi co the la 0
    else if(str[len-1] == '1')
        Solve(str+'0',num);
    else
    {
        Solve(str+'0',num);
        Solve(str+'1',num);
    }
}
 
void Print(int& num)
{
    string word;
    //word[1] = '0';
    //word.push_back('0');
    //for(int i = 0; i < word.length(); ++i)  cout << word[i] << endl;
    Solve(word,num);
    //word[0]='1';
    //Solve(word,num);
}
 
//driver's code
int main()
{
    int n;

    cin >> n;
    Print(n);
    return 0;
}