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

string s;
vector<string> vec = {"BC","CA","AB"};

char abc(int pos, int lev)
{
    if(lev==0) { return s[pos-1];}
    char c = abc(ceill(pos/2.0),lev-1);
    if(pos%2) return vec[c-'A'][0];
    else return vec[c-'A'][1];
}

signed main()
{
    //freopen("","r+",stdin);
    //freopen("","w+",stdout);
    FastIO;
    int Master0fTheSEA=1;
    //cin>>Master0fTheSEA;
    for(int tttttttt=1;tttttttt<=Master0fTheSEA;tttttttt++)
    {
        cin>>s;
        int q;
        cin>>q;
        while(q--)
        {
            int t,pos;
            cin>>t>>pos;
            //cout<<t%120<<" ";
            int xy = (t%60)+60;
            cout<<abc(pos,xy)<<endl;
        }
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
