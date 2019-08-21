# include <iostream>
using namespace std;
int times(int n)
{
   int i=0;
   long long sum=0;
   if(n==1||n==0) return 1;
   else if(n==2) return 2;
   else  
   {   
       while(i<n/2)
       {
          sum+=times(n-i-1)*times(i);
          i++; 
       }
       if(n%2==0) return 2*sum;
       else return 2*sum+times((n-1)/2)*times((n-1)/2);
   }
}
int main()
{
   int n;
   while(cin>>n)
   {
      cout<<times(n)<<endl;
   }
} 

