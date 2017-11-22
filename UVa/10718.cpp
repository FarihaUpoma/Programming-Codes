#include <stdio.h>

#define I (1ll <<32)

int main()
{
  long long int n, l, r, M, m, i;
  while(scanf("%lld %lld %lld", &n, &l, &r)==3)
  {
      M=0;
      for(i=I ; i>0 ; i= i>>1)
      {
          m= M|i;
          if(  (m <= l) || (( m<=r) && (~n&i)))
            M=m;
      }
      printf("%lld\n", M);
  }

}
