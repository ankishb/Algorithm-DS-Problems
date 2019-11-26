class box{
public:
    int h, w, l, area;
    box(){}
    box(int h, int w, int l):
    h(h), w(w), l(l), area(h*w){}
};
bool operator<(const box &b1, const box &b2){
    return (b1.area < b2.area) ;
    // || (b1.area == b2.area && b1.l < b2.l);
}

int maxHeight(int hs[],int ws[],int ls[],int n){
    vector<box> boxes(n*3);
    for(int i=0; i<n; i++){
        boxes[i*3] = box(max(hs[i], ws[i]), min(hs[i], ws[i]), ls[i]);
        boxes[i*3+1] = box(max(ws[i], ls[i]), min(ws[i], ls[i]), hs[i]);
        boxes[i*3+2] = box(max(ls[i], hs[i]), min(ls[i], hs[i]), ws[i]);
    }
    sort(boxes.begin(), boxes.end());
    vector<int> lps(3*n);
    for(int i=0; i<3*n; i++){
        lps[i] = boxes[i].l;
    }
    
    int ans = 0;
    for(int i=1; i<3*n; i++){
        for(int j=0; j<i; j++){
            if(boxes[i].h > boxes[j].h && boxes[i].w > boxes[j].w){
                lps[i] = max(lps[i], lps[j] + boxes[i].l);
            }
        }
        ans = max(ans, lps[i]);
    }
    return ans;
}