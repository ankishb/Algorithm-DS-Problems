/*
[LeetCode] Add Bold Tag in String Add a thick label to the string

Given a string s and a list of strings dict, you need to add a closed pair of bold tag <b> and </b> to wrap the substrings in s that exist in dict. If two such substrings overlap, you need to wrap Also, if two substrings wrapped by bold tags are consecutive, you need to combine them.

Example 1:

  Input: 
 s = "abcxyz123"
 Dict = ["abc","123"]
 Output:
 "<b>abc</b>xyz<b>123</b>"

Example 2:

  Input: 
 s = "aaabbcc"
 Dict = ["aaa","aab","bc"]
 Output:
 "<b>aaabbc</b>c"

Note:

    The given dict won't contain duplicates, and its length won't exceed 100.
    All the strings in input have length in range [1, 1000]. 

This question gives us a string, and a dictionary, let us bold the words in the dictionary in the string, pay attention to if the two words have an intersection or a connection, put it in the same bold label. The idea of ​​the bloggers is that since they need to match the strings, they will go to the KMP Dafa, then get the position of each word in the string matching interval, then merge the intervals, and then label the two ends of the merged interval. But when you look at the difficulty of the topic, Medium, the medium-difficult question is not going to sacrifice KMP Dafa, so I went to the Internet to glance at the solutions of the gods and found that most of them are violent matches. Since OJ can pass, then violence Let's go. This question refers to the solution of Gao Shen shawngao , but Gao Shen is a man who has more than 1,500 praises. The idea is to create a bold boolean array of the same length as the string s, meaning that if the character is true inside the word, then we can add tags based on the true and false values ​​of the bold array. We traverse each character in the string s and treat each character traversed as the starting position. We match all the words in the dictionary. If we can match, we use i + len to update the end, len Is the length of the current word, end represents the position of the word in the dictionary ending in the string s, then if i is less than end, bold[i] will be assigned true. Finally, we update the bold array, and then iterate over the string s. If bold[i] is false, we will add s[i] directly to the result res; if bold[i] is true, then we use the while loop to find All the numbers that are consecutively true, then add labels on the left and right ends, see the code below:

Solution one:

  Class Solution { 
  Public : 
      String addBoldTag( string s, vector< string >& dict) { 
          String res = "" ; 
          Int n = s.size(), end = 0 ; 
          Vector < bool > bold(n, false ); 
          For ( int i = 0 ; i < n; ++ i) { 
              For ( string word : dict) { 
                  Int len = word.size(); 
                  If (i + len <= n && s.substr(i, len) == word) { 
                      End = max(end, i + len); 
                  } 
              } 
              Bold[i] = end > i; 
          } 
          For ( int i = 0 ; i < n; ++ i) { 
              If (! bold[i]) { 
                  Res.push_back(s[i]); 
                  Continue ; 
              } 
              Int j = i; 
              While (j < n && bold[j]) ++ j; 
              Res += " <b> " + s.substr(i, j - i) + " </b> " ; 
              i = j - 1 ; 
          } 
          Return res; 
      } 
  }; 

This question is exactly the same as the Bold Words in String after that, so the solution can of course be interoperable. Here we put the solution 2 in that question too, because the solution one and the solution two are too similar. Just post it, for specific explanations, see Bold Words in String for this post, see the code below:

Solution 2:

  Class Solution { 
  Public : 
      String addBoldTag( string s, vector< string >& dict) { 
          String res = "" ; 
          Int n = s.size(); 
          Unordered_set < int > bold; 
          For ( string word : dict) { 
              Int len = word.size(); 
              For ( int i = 0 ; i <= n - len; ++ i) { 
                  If (s[i] == word[ 0 ] && s.substr(i, len) == word) { 
                      For ( int j = i; j < i + len; ++ j) bold.insert(j); 
                  } 
              } 
          } 
          For ( int i = 0 ; i < n; ++ i) { 
              If (bold.count(i) && !bold.count(i - 1 )) res += " <b> " ; 
              Res += s[i]; 
              If (bold.count(i) && !bold.count(i + 1 )) res += " </b> " ; 
          } 
          Return res; 
      } 
  }; 
*/