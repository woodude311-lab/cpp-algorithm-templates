struct BIT
{
    int n;
    vector <long long> t;
    BIT(int n) : n(n),t(n + 1){}

    void add(int x,long long v)
    {
        for(;x <= n;x += x & -x) t[x] += v;
    }

    long long sum(int x)
    {
        long long res = 0;
        for(;x;x -= x & -x) res += t[x];
        return res;
    }

    long long query(int l,int r)
    {
        return sum(r) - sum(l - 1);
    }
};
