const int N = 1e7 + 10;
bool isPrime[N+1];
vector<int> mu(N+1),primes;
void init()
{
  fill(isPrime,isPrime+N+1,true);
  isPrime[0] = isPrime[1] = false;
  mu[1] = 1;
  for(int i = 2;i <= N;i++)
  {
      if(isPrime[i])
      {
          primes.push_back(i);
          mu[i] = -1;
      }
      for(int p : primes)
      {
          if(1LL * i * p > N) break;
          isPrime[i * p] = false;
          if(i % p == 0)
          {
              mu[i * p] = 0;
              break;
          }
          else
          {
              mu[i * p] = -mu[i];
          }
      }
  }
}
