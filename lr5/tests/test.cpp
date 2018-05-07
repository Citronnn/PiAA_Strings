#include "../hdr/kmpFunc.h"
#include <cassert>
#include <iostream>

void TestPref(){
    assert(prefix(" ")==vector<int>({0}));
    assert(prefix("a")==vector<int>({0}));
    assert(prefix("abcde")==vector<int>({0,0,0,0,0}));
    assert(prefix("aaaaa")==vector<int>({0,1,2,3,4}));
    assert(prefix("ababa")==vector<int>({0,0,1,2,3}));
    assert(prefix("baaab")==vector<int>({0,0,0,0,1}));
    assert(prefix("aaabaaa")==vector<int>({0,1,2,0,1,2,3}));
    assert(prefix("aabaaab")==vector<int>({0,1,0,1,2,2,3}));
    assert(prefix("abcaababcabcacab")==vector<int>({0,0,0,1,1,2,1,2,3,4,2,3,4,0,1,2}));
}

void TestKmp(){
    int counter=0;
    assert(kmp("a","a",vector<int>({0}),counter)==vector<int>({0}));
    assert(kmp("a","b",vector<int>({0}),counter).size()==0);
    assert(kmp("a","bcs",vector<int>({0}),counter).size()==0);
    assert(kmp("aba","a",vector<int>({0}),counter)==vector<int>({0,2}));
    assert(kmp("aba","b",vector<int>({0}),counter)==vector<int>({1}));
    assert(kmp("aaa","aa",vector<int>({0,1}),counter)==vector<int>({0,1}));
    assert(kmp("aabaabbaaabaabaabaabaabbaabb","aabbaab",vector<int>({0,1,0,0,1,2,3}),counter)==vector<int>({20}));
}

int main(){
    TestPref();
    TestKmp();
    cout<<"Correct!\n";
    return 0;
}