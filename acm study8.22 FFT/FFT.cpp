#include<cstdio>
#include<algorithm>
#include<cmath>
#include<complex>
#include<cstring>
using namespace std;
typedef complex<double> cp;
const double pi = acos(-1);
const int maxn = 200000 + 8;
char sa[maxn], sb[maxn];
int n, lena, lenb, res[200000+8];
cp a[maxn], b[maxn], omg[maxn], inv[maxn];  // omg 单位根 inv 单位根的共轭 
 
void init()   // 初始化 
{
	memset(omg, 0, sizeof(omg));
	memset(inv, 0, sizeof(inv));
	for(int i = 0; i < n; i++) {
		omg[i] = cp(cos(2 * pi * i / n), sin(2 * pi * i / n));
		inv[i] = conj(omg[i]); 
	}
	memset(res, 0, sizeof(res));
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
}
 
void FFT(cp *a, cp *omg)   // 快速傅里叶变换 
{   int lim = 0;
    while((1 << lim) < n) lim++;   // 确定位数 
    for(int i = 0; i < n; i++) {   // 确定最后的位置 
        int t = 0;
        for(int j = 0; j < lim; j++)   // 枚举每一位是否为1 然后变换 
            if((i >> j) & 1) t |= (1 << (lim - j - 1));  // 确定分组的最后位置 
        if(i < t) swap(a[i], a[t]); // i < t 的限制使得每对点只被交换一次（否则交换两次相当于没交换）
    }
    for(int l = 2; l <= n; l *= 2) {  // 分治 向上还原 
        int m = l / 2;
    for(cp *p = a; p != a + n; p += l)
        for(int i = 0; i < m; i++) {
            cp t = omg[n / l * i] * p[i + m];  // 蝴蝶操作 
            p[i + m] = p[i] - t;
            p[i] += t;
        }
    }
}
 
int main()
{
	while(scanf("%s %s", sa, sb) == 2) {
		lena = strlen(sa), lenb = strlen(sb);
		n = 1;
		while(n < lena + lenb) n *= 2;   //  补齐位数 
		init();  // 初始化 
		for(int i = 0; i < lena; i++)   // 实部初始化 
		a[i].real(sa[lena - 1 - i] - '0');   
		for(int i = 0; i < lenb; i++)  // 实部初始化  
		b[i].real(sb[lenb - 1 - i] - '0');
		FFT(a, omg);  // 系数转点值 
		FFT(b, omg);  // 系数转点值 
		for(int i = 0; i < n; i++)
		a[i] *= b[i];  // 点乘 
		FFT(a, inv);  // 点值转系数 离散傅里叶变换逆变换 
		for(int i = 0; i < n; i++) {
			res[i] += floor(a[i].real() / n + 0.5);  // 离散傅里叶变换逆变换 
			res[i + 1] += res[i] / 10;  // 进位 
			res[i] %= 10;
		}
		int len = lena + lenb - 1;
		while(res[len] <= 0 && len > 0) len--;
		for(int i = len; i >= 0; i--)
			putchar('0' + res[i]);  // 打印结果 
		printf("\n");
	}
	return 0; 
}
