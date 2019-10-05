// first approach, using stack and vector
vector<int> min_els;
stack<int> s;

MinStack::MinStack() {
    while(!s.empty()) s.pop();
    min_els.clear();
}

void MinStack::push(int x) {
    s.push(x);
    if(min_els.size() == 0 || x <= min_els.back()){
        min_els.push_back(x);
    } 
}


void MinStack::pop() {
    if(!s.empty()){
        if(s.top() == min_els.back()){
            min_els.pop_back();
        }
        s.pop();
    }
}

int MinStack::top() {
    return (s.empty()) ? -1 : s.top();
}

int MinStack::getMin() {
    return (s.empty()) ? -1 : min_els.back();
}




// using only one stack (with a beautiful math trick)
int min_el;
stack<int> s;

MinStack::MinStack() {
    min_el = 0;
    while(!s.empty()){
        s.pop();
    }
}

void MinStack::push(int x) {
    if(s.empty()){
        s.push(x);
        min_el = x;
    }
    else{
        if(x >= min_el){
            s.push(x);
        }
        else{
            s.push(2*x - min_el);
            min_el = x;
        }
    }
}

void MinStack::pop() {
    if(s.empty()){
        return ;
    }
    int top = s.top();
    if(top >= min_el){
        s.pop();
    }
    else{
        min_el = 2*min_el - top;
        s.pop();
    }
}

int MinStack::top() {
    if(s.empty()){
        return -1;
    }
    int top = s.top();
    if(top >= min_el){
        return top;
    }
    else{
        return min_el;
    }
}

int MinStack::getMin() {
    return (s.empty()) ? -1 : min_el;
}








// Naive approach using 2 vectors
vector<int> v,v1;

MinStack::MinStack() {
    v.clear();
    v1.clear();
}

void MinStack::push(int x) {
    v.push_back(x);
    if(v1.empty() || x<=v1.back()) v1.push_back(x);
}

void MinStack::pop() {
    if(!v.empty())
    {
        if(v.back()==v1.back()) v1.pop_back();
        v.pop_back();
    }
}

int MinStack::top() {
    if(!v.empty()) return v.back();
    else return -1;
}

int MinStack::getMin() {
    if(!v1.empty()) return v1.back();
    else return -1;
}