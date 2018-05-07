#include <iostream>
#include "../hdr/kmpFunc.h"

using namespace std;

int main(){
    string str1, str2;
    cout<<"Str1:\n";
    cin>>str1;
    cout<<"Str2:\n";
    cin>>str2;
    if(str1.size()!=str2.size()){
        cout<<"-1";
        return 0;
    }
    vector<int> pi=prefix(str2);
    int count_opers=0;
    vector<int> index=kmp(str1+str1,str2,pi,count_opers);
    if(index.size()){
        cout<<index[0]<<"\n";
    }
    else
        cout<<"-1\n";
    return 0;
}