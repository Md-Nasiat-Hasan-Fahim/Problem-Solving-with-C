#include<bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false), cin.tie(0)
#define endl '\n'
#define int long long
#define all(x) x.begin(),x.end()
#define pb push_back
#define YES cout<<"YES\n"
#define NO cout<<"NO\n"
#define check(x) cout << (#x) << " is " << (x) << endl;
#define ld long double
const int mod = 1e9+7;
const ld cmp = 1e-9;

int n,k;

bool is_same(pair<ld,ld> a, pair<ld,ld> b)
{
    return ((fabsl(a.first-b.first))<cmp&&(fabsl(a.second-b.second)<cmp));
}

bool calculate_y(ld x)
{
    return sqrtl((n*n)-(x*x));
}

bool is_valid(pair<ld,ld> a)
{
    return ((a.first*a.first)+(a.second*a.second))<n*n;
}

pair<ld,ld> intersection(pair<ld,ld> a, pair<ld,ld> b)
{
    ld x1 = a.first; ld x2 = a.second; ld x3 = b.first; ld x4 = b.second;
    ld y1 = calculate_y(x1);ld y2 = calculate_y(x2);ld y3 = calculate_y(x3); ld y4 = calculate_y(x4);
    if(!((x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4))) return {-1,-1};
    long double x = ((x1 * y2 - y1 * x2) * (x3 - x4) - (x1 - x2) * (x3 * y4 - y3 * x4)) / ((x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4));
    long double y = ((x1 * y2 - y1 * x2) * (y3 - y4) - (y1 - y2) * (x3 * y4 - y3 * x4)) / ((x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4));
    if(is_valid({x,y})) return {x,y};
    return {-1,-1};
}

signed main()
{
    //freopen("","r+",stdin);
    //freopen("","w+",stdout);
    FastIO;
    int ttt=1;
    cin>>ttt;
    for(int z=1;z<=ttt;z++)
    {
        //cout<<"Case "<<z<<": ";
        /*int n;
        cin>>n;
        vector<int>vec(n);
        for(int i=0;i<n;i++) cin>>vec[i];*/
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
