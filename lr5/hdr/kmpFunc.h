#ifndef kmpFunc_h
#define kmpFunc_h

#include <vector>
#include <string>

using namespace std;

vector<int> prefix(string temp);
vector<int> kmp(string text, string temp, const vector<int>& pi, int& count_opers);
vector<int> naive(string text, string temp, int& count_opers);

#endif //kmpFunc_h