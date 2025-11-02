#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

void check_Comment(string s)
{

    if(s.length() >= 2 && s[0] == '/' && s[1] == '/')
    {
        cout << "Single-Line Comment Detected" << endl;
    }
    else if(s.length() >= 4 && s[0] == '/' && s[1] == '*' && s[s.length()-2] == '*' && s[s.length()-1] == '/')
    {
        cout << "Multi-Line Comment Detected (on a single line)" << endl;
    }
    else
    {
        cout << "No Comment Detected" << endl;
    }
}

int main()
{
    string s;
    char choice;

    do {
        cout << "\nEnter a line of text to check for a comment: ";
        getline(cin, s);

        check_Comment(s);

        cout << "\nDo you want to check another line? (y/n): ";

        if (!(cin >> choice)) {

            break;
        }

        char c;

        while ((c = cin.get()) != '\n' && c != EOF) {}

    } while (choice == 'y' || choice == 'Y');


    return 0;
}
