#ifndef AKfunc_hpp
#define AKfunc_hpp

#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;

struct Bohr{
    map<char,int> nextV; //nextV[i] — номер вершины, в которую мы придем по символу с номером i в алфавите
    vector<int> pat_num; //pat_num — номер строки-образца, обозначаемого этой вершиной
    int suff_link; //suff_link - суффиксная ссылка
    map<char,int> auto_move; //auto_move - запоминание перехода автомата
    int parent; //parent - вершина-отец в дереве
    int suff_flink; //suff_flink - "хорошая" суф. ссылка
    bool flag; //flag — бит, указывающий на то, является ли наша вершина исходной строкой
    char symb; //символ на ребре от parent к этой вершине
};

Bohr makeBohr(int p, char c);
void initBohr();
void addstrBohr(const string& s, vector<string>& pattern);
int getAuto_move(int v, char ch);
int getSuff_link(int v);
int getSuff_flink(int v);
void checkForStandart(int v,int i,const vector<string>& pattern, map<int,vector<int>>& answ);
void checkForDjoker(int v,int i,vector<int>& count, const vector<int>& lenght);
void findAllPosForStandart(const string& s,const vector<string>& pattern, map<int,vector<int>>& answ);
void findAllPosForDjoker(const string& s,vector<int>& count, const vector<int>& lenght);
vector<int> spliter(stringstream& str_pat, char razd, vector<string>& pattern);

#endif //AKfunc_hpp