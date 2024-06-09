#include  "../../../include/normal.h"

void Bubling1(int arr[],int n)
{
    for(int i=0;i<n-1;i++) //比较次数
    {
        //两两比较 挑最大
        for(int j=0;j<(n-1)-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);
            }
        }
    }
}

//双向浮现 
void Bubling2(int arr[],int n)
{
    //两个方向比较位置的上限
    int R = n-1;
    int L = 0;
    while(L<R) // L<R的情况下才有继续排序的价值
    {
        //右边处理 挑最大值
        for (int i = 0 ; i < R; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                swap(arr[i], arr[i + 1]);
            }
        }

        //左边处理
        for(int j=R-1;j>L;j--)
        {
            if(arr[j]<arr[j-1])
            {
                swap(arr[j],arr[j-1]);
            }
        }
        R--;
        L++;
    }
}


void SetArr(int arr[],int n)
{
    for(int i =0;i<n;i++)
    {
        arr[i] = rand()%101;
    }
}

void PrinthfArr(int arr[],int n)
{
    for(int i=0;i<n;i++)
    { 
        cout<< arr[i]<<" ";
    }
    cout<<endl;
}

void TestNum(int num,int arr[],int n)
{
    while(num>0)
    {
        num--;
        SetArr(arr,n);
        Bubling1(arr,n);
        cout<<"法二"<<endl;
        Bubling2(arr,n);
        PrinthfArr(arr,n);
    }
}

int main()
{
    int arr[10] ={0};
    srand((unsigned)time(NULL));
    TestNum(5,arr,sizeof(arr)/sizeof(arr[0]));
    return 0;
}

