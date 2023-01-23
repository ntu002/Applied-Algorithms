// you can use includes, for example:
// #include <algorithm>
//#include<bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
using namespace std;
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
int findFirstAppearance (string A, string B) {

    for (int i = 0; i < A.length(); i ++) {

        string tempString = A.substr(i, 2);

        if (tempString == B) {
            return i;
        }
    }

    return -1;

}

int findLastAppearance (string A, string B) {

    for (int i = A.length() - 2; i >=0 ; i --) {

        string tempString = A.substr(i, 2);

        if (tempString == B) {
            return i;
        }
    }

    return -1;
}

int solution(string &S) {
    // Implement your solution here
    int N = S.length();

    map<string, int> diagramsMap;

    for (int i = 0; i < N - 1; i ++) {

        string diagram = std::string(1,S[i])+S[i+1];

        if (diagramsMap.find(diagram) == diagramsMap.end()) {

            //diagramsMap.insert({diagram , 1 });
            diagramsMap[diagram] = 1;
        
        } else {

            diagramsMap[diagram] ++;
        }
    }

    // loop through map to find diagram with appearance is greater than 1
    int result  = -1 ;
    vector<string> hasIdenticalDiagrams;

    for (auto itr = diagramsMap.begin(); itr != diagramsMap.end(); ++itr) {

        if (itr->second > 1) {
            hasIdenticalDiagrams.push_back(itr->first);
        }
    }

    for(int i = 0; i < hasIdenticalDiagrams.size(); i++){

        int distance = findLastAppearance(S, hasIdenticalDiagrams[i]) - findFirstAppearance(S, hasIdenticalDiagrams[i]);

        if (result < distance) {
            result = distance;
        }
    }
    
    return result;
}