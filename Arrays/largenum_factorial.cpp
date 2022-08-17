#include <bits/stdc++.h>
using namespace std;

#define size 2570

int multiply(int val, int res[], int res_size)
{
    int carry=0;
    for(int i=0;i<res_size;i++)
    {
        int product=res[i]*val + carry;
        res[i]=product % 10;
        carry=product/10;
    }

    while (carry)
    {
        res[res_size]=carry % 10;
        carry/=10;
        res_size++;
    }
    return res_size;
}
void factorial(int n)
{
    int res[size];
    res[0]=1;
    int res_size=1;
    for(int i=2;i<=n;i++)
    {
        res_size=multiply(i,res,res_size);
    }
    for(int i=res_size-1;i>=0;i--)
        cout<<res[i];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x;
    cin>>x;
    factorial(x);

    return 0;
}