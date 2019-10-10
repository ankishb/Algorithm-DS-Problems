typedef long long int ll;

string Solution::fractionToDecimal(int A, int B) {
    if(B == 0) return "";
    if(A == 0) return "0";
    ll num = A, den = B;
    bool neg = (num < 0) ^  (den < 0);
    num = abs(num);
    den = abs(den);
    
    ll dividend = num/den;
    ll rem = num%den, rem_s = num%den, divi;
    int count = 0, found = 0;
    string decimal = "", ans = to_string(dividend);
    unordered_map<ll,int> map;
    while(rem > 0){
        if(map.find(rem) != map.end()){
            found = 1;
            break;
        }
        map[rem] = count;
        count++;
        rem *= 10;
        divi = rem/den;
        rem = rem%den;
        decimal += to_string(divi);
    }
    if(found != 0){
        int idx = map[rem];
        decimal = decimal.substr(0,idx)+"("+decimal.substr(idx)+")";
    }
    /* here is tricky part. There can be 3 cases:
    1. decimal is of length zero, which means, 4/2 = 2
    2. decimal has length 1, 1/5 = 0.2
    3. decimal has length >1, which is handled by above block
    */
    if(decimal.length() == 1 && decimal[0] != '0'){
        ans = ans+"." +decimal;
    }
    if(decimal.length() > 1) ans = ans+"."+decimal;
    if(neg) ans = "-"+ans;
    return ans;
}




// editorial nice solution

string Solution::fractionToDecimal(int numerator, int denominator) {
    int64_t n = numerator, d = denominator;
    // zero numerator
    if (n == 0) return "0";
    string res;
    // determine the sign
    if (n < 0 ^ d < 0) res += '-';

    // remove sign of operands
    n = abs(n), d = abs(d);

    // append integral part
    res += to_string((n / d));

    // in case no fractional part
    if (n % d == 0) return res;
    res += '.';
    unordered_map<int, int> map;

    // simulate the division process
    for (int64_t r = n % d; r; r %= d) {
        // meet a known remainder
        // so we reach the end of the repeating part
        if (map.find(r) != map.end()) {
            // insert '(' at the start position where we first saw the remainder
            res.insert(map[r], 1, '(');
            res += ')';
            break;
        }

        // the remainder is first seen
        // remember the current position for it
        map[r] = res.size();
        r *= 10;
        // append the quotient digit
        res.push_back((char)('0' + (r / d)));
    }

    return res;    
}