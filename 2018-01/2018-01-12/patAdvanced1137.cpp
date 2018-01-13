#include<iostream>  
#include<algorithm>  
#include<string>  
#include<map>  
#include<vector>  
using namespace std;  
struct node{  
    string name;  
    int g1,g2,gb,g;  
    node(string nm="",int p=-1,int m=-1,int f=-1,int a=0):name(nm),gb(p),g1(m),g2(f),g(a){}  
    //重载，成绩相同按学号排序   
    bool operator < (const node &a)const{  
        return a.g == g ? a.name > name : a.g < g;  
    }  
};  
  
int main(){  
    int p,m,n;  
    string str;  
//  freopen("input.txt","r",stdin);  
    map<string,node>mp;  
    vector<node>v,result;  
    int score;  
    scanf("%d%d%d",&p,&m,&n);  
    for(int i = 0;i < p;i++){  
        cin>>str>>score;  
        if(score >= 200)  
            mp[str]=node(str,score,-1,-1,0);  
    }  
      
    for(int i = 0;i <  m;i++){  
        cin>>str>>score;  
        if(mp.count(str)){  
            mp[str].g1 = score;  
        }else{  
            continue;  
        }  
    }  
      
    for(int i = 0;i <  n;i++){  
        cin>>str>>score;  
        if(mp.count(str)){  
            mp[str].g2 = score;  
            if(mp[str].g1>mp[str].g2){  
                mp[str].g=(mp[str].g1*0.4+mp[str].g2*0.6+0.5);  
            }else{  
                mp[str].g = score;  
            }  
            if(mp[str].g >= 60){  
                v.push_back(mp[str]);  
            }  
        }else{  
            continue;  
        }  
    }  
    sort(v.begin(),v.end());  
    for(int i = 0;i < v.size();i++){  
        cout<<v[i].name;  
        printf(" %d %d %d %d\n",v[i].gb,v[i].g1,v[i].g2,v[i].g);  
    }  
    return 0;  
} 