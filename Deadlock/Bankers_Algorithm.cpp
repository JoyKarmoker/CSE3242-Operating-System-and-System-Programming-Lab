#include<bits/stdc++.h>

using namespace std;

void In_file(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
}

struct process{
    char p_id[20];
    int allocation[30];
    int max_need[30];
};

int32_t main(){
    In_file();
    //cout << "Hello" << endl;
    int n;
    // cout << "Enter Total Number of processes\n";
    cin >> n;
    //struct process pros[n];
    vector<process> pros;
    process temp_pros;
    int r=3;
    int available[r];
    // cout << "Please enter the number of instances of available resources\n";
    for(int i=0;i<r;i++)
        cin >> available[i];

    // cout << "Please enter P-id Allocation Max_need\n";
    for(int i=0;i<n;i++)
    {
        cin >> temp_pros.p_id;
        for(int j=0;j<r;j++) cin >> temp_pros.allocation[j];
        for(int j=0;j<r;j++) cin >> temp_pros.max_need[j];
        pros.push_back(temp_pros);
    }

    for(auto p: pros)
    {
        for(int j=0;j<r;j++)
            p.max_need[j]-=p.allocation[j];
    }

    bool finish[n]={false};
    vector<string> safe_seq;

    while(!pros.empty()){
        bool check=false;
        auto it = pros.begin();
        for(auto p:pros)
        {
            bool flag = true;
            for(int j=0; j<r; j++)
            {
                if(p.max_need[j] > available[j]) flag =false;
            }

            if(flag == true){
                check = true;
                safe_seq.push_back(p.p_id);
                pros.erase(it);
                for(int j=0;j<r;j++){
                        available[j]+=p.allocation[j];
                }
            }
            ++it;
        }

        /*for(int i=0;i<n;i++){
            bool flag = true;
            if(finish[i]==false){
                for(int j=0;j<r;j++){
                    if(pros[i].max_need[j]>available[j]) flag=false;
                }

                if(flag==true){
                    check=true;
                    safe_seq.push_back(pros[i].p_id);
                    finish[i]=true;
                    for(int j=0;j<r;j++){
                        available[j]+=pros[i].allocation[j];
                    }
                }
            }
        }*/
        cout << "Checking Process " << endl;
        if(!check) break;
    }

    if(safe_seq.size()<n) cout << "Unsafe\n";
    else{
        cout << "Safe sequence:\n";
        for(auto it:safe_seq) cout << it << " ";
    }
    cout << endl;
}
