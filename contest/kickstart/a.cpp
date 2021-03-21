#include<bits/stdc++.h>
using namespace std;
#define ll long long int

class elem{
    public:
    ll vertical;
    ll bottom;
    ll lefthorizontal;
    ll righthorizontal;
};

int main(){
    ll t;
    cin>>t;
    
    ll w = 1;
    while(t--){
        ll r,c;
        cin>>r>>c;
        // cout<<"r is : "<<r<<" col is : "<<c<<endl;
        ll matrix[r][c];
        for(ll i=0;i<r;i++){
            for(ll j=0;j<c;j++){
                ll value;
                cin>>value;
                matrix[i][j] = value;
            }
        }
        // cout<<"hello world"<<endl;
        
        elem matrixx[r][c];
        for(ll i=0;i<r;i++){
            for(ll j=0;j<c;j++){
                if(matrix[i][j] != 1){
                    matrixx[i][j].lefthorizontal = 0;
                    continue;
                }
                
                if(j == 0 && matrix[i][j] == 1){
                    matrixx[i][j].lefthorizontal = 1;
                    continue;
                }
                
                if(matrix[i][j] == 1){
                    matrixx[i][j].lefthorizontal = 1;
                    if(matrix[i][j - 1] == 1){
                        matrixx[i][j].lefthorizontal = matrixx[i][j - 1].lefthorizontal + 1;
                    }                    
                }
            }
            
            for(ll j = c - 1;j >= 0;j--){
                if(matrix[i][j] != 1){
                    matrixx[i][j].righthorizontal = 0;
                    continue;
                }
                
                if(j == c - 1 && matrix[i][j] == 1){
                    matrixx[i][j].righthorizontal = 1;
                    continue;
                }
                
                if(matrix[i][j] == 1){
                    matrixx[i][j].righthorizontal = 1;
                    if(matrix[i][j + 1] == 1){
                        matrixx[i][j].righthorizontal = matrixx[i][j +1].righthorizontal + 1;
                    }
                }
            }
        }
        
        for(ll i=0;i<c;i++){
            for(ll j=0;j<r;j++){
                if(matrix[j][i] != 1){
                    matrixx[j][i].vertical = 0;
                    continue;
                }
                
                if(j == 0 && matrix[j][i] == 1){
                    matrixx[j][i].vertical = 1;
                    continue;
                }
                
                if(matrix[j][i] == 1){
                    matrixx[j][i].vertical = 1;
                    if(matrix[j - 1][i] == 1){
                        matrixx[j][i].vertical = matrixx[j - 1][i].vertical + 1;
                    }
                }
            }
            
            for(ll j=r - 1;j>=0;j--){
                if(matrix[j][i] != 1){
                    matrixx[j][i].bottom = 0;
                    continue;
                }
                
                if(j == r-1 && matrix[j][i] == 1){
                    matrixx[j][i].bottom = 1;
                    continue;
                }
                
                if(matrix[j][i] == 1){
                    matrixx[j][i].bottom = 1;
                    if(matrix[j + 1][i] == 1){
                        matrixx[j][i].bottom = matrixx[j + 1][i].bottom + 1;
                    }
                }
            }
        }
        
        ll ans = 0;
        for(ll i=0;i<r;i++){
            for(ll j=0;j<c;j++){
                ll rightdis = matrixx[i][j].righthorizontal;
                ll top = matrixx[i][j].vertical;
                ll leftdis = matrixx[i][j].lefthorizontal;
                ll bottomdis = matrixx[i][j].bottom;

                ll mini = rightdis;
                for(ll m = 2;m <= mini;m++){
                    if(2*m <= top){
                        ans++;
                    }
                }

                
                mini = leftdis;
                for(ll m = 2;m<=mini;m++){
                    if(2*m <= top){
                        ans++;
                    }
                }
                
                
                
                mini = rightdis;
                for(ll m = 2;m<= mini;m++){
                    if(2*m <= bottomdis){
                        ans++;
                    }
                }
                
                
                mini = leftdis;
                for(ll m =2;m<=mini;m++){
                    if(2*m <= bottomdis){
                        ans++;
                    }
                }
                
                
                mini = top;
                for(ll m = 2;m<=mini;m++){
                    if(2*m <= rightdis){
                        ans++;
                    }
                }
                
                mini =top;
                for(ll m = 2;m<=mini;m++){
                    if(2*m <= leftdis){
                        ans++;
                    }
                }
                
                
                mini = bottomdis;
                for(ll m=2;m<=bottomdis;m++){
                    if(2*m <= rightdis){
                        ans++;
                    }
                }
                
                
                
                mini = bottomdis;
                for(ll m=2;m<=bottomdis;m++){
                    if(2*m <= leftdis)
                    {
                        ans++;
                    }
                }
                
            }
        }
        
        cout<<"Case #"<<w<<": "<<ans<<endl;
        w++;
    }
}