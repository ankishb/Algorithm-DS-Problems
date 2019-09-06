//https://www.youtube.com/watch?v=nbTSfrEfo6M
// https://tarokuriyama.com/projects/palindrome2.php

vector<int> P(T.length());
int center = 0, right = 0;

for(int i=1; i<T.length(); i++){
	int mirror = 2*center - i;

	// check if current index lies in the current largest pallindromic boundary, then either it will be same as length of its mirror or length from current to its right
	if(i < right){
		P[i] = min(Right - i, P[mirror]);
	}

	// Now at current centre, we strat to expand. Note that, using above condition, will help us starting from at least possible pallindromic substring.
	while(T[i + (1 + P[i])] == T[i - (1 + P[i])]) P[i]++;

	// if we get larger pallindrome, then we need to update, center and right bundary
	if(i + P[i] > right){
		center = i;
		right = i + P[i];
	}
}










def longestPalindromicSubstringManacher(ip):
    """
    This function is an implementation of the Manacher algorithm for finding the Longest Palindromic Substring.
    It takes O(n) time. 
    """
    s = '$*' + '*'.join(ip) + '*#'
    P = [0] * len(s)
    Mirror,C,R,maxLPS,maxLPSIndex = 0,0,0,0,0
    for i in range(1,len(s)-1):
        Mirror = 2*C - i 
        if i < R:
            P[i] =  min(R-i,P[Mirror])
        while s[i + (P[i] + 1)] == s[i - (P[i] + 1)]:
            P[i] += 1
        if i + P[i] > R:
            C = i
            R = i + P[i]
        # Keep track of the index at which the longest palindromic substring occurs
        if P[i] > maxLPS:
            maxLPS = P[i]
            maxLPSIndex = i
    #print P
    print "Input String : %s\
            \nLength of Longest Palindromic Substring : %d\
            \nThe Longest Palindromic Substring is : %s\n" \
            % (ip, P[maxLPSIndex], s[maxLPSIndex - P[maxLPSIndex]: maxLPSIndex + 1 + P[maxLPSIndex]].replace('*',''))

        
longestPalindromicSubstringManacher('aa')
longestPalindromicSubstringManacher('abcd')
longestPalindromicSubstringManacher('forgeeksskeegfor')

text1 = "babcbabcbaccba"
longestPalindromicSubstringManacher(text1)
  
text2 = "abaaba"
longestPalindromicSubstringManacher(text2)
  
text3 = "abababa"
longestPalindromicSubstringManacher(text3)
  
text4 = "abcbabcbabcba"
longestPalindromicSubstringManacher(text4)
  
text5 = "forgeeksskeegfor"
longestPalindromicSubstringManacher(text5)
  
text6 = "caba"
longestPalindromicSubstringManacher(text6)
  
text7 = "abacdfgdcaba"
longestPalindromicSubstringManacher(text7)
  
text8 = "abacdfgdcabba"
longestPalindromicSubstringManacher(text8)
  
text9 = "abacdedcaba"
longestPalindromicSubstringManacher(text9)


Input String : aa            
Length of Longest Palindromic Substring : 2            
The Longest Palindromic Substring is : aa

Input String : abcd            
Length of Longest Palindromic Substring : 1            
The Longest Palindromic Substring is : a

Input String : forgeeksskeegfor            
Length of Longest Palindromic Substring : 10            
The Longest Palindromic Substring is : geeksskeeg

Input String : babcbabcbaccba            
Length of Longest Palindromic Substring : 9            
The Longest Palindromic Substring is : abcbabcba

Input String : abaaba            
Length of Longest Palindromic Substring : 6            
The Longest Palindromic Substring is : abaaba

Input String : abababa            
Length of Longest Palindromic Substring : 7            
The Longest Palindromic Substring is : abababa

Input String : abcbabcbabcba            
Length of Longest Palindromic Substring : 13            
The Longest Palindromic Substring is : abcbabcbabcba

Input String : forgeeksskeegfor            
Length of Longest Palindromic Substring : 10            
The Longest Palindromic Substring is : geeksskeeg

Input String : caba            
Length of Longest Palindromic Substring : 3            
The Longest Palindromic Substring is : aba

Input String : abacdfgdcaba            
Length of Longest Palindromic Substring : 3            
The Longest Palindromic Substring is : aba

Input String : abacdfgdcabba            
Length of Longest Palindromic Substring : 4            
The Longest Palindromic Substring is : abba

Input String : abacdedcaba            
Length of Longest Palindromic Substring : 11            
The Longest Palindromic Substring is : abacdedcaba