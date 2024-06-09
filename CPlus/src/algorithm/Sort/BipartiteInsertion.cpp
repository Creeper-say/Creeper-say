#include "../../../include/normal.h"
// 二分插入排序
// 插入排序 + 二分查找
void BISort(int arr[], int n)
{
    int mid_index;
    int l, r;
    int lay_value;
    // 划分排序组
    // O(nlog2n)
    for (int i = 1; i < n; i++)
    {
        // 开始寻找位置
        lay_value = arr[i];
        // [0,i-1]这个范围是已经排好序的范围
        // 利用二分查找可以解决当前lay_value值应该放置在这个有序范围内那个位置上的问题
        l = 0;
        r = i - 1;
        mid_index = l + (r - l) / 2;
        while (l <= r)
        {
            if (lay_value > arr[mid_index])
            {
                l = mid_index + 1;
            }
            if (lay_value < arr[mid_index])
            {
                r = mid_index - 1;
            }
            mid_index = l + (r - l) / 2;
        }

        //调整位置
        for(int k = i-1;k>=l;k--)
        {
            arr[k+1] = arr[k];
        }
        arr[l] = lay_value;
    }
}

void SetArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 101;
    }
}

void PrinthfArr(int arr[], int n)
{
    for (int num = 0; num < n; num++)
    {
        cout << arr[num] << " ";
    }
    cout << endl;
}

void Test(int num, int arr[], int n)
{
    while (num > 0)
    {
        num--;
        SetArr(arr, n);
        BISort(arr, n);
        PrinthfArr(arr, n);
    }
}

int main()
{
    int arr[10] = {0};
    srand((unsigned)time(NULL));
    Test(6, arr, sizeof(arr) / sizeof(arr[0]));
    return 0;
}