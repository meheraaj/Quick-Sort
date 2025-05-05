
#include<bits/stdc++.h>
using namespace std;


int arr[100];
int arr2[100];

int partitionn(int l,int h)
{

    int i =l,j=h,pivot = arr[l];

    while(i<j)
    {
        while(arr[i] <= pivot && i <=h)
        {
            i++;
        }
        while(arr[j]>pivot &&j>=l)
        {
            j--;
        }
        if(i<j)
        {
            swap(arr[j],arr[i]);
        }
    }
    swap(arr[l],arr[j]);

    return j;
}

void quicksort(int l,int h)
{
    if(l<h)
    {
        int j = partitionn(l,h);
        quicksort(l,j-1);
        quicksort(j+1,h);
    }
}



int main()
{

    int n;
    cin >> n;
    for(int i =0; i<n; i++)
        cin >> arr[i];
    quicksort(0,n-1);

    for(int i =0; i<n; i++)
        cout << arr[i] << " ";

    return 0;
}
