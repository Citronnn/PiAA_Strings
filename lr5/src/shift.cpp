#include <iostream>
#include "../hdr/kmpFunc.h"

using namespace std;

int main(){
    string str1, str2;
    cout<<"Str1:\n";
    cin>>str1;
    cout<<"Str2:\n";
    cin>>str2;
    cout<<is_shift(str1,str2)<<"\n";
    return 0;
}