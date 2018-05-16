#ifndef helpfunc_hpp
#define helpfunc_hpp
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

bool checker(const string& text);
void printDj(const vector<int>& count, int stopper, int pattern_size);
void printSt(map<int, vector<int>>& answ);

#endif //helpfunc_hpp