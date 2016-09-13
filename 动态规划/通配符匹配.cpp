#include <bits/stdc++.h>
using namespace std;

// T[i][j] is true if first i characters in given string matches the first j characters of pattern.
bool strmatch(char str[], char pattern[]) {
  int n = strlen(str), m = strlen(pattern);

  if (m == 0) return (n == 0);

  bool lookup[n + 1][m + 1];

  memset(lookup, false, sizeof(lookup));

  lookup[0][0] = true;

  for (int j = 1; j <= m; j++)
    if (pattern[j - 1] == '*')
      lookup[0][j] = lookup[0][j - 1];

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (pattern[j - 1] == '*')
        lookup[i][j] = lookup[i][j - 1] || lookup[i - 1][j];
      else if (pattern[j - 1] == '?' || str[i - 1] == pattern[j - 1])
        lookup[i][j] = lookup[i - 1][j - 1];
      else lookup[i][j] = false;
    }
  }

  return lookup[n][m];
}

int main()
{
  char str[] = "baaabab";
  char pattern[] = "*****ba*****ab";
  // char pattern[] = "ba*****ab";
  // char pattern[] = "ba*ab";
  // char pattern[] = "a*ab";
  // char pattern[] = "a*****ab";
  // char pattern[] = "*a*****ab";
  // char pattern[] = "ba*ab****";
  // char pattern[] = "****";
  // char pattern[] = "*";
  // char pattern[] = "aa?ab";
  // char pattern[] = "b*b";
  //char pattern[] = "a*a";
  // char pattern[] = "baaabab";
  // char pattern[] = "?baaabab";
  // char pattern[] = "*baaaba*";

  if (strmatch(str, pattern))
    cout <<   "Yes" << endl;
  else
    cout << "No" << endl;

  return 0;
}
