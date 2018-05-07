#include <iostream>
#include "../hdr/kmpFunc.h"

using namespace std;
/*
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
    if(text.size()>=temp.size()){
        int count_opers=0;
        vector<int> pi=prefix(temp);
        vector<int> index1=kmp(text,temp,pi,count_opers);
        cout<<"---------\nKMP:\n";
        if(index1.size()){
            print(index1);
        }
        else
            cout<<"-1\n";
        cout<<"Число операций: "<<count_opers+temp.size()<<"\n---------\nNaive:\n";
        count_opers=0;
        vector<int> index2=naive(text,temp,count_opers);
        if(index2.size()){
                print(index2);
        }
        else
            cout<<"-1\n";
        cout<<"Число операций: "<<count_opers<<"\n---------\n";
    }
    else
        cout<<"Шаблон должен быть меньше текста\n";
    return 0;
}
*/

string RandString(int size1, int size2){
    string str="";
    int strsize=size2+rand()%size1;
    for(int i=0; i< strsize;i++){
        str+=(char)(rand()%26 +97);
    }
    return str;
}

int main(){
    srand(time(NULL));
    vector<string> texts(5);
    for(int i=0;i<5;i++){
        texts[i]=RandString(100000,50000);
    }
    vector<string> temps(1000);
    for(int i=0;i<5;i++){
        for(int j=0;j<200;j++){
            temps[j+i*200]=RandString(100,100);
        }
    }
    int counter=0;
    for(int i=0; i<5;i++){
        for(int j=0;j<200;j++){
            vector<int> pi=prefix(temps[j+i*200]);
            int s1=0,s2=0;
            vector<int> index1=kmp(texts[i],temps[j+i*2],pi,s1);
            vector<int> index2=naive(texts[i],temps[j+i*200],s2);
            if(s1+temps[j+i*200].size()<s2)
                counter++;
        }
    }
    cout<<"Кол-во случаев, в которых алгоритм КМП сработал за меньшее число операций "<<counter<<" из 1000\n";
    return 0;
}