///////////////////// Start of hashing //////////////////////////
const int N = 1e6 + 6;

int add(int a, int b, int mod){
    int res = (a + b) % mod;
    if(res < 0){
        res+=mod;
    }
    return res;
}
int mult(int a, int b, int mod){
    int res = (a * 1LL * b) % mod;
    if(res < 0){
        res+=mod;
    }
    return res;
}

int power(int a, int b, int mod){
    int res=1;
    while(b){
        if((b % 2) == 1){
            res = mult(res, a, mod);
        }
        a = mult(a, a, mod);
        b/=2;
    }
    return res
}


struct hash_st {
    string s;
    vector<ll>pw, h, inv, hrev;
    ll mod, base;
    hash_st(string s, int mod, int base){
        this->mod = mod;
        this->s = s;
        this->base = base;
        precalc();
    }

    void precalc(){
        pw.pb(1);
        for(int i = 1; i < s.size(); i++){
            int cur = mult(pw[i-1], base, mod);
            pw.pb(cur);
        }
        int pw_inv = power(base, mod - 2, mod);
        inv.pb(1);
        for(int i = 1; i < s.size(); i++){
            int cur = mult(inv[i-1], pw_inv, mod);
            inv.pb(cur);
        }
    }
    void build(){

        for(int i = 0; i < s.size(); i++){
            if(i==0){
                int cur = add(0, mult(pw[i], s[i] - 'a' + 1, mod), mod);
                h.pb(cur);
            }
            else{
                int cur = add(h[i-1], mult(pw[i], s[i] - 'a' + 1, mod), mod);
                h.pb(cur);
            }
        }
    }

    void build_reverse(){
        string srev = s;
        reverse(srev.begin(), srev.end());

        for(int i = 0; i < srev.size(); i++){
            if(i==0){
                int cur = add(0, mult(pw[i], srev[i] - 'a' + 1, mod), mod);
                hrev.pb(cur);
            }
            else{
                int cur = add(hrev[i-1], mult(pw[i], srev[i] - 'a' + 1, mod), mod);
                hrev.pb(cur);
            }
        }
    }

    int get_hash(int l, int r){
        if(l<=r){
            int res;
            if(l == 0){
                res = add(h[r], 0, mod);
            }
            else{
                res = add(h[r], -h[l-1], mod);
            }
            return res = mult(res, inv[x], mod);
        }
        else {
            l = s.size()-l+1;
            r = s.size()-r+1;

            int res;
            if(l == 0){
                res = add(hrev[r], 0, mod);
            }
            else{
                res = add(hrev[r], -hrev[l-1], mod);
            }
                return res = mult(res, inv[x], mod);
        }
    }
};

///////////////////// End of Hashing //////////////////////////
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    string s;
    cin >> s;

    hash_st h(s, 1000000007, 31);
    hash_st h2(s, 1000000009, 29);

    h.build();
    h2.build();

}
