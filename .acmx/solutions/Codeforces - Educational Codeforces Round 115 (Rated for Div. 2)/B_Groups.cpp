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
        int n;
        cin>>n;
        int day[n][5];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<5;j++)
            {
                cin>>day[i][j];
            }
        }
        bool ans = false;
        for(int i=0;i<5;i++)
        {
            for(int j=i+1;j<5;j++)
            {
                int ci = 0, cj = 0, cb = 0;
                bool falg = true;
                for(int k=0;k<n;k++)
                {
                    if(day[k][i]&&day[k][j]) cb++;
                    else if(day[k][i]) ci++;
                    else if(day[k][j]) cj++;
                    else {falg=false;break;}
                }
                if(!falg) continue;
                if(ci<=(n/2)&&cj<=(n/2)) ans=true;
            }
        }
        if(ans) YES;
        else NO;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
