### Scrabled Word

You are given a scrambled input sequence. Each word is scrambled independently, and the result are concatenated.

So:

'hello to the world' might become: 'elhloothtedrowl'

You have a dictionary with all words in it. Unscramble the sentence.

一个英文句子被去掉标点和空格后打乱（以字母为单位打乱而不是以单词为单位）。现在给你这个打乱后的仅由字母组成的字符串。在给你一个英文字典，字典里包含所有在原句中出现的单词（不存在未知词）。现在让你找出至少一个（多个当然更好）原句的组成方案。注意打乱字符串没有无用字母，忽略大小写。

LA3942

DFS

Trie + DP