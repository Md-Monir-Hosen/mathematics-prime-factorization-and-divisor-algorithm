#include<bits/stdc++.h>
using namespace std;
const int Max=10000;
vector<int>primes;
void sieveSundaram()
{
    bool marked[Max/2+100]={0};
    for(int i=1;i<=(sqrt(Max)-1)/2;i++)
    {
        for(int j=(i*(i+1))<<1;j<=Max/2;j=j+2*i+1)
        {
            marked[j]=true;
        }
    }
    primes.push_back(2);
    for(int i=1;i<=Max/2;i++)
    {
        if(marked[i]==false)
        {
            primes.push_back(2*i+1);
        }
    }
}
bool isSmith(int n)
{
   int orginal_no=n;
   int pDigitSum=0;
   for(int i=0;primes[i]<=n/2;i++)
   {
       while(n%primes[i]==0)
       {
           int p=primes[i];
           n=n/p;
           while(p>0)
           {
               pDigitSum += (p%10);
               p=p/10;
           }
       }
   }
   if(n != 1 && n!=orginal_no)
   {
       while(n>0)
       {
             pDigitSum = pDigitSum + n%10;
            n = n/10;
       }
   }
   int sumDigits=0;
   while(orginal_no>0)
   {
        sumDigits = sumDigits + orginal_no % 10;
        orginal_no = orginal_no/10;
   }
   return (pDigitSum=sumDigits);
}
int main()
{
     sieveSundaram();

   cout << "Printing first few Smith Numbers"
           " using isSmith()n";
   for (int i=1; i<500; i++)
      if (isSmith(i))
          cout << i << " ";
    return 0;
}
