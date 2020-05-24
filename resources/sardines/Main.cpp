#include <cstdio>
#include <map>

class ratNode
{
    private:
        long long num,den;
        long long gcd(long long a,long long b)
        {

        }
    public:
       ratNode(long long n,long long d)
       {
           if (d==0)
           {
               den=0;
               if(n>0)
                   num=1;
               else if(n<0)
                   num=-1;
               else
                   num=0;
           }
           else if(d>0)
           {
               long long g = gcd(n,d);
               num = n/g;
               den = d/g;
           }
           else
           {
               long long g = gcd(n,d);
               num = -n/g;
               den = -d/g;
           }

       }
       bool operator< (const ratNode &o)
       {
             
       }
};

int main(void)
