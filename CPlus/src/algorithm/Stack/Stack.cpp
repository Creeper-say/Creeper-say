#include "../../../include/normal.h"
using namespace std;
/***
 * 基本栈的描述
 * 顺序表
 */

class Stack
{
protected:
    Stack(int storageSize);
    Stack();

public:
    bool Push(int value);
    void Pop(int &currentValue);

    int Length();
    int FindToValue(int value);
    int FindToIndex(int value);

    
private:
    int *localStorage;
    int sizeNum;
    int stackTop;
};

// 构造函数 处理数据的初始化
Stack::Stack()
{
    sizeNum = 1;
    localStorage = new int[sizeNum];
    localStorage[0] = 0;
    stackTop = 0;
}

Stack::Stack(int storageSize)
{
    if (storageSize < 1)
    {
        return;
    }
    sizeNum = storageSize;
    localStorage = new int[sizeNum];
    stackTop = 0;
}

// 入栈 数据放入
// 注意数据是否上溢
// 留一个最后的内存位置 该位置不放数据 只有数据满时栈顶游标指向它 目的是统一记录栈的长度
bool Stack::Push(int value)
{
    // 判断是否出现上溢
    if (stackTop > (sizeNum - 2))
    {
        throw "数据上溢";
        return false;
    }
    else
    {
        // localStorage[stackTop++] = value;
        localStorage[stackTop] = value;
        stackTop++; // 栈顶游标
        return true;
    }
}

// 出栈
void Stack::Pop(int &currentValue)
{
    if (stackTop < 1)
    {
        throw "下溢";
    }
    else
    {
        // int x = localStorage[--stackTop];
        stackTop--;
        currentValue = localStorage[stackTop];
        cout << currentValue << endl;
    }
}

//查找
int Stack::FindToValue(int value)
{
    int index = -1;
    for(int i =0;i< stackTop;i++)
    {
        if(localStorage[i] == value)
        {
            index =i;
            return index;
        }
    }
    return index;
}

int Stack::FindToIndex(int index)
{
    if (index > (stackTop - 1) || index < 0)
    {
        throw "位置错误";
    }
    return localStorage[index];
}

// 栈内存放数据的个数
int Stack::Length()
{
    return stackTop;
}

int main()
{

    return 0;
}