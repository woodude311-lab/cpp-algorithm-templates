const int N = 1e7 + 10;
int minp[N];
vector<int> primes;
void init(int n)
{
    minp[1] = 1;
    for(int i = 2;i <= n;++i)
    {
        if(!minp[i])
        {
            minp[i] = i;
            primes.push_back(i);
        }
        for(int p : primes)
        {
            if(1LL * i * p > n) break;
            minp[i * p] = p;
            if(p == minp[i]) break;
        }
    }
}
vector <pair <int,int>> factorize(int x)
{
    vector <pair <int,int>> res;
    while(x > 1)
    {
        int p = minp[x];
        int cnt = 0;
        while(x % p == 0)
        {
            x /= p;
            cnt++;
        }
        res.push_back({p,cnt});
    }
    return res;
}
/*
#include <iostream>
#include <vector>
using namespace std;
const int N = 31623 + 10;
bool isPrime[N+1];
vector <int> primes;
void init()
{
    fill(isPrime,isPrime+N+1,true);
    isPrime[0] = isPrime[1] = false;
    for(int i = 2;i <= N;i++)
    {
        if(isPrime[i]) primes.push_back(i);
        for(auto& p : primes)
        {
            if(1LL*i*p > N) break;
            isPrime[i*p] = false;
            if(i % p == 0) break;
        }
    }
}
vector <pair <int,int>> factorize(int x)
{
    vector <pair <int,int>> res;
    for(auto& p : primes)
    {
        if(1LL*p*p > x) break;
        if(x % p == 0)
        {
            int cnt = 0;
            while(x % p == 0)
            {
                x /= p;
                cnt++;
            }
            res.push_back({p,cnt});
        }
    }
    if(x > 1) res.push_back({x,1});
    return res;
}
*/
