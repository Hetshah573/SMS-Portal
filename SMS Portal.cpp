#include <bits/stdc++.h>
#include <ctime>

using namespace std;

/*
    -----------------------------------------------------------------SMS PORTAL USING GRAPH THEORY--------------------------------------------------------------------
   -------------------------------------------------------Created by Aagam Shah(22BCE320) and Het Shah(22bce322)------------------------------------------------------
*/

//to give unique indices to unique name
int ct=0;

//2-D array to store pair of {message_details,date}
vector<vector<pair<string,string>> > v(1000,vector<pair<string,string>>(1000,{"0","0"}));

//pair of {person {email-id,user name},person's unique number}
map<pair<string,string>,int> mp;

//pair of {person's unique number,person {email-id,user name}}
map<int,pair<string,string>> mr;

//Taking input and assininig particular name it's corresponding unique number
void input() {
    cout<<endl;

    string from,to,message_details,date,from_email,to_email;
    cin.ignore();

    cout<<"Enter the sender name : ";
    getline(cin,from);
    cout<<"Enter the receiver name : ";
    getline(cin,to);
    cout<<"Enter the sender email id : ";
    getline(cin,from_email);
    cout<<"Enter the receiver email id : ";
    getline(cin,to_email);
    cout<<"Enter the message to be sent : ";
    getline(cin,message_details);

    time_t now = time(0);
   
    char* dt = ctime(&now);
    date=dt;
    cout << "The local date and time is: " << date << endl;
    cout<<endl;

    int from_indices,to_indices;

    if(mp.find({from_email,from})!=mp.end()){
        from_indices=mp[{from_email,from}];
    }
    else {
        mp[{from_email,from}]=ct;
        mr[ct]={from_email,from};
        from_indices=ct;
        ct++;
    }

    if(mp.find({to_email,to})!=mp.end()){
        to_indices=mp[{to_email,to}];
    }
    else {
        mp[{to_email,to}]=ct;
        mr[ct]={to_email,to};
        to_indices=ct;
        ct++;
    }

    v[from_indices][to_indices]={message_details,date};
    
}

//printing user wise
void print_user_wise()
{
    cout<<endl;
    string username,email;
    cout<<"Enter the username to search : ";
    cin.ignore();
    getline(cin,username);
    cout<<"Enter the unique email-id to search : ";
    getline(cin,email);
    cout<<endl;

    int index;

    if(mp.find({email,username})!=mp.end()) {
        index=mp[{email,username}];

        //messages send by user
        cout<<"Messages sent by the user : "<<endl;
        cout<<endl;
        for(int i=0;i<1000;i++)
        {
            if(v[index][i].first!="0") {
                cout<<"TO : "<<endl<<"Email-id: "<<mr[i].first<<endl<<"Username: "<<mr[i].second<<endl;
                cout<<"MESSAGE : "<<v[index][i].first<<endl;
                cout<<"Date : "<<v[index][i].second<<endl;
                cout<<endl;
            }
        }

        cout<<endl;
        //messages received by user
        cout<<"Messages received by the user : "<<endl;
        cout<<endl;
        for(int i=0;i<1000;i++)
        {
            if(v[i][index].first!="0") {
                cout<<"FROM : "<<endl<<"Email-id: "<<mr[i].first<<endl<<"Username: "<<mr[i].second<<endl;
                cout<<"MESSAGE : "<<v[i][index].first<<endl;
                cout<<"Date : "<<v[i][index].second<<endl;
                cout<<endl;
            }
        }
        cout<<endl;
    }
    else {
        cout<<"User name enter not found"<<endl;
    }
}

