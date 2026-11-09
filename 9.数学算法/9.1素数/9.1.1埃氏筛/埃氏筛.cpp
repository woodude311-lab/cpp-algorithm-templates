const int N = 1e7 + 10;
bool isPrime[N+1];   // isPrime[i] = true 表示 i 是素数
void init()
{
    fill(isPrime,isPrime + N + 1,true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2;i * i <= N;++i) 
    {
        if(isPrime[i])
        {
            for(int j = i * i;j <= N;j += i)
            {
                isPrime[j] = false;
            }
        }
    }
}
