#include <iostream>

using namespace std;

void citire_vector(int v[],int n)
{
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
}

void afisare_vector(int v[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

void interclasare(int v[],int l,int m,int r,int vaux[])
{
    int i=l;
    int j=m+1;
    int k=l;
    while(i<=m&&j<=r)
    {
       
        if(v[i]<v[j])
        {
            vaux[k]=v[i];
            k++;
            i++;
        }
        else 
        {
            vaux[k]=v[j];
            k++;
            j++;
        }
    }
   
    while(i<=m)
    {
        vaux[k++]=v[i++];
    }
 while(j<=r)
    {
        vaux[k++]=v[j++];
    }

    for(int f=l;f<=r;f++)
    {
        v[f]=vaux[f];
    }
}

void merge_sort(int v[],int l,int r,int vaux[])
{
    if(l<r)
    {
        int m=l+(r-l)/2;
        merge_sort(v,l,m,vaux);
        merge_sort(v,m+1,r,vaux);
        interclasare(v,l,m,r,vaux);
    }
}


int main()
{
    int v[100];
    int vaux[100];
    int n;
    cin>>n;
    citire_vector(v,n);
    merge_sort(v,0,n-1,vaux);
    afisare_vector(v,n);
}