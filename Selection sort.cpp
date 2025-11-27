#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter array size: "<<endl;
    cin>>n;
    int A[n];
    cout<<"Enter array elements: ";
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }
    for(int i=0;i<n-1;i++){
        int Min=i;

    for(int j=i;j<n;j++)
{
    if(A[Min]>A[j])
    {
       Min=j;
    }
}
if(Min!=i){
 int temp=A[i];
        A[i]=A[Min];
        A[Min]=temp;
    }

    }

    cout<<"Sorted array: ";
     for(int i=0;i<n;i++)
    {
        cout<<A[i]<<" ";
    }
    return 0;
}
