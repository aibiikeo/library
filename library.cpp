#include <iostream>
#include <fstream>
using namespace std;

void loginInfo (string *loginUser, string *passwordUser){
    cout << "Enter login: ";
    cin >> *loginUser;
    cout << "Enter password: ";
    cin >> *passwordUser;
}

void readerLogin(string loginUser, string passwordUser){
    string loginPasswordTxt, loginTxt, passwordTxt;
    ifstream fin;
        fin.open("readers.txt");
        if(fin.is_open()){
            while(!fin.eof() ){
                loginPasswordTxt = "";
                getline(fin, loginPasswordTxt);
                int dividerPosition = loginPasswordTxt.find(" ");
                loginTxt = loginPasswordTxt.substr(0, dividerPosition);
                passwordTxt = loginPasswordTxt.substr(dividerPosition + 1);
                if (loginUser == loginTxt && passwordUser == passwordTxt){
                    cout << "You entered" << endl;
                    break;
                }
            }
        }
        else
            cout << "readers.txt doesn't open" << endl;
            
        fin.close();
}

void librarianLogin(string loginUser, string passwordUser){
    string loginPasswordTxt, loginTxt, passwordTxt;
    ifstream fin;
        fin.open("librarian.txt");
        if(fin.is_open()){
            while(!fin.eof()){
                loginPasswordTxt = "";
                getline(fin, loginPasswordTxt);
                int dividerPosition = loginPasswordTxt.find(" ");
                loginTxt = loginPasswordTxt.substr(0, dividerPosition);
                passwordTxt = loginPasswordTxt.substr(dividerPosition + 1);
                if (loginUser == loginTxt && passwordUser == passwordTxt){
                    cout << "You entered" << endl;
                    break;
                }
            }
        }
        else
            cout << "librarian.txt doesn't open" << endl;
        
        fin.close();
}

int main()
{
    string accType, loginUser, passwordUser;
    cout << "Enter account type: ";
    cin >> accType;
    
    loginInfo (&loginUser, &passwordUser);
    
    if (accType == "reader"){
        readerLogin(loginUser, passwordUser);
    }
    else if (accType == "librarian"){
        librarianLogin(loginUser, passwordUser);
    }
    
    return 0;
}