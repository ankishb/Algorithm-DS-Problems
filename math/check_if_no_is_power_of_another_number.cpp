
int check_power(int x, int y){
    if(x == 1) return (y == 1);
	if(y == 1) return 1;

    ll xx = x;
    while(xx < y){
        xx *= x;
    }
    return (xx == y);
}