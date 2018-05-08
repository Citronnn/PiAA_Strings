#include <iostream>
#include "../hdr/kmpFunc.h"

using namespace std;

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
    cout<<"Длина текста от 50000 до 150000 символов.\nДлина образца от 100 до 200 символов.\n";
    cout<<"Кол-во случаев, в которых алгоритм КМП сработал за меньшее число операций "<<counter<<" из 1000\n";
    return 0;
}
