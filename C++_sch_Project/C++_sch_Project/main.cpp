#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

struct data{
    string name;
    string email;
    string password;
    int score_point{};
};

string arr[3];

int main(){
    struct data one;
    struct data two;
    ofstream file("db.txt");
//    cin>>one.name;
//    cin>>one.email;
//    cin>>one.password;

//    ofstream apple("eg.txt");
//    apple<<one.name<<" "<< one.email<<" "<< one.password<<endl;
//    apple<<"orane"<<" bird"<<" 2344"<<endl;
//    apple.close();
    string str;
    ifstream to_read("eg.txt");
    while (getline(to_read, str)){
        int i=0;
//        stringstream ss(str);
//        while ( ss >> str){
//            arr[i] = str;
//            i++;
//        }
        to_read >> arr[0] >> arr[1] >> arr[2];
        two.name = arr[0];
        two.email = arr[1];
        two.password = arr[2];
        cout<<arr[0]<<endl;
        cout<<arr[1]<<endl;
        cout<<arr[2]<<endl;
        cout<<endl;
    }
    to_read.close();



    return 0;
}

