#include<bits/stdc++.h>
using namespace std;

void mazepath(int sr,int sc,int er,int ec,string ans){
    if(sr==er && sc==ec){
        cout<<ans<<endl;
        return;
    }

    for(int jump=1;jump+sc<=ec;jump++){
        mazepath(sr,sc+jump,er,ec,ans+"H"+to_string(jump));
    }

    for(int jump=1;jump+sr<=er&&jump+sc<=ec;jump++){
        mazepath(sr+jump,sc+jump,er,ec,ans+"D"+to_string(jump));
    }

    for(int jump=1;jump+sr<=er;jump++){
        mazepath(sr+jump,sc,er,ec,ans+"V"+to_string(jump));
    }
    
}

int main(){
    mazepath(0,0,3,4,"");
    return 0;
}