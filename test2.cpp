#include <immintrin.h>
#include <stdio.h>
#include <random>
void
bitdump(double a){
  printf("%.16f\n",a);
  char *x = (char*)(&a);
  int count = 0;
  for(int i=0;i<8;i++){
    for(int j=0;j<8;j++){
      if(x[7-i] & (1<<(7-j)))printf("1");
      else printf("0");
      count++;
      if(count==1 || count==12)printf(" ");
    }
  }
  printf("\n");
}

int
bitcomp(double a, double b){
  char *x = (char*)(&a);
  char *y = (char*)(&b);
  int sum = 0;
  for(int i=0;i<8;i++){
    for(int j=0;j<8;j++){
      char xb = x[7-i] & (1<<(7-j));
      char yb = y[7-i] & (1<<(7-j));
      if(xb!=yb)return sum-12;
      sum++;
    }
  }
  return sum - 12;
}

double out[8];

int
main(){
  std::mt19937 mt(1);
  __m512d v2 = _mm512_set1_pd(2.0);
  std::uniform_real_distribution<double> ud(0.0,1.0);
  for(int i=0;i<10;i++){
    double a = ud(mt);
    __m512d z = _mm512_set1_pd(a);
    __m512d zinv = _mm512_rcp28_pd(z);
    __m512d ze = _mm512_mul_pd(z,zinv);
    __m512d zinv2 = _mm512_sub_pd(v2,ze);
    zinv2 = _mm512_mul_pd(zinv2,zinv);
    double ainv = 1.0/a;
    _mm512_storeu_pd(out, zinv2);
    bitdump(ainv);
    bitdump(out[0]);
    printf("%d\n",bitcomp(ainv,out[0]));
    printf("\n");
  }
}
