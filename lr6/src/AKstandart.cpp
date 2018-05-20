#include "../hdr/AKfunc.hpp"
#include "../hdr/helpfunc.hpp"

int main(){
    initBohr();
    string text, temp;
    int n;
    cin>>text>>n;
    vector<string> pattern;
    map<int,vector<int>> answ;
    for(int i=0; i<n; i++){
        cin>>temp;
        addstrBohr(temp, pattern);
    }
    findAllPosForStandart(text, pattern,answ);

    printSt(answ);
    return 0;
}