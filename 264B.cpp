#include <cstdio>
#include <cmath>
#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <map>
#include <cassert>
#include <string>
#include <cstring>
#include <queue>
#include <stack>
using namespace std;
#define test() int t;scanf("%d",&t);for(int tno=1;tno<=t;tno++)
#define mp make_pair
#define pb push_back
#define wl(n) while(n--)
#define fi first
#define se second
#define all(c) c.begin(),c.end()
typedef long long ll;
typedef unsigned long long llu;
typedef vector<int> vi; 
typedef pair<int,int> pii;
typedef pair<int,pair<int,int> > piii ;
typedef pair<ll,ll> pll;
typedef pair<ll,int> pli;
#define sz(a) int((a).size())
#define ini(a,v) memset(a,v,sizeof(a))
#define sc(x) scanf("%d",&x)
#define sc2(x,y) scanf("%d%d",&x,&y)
#define sc3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define scl(x) scanf("%lld",&x)
#define scl2(x,y) scanf("%lld%lld",&x,&y)
#define scl3(x,y,z) scanf("%lld%lld%lld",&x,&y,&z)
#define scs(s) scanf("%s",s);
#define debug() printf("here\n") 
#define chk(a) cerr << endl << #a << " : " << a << endl
#define chk2(a,b) cerr << endl << #a << " : " << a << "\t" << #b << " : " << b << endl
#define tr(container, it)  for(typeof(container.begin()) it = container.begin(); it != container.end(); it++) 
#define inf ((1<<29)-1)
#define linf ((1LL<<60)-1)
const double eps = 1e-9;
const int MAX = 200009;
const ll MOD = 1000000007;
//-----------------------------------------------------------------------------------------------
ll pw(ll base ,ll expo,ll c)
{
	if(expo == 0 )
	return  1 ; 
	ll f = pw(base , expo /2,c) ; 
	if(expo&1)
	return (((f*f)%c)*base)%c ; 
	return (f*f)%c;
}
int gcd(int a, int b){
    if(!a || !b)return a+b;
    return gcd(b,a%b);
}
ll n;
ll A[MAX];
set<ll>G[MAX];
ll dp[MAX];
ll prime[MAX],cp=0;
void pre(){
    vector<int>c(MAX,false);
    c[0] = c[1] = true;
    for(int i=2;i<MAX;i++){
        if(!c[i]){
            for(int j=2*i;j<MAX;j+=i){
                c[j] = true;
            }
        }
    }
    for(int i=2;i<MAX;i++){
        if(!c[i]){
            prime[cp++] = i;
        }
    }
}
int main() {
    scl(n);
    pre();
    for(int i=0;i<n;i++){
        scl(A[i]);
    }
    ll ans = 0;
    for(int i=0;i<n;i++){
        ll x = A[i];
        ll p = 0;
        for(ll j=0;prime[j]*prime[j]<=x;j++){
            if(x%prime[j]==0){
                p = max(p,G[prime[j]].size()==0?0:(*(--G[prime[j]].end())));
                while(x%prime[j]==0){
                    x/=prime[j];
                }
            }
        }
        if(x>1){
            p = max(p,G[x].size()==0?0:(*(--G[x].end())));
        }
        dp[i] = p+1;
        x = A[i];
        for(ll j=0;prime[j]*prime[j]<=x;j++){
            if(x%prime[j]==0){
                G[prime[j]].insert(dp[i]);
                while(x%prime[j]==0){
                    x/=prime[j];
                }
            }
        }
        if(x>1){
            G[x].insert(dp[i]);
        }
        ans = max(ans,dp[i]);
    }
    printf("%lld\n",ans);
    return 0;
}
 