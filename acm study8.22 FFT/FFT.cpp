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
cp a[maxn], b[maxn], omg[maxn], inv[maxn];  // omg ��λ�� inv ��λ���Ĺ��� 
 
void init()   // ��ʼ�� 
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
 
void FFT(cp *a, cp *omg)   // ���ٸ���Ҷ�任 
{   int lim = 0;
    while((1 << lim) < n) lim++;   // ȷ��λ�� 
    for(int i = 0; i < n; i++) {   // ȷ������λ�� 
        int t = 0;
        for(int j = 0; j < lim; j++)   // ö��ÿһλ�Ƿ�Ϊ1 Ȼ��任 
            if((i >> j) & 1) t |= (1 << (lim - j - 1));  // ȷ����������λ�� 
        if(i < t) swap(a[i], a[t]); // i < t ������ʹ��ÿ�Ե�ֻ������һ�Σ����򽻻������൱��û������
    }
    for(int l = 2; l <= n; l *= 2) {  // ���� ���ϻ�ԭ 
        int m = l / 2;
    for(cp *p = a; p != a + n; p += l)
        for(int i = 0; i < m; i++) {
            cp t = omg[n / l * i] * p[i + m];  // �������� 
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
		while(n < lena + lenb) n *= 2;   //  ����λ�� 
		init();  // ��ʼ�� 
		for(int i = 0; i < lena; i++)   // ʵ����ʼ�� 
		a[i].real(sa[lena - 1 - i] - '0');   
		for(int i = 0; i < lenb; i++)  // ʵ����ʼ��  
		b[i].real(sb[lenb - 1 - i] - '0');
		FFT(a, omg);  // ϵ��ת��ֵ 
		FFT(b, omg);  // ϵ��ת��ֵ 
		for(int i = 0; i < n; i++)
		a[i] *= b[i];  // ��� 
		FFT(a, inv);  // ��ֵתϵ�� ��ɢ����Ҷ�任��任 
		for(int i = 0; i < n; i++) {
			res[i] += floor(a[i].real() / n + 0.5);  // ��ɢ����Ҷ�任��任 
			res[i + 1] += res[i] / 10;  // ��λ 
			res[i] %= 10;
		}
		int len = lena + lenb - 1;
		while(res[len] <= 0 && len > 0) len--;
		for(int i = len; i >= 0; i--)
			putchar('0' + res[i]);  // ��ӡ��� 
		printf("\n");
	}
	return 0; 
}
