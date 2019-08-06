#include <bits/stdc++.h>
using namespace std;
#define ipair pair<long, int>
vector<string> split_string(string);

bool customSort(const ipair &p1, const ipair &p2){
    return (p1.first > p2.first);
}

// Complete the minimumLoss function below.
int minimumLoss(vector<ipair> price) {
    int n = price.size();
    long int ans = INT_MAX, cur;
    sort(price.begin(), price.end(), customSort);
    for(int i=1; i<n; i++){
        if(price[i].second > price[i-1].second){
            cur = price[i-1].first - price[i].first;
            ans = min(ans, cur);
        }
    }
    return (int) ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n; cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string price_temp_temp;
    getline(cin, price_temp_temp);

    vector<string> price_temp = split_string(price_temp_temp);

    vector<pair<long,int>> price(n);

    for (int i = 0; i < n; i++) {
        long price_item = stol(price_temp[i]);
        price[i] = make_pair(price_item, i);
    }

    int result = minimumLoss(price);
    fout << result << "\n";
    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
