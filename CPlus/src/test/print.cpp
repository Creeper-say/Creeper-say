#include "../../include/print.h"

void printMessage(vector<string> &msg)
{
    for (int i = 0; i < msg.size(); i++)
    {
        cout << msg[i] << " ";
    }
    cout<< endl;
    cout<< "c++11 的新特性表达输出"<<endl;

    for (auto &msgc: msg)
    {
        cout<< msgc << " ";
    }
    cout<<endl;
}
