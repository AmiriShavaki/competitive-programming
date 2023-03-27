#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string par1, par2, child;
        cin >> par1 >> par2 >> child;
        if (child.find("+") != string::npos && !(par1.find("+") != string::npos || par2.find("+") != string::npos))
            cout << "invalid\n";
        else if (child.find("A") != string::npos && !(par1.find("A") != string::npos || par2.find("A") != string::npos))
            cout << "invalid\n";
        else if (child.find("B") != string::npos && !(par1.find("B") != string::npos || par2.find("B") != string::npos))
            cout << "invalid\n";
        else
            cout << "valid\n";
    }
    return 0;
}