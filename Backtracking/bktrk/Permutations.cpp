#include<bits/stdc++.h>
using namespace std;

/*
void permuteRecursive(vector<int> &num, int begin, vector<vector<int> > &result)
{
    if (begin >= num.size()) {
        result.push_back(num);
        return;
    }
    
    for (int i = begin; i < num.size(); i++) {
        swap(num[begin], num[i]);
        permuteRecursive(num, begin + 1, result);
        // reset
        swap(num[begin], num[i]);
    }
}

vector<vector<int> >  Solution::permute(vector<int> &num)
{
    vector<vector<int> > result;
	    
    permuteRecursive(num, 0, result);
    return result;
    
}

*/
void generateAllPermutations(vector<int>& toBePermuted, unsigned int nextIndex,vector<vector<int> >& my_vec);
 
void swap(int &a,int &b)
{
    int temp=a;
    a=b;
    b=temp;
}
 
 
void generateAllPermutations(vector<int>& toBePermuted, unsigned int nextIndex,vector<vector<int> >& my_vec)
{ 
    
    if (nextIndex==toBePermuted.size()-1)  
    { 
        my_vec.push_back(toBePermuted); 
        return;
    }

    for (unsigned int i=nextIndex; i<toBePermuted.size(); i++)
    {
        swap(toBePermuted[i], toBePermuted[nextIndex]);
        generateAllPermutations(toBePermuted, nextIndex+1,my_vec);
        swap(toBePermuted[i], toBePermuted[nextIndex]);
    }
  
}

void generateAllPermutations_v2(vector<int>& toBePermuted, unsigned int nextIndex,vector<vector<int> >& my_vec)
{ // input may contain duplicate elements
    
    if (nextIndex == toBePermuted.size()-1)  
    { 
        my_vec.push_back(toBePermuted); 
        return;
    }

    unordered_set<int> unique;

    for (unsigned int i=nextIndex; i<toBePermuted.size(); i++)
    {
        if(unique.find(toBePermuted[i]) != unique.end())
            continue;
        
        unique.insert(toBePermuted[i]);

        swap(toBePermuted[i], toBePermuted[nextIndex]);
        generateAllPermutations(toBePermuted, nextIndex+1,my_vec);
        swap(toBePermuted[i], toBePermuted[nextIndex]);
    }
  
}

 
vector<vector<int> > permute(vector<int> &A)
{
    
    vector<vector<int> > result;
    if(A.size()==0)
    return result;
    
    sort(A.begin(),A.end());
    generateAllPermutations(A,0,result);
    
    return result;
 
    
    
}


int main()
{

    

    return 0;
}