    int checkRecord(int n) {
        int * a = new int[n];
        int * p = new int[n];
        int * l = new int[n];
        int MOD = 1000000007;
        
        p[0] = 1;
        l[0] = 1;
        l[1] = 3;
        a[0] = 1;
        a[1] = 2;
        a[2] = 4;
        
        // p[1] = 3;
        

        if(n == 1){
            return 3;
        }

        if(n == 2){
            return 8;
        }

        for(int i=1;i<n;i++)
        {
            a[i - 1] %= MOD;
            p[i - 1] %= MOD;
            l[i - 1] %= MOD;

            p[i] = ((a[i - 1]  + p[i - 1])%MOD + l[i - 1])%MOD;
            
            if(i > 1){
                l[i] = (((p[i - 1] + a[i - 1]) %MOD + p[i - 2])%MOD + a[i - 2])%MOD;
            }
            if(i > 2){
                a[i] = ((a[i - 1] + a[i - 2])%MOD + a[i - 3])%MOD;
            }
        }
        return ((a[n - 1]%MOD + p[n - 1]%MOD)%MOD + l[n - 1]%MOD)%MOD;
    }