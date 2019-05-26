
const int BLOCKSZ = 300;

struct query {

    int l, r;
    int id;

    bool operator < (const query &A){
        if(l/BLOCKSZ == A.l/BLOCKSZ) return r < A.r;
        return l/BLOCKSZ < A.l/BLOCKSZ;
    }
};

    vector<query> q(Q);
    vector<ll> resp(Q);

    for(int i=0; i<Q; i++){
        cin >> q[i].l >> q[i].r;
        q[i].l--;
        q[i].id = i;
    }
    sort(q.begin(), q.end());

    for(int i=q[0].l; i<=q[0].r; i++){
        add(i);
    }

    int j=q[0].l, k=q[0].r;
    for(auto qu: q){
        
        while(j>qu.l){
            j--;
            add(j);
        }

        while(k<qu.r){
            k++;
            add(k);
        }

        while(j<qu.l){
            remove(j);
            j++;
        }

        while(k>qu.r){
            remove(k);
            k--;
        }

        resp[qu.id] = ans;
    }