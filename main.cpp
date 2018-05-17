#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int T,N;
long long P,A[1005];

bool binarySearch(int i3,int n,long long pLeft)
{
    int middle= 0;
    n=n-1;
    bool check=false;
    while(n>=i3)
    {
        middle=(i3+n)/2;
        if (A[middle]==pLeft)
        {
            check==true;
            break;
        }
        else if (A[middle]>pLeft)
        {
            n=middle-1;
        }
        else if (A[middle]<pLeft)
        {
            i3=middle+1;
        }
    }
    return check;
}

int main()
{
   cin>>T;
    //read test cases;
   for (int i=1;i<=T;i++)
   {
       cin>>N;

       for(int i1=0;i1<N;i1++)
       {
           cin>>A[i1];
       }
       cin>>P;

        sort(A,A+N);

        bool check=false;
       for(int i2=0;i2<N;i2++)
       {
           for(int i3=i2+1;i3<N;i3++)
           {
               long long pLeft= P-A[i2]-A[i3];
                if(binarySearch(i3+1,N, pLeft)==true)
                {
                    check=true;
                }
           }
       }

       if (check==true)
       {
           cout<<"YES\n";
       }
       else
       {
           cout<<"NO\n";
       }
   }
    return 0;
}
