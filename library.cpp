#include <iostream>
#include <fstream>
using namespace std;

void loginInfo (string *loginUser, string *passwordUser){
    cout << "Enter login: ";
    cin >> *loginUser;
    cout << "Enter password: ";
    cin >> *passwordUser;
}

bool readerLogin(string loginUser, string passwordUser){
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
                    return true;
                    break;
                }
            }
        }
        else
            cout << "readers.txt doesn't open" << endl;
            
        fin.close();
    return false;
}

bool librarianLogin(string loginUser, string passwordUser){
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
                    return true;
                    break;
                }
            }
        }
        else
            cout << "librarian.txt doesn't open" << endl;
        
        fin.close();
    return false;
}

int main()
{
    string accType, loginUser, passwordUser;
    cout << "Enter account type: ";
    cin >> accType;
    
    loginInfo (&loginUser, &passwordUser);
    
    if(readerLogin(loginUser, passwordUser)){
        // cout << "You entered" << endl;
        cout << "--------MENU--------\n";
        cout << "1.All books\n";
        cout << "2.Search book\n";
        cout << "3.Add to Favourites\n";
        cout << "4.My Favourites\n";
        cout << "5.My Balance\n";
        cout << "6.Buy a book\n";
        cout << "7.Exit\n";
        cout << "--------------------\n";
        
    }
    
    else if(librarianLogin(loginUser, passwordUser)){
        cout << "--------MENU--------\n";
        cout << "1.All books\n";
        cout << "2.Search book\n";
        cout << "3.All Readers\n";
        cout << "4.Search reader\n";
        cout << "5.Exit\n";
        cout << "--------------------\n";
    }
    
    return 0;
}
