#include <bits/stdc++.h>

using namespace std;

void check (string s)
{
    int flag=0;
    char x;
    for(x : s)
    {
        if(x>='0' && x<='9')
        {
            flag=0;
        }
        else
        {
            flag=1;
        }
    }

    if (flag==0)
    {
        cout<<"Numeric constant";
    }
    else
    {
        cout<<"Not numeric";
    }

}

int main()
{
    string s;
    cin>>s;
    check(s);
    return 0;
}

