#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        int x,flag=0;
        cin>>x;
        
        for(int i=0;i<=x;i++)
        {
            for(int j=1;j<=x;j++)
            {
                if((i*j)==x && (float)i/j>=0.5)
                    flag=1;
            }
        }
        cout<<flag<<endl;
    }

    return 0;
}

