#include "../../../include/normal.h"

void InsertSort(int arr[],int n)
{
    int lay_place,j;
    for (int i = 1; i < n; i++) //有序组范围 [0 - 1] ... [0 - n-1]
    {
        lay_place = arr[i];
        //开始判断放置的位置
        for (j = i - 1; j > -1 && lay_place < arr[j]; j--)
        {
            arr[j+1] = arr[j];
        }
        //开始放置
        arr[j+1] = lay_place;
    }
}

void InsertSort1(int arr[], int n)
{
    int j;
    for (int i = 1; i < n; i++)
    {
        for (j = i; j > 0 && arr[j] < arr[j - 1]; j--)
        {
            swap(arr[j], arr[j - 1]);
        }
    }
}

void SetArr(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        arr[i] = rand()%101;
    }
}

void PrinthfArr(int arr[],int n)
{
    for(int num = 0;num<n;num++)
    {
        cout<< arr[num] <<" ";
    }
    cout<<endl;
}

void Test(int num,int arr[],int n)
{
    while(num>0)
    {
        num--;
        SetArr(arr,n);
        InsertSort(arr,n);
        PrinthfArr(arr,n);
    }
}

int main()
{
    int arr[10]={0};
    Test(6,arr,sizeof(arr)/sizeof(arr[0]));
    return 0;
}