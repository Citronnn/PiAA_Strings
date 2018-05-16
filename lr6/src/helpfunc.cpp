#include "../hdr/helpfunc.hpp"

void printDj(const vector<int>& count, int stopper, int pattern_size){
    for(int i=0;i<stopper;i++){
        if(count[i]==pattern_size)
            cout<<i+1<<"\n";
    }
}

void printSt(map<int, vector<int>>& answ){
    for(auto& it: answ){
        sort(it.second.begin(),it.second.end());
        for(const auto& it_sec: it.second)
        cout<<it.first<<" "<<it_sec<<"\n";
    }
}

bool checker(const string& text){
    for(size_t i=0; i<text.size();i++){
        if(text[i]<'A' || text[i]>'Z'){
            return false;
        }
    }
    return true;
}