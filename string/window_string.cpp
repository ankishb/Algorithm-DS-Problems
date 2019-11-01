// Your Input: Ankishbansal anka
// Expected output is kishbansa 

const int no_of_chars = 256; 
string Solution::minWindow(string str, string pat) 
{ 
    int len1 = str.length(); 
    int len2 = pat.length(); 
  
    // check if string's length is less than pattern's 
    // length. If yes then no such window can exist 
    if (len1 < len2) return ""; 
  
    int hash_pat[no_of_chars] = {0}; 
    int hash_str[no_of_chars] = {0}; 
  
    // store occurrence ofs characters of pattern 
    for (int i = 0; i < len2; i++) 
        hash_pat[pat[i]]++; 
  
    int start = 0, start_index = -1, min_len = INT_MAX; 
  
    // start traversing the string 
    int count = 0; // count of characters 
    for (int j = 0; j < len1 ; j++) { 
        // count occurrence of characters of string 
        hash_str[str[j]]++; 
  
        // If string's char matches with pattern's char 
        // then increment count 
        if (hash_pat[str[j]] != 0 && 
            hash_str[str[j]] <= hash_pat[str[j]] ) 
            count++; 
  
        // if all the characters are matched 
        if (count == len2) { 
            // Try to minimize the window i.e., check if 
            // any character is occurring more no. of times 
            // than its occurrence in pattern, if yes 
            // then remove it from starting and also remove 
            // the useless characters. 
            while ( hash_str[str[start]] > hash_pat[str[start]] 
                || hash_pat[str[start]] == 0) { 
  
                if (hash_str[str[start]] > hash_pat[str[start]]) 
                    hash_str[str[start]]--; 
                start++; 
            } 
  
            // update window size 
            int len_window = j - start + 1; 
            if (min_len > len_window) 
            { 
                min_len = len_window; 
                start_index = start; 
            } 
        } 
    } 
  
    // If no window found 
    if (start_index == -1) 
    { 
    // cout << "No such window exists"; 
    return ""; 
    } 
  
    // Return substring starting from start_index 
    // and length min_len 
    return str.substr(start_index, min_len); 
} 

// string Solution::minWindow(string s, string t){
//     unordered_map<char, int> tmap, smap;
//     for(auto ch : t) tmap[ch]++;
//     string ans = "";
//     int idx, count = 0, i = 0, j = 0;
//     int n = s.length(), m = t.length();
//     while(i < n && tmap.find(s[i]) == tmap.end()) i++;
//     idx = i;
//     j = i;
//     while(i < n && j < n){
//         // cout<<i<<" "<<j<<" "<<count<<endl;
//         if(tmap.find(s[j]) != tmap.end()){
//             if(smap[s[j]] < tmap[s[j]]) count++;
//             smap[s[j]]++;
//         }
//         if(count == m){
//             if(ans == "" || ans.length() > j-i+1) ans = s.substr(i, j-i+1);
//             smap[s[i]]--;
//             if(smap[s[i]] < tmap[s[i]]) count--;
//             i++;
//             while(i < j && tmap.find(s[i]) == tmap.end()) i++;
//             if(count == m && ans.length() > j-i+1) ans = s.substr(i, j-i+1);
//         }
        
//         j++;
//     }
//     int na = ans.length();
//     i = 0;
//     while(i < na){
//         if(tmap.find(ans[i]) == tmap.end()) i++;
//         else if(tmap[ans[i]] < smap[ans[i]]){
//             smap[ans[i]]--;
//             i++;
//         }
//         else break;
//     }
//     j = na-1;
//     while(j >= 0){
//         if(tmap.find(ans[j]) == tmap.end()) j--;
//         else if(tmap[ans[j]] < smap[ans[j]]){
//             smap[ans[j]]--;
//             j--;
//         }
//         else break;
//     }
    
//     return ans.substr(i, j-i+1);
// }
