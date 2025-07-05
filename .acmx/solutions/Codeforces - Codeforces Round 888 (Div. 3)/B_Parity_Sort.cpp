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
const int mod = 1e9+7;

//{{1,0},{0,1},{-1,0},{0,-1},{1,1},{-1,-1},{-1,1},{1,-1}}
//{{1,2},{2,1},{2,-1},{-1,2},{-1,-2},{-2,-1},{-2,1},{1,-2}}

signed main()
{
    //freopen("","r+",stdin);
    //freopen("","w+",stdout);
    FastIO;
    int ttt=1;
    cin>>ttt;
    for(int z=1;z<=ttt;z++)
    {
        int n;
        cin>>n;
        multiset<int>ev,od;
        set<int>odi,evi;
        for(int i=0;i<n;i++)
        {
            int a;
            cin>>a;
            if(a%2)
            {
                odi.insert(i);
                od.insert(a);
            }
            else
            {
                evi.insert(i);
                ev.insert(a);
            }
        }
        vector<int>vec;
        for(int i=0;i<n;i++)
        {
            if(odi.count(i))
            {
                vec.pb(*od.begin());
                od.erase(od.begin());
                odi.erase(i);
            }
            else
            {
                vec.pb(*ev.begin());
                ev.erase(ev.begin());
                ev.erase(i);
            }
        }
        if(is_sorted(all(vec))) YES;
        else NO;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
