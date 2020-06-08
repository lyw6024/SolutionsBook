#include <cstdio>
#include <map>
using std::map;

class ratNode
{
    private:
        long long num,den;
        long long gcd(long long a,long long b)
        {
            if(a==0)
                return b;
            if(b==0)
                return a;
            if(a%b==0)
            {
                return b;
            }
            else
            {
                return gcd(b,a%b);
            }

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

       bool operator< (const ratNode &o) const
       {
           if(num*o.num<0)
           {
               return num<o.num;
           }
           else
           {
                return o.den*num<o.num*den;
           }
       }
};

int main(void)
{
    map<ratNode,int> m;
    int i,j;
    for(i=-2;i<5;i++)
    {
        for(j=-2;j<5;j++)
        {
            if(m.count(ratNode(i,j))==0)
                m[ratNode(i,j)]=i+j;
        }
    }
    for(i=-2;i<5;i++)
    {
        for(j=-2;j<5;j++)
        {
            printf("%d,%d\t%d\n",i,j,m[ratNode(i,j)]);
        }
    }
    return 0;
}
 
