#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll a[200004], n, tc, g=0, ans=1, pos=0;
int main()
{
cin >> tc;
while (tc--)
{
cin>>n;
for(ll i=1;i<=n;i++)
cin>>a[i];
ans=1,g=0,pos=0;
for(ll i=2;i<=n;i++)
{
g=__gcd(g,abs(a[i]-a[i-1]));
if(g>1)
ans=max(ans,i-pos);
else{
g=0;
pos=i;
ll s=0;
while(g!=1)
{
s=g;
g=__gcd(g,abs(a[pos]-a[pos-1]));
pos--;
}
g=s;
}
}
cout<<ans<<endl;
}
return 0;
}