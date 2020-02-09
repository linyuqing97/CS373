#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<list>


using namespace std;
unordered_map<int,string>stateRecord;
vector<int>stageRecord;
unordered_map<int,list<pair<char,char> > > transitionRecord;
unordered_set<int>isVisited;

bool compareId(const pair<int,int>&i,const pair<int,int>j){
    return i .second<j.second;
}
void stateRecorder(string behavior, int id){
    stateRecord[id]=behavior;
}
void transitionRecorder(int id,int approch, int result){
    pair<int,int>p(approch,result);
    transitionRecord[id].push_back(p);
    transitionRecord[id].sort(compareId);
}



void NFSSimulator(string s,int startState){
  
    isVisited.insert(startState); // insert the startstate;
    std::list<pair<int,int> >::iterator it;
    stageRecord.push_back(startState);
    list<pair<char,char> > temp;

    for (int i = 0; i < s.size(); i++){
        int stageRecodsize = stageRecord.size();
        for(int j = 0;j<stageRecodsize;j++){
            temp = transitionRecord[stageRecord[j]];
            bool isSelfRepeating = false;
            for(std::list<pair<char,char> >::iterator it = temp.begin(); it != temp.end(); ++it){
                char c = s[i];
                if(it->first ==c && isVisited.find(it->second)==isVisited.end()){
                    isVisited.insert(it->second);
                    stageRecord.push_back(it->second);
                }
                if(it->first == c && stageRecord[j] == it->second){
                    isSelfRepeating = true;
                }
             
            }
            if(!isSelfRepeating){
                isVisited.erase(j);
                stageRecord[j]=0;
            }
           

        }
    }
    vector<int>acceptResult;
    for(int i = 0;i<stageRecord.size();i++){
        if(stateRecord[stageRecord[i]] == "accept"){
            acceptResult.push_back(stageRecord[i]);
        }
    }

    if(acceptResult.size() == 0){
        cout<<"reject ";
        for(int i = 0;i<stageRecord.size();i++){
             if(stageRecord[i]!=0)
            cout<<stageRecord[i]<<" ";
        }
        cout<<"\n";
    }
    else{
        cout<<"accept ";
        for(int i = 0;i<acceptResult.size();i++){
            cout<<acceptResult[i]<<" ";
        }
        cout<<"\n";
    }
    
}
int main(int argc, char*argv[]){
    //Check inputs
    if(argc != 3){
        cerr<<"Input error"<<endl;
        exit(1);
    }
    string filename = argv[1];
    string input = argv[2];
    ifstream infile(filename,std::ifstream::in);
    string line;
    string behavior;
    int id;
    char approch;
    int result;
    string name;
    int startState;
   
    while(getline(infile,line)){
        
        stringstream ss(line);
        ss>>name;
        if(name =="state"){
            ss>>id>>behavior;
            stateRecorder(behavior,id);
            if(behavior=="start")
            startState=id;
        }
        else if (name == "transition"){
            ss>>id>>approch>>result;
            transitionRecorder(id,approch,result);
        }
    }
    /*
    Through process：
        after we have everything tracerable, we need to have a set to prevent duplicate after that, we need to main tain a queue to proces
        the job with termination point of both input finished and queue is empty
    */
       NFSSimulator(input,startState);



}
