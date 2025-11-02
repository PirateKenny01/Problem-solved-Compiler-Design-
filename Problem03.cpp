#include <bits/stdc++.h>
using namespace std;

void check_Comment(string s)
{
    if(s[0] == '/' && s[1] == '/')
    {
        cout << "Single Comment Detected" << endl;
    }
    else if(s[0] == '/' && s[1] == '*' && s[s.length()-1] == '/' && s[s.length()-2] == '*')
    {
        cout << "Multiple Comment Detected" << endl;
    }
    else
    {
        cout << "No Comment Detected";
    }
}

int main()
{
    string s;
    getline(cin , s);
    check_Comment(s);
    return 0;
}
