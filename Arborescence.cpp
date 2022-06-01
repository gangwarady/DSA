#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n , m, s;
        cin>>n>>m>>s;
        int n2=n;
        unordered_map<int,vector< pair<int,int>>> incoming;
        unordered_map<int,vector< pair<int,int>>> outgoing;
        map<int,int> s_outgoing;
        unordered_map<int,int> s_outgoing2;
        unordered_map<int,int> min_i;
        map<int,int> parent;
        unordered_map<int,vector<int>>child;
        map<int,int>track;
        unordered_map<int,int>degree;
        unordered_map<int,int>visited;
        set <int> final_nodes;
        set <int> source_child;
        set<int> total;
        for(int i=0;i<m;i++){
            int u , v, w;
            cin>>u>>v>>w;
            if(v!=s){
                incoming[v].push_back(make_pair(u,w));
                outgoing[u].push_back(make_pair(v,w));
                min_i[v]=INT_MAX;
                total.insert(v);
            }
            if(u==s){
                s_outgoing2[v]=w;
                outgoing[u].push_back(make_pair(v,w));
            }
        }
        queue<int> find_u;//find unreachable nodes and remove them
        set<int> reachable;
        set<int>remove;//unreachable nodes
        for(int i=1;i<=n;i++){
            if(i!=s){
                if(incoming.find(i)==incoming.end()){
                    remove.insert(i);
                    track[i]=-1;
                    parent[i]=-1;
                }
            }
        }
        unordered_map<int,int> vis;
        find_u.push(s);
        while(!find_u.empty()){
            if(!vis[find_u.front()]){
                vis[find_u.front()]=1;
            for(auto it :outgoing[find_u.front()]){
                find_u.push(it.first);
                reachable.insert(it.first);
            }
            }
            find_u.pop();
        }
        for(auto it: total){
            if(reachable.find(it)==reachable.end()){
                min_i.erase(it);
                incoming.erase(it);
                remove.insert(it);
                track[it]=-1;
                parent[it]=-1;
            }
        }
        for(auto it: incoming){
            for(auto it2: it.second){
                if(remove.find(it2.first)!=remove.end()){
                    auto pos = find(incoming[it.first].begin(),incoming[it.first].end(),make_pair(it2.first,it2.second));
                    incoming[it.first].erase(pos);
                }
            }
        }
        for(auto it : incoming){
            for(auto it2 : it.second){
                if(remove.find(it2.first)==remove.end()){
                    if(it2.second<min_i[it.first]){
                        min_i[it.first]=it2.second;
                    }
                }
            }
        }
        n=1;
        for(auto it: incoming){
            n++;
        }
        parent[s]=0;
        for(int i=1;i<=n;i++){
            if(i!=s){
                degree[i]=0;
                visited[i]=0;
            }
        }
        for(auto &it : incoming){
            for(auto &it2: it.second){
                it2.second = it2.second-min_i[it.first];
                if(it2.second==0){
                    final_nodes.insert(it.first);
                    parent[it.first]=it2.first;
                    child[it2.first].push_back(it.first);
                    degree[it2.first]++;
                }
                if(it2.second==0 && it2.first==s){
                    final_nodes.insert(it2.first);
                    source_child.insert(it.first);
                }
                if(it2.first==s){
                    if(s_outgoing.find(it2.second)==s_outgoing.end()){
                        s_outgoing[it2.second]=it.first;
                    }
                    else{
                        if(s_outgoing[it2.second]>it.first){
                            s_outgoing[it2.second]=it.first;
                        }
                    }
                }
            }
        }
        for(auto it : incoming){
            for(auto it2: it.second){
                for(auto it3 : source_child){
                    if(it3==it2.first){
                        if(s_outgoing2.find(it.first)==s_outgoing2.end()){
                            if(s_outgoing.find(it2.second)==s_outgoing.end()){
                                s_outgoing[it2.second]=it.first;
                            }
                            else{
                                if(s_outgoing[it2.second]>it.first){
                                    s_outgoing[it2.second]=it.first;
                                }
                            }
                            s_outgoing2[it.first]=it2.second+min_i[it.first];
                        }
                    }
                }
            }
        }
        int s_ize=final_nodes.size();
        if(s_ize==n-1){
            int min_node=0;
            queue<int> d1;
            int f=1;
            while(f){
                int count=0;
                for(auto &it : degree){
                    if(it.second==0 && visited[it.first]==0){
                        d1.push(it.first);
                        visited[it.first]++;
                        count++;
                    }
                }
                if(count==0){
                    f=0;
                }
                while(!d1.empty()){
                    degree[parent[d1.front()]]--;
                    d1.pop();
                }
            }
            set<int> super_nodes;
            for(auto it : degree){
                if(it.second>0){
                    super_nodes.insert(it.first);
                }
            }
            for (auto itr = s_outgoing.begin(); itr != s_outgoing.end(); ++itr) {
                if(super_nodes.find(itr->second)!=super_nodes.end()){
                    min_node=itr->second;
                    break;
                }
            }
            if(min_node==0){
                cout<<"-1";
            }
            else{
            int sum=0;
            min_i[min_node]=s_outgoing2[min_node];
            int r_parent=parent[min_node];
            auto del=find(child[r_parent].begin(),child[r_parent].end(),min_node);
            child[r_parent].erase(del);
            parent[min_node]=s;
            child[s].push_back(min_node);
            for(auto it: min_i){
                sum=sum+it.second;
            }
            cout<<sum;
            queue<int> q;
            q.push(s);
            track[s]=0;
            while(!q.empty()){
                for(auto it : child[q.front()]){
                    q.push(it);
                    track[it]=track[q.front()]+min_i[it];
                }
                q.pop();
            }
            for(auto it : track){
                cout<<" "<<it.second;
            }
            cout<<" #";
            for(auto it : parent){
                cout<<" "<<it.second;
            }
            }
        }
        else if(s_ize==n){
            queue <int> check;
            set <int> checked;
            check.push(s);
            while(!check.empty()){
                for(auto it : child[check.front()]){
                    check.push(it);
                }
                checked.insert(check.front());
                check.pop();
            }
            int ssize =checked.size();
            if(ssize==n){
                int sum=0;
                for(auto it: min_i){
                    sum=sum+it.second;
                }
                cout<<sum;
                queue<int> q;
                q.push(s);
                track[s]=0;
                while(!q.empty()){
                    for(auto it : child[q.front()]){
                        q.push(it);
                        track[it]=track[q.front()]+min_i[it];
                    }
                    q.pop();
                }
                for(auto it : track){
                    cout<<" "<<it.second;
                }
                cout<<" #";
                for(auto it : parent){
                    cout<<" "<<it.second;
                }
            
            }
            else{
                int min_node=0;
                queue<int> d1;
                int f=1;
                while(f){
                int count=0;
                for(auto &it : degree){
                    if(it.second==0 && visited[it.first]==0){
                        d1.push(it.first);
                        visited[it.first]++;
                        count++;
                    }
                }
                if(count==0){
                    f=0;
                }
                while(!d1.empty()){
                    degree[parent[d1.front()]]--;
                    d1.pop();
                }
            }
                set<int> super_nodes;
                for(auto it : degree){
                    if(it.second>0){
                        super_nodes.insert(it.first);
                    }
                }
                for (auto itr = s_outgoing.begin(); itr != s_outgoing.end(); ++itr) {
                    if(super_nodes.find(itr->second)!=super_nodes.end()){
                        min_node=itr->second;
                        break;
                    }
                }
                if(min_node==0){
                    cout<<"-1";
                }
                else{
                    int sum=0;
                    min_i[min_node]=s_outgoing2[min_node];
                    int r_parent=parent[min_node];
                    auto del=find(child[r_parent].begin(),child[r_parent].end(),min_node);
                    child[r_parent].erase(del);
                    parent[min_node]=s;
                    child[s].push_back(min_node);
                    for(auto it: min_i){
                        sum=sum+it.second;
                    }
                    cout<<sum;
                    queue<int> q;
                    q.push(s);
                    track[s]=0;
                    while(!q.empty()){
                        for(auto it : child[q.front()]){
                            q.push(it);
                            track[it]=track[q.front()]+min_i[it];
                        }
                        q.pop();
                    }
                    for(auto it : track){
                        cout<<" "<<it.second;
                    }
                    cout<<" #";
                    for(auto it : parent){
                        cout<<" "<<it.second;
                    }
                }
            }
        }
        else{
            cout<<"-1";
        }
        cout<<"\n";
    }
    return 0;
}
