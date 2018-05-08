#include "../hdr/kmpFunc.h"

vector<int> prefix(const string& temp){ //find prefix function
    size_t n = temp.size();
    vector<int> pi(n);
    for (size_t i=1; i<n; ++i){
        size_t j = pi[i-1];
        while ((j > 0) && (temp[i] != temp[j]))
            j = pi[j-1];
        if (temp[i] == temp[j])
            ++j;
        pi[i] = j;
     }
     return pi;
}

vector<int> kmp(const string& text, const string& temp, const vector<int>& pi, int& count_opers){
    vector<int> index(0);
    size_t j=0;
    for (size_t i=0; i<text.size(); ++i){
        while ((j > 0) && text[i] != temp[j]){
            j = pi[j-1];
        }
        if (text[i] == temp[j])
            ++j;
        if (j==temp.size())
            index.push_back(i-j+1);
        count_opers++;
    }
    return index;
}

int is_shift(const string& str1, const string& str2){
    if(str1.size()!=str2.size()){
        return -1;
    }
    vector<int> pi=prefix(str2);
    int count_opers=0;
    vector<int> index=kmp(str1+str1,str2,pi,count_opers);
    if(index.size()){
        return index[0];
    }
    else
        return -1;
}

vector<int> naive(const string& text, const string& temp, int& count_opers){
    vector<int> index;
    for(size_t i=0; i < text.size()-temp.size()+1;i++){
        for(size_t j=0; j < temp.size();j++){
            count_opers++;
            if(temp[j]==text[i+j]){
                if(j==temp.size()-1)
                    index.push_back(i);
            }
            else
                break;
        }
    }
    return index;
}