#include <bits/stdc++.h>

using namespace std;
int main()
{
    int n;
    cin >> n;
    struct str
    {
        string s;
    };
    str arr[n + 1];
    int cnt = 0, k;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i].s;
    }
    for (int i = 1; i <= n; i++)
    {
        //i = 0
        k = i;
        int tem = i;
        //k=0,i=0
        while (i--)
        {
            //i=0
            if (
            {
                cnt++;
            }
        }
        //i=-1
        if (cnt == 0)
            cout << "OK" << endl;
        else
            cout << arr[k].s << cnt << endl;
        cnt = 0;
        i = tem;
    }
    return 0;
}arr[k].s == arr[i].s)