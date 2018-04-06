#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// C function for extended Euclidean Algorithm
long long gcdExtended(long long a, long long b, long long *x, long long *y)
{
    // Base Case
    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }
 
    long long x1, y1; // To store results of recursive call
    long long gcd = gcdExtended(b%a, a, &x1, &y1);
 
    // Update x and y using results of recursive
    // call
    *x = y1 - (b/a) * x1;
    *y = x1;
 
    return gcd;
}
long long modInverse(long long a, long long m)
{
    long long x, y;
    long long g = gcdExtended(a, m, &x, &y);
    long long res = (x%m + m) % m;
    return res;
}
 

 
long long gc(long long a, long long b){
    if(min(a,b)==0LL){
        return a+b;
    }
    return gc(b%a,a);
}
long long dp1[1001][1001];
long long dp2[1001][1001];
class Pair{
    public:
        long long p, q;
        Pair(long long a, long long b){
            p = a;
            q = b;
        }
};
int k;
long long pa, pb;
long long tot;
long long mod;
Pair go(int a, int pair){
    if(dp1[a][pair]!=-1){
        return Pair(dp1[a][pair],dp2[a][pair]);
    }
    if(pair+a>=k){
        long long num = tot+pb*((long long)a+(long long)pair-1LL);
        long long dem = pb;
        long long g = gc(num,dem);
        num /= g;
        dem /= g;
        dp1[a][pair] = num%mod;
        dp2[a][pair] = dem%mod;
        cout << a << " " << pair << " " << " => " << num << "/" << dem << endl;
        return Pair(num%mod,dem%mod);
    }
    else{
        Pair p1 = go(a+1,pair);
        Pair p2 = go(a,pair+a);
        long long num = ((((pa*p1.p)%mod)*p2.q)%mod)+((((pb*p2.p)%mod)*p1.q)%mod);
        long long dem = ((tot*p1.q)%mod)*p2.q;
        num %= mod;
        dem %= mod;
        dp1[a][pair] = num;
        dp2[a][pair] = dem;
        cout << a << " " << pair << " " << " => " << num << "/" << dem << endl;
        return Pair(num,dem);
        //ans = (p1/tot)*go(a+1,pair) + (p2/tot)*go(a,pair+a);
    }
}
int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    mod = 1000000007LL;
    cin >> k >> pa >> pb;
    long long g = gc(pa,pb);
    pa/=g;
    pb/=g;
    tot = pa+pb;
    for(int i = 0; i<=1000; i++){
        for(int j = 0; j<=1000; j++){
            dp1[i][j] = -1LL;
            dp2[i][j] = -1LL;
        }
    }
    Pair ret = go(1,0);
    g = gc(ret.p,ret.q);
    long long ans = (ret.p*modInverse(ret.q,mod))%mod;
    cout << ans << endl;
    return 0;
}
