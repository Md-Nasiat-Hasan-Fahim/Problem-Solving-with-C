#include<bits/stdc++.h>
using namespace std;

#define intt int

const int maxx = 1e5;

intt n, arr[maxx];
intt used[maxx];
intt cycle = 0;

void dfs (intt v) {
    used[v] = 1;
    if (used[arr[v]]) cycle ++;
    else dfs (arr[v]);
}

int main() {
    cin >> n;
    for (intt i = 1; i <= n; i++)
        cin >> arr[i]; /// ONLY PERMUTATION OF NUMBERS 1 to n
    for (intt i = 1; i <= n; i++)
        if (!used[i])
            dfs (i);
    cout << n - cycle << endl;
    return 0;
}