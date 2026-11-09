#include <iostream>
#include <vector>
using namespace std;
// 鞋带公式判断多边形方向
// 屏幕坐标(y向下)：1顺时针，-1逆时针，0退化
int polyDir(const vector <pair <int,int>>& p)
{
    int n = (int)p.size();
    if(n < 3) return 0;

    long long s = 0; // 2倍有向面积
    for(int i = 0;i < n;i++)
    {
        int j = (i + 1) % n;
        s += 1LL * p[i].first * p[j].second - 1LL * p[j].first * p[i].second;
    }
    if (s > 0) return 1;
    else if (s < 0) return -1;
    return 0;
}
