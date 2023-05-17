//
// Created by zl_shit_h on 15/05/23.
//

#include <iostream>
#include <vector>
using namespace std;
class Bank{
private:
    string u_name;
    string u_email;
    string u_password;
public:
    vector<string> data;
    void settor(string name, string email, string password){
        u_name = name;
        u_email = email;
        u_password = password;
    }
    vector<string> gettor(){
        data.push_back(u_name);
        data.push_back(u_email);
        data.push_back(u_password);
        return data;
    }
};

int main(){
    Bank bank_obj;
    bank_obj.settor("ZawLwinHtoo","asd@gmail.com","apple");
    vector<string>data = bank_obj.gettor();
    for (auto i = data.begin(); i != data.end(); i++){
        cout<< *i << " ";
    };
    int Size = data.size();
    cout<<"\n"<<endl;
    for (auto i=0; i<Size; i++){
        cout<< data.at(i) << endl;
    }
    return 0;
}