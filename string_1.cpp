#include <bits/stdc++.h>
using namespace std;

// void substringRange(string str){    // to find all the substrings 
//     int n = str.length();
//     for(int i = 0;i<n;i++){
//         for(int j = 1;j<=n-i;j++){
//             cout<<str.substr(i,j)<<endl;
//         }
//     }
// }

// int toDigit(char ch){return (ch-'0');}

int sumofSubstring(string str){         // to find the sum of all substrings
    vector<int> v;
    int n = str.length();
    for(int i=0;i<n;i++){
        for(int j=1;j<=n-i;j++){                
            string sub = (str.substr(i,j));     
            int x = stoi(sub);            // stoi is used to convert string to integer
            v.push_back(x);
        }
    }
    int res = accumulate(v.begin(),v.end(),0);      // accumulate is used to find the sum of all elements in the vector
    return res;
}

int main(){
    string str = "1234";
    // substringRange(str); 
    cout<<"sum is :"<<sumofSubstring(str)<<" ";
    return 0;
}