//printing date wise
void print_date_wise()
{
    cout<<endl;

    string datewise;
    cin.ignore();
    cout<<"Enter the date : ";
    getline(cin,datewise);
    cout<<endl;

    for(int i=0;i<1000;i++) {
        for(int j=0;j<1000;j++) {
            if(v[i][j].second==datewise) {
                cout<<"FROM : "<<endl<<"Email-id: "<<mr[i].first<<endl<<"Username: "<<mr[i].second<<endl;
                cout<<"TO : "<<endl<<"Email-id: "<<mr[j].first<<endl<<"Username: "<<mr[j].second<<endl;
                cout<<"MESSAGE : "<<v[i][j].first<<endl;
                cout<<"Date : "<<v[i][j].second<<endl;
                cout<<endl;
            }
        }
    }
    cout<<endl;
}

//printing date and user wise
void print_date_and_user_wise()
{
    cout<<endl;

    string datewise,email;
    cout<<"Enter the date : ";
    cin.ignore();
    getline(cin,datewise);
    cout<<endl;
    string username;
    cout<<"Enter the username to search : ";
    getline(cin,username);
    cout<<endl;
    cout<<"Enter the unique email id to search : ";
    getline(cin,email);
    cout<<endl;

    int index;

    if(mp.find({email,username})!=mp.end()) {
        index=mp[{email,username}];

        //messages send by user
        cout<<"Messages sent by the user : "<<endl;
        cout<<endl;
        for(int i=0;i<1000;i++)
        {
            if(v[index][i].first!="0"&&v[index][i].second==datewise) {
                cout<<"TO : "<<endl<<"Email-id: "<<mr[i].first<<endl<<"Username: "<<mr[i].second<<endl;
                cout<<"MESSAGE : "<<v[index][i].first<<endl;
                cout<<"Date : "<<v[index][i].second<<endl;
                cout<<endl;
            }
        }

        cout<<endl;
        //messages received by user
        cout<<"Messages received by the user : "<<endl;
        cout<<endl;
        for(int i=0;i<1000;i++)
        {
            if(v[i][index].first!="0"&&v[i][index].second==datewise) {
                cout<<"FROM : "<<endl<<"Email-id: "<<mr[i].first<<endl<<"Username: "<<mr[i].second<<endl;
                cout<<"MESSAGE : "<<v[i][index].first<<endl;
                cout<<"Date : "<<v[i][index].second<<endl;
                cout<<endl;
            }
        }
        cout<<endl;
    }
    else {
        cout<<"User name enter not found"<<endl;
    }
}

//printing to whom user have sent the message
void print_from_wise()
{
    cout<<endl;

    string email;
    string username;
    cin.ignore();
    cout<<"Enter the username to search : ";
    getline(cin,username);
    cout<<endl;
    cout<<"Enter the unique email id to search : ";
    getline(cin,email);
    cout<<endl;

    int index;

    if(mp.find({email,username})!=mp.end()) {
        index=mp[{email,username}];

        //messages send by user
        cout<<"Messages sent by the user : "<<endl;
        cout<<endl;
        for(int i=0;i<1000;i++)
        {
            if(v[index][i].first!="0") {
                cout<<"TO : "<<endl<<"Email-id: "<<mr[i].first<<endl<<"Username: "<<mr[i].second<<endl;
                cout<<"MESSAGE : "<<v[index][i].first<<endl;
                cout<<"Date : "<<v[index][i].second<<endl;
                cout<<endl;
            }
        }
    }
    else {
        cout<<"User name enter not found";
    }
}

//printing the all messages recieved by thr user
void print_to_wise()
{
    cout<<endl;

    string username,email;
    cout<<"Enter the username to search : ";
    cin.ignore();
    getline(cin,username);
    cout<<"Enter the unique email id to search : ";
    getline(cin,email);

    cout<<endl;

    int index;

    if(mp.find({email,username})!=mp.end()) {
        index=mp[{email,username}];
        //messages received by user
        cout<<"Messages received by the user : "<<endl;
        cout<<endl;
        for(int i=0;i<1000;i++)
        {
            if(v[i][index].first!="0") {
                cout<<"FROM : "<<endl<<"Email-id: "<<mr[i].first<<endl<<"Username: "<<mr[i].second<<endl;
                cout<<"MESSAGE : "<<v[i][index].first<<endl;
                cout<<"Date : "<<v[i][index].second<<endl;
                cout<<endl;
            }
        }
        cout<<endl;
    }
    else {
        cout<<"User name enter not found";
    }
}

