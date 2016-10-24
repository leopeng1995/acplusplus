#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

const int MAXN = 1000;

void preprocess(char *pat, int *lps, int M) {
  lps[0] = 0;
  int i = 1;
  int len = 0;

  while (i < M) {
    if (pat[i] == pat[len]) {
      lps[i++] = ++len;
    } else {
      if (len != 0) len = lps[len - 1];
      else lps[i++] = 0;
    }
  }
}

void kmp(char *txt, char *pat) {
  int N = strlen(txt);
  int M = strlen(pat);

  int *lps = (int *)malloc(sizeof(int) * M);
  preprocess(pat, lps, M);

  int i = 0, j = 0;
  while (i < N) {
    if (txt[i++] == pat[j++]);

    if (j == M) {
      printf("%d\n", i - j);
      j = lps[j - 1];
    } else if (i < N && txt[i] != pat[j]) {
      if (j != 0) j = lps[j - 1];
      else i = i + 1;
    }
  }
  free(lps);
}

class Solution {
public:
  int strStr(string haystack, string needle) {
    if (!haystack.size() && !needle.size()) return 0;
    if (!needle.size()) return 0;
    if (!haystack.size()) return -1;

    return kmp(haystack, needle);
  }
private:
  int kmp(string &txt, string &pat) {
    int N = txt.size();
    int M = pat.size();

    vector<int> lps;
    preprocess(pat, lps, M);

    int i = 0, j = 0;
    while (i < N) {
      if (txt[i] == pat[j]) {
        i += 1;
        j += 1;
      }

      if (j == M) {
        return i - j;
      } else if (i < N && txt[i] != pat[j]) {
        if (j != 0) j = lps[j - 1];
        else i = i + 1;
      }
    }
    return -1;
  }
  void preprocess(string &pat, vector<int> &lps, int M) {
    lps.push_back(0);
    int len = 0;
    int i = 1;

    while (i < M) {
      if (pat[i] == pat[len]) {
        len += 1;
        i += 1;
        lps.push_back(len);
      } else {
        if (len != 0) len = lps[len - 1];
        else {
          lps.push_back(0);
          i += 1;
        }
      }
    }
  }
};

int main()
{
  //char txt[MAXN] = "ABABDABACDABABCABAB"; // ÎÄ±¾´®
  //char pat[MAXN] = "ABABCABAB"; // Ä£Ê½´®
  //kmp(txt, pat);
  Solution solution;
  string haystack("mississippi");
  string needle("a");
  cout << solution.strStr(haystack, needle) << endl;
  return 0;
}
