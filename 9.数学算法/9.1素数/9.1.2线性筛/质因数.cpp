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
