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

signed main()
{
    //freopen("","r+",stdin);
    //freopen("","w+",stdout);
    FastIO;
    int Master0fTheSEA=1;
    cin>>Master0fTheSEA;
    for(int tttttttt=1;tttttttt<=Master0fTheSEA;tttttttt++)
    {
        int n;string s;
        cin>>n>>s;
        int si = -1, ed = -1;
        for(int i=0;i<n;i++)
        {
            int ct = 0;
            for(int j=i;j<n;j++)
            {
                if(s[j]=='a') ct++;
                if(2*ct==j-i+1)
                {
                    si = i+1;
                    ed = j+1;
                    break;
                }
            }
            if(si!=-1) break;
        }
        cout<<si<<" "<<ed<<endl; 
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
