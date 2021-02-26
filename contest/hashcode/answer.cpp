#include <bits/stdc++.h>
using namespace std;
#define ll long long int

vector<ll> getIntegerFromString(string str){
    vector<ll> v;
    string word = "";
    for (auto x : str){
        if (x == ' '){
            ll val = stoll(word);
            v.push_back(val);
            word = "";
        }
        else{
            word = word + x;
        }
    }
    v.push_back(stoll(word));
    return v;
}

vector<string> getStringsFromStrings(string str){
    vector<string> v;
    string word = "";
    for (auto x : str){
        if (x == ' '){
            string val = word;
            v.push_back(val);
            word = "";
        }
        else{
            word = word + x;
        }
    }
    v.push_back(word);
    return v;
}

class elem{
    public:
    int end;
    string name;
    string timeTaken;
};

class elem2{
    public:
    ll occur;
    string name;
};

bool compare(elem2 a, elem2 b){
    if(a.occur < b.occur){
        return true;
    }
    return false;
}

int main()
{
    ifstream newfile("input.txt");
    string line;
    vector<string> vv;
    if (newfile.is_open()){
        while (getline(newfile, line)){
            vv.push_back(line);
        }
        newfile.close();
    }
    else{
        cout << "Unable to open file";
    }
    unordered_map<ll,elem> um;
    unordered_map<string,ll> startingNode;
    unordered_map<string,ll> occurence;
    int vvSize = vv.size();
    ll i = 0;
    ll D,I,S,V,F;
    while(i < vvSize){
        if(i == 0){
            vector<ll> in = getIntegerFromString(vv[i]);
            D = in[0];
            I = in[1];
            S = in[2];
            V = in[3];
            F = in[4];
            i++;
            continue;
        }
        
        if(i == 1){
            for(ll m = i;m <= S;m++){
                vector<string> inn = getStringsFromStrings(vv[m]);
                ll b = stoll(inn[0]);
                ll e = stoll(inn[1]);
                string name = inn[2];
                ll l = stoll(inn[3]);
                um[b].end = e;
                um[b].name = name;
                um[b].timeTaken = l;
                startingNode[name] = e;  
            }
            i = S + 1;
            continue;
        }

        if(i == S + 1){
            for(ll m = i;m <= i + V - 1;m++){
                vector<string> inn = getStringsFromStrings(vv[m]);
                for(ll w = 1;w<inn.size();w++){
                    occurence[inn[w]]++;
                }
            }
            i = vvSize;
        }
    }
    // generating output
    ofstream myfile;
    myfile.open("output.txt");
    // myfile << "Writing this to a file .\n";
    // myfile.close();
    unordered_map<ll,set<string>> finalans;
    for(auto x : occurence){
        finalans[startingNode[x.first]].insert(x.first);
    }
    myfile << finalans.size();
    myfile << "\n";
    
    for(auto x: finalans){
        myfile << x.first;
        myfile << "\n";
        myfile << x.second.size();
        myfile << "\n";
        vector<elem2> out;
        for(auto y : x.second){
            out.push_back({occurence[y],y});  
            // myfile << y << " "<< 1 << "\n";
        }
        sort(out.begin(),out.end(),compare);
        ll counter = 1;
        ll vall = out.size();
        for(ll pq = out.size() - 1;pq >= 0;pq--){
            if(counter <= (vall/2) + (vall /3) + (vall/4)){
                myfile << out[pq].name<< " " << 3<< "\n";
            }
            else{
                myfile << out[pq].name << " "<<1<< "\n";
            }
            counter++;
        }
    }
    return 0;
}