#include "../hdr/AKfunc.hpp"
#include "../hdr/helpfunc.hpp"

int main(){
    initBohr();
    string text, temp;
    char razd;
    cin>>text>>temp>>razd;
    stringstream str_pat(temp);
    vector<int> count(text.size(),0); //вектор, содержащий счётчики вхождений частей шаблона
    vector<string> pattern; //вектор для частей шаблона
    vector<int> lenght = spliter(str_pat, razd, pattern);//места, где части шаблона заканчиваются в самом шаблоне
    findAllPosForDjoker(text, count, lenght);
    printDj(count,text.size()-temp.size()+1,pattern.size());

    return 0;
}