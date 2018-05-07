#include <iostream>
#include "../hdr/kmpFunc.h"

void print(const vector<int>& index){ //print result
    for(const auto& it: index){
        cout<<it;
        if(it!=index[index.size()-1])
            cout<<",";
    }
    cout<<"\n";
}

int main(){
    string text, temp;
    cout<<"Template:\n";
    cin>>temp;
    cout<<"Text:\n";
    cin>>text;
    int count_opers=0;
    if(temp.size()<15000 && text.size()<5000000){
        vector<int> pi=prefix(temp);
        vector<int> index=kmp(text,temp,pi,count_opers);
        if(index.size()){
            print(index);
        }
        else
            cout<<"-1\n";
    }
    else
        cout<<"out of range\n";
    return 0;
}