set<int> pq;
set<int>::iterator it;
stack<int> s;

MinStack::MinStack() {
    pq.clear();
    while(!s.empty()){
        s.pop();
    }
}

void MinStack::push(int x) {
    s.push(x);
    pq.insert(x);
}

void MinStack::pop() {
    if(!s.empty()){
        it = pq.find(s.top());
        pq.erase(it);
        s.pop(); 
    }
}

int MinStack::top() {
    if(!s.empty()){
        return s.top();
    }
    else{
        return -1;
    }
}

int MinStack::getMin() {
    if(!s.empty()){
        it = pq.begin();
        return *it;
    }
    else{
        return -1;
    }
}







// elegant solution using 2 stacks
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