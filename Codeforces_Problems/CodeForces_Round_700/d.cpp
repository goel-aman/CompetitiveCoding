// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long int
// int main(){
//     ll t;
//     cin>>t;
//     while(t--){
//         ll n;
//         cin>>n;
//     }
// }


#include <bits/stdc++.h>
using namespace std;
struct def{
    int a;
    int h;
};
bool com(def a1,def a2){
    if(a1.a < a2.a){
        return true;
    }
    return false;
}
int main() {
    int t;
    cin>>t;
    while(t--){
        int a,b,n;
        cin>>a>>b>>n;
        int ma[n],mb[n];
        for(int i=0;i<n;i++){
            cin>>ma[i];
        }
        for(int i=0;i<n;i++){
            cin>>mb[i];
        }
        def comb[n];
        for(int i=0;i<n;i++){
            comb[i].a=ma[i];
            comb[i].h=mb[i];
        }
        sort(comb,comb+n,com);
        int f=0;
        for(int i=0;i<n;i++){
            int z=comb[i].h/a;
            if(comb[i].h%a!=0){
                z++;
            }
           // cout<<z<<endl;
            if(i==n-1){
              
                if((b-(z-1)*comb[i].a)>0){
                    continue;
                }
                else{
                    f=1;
                    break;
                }
            }
            if((b-z*comb[i].a)>0){
                b-=(z*comb[i].a);
                continue;
            }
            
            else{
                f=1;
                break;
            }
        }
        if(f==1){
            cout<<"NO"<<endl;
        }
        else{
            cout<<"YES"<<endl;
        }

    }
   // cout<<"Hello World!";
}