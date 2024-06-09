#include "../../../include/normal.h"

void SelectedSort1(int arr[],int n)
{
    //记录最小值的下标
    int target_index;
    for(int i =0;i<n;i++) //放置次数
    {
       target_index = i;
       for(int j = i;j<n;j++)
       {
            target_index = arr[target_index] > arr[j] ? j: target_index;
       }
       // 交换 放置最小值到指定位置
       swap(arr[i],arr[target_index]);
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
        SelectedSort1(arr,n);
        PrinthfArr(arr,n);
    }
}


int main()
{   
    int arr[10]={0};
    Test(6,arr,sizeof(arr)/sizeof(arr[0]));
    return 0;
}