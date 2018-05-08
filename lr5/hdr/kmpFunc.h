#ifndef kmpFunc_h
#define kmpFunc_h

#include <vector>
#include <string>

using namespace std;

vector<int> prefix(const string& temp);
vector<int> kmp(const string& text, const string& temp, const vector<int>& pi, int& count_opers);
int is_shift(const string& str1, const string& str2);
vector<int> naive(const string& text, const string& temp, int& count_opers);

#endif //kmpFunc_h