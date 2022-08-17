#include<bits/stdc++.h>
using namespace std;

class Box
{
public:
    int l;
    int w;
    int h;
};

bool comp(const Box &b1, const Box &b2)
{
    return (b1.l*b1.w) < (b2.l*b2.w);
}

int boxStack(int length[], int width[], int height[], int n)
{
    Box box[3*n];

    int iter=0;
    for(int i=0;i<n;i++)
    {
        box[iter].h=height[i];
        box[iter].l=min(length[i], width[i]);
        box[iter].w=max(length[i], width[i]);
        iter++;

        box[iter].h=length[i];
        box[iter].l=min(height[i], width[i]);
        box[iter].w=max(height[i], width[i]);
        iter++;

        box[iter].h=width[i];
        box[iter].l=min(length[i], height[i]);
        box[iter].w=max(length[i], height[i]);
        iter++;
    }

    sort(box, box+(3*n), comp);
    // for(int i=0;i<n*3;i++)
    // {
    //     cout<<box[i].l<<" "<<box[i].w<<" "<<box[i].h<<"\n";
    // }

    int LIS[3*n];
    for(int i=0;i<3*n;i++)
    {
        int maxHeight=0;
        for(int j=0;j<i;j++)
        {
            if(box[j].l < box[i].l && box[j].w < box[i].w && maxHeight < LIS[j])
            {
                maxHeight = LIS[j];
            }
        }
        LIS[i] = maxHeight + box[i].h;
    }

    int mx=0;
    for(int i=0;i<3*n;i++)
        mx = max(mx, LIS[i]);
    return mx;
}


int main()
{
    int n;
    cin>>n;

    int length[n];
    int width[n];
    int height[n];
    
    for(int i=0;i<n;i++)
    {
        cin>>height[i]>>width[i]>>length[i];
    }

    cout<<boxStack(length, width, height, n);

    return 0;
}