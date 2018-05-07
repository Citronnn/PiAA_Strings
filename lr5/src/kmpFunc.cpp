#include "../hdr/kmpFunc.h"

vector<int> prefix(string temp){ //find prefix function
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

vector<int> kmp(string text, string temp, const vector<int>& pi, int& count_opers){
    vector<int> index(0);
    size_t j=0;
    for (int i=0; i<text.size(); ++i){
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

vector<int> naive(string text, string temp, int& count_opers){
    vector<int> index;
    for(int i=0; i < text.size()-temp.size()+1;i++){
        for(int j=0; j < temp.size();j++){
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