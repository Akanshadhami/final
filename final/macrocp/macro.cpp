#include<bits/stdc++.h>
using namespace std;

int main(){
    fstream inp , mnt , mdt , ala;
    inp.open("pass.txt" , ios::in);    
    mnt.open("mnt.txt" , ios::out);    
    mdt.open("mdt.txt" , ios::out);    
    ala.open("ala.txt" , ios::out);
    mnt << "INDEX  " << "  NAME  " << "  ALA  " << endl;

    string line;
    int cnt=0 , flag=0 , ind=0 , num=1;
    map<string , int> mp , mp1;
    while(getline(inp , line)){
        if(line == "MACRO"){
            flag = 1;
            num = 1;
            continue;
        }
        if(line == "MEND"){
            flag = 0;
            mdt << line << endl;
            continue;
        }
        cnt++;
        if(flag == 1){
            mdt << line << endl;
            string temp = "";
            for(auto ch:line){
                if(ch == ' '){
                    mnt << ind << "        " << temp << "     " << cnt << endl;
                    ind++;
                    mp1[temp] = 1;
                    break;
                }temp += ch;
            }
            
            temp = "";
            for(auto ch:line){
                if(ch == '='){
                    mp[temp] = num;
                    break;
                }
                else if(ch == ' '){
                    temp = "";
                    continue;
                }
                else if(ch == ','){
                    mp[temp] = num;
                    num++;
                    temp = "";
                }else temp += ch;
                 
            }
            flag = 2;
            continue;
        }

        if(flag == 2){
            string temp ="";
            for(auto ch:line){
                if(ch == ' '){
                    mdt << temp << " ";
                    temp = "";
                } 
                else if(ch == ','){
                    mdt << "#" << mp[temp] << ", ";
                    temp = "";
                }else temp += ch;
            }
            mdt << "#" << mp[temp] << endl;
        }

        if(flag == 0){
            string temp ="";
            int q = 0 , w = 1;
            for(auto ch:line){
                
                if(ch == ' '){
                    if(mp1[temp] == 1){
                        ala << line << endl;
                        q = 1; 
                        temp = "";
                    }
                }
                else if(ch == ',' and q == 1){
                    ala << w-1 << "   " << temp << "   #" << w << endl;
                    w++;
                    temp = "";  
                }
                else if(ch == '=' and q == 1){
                    break;
                }
                else temp += ch;
            }
            if(q == 1) ala << w-1 << "   " << temp << "   #" << w << endl;
        }
    }
}