//Printing all messages that contains particular substring
void search_string()
{
    cout<<endl;

    string s;
    cout<<"Enter the string to be found : ";
    cin.ignore();
    getline(cin,s);

    cout<<endl;

    for(int i=0;i<1000;i++){
        for(int j=0;j<1000;j++) {
            if(v[i][j].first.find(s)!=string::npos){
                cout<<"FROM : "<<endl<<"Email-id: "<<mr[i].first<<endl<<"Username: "<<mr[i].second<<endl;
                cout<<"TO : "<<endl<<"Email-id: "<<mr[i].first<<endl<<"Username: "<<mr[i].second<<endl;
                cout<<"Message : "<<v[i][j].first<<endl;
                cout<<"Date : "<<v[i][j].second<<endl;
                cout<<endl;
            }
        }
    }
    cout<<endl;
}

//delete the all sms sent by the particular user and storing it in particular text file
void delete_sms() {
    cout<<endl;

    string user_name,email;
    cout<<"Enter the user-name  whose sent messages should be deleted : "<<endl;
    cin.ignore();
    getline(cin,user_name);
    cout<<endl;
    cout<<"Enter the unique email id of the above username: "<<endl;
    getline(cin,email);
    cout<<endl;
    
    if(mp.find({email,user_name})==mp.end()){
        cout<<"User name does not exist"<<endl;
    }
    else {
        // FILE*fptr;
        int idx=mp[{email,user_name}];
        ofstream fptr;
        fptr.open("delete_sms.txt");
        string s="";
         s+="FROM : ";
         s+="\n";
         s+="Username : "+user_name+"\n"+"Email-id : "+email+"\n";
        for(int i=0;i<1000;i++){
            if(v[idx][i].first!="0")
            {
                s=s+"TO : "+"\n";
                s+="Email-id : "+mr[i].first+"\n"+"Username : "+mr[i].second+"\n"+"Message : "+v[idx][i].first+"\n"+"Date : "+v[idx][i].second+"\n";
                fptr<<s;
                s=" ";
            }
            v[idx][i]={"0","0"}; 
        }
        fptr.close();
        mp.erase({email,user_name});
        mr.erase(idx);
        cout<<"MESSAGE DELETED SUCCESSFULLY"<<endl;
    }
}

int32_t main() {
    cout<<"---------------------------------------------------------------Welcome to the SMS portal-------------------------------------------"<<endl<<endl;
    
    cout<<"Enter 1 for adding details like fROM, TO , MESSAGE_DETAILS and DATE."<<endl;
    cout<<"Enter 2 for searching details user-wise."<<endl;
    cout<<"Enter 3 for searching details date-wise."<<endl;
    cout<<"Enter 4 for searching details user-wise and date-wise."<<endl;
    cout<<"Enter 5 for searching details through FROM wise."<<endl;
    cout<<"Enter 6 for searching details through TO wise."<<endl;
    cout<<"Enter 7 to find all messages which includes the particular sub-string."<<endl;
    cout<<"Enter 8 to delete the particular SMS from the portal."<<endl;
    cout<<"Enter -1 anytime to stop performing the operation."<<endl;

    while(true){

        int operation_to_be_chosen;
        cout<<"Operation number to be performed : ";
        cin>>operation_to_be_chosen;

        if(operation_to_be_chosen==-1){
            cout<<"EXIT"<<endl;
            break;
        }

        switch(operation_to_be_chosen) {
            case 1 :input();
                    break;

            case 2 :print_user_wise();
                    break;

            case 3:print_date_wise();
                    break;

            case 4:print_date_and_user_wise();
                    break;

            case 5:print_from_wise();
                    break;

            case 6:print_to_wise();
                    break;   

            case 7:search_string();
                   break;   

            case 8:delete_sms();
                   break;

            default : cout<<"INVALID OPERATION "<<endl;
                      break;  
        }
    }
}