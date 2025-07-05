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
        int a,b,c;
        cin>>a>>b>>c;
        int tc = 3*ceil(c/2.0);
        int tp = (c-ceil(c/2.0))*3;
        if(tc>tp)
        {
            if(b>0)
            {
                tp+=2;
                b--;
            }
        }
        //cout<<tc<<" "<<tp<<endl;
        // if(tc>tp)
        // {
        //     while(a>0&&tc>tp) 
        //     {
        //         a--;
        //         tp++;
        //     }
        // }
        tp+=2*ceil(b/2.0);
        tc+=(b-ceil(b/2.0))*2;
        //cout<<tc<<" "<<tp<<endl;
        while(a>0&&tp>tc)
        {
            a--;
            tc++;
        }
        while(a>0&&tp<tc)
        {
            a--;
            tp++;
        }
        tc+=ceil(a/2.0);
        tp+=(a-ceil(a/2.0));
        cout<<abs(tc-tp)<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
