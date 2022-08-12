#include<bits/stdc++.h>
using namespace std;

int min_of_three(int n1,int n2,int n3)
   {
       return n1 < n2 ? (n1 < n3 ? n1 : n3) : (n2  <n3 ? n2 : n3);
   }
int equal(int n1,int n2,int n3)
{
  if(n1==n2 && n2==n3)
    return true;
  return false;
}
vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
            int i=0;
            int j=0;
            int k=0;
            vector<int> ans;
            while(i<n1 && j<n2 && k<n3)
             {
               if(equal(A[i],B[j],C[k]))
                    {
                        int ser = A[i];
                        vector<int>::iterator it;
                        it =find (ans.begin(), ans.end(), ser);
                        if (it == ans.end())
                              ans.push_back(A[i]);
                        i++;j++;k++;
                    }
                else if(min_of_three(A[i],B[j],C[k])==A[i])
                    i++;
                else if(min_of_three(A[i],B[j],C[k])==B[j])
                    j++;
                else if(min_of_three(A[i],B[j],C[k])==C[k])
                    k++;
             }
             return ans;
        }
       int main()
       {
         int A[]={1, 5, 10, 20, 40, 80};
         int B[]={6, 7, 20, 80, 100};
         int C[]={3, 4, 15, 20, 30, 70, 80, 120};

         int n1=sizeof(A)/sizeof(A[0]);
         int n2=sizeof(B)/sizeof(B[0]);
         int n3=sizeof(C)/sizeof(C[0]);

         vector<int> ans=commonElements(A,B,C,n1,n2,n3);
         for(int i=0;i<ans.size();i++)
             cout<<ans[i]<<" ";
        cout<<endl;

       }
