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

void TestShift(){
    assert(is_shift("defabc","abcdef")==3);
    assert(is_shift("a","aaa")==-1);
    assert(is_shift("aaa","a")==-1);
    assert(is_shift("aaa","aaa")==0);
    assert(is_shift("aaab","aaaa")==-1);
    assert(is_shift("qwertyuiop","uiopqwerty")==6);
    assert(is_shift(string(4999999, 'a')+'b','b'+string(4999999, 'a'))==4999999);
}

int main(){
    TestPref();
    TestKmp();
    TestShift();
    cout<<"Correct!\n";
    return 0;
}