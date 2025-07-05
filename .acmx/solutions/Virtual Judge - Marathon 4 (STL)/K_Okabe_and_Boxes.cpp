#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false), cin.tie(0)
#define endl '\n'
#define int long long
#define all(x) x.begin(), x.end()
#define pb push_back
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define check(x) cout << (#x) << " is " << (x) << endl;
const int mod = 1e9 + 7;

struct node{
    int a,b,c;
};

signed main()
{
    // freopen("","r+",stdin);
    // freopen("","w+",stdout);
    // FastIO;
    int Master0fTheSEA = 1;
    scanf("%lld ", &Master0fTheSEA);
    for (int tttttttt = 1; tttttttt <= Master0fTheSEA; tttttttt++)
    {
        YES;
        char ab[100];
        int ara[101][11],bra[101][11];
        memset(ara,0,sizeof(ara));
        memset(bra,0,sizeof(bra));
        while (gets(ab))
        {
            int n = strlen(ab);
            if (!n)
                break;
            int no = 0, prb = 0, time = 0;
            char ver;
            for (int i = 0; i < n;)
            {
                while (ab[i] == ' ' && i < n)
                    i++;
                while (ab[i] != ' ' && i < n)
                {
                    no = no * 10 + (ab[i] - '0');
                    i++;
                }
                while (ab[i] == ' ' && i < n)
                    i++;
                while (ab[i] != ' ' && i < n)
                {
                    prb = prb * 10 + (ab[i] - '0');
                    i++;
                }
                while (ab[i] == ' ' && i < n)
                    i++;
                while (ab[i] != ' ' && i < n)
                {
                    time = time * 10 + (ab[i] - '0');
                    i++;
                }
                while (ab[i] == ' ' && i < n)
                    i++;
                ver = ab[i++];
                while (ab[i] == ' ' && i < n)
                    i++;
                if(bra[no][prb]) continue;
                if (ver == 'C')
                {
                    bra[no][prb]=1;
                    ara[no][prb]= 20*ara[no][prb]+time;
                }
                else if(ver == 'I')
                {
                    ara[no][prb]++;
                }
            }
        }
        vector<node>vec;
        for(int i=1;i<101;i++)
        {
            int a=0,b=0;
            for(int j=1;j<10;j++)
            {
                if(bra[i][j])
                {
                    a++;
                    b+=ara[i][j];
                }
            }
            if(a) vec.pb({i,a,b});
        }
        sort(vec.begin(),vec.end(),[&](node &x, node &y){
            if(x.b!=y.b) return x.b>y.b;
            else
            {
                if(x.c!=y.c) return x.c<y.c;
                else return x.a<y.a;
            }
        });
        for(int i=0;i<vec.size();i++) cout<<vec[i].a<<" "<<vec[i].b<<" "<<vec[i].c<<endl;
        cout<<endl;
    }
    // cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
