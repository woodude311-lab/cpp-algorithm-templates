const int N = 1e7 + 10;
bool isPrime[N];
vector<int> primes;
void init(int n)
{
    fill(isPrime, isPrime + N + 1, true);
    isPrime[0] = isPrime[1] = false;
    for(int i = 2;i <= N;++i)
    {
        if(isPrime[i]) primes.push_back(i);
        for(int p : primes)
        {
            if(1LL * i * p > n) break;
            isPrime[i * p] = false;
            if(i % p == 0) break;  // 保证每个合数只被最小质因子筛一次
        }
    }
}
