#include<iostream>
#include<vector>

using namespace std;


// print pattern 1-n
void printPattern(int n){
    if(n<1) return;
    if(n==1) {
        cout<<1<<endl;
        return;
    }

    printPattern(n-1);
    cout<<n<<endl;

}

// print pattern n-1
void printPattern1(int n){
    if(n<1) return;
    if(n==1) {
        cout<<1<<endl;
        return;
    }
    cout<<n<<endl;
    printPattern1(n-1);
    

}

int printZigZag(int n,int level){
    if(n<=1) return 1;
    int count=1;
    count+=printZigZag(n-1,level+1);
    count++;
    count+=printZigZag(n-2,level+1);
    return count;
     
}

int powerFn(int a,int b){
    if(b==1) return a;
    else return a*powerFn(a,b-1);
}

int powerBtr(int a,int b){
    if(b==1) return a;
    return b%2==0?powerBtr(a,b/2)*powerBtr(a,b/2):powerBtr(a,b/2)*powerBtr(a,b/2)*a;
}

vector<string> subSequences(string str){
    if(str.length()==0){
        vector<string> ans;
        ans.push_back(" ");
        return ans;
    }

    string c=str.substr(0,1);
    vector<string> ans=subSequences(str.substr(1));
    int n=ans.size();
    for( int i=0;i<n;i++){
        ans.push_back(c+ans[i]);
    }
    return ans;
}

vector<string> patternZeroOne(int n){
    if(n==1){
        vector<string> v;
        v.push_back("0");
        v.push_back("1");
        return v;
    }
    vector<string> ans=patternZeroOne(n-1);
    int size=ans.size();
    for(int i=0;i<size;i++){
        ans.push_back("1"+ans[i]);
        ans[i]="0"+ans[i];
    }
    return ans;
    }

void subOneZero(string s,int len){
    if(len==0){
         cout<<s<<endl;
         return;
    }
    subOneZero(s+"0",len-1);
    subOneZero(s+"1",len-1);
}

int permuWithoutDuplicates(string str,string ans){
    if(str.length()==0) {
        cout<<ans<<endl;
        return 1;
    }
    int count=1;
    vector<bool> vis(26,false);
    for(int i=0;i<str.length();i++){
        char ch=str[i];
        if(!vis[ch-'a']){
            vis[ch-'a']=true;
            string nxt=str.substr(0,i)+str.substr(i+1);
            count+=permuWithoutDuplicates(nxt,ans+ch);
        }
    }
    return count;


}


int main(){
    //printPattern1(10);
    // cout<<"loop ran "<<printZigZag(5,0)<<" times";
    //cout<<powerBtr(5,10);

    
    // vector<string> v=patternZeroOne(3);
    // for(string s:v)
    // cout<<s<<endl;
    // subOneZero("",3);
    //cout<<permuWithoutDuplicates("aabc","");
    string s="aabc";
    cout<<s.substr(1);
    return 0;
}