//
// Created by HUAWEI on 12/16/2022.
//
#include "iostream"
using namespace std;


class myClass{
public:
    string name;
    int age;

    myClass(string myName, int myAge){
        name = myName;
        age = myAge;
    }

    void myMethod(){
    cout<< "apple" <<endl;
    cout << name << ";" << age <<endl;
    }

    string Getter(){
    return bank;
    }

    void setter(int ID, string pass, string bankName){
    id = ID;
    pw = pass;
    bank = bankName;
    }

private:
    int id;
    string pw;
    string bank;

protected:
    string prot = "This is protected";
} ;

class abc: public myClass{

public:
    string sub = "ABCD";

    abc(string myName, int myAge) : myClass(myName, myAge) {
        cout << sub <<endl;
    }

};
int main(){

    myClass name1("MG Mg", 12);
    myClass name2("Kyaw Kyaw", 17);

    name1.name = "Mg Mg";
    name2.name = "Zaw Zaw";

    name1.age = 18;
    name2.age = 22;

    cout<< name1.name << endl;
    cout << name1.age<< '\n';
    cout << name2.name<< '\n'<< name2.age<< endl;
    name1.myMethod();
    name2.myMethod();
    name1.setter(123, "abcd", "KBZ");
    cout<< name1.Getter() <<endl;
    abc newobj(std::string(), 0);
    cout << newobj.name<< endl;
    return 0;
}