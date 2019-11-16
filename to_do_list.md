
# geeksforgeeks
- [ ]  [Find Missing And Repeating](https://practice.geeksforgeeks.org/problems/find-missing-and-repeating/0)
- [ ] [pairs of prime no](https://practice.geeksforgeeks.org/problems/pairs-of-prime-number/0/?track=interview-mathematical&batchId=117)
- [x] [gcd of array](https://practice.geeksforgeeks.org/problems/gcd-of-array/0/?track=interview-mathematical&batchId=117)
- [ ] [pythagorean triplet]()
- [ ] [find kth largest element](https://practice.geeksforgeeks.org/problems/kth-largest-element-in-a-stream/0)
- [ ] [chocolate distribution]
- [x] [zig-zag fashion arrangement]
- [x] [count-total-set-bits](https://practice.geeksforgeeks.org/problems/count-total-set-bits/0)
- [ ] [Do it](https://practice.geeksforgeeks.org/problems/three-great-candidates/0/?ref=self)
- [ ] Stack/Queue/Priority-Queue
- [ ] Unordered stack vectors
- [ ] https://practice.geeksforgeeks.org/problems/largest-subarray-of-0s-and-1s/1/?ref=self
- [ ] [sort by abs diff](https://practice.geeksforgeeks.org/problems/sort-by-absolute-difference/0/?ref=self)
- [ ] [get min element in O(1)](https://practice.geeksforgeeks.org/problems/get-minimum-element-from-stack/1/?ref=self)
- [ ] [Knight Problem](https://practice.geeksforgeeks.org/problems/knight-walk/0)
```c++
/*returns min element from stack*/
int _stack :: getMin()
{
   if(s.empty()){
      cout<<"-1 ";
       return -1;
   }
   else{
      cout<<minEle<<" ";
       return minEle;
   }
}
/*returns poped element from stack*/
int _stack ::pop()
{
    if (s.empty()){
        cout<<"-1 ";
        return -1;
    }
   int top_ = s.top();
   s.pop();
   // update minEle
   vector <int> vect;
   
   if(!s.empty()){
       minEle = s.top();
   }
   else{
    s = 100;
   }
   
   int count = 0;
   while(!s.empty()){
       minEle = (minEle < s.top()) ? minEle : s.top();
       vect.push_back(s.top());
       count++;
       s.pop();
   }
   
   for(int i=count-1; i>=0; i++){
       s.push(vect[i]);
   }
   
  cout<<top_<<" ";
   return top_;
}
/*push element x into the stack*/
void _stack::push(int x)
{
   if(s.empty()){
       minEle = x;
   }
   else{
       minEle = (minEle < x) ? minEle : x;
   }
   s.push(x);
}
```


# geeksforgeeks (need to optimize code)
- [ ] [continuous_subarray_sum.cpp] (https://practice.geeksforgeeks.org/problems/subarray-with-given-sum/0)
- [ ] [leaders in array](https://practice.geeksforgeeks.org/problems/leaders-in-an-array/0)
- [ ] [spiral transversal](https://practice.geeksforgeeks.org/problems/spirally-traversing-a-matrix/0)
- [ ] [relative sorting](https://practice.geeksforgeeks.org/problems/relative-sorting/0)(https://www.includehelp.com/icp/relative-sorting.aspx)
- [ ] [sort_a_stack-segmentation fault](https://www.geeksforgeeks.org/stack-in-cpp-stl/) 
- [ ] [alternate +ve and -ve no in order]

Reference: 
1. https://www.geeksforgeeks.org/must-do-coding-questions-for-companies-like-amazon-microsoft-adobe/
2. https://www.geeksforgeeks.org/dynamic-programming/


# Hackerrank
- [ ] [Flipping the matrix](https://www.hackerrank.com/challenges/flipping-the-matrix/problem)
- [ ] [new-year-chaos](https://www.hackerrank.com/challenges/new-year-chaos/problem)
- [ ]
- [ ]
- [ ]
- [ ]
