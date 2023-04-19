#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void accountType (string *accType){
    cout << "Enter account type(1 for reader, 2 for librarian): ";
    cin >> *accType;
    while (*accType != "1" && *accType != "2") {
        cout << "Enter correct account type: ";
        cin >> *accType;
    } 
}

void loginInfo (string *loginUser, string *passwordUser){
    cout << "Enter login: ";
    cin >> *loginUser;
    cout << "Enter password: ";
    cin >> *passwordUser;
    cout << endl;
}

bool readerLogin(string loginUser, string passwordUser){
    string loginPasswordTxt, loginTxt, passwordTxt;
    vector <string> allLoginTxt, allPasswordTxt;
    ifstream fin;
        fin.open("readers.txt");
        if(fin.is_open()){
            while(!fin.eof() ){
                loginPasswordTxt = "";
                getline(fin, loginPasswordTxt);
                int dividerPosition = loginPasswordTxt.find(" ");
                loginTxt = loginPasswordTxt.substr(0, dividerPosition);
                passwordTxt = loginPasswordTxt.substr(dividerPosition + 1);
                allPasswordTxt.push_back(passwordTxt);
                allLoginTxt.push_back(loginTxt);
            }
            for (int i = 0; i < allPasswordTxt.size(); i++){
                if (loginUser == allLoginTxt[i] && passwordUser == allPasswordTxt[i]){
                    return true;
                    break;
                }
            }
        }
        else
            cout << "readers.txt doesn't open" << endl;
            
        fin.close();
    cout << "Incorrect login or password." << endl;
    return false;
}

bool librarianLogin(string loginUser, string passwordUser){
    string loginPasswordTxt, loginTxt, passwordTxt;
    vector <string> allLoginTxt, allPasswordTxt;
    ifstream fin;
        fin.open("librarian.txt");
        if(fin.is_open()){
            while(!fin.eof()){
                loginPasswordTxt = "";
                getline(fin, loginPasswordTxt);
                int dividerPosition = loginPasswordTxt.find(" ");
                loginTxt = loginPasswordTxt.substr(0, dividerPosition);
                passwordTxt = loginPasswordTxt.substr(dividerPosition + 1);
                allPasswordTxt.push_back(passwordTxt);
                allLoginTxt.push_back(loginTxt);
            }
            for (int i = 0; i < allPasswordTxt.size(); i++){
                if (loginUser == allLoginTxt[i] && passwordUser == allPasswordTxt[i]){
                    return true;
                    break;
                }
            }
        }
        else
            cout << "librarian.txt doesn't open" << endl;
        
        fin.close();
    cout << "Incorrect login or password." << endl;
    return false;
}

void readerMenu(){
    cout << " --------MENU--------\n";
    cout << "|1.All books        |\n";
    cout << "|2.Search book      |\n";
    cout << "|3.Add to Favourites|\n";
    cout << "|4.My Favourites    |\n";
    cout << "|5.Borrow a book    |\n";
    cout << "|6.My Borrowed Books|\n";
    cout << "|7.Exit             |\n";
    cout << " --------------------\n";
}

void librarianMenu(){
    cout << " ----------MENU----------\n";
    cout << "|1.All books             |\n";
    cout << "|2.Search book           |\n";
    cout << "|3.All Readers           |\n";
    cout << "|4.Search reader         |\n";
    cout << "|5.List of borrowed books|\n";
    cout << "|6.Exit                  |\n";
    cout << " ------------------------\n";
}

void allBooks(){
    string book;
    ifstream fin;
        fin.open("books.txt");
        if(fin.is_open()){
            cout << "   All Books\n";
            while(!fin.eof()){
                book = "";
                getline(fin,book);
                cout << book << endl;
            }
            cout << endl;
        }
        else
            cout << "books.txt doesn't open" << endl;

        fin.close();
}

void searchBook() {
    string book;
    ifstream fin;
        fin.open("books.txt");
        if(fin.is_open()){
            vector <string> allBooksTxt;
            vector <string> allBookNamesTxt;
            vector <string> allBookAuthorsTxt;
            vector <string> allBookYearsTxt;
            while(!fin.eof()){
                book = "";
                getline(fin,book);
                int dividerPosition1 = book.find("\"");
                
                int dividerPosition2;
                int findDividerPosition2 = -1;
                do {
                    findDividerPosition2 = book.find("\"", findDividerPosition2 + 1);
                    if (findDividerPosition2 != -1)
                        dividerPosition2 = findDividerPosition2 - dividerPosition1 - 1;
                } while (findDividerPosition2 != -1);
                
                int dividerPosition3 = book.find("-") + 1;
                
                int dividerPosition4;
                int findDividerPosition4 = -1;
                do {
                    findDividerPosition4 = book.find("-", findDividerPosition4 + 1);
                    if (findDividerPosition4 != -1)
                        dividerPosition4 = findDividerPosition4 - dividerPosition3 - 2;
                } while (findDividerPosition4 != -1);
                
                int dividerPosition5;
                int findDividerPosition5 = -1;
                do {
                    findDividerPosition5 = book.find("-", findDividerPosition5 + 1);
                    if (findDividerPosition5 != -1)
                        dividerPosition5 = findDividerPosition5 + 2;
                } while (findDividerPosition5 != -1);
                
                string booksTxt = book.substr(dividerPosition1);
                allBooksTxt.push_back(booksTxt);
                string bookNameTxt = book.substr(dividerPosition1 + 1, dividerPosition2);
                allBookNamesTxt.push_back(bookNameTxt);
                string bookAuthorTxt = book.substr(dividerPosition3 + 1, dividerPosition4);
                allBookAuthorsTxt.push_back(bookAuthorTxt);
                string bookYearTxt = book.substr(dividerPosition5);
                allBookYearsTxt.push_back(bookYearTxt);
            }
            
            int bookOption;
            cout << " --------------------------\n";
            cout << "|Search by:                |\n";
            cout << "|   1.Book's name          |\n";
            cout << "|   2.Book's author        |\n";
            cout << "|   3.Book's year of issue |\n";
            cout << " --------------------------\n";
            cout << "Choose an option: ";
            cin >> bookOption;
            cout << endl;
            
            string bookExist = "";
            switch (bookOption){
                case 1:{
                    string bookName;
                    cout << "Enter book name: ";
                    cin.ignore();
                    getline(cin, bookName);
                    
                    for (int i = 0; i < allBookNamesTxt.size(); i++){
                        if (bookName == allBookNamesTxt[i]){
                            bookExist =  allBooksTxt[i];
                        }
                    }
                    if (bookExist != "")
                        cout << bookExist << endl;
                    else 
                        cout << "This book has not yet been added to the library.\n";
                    break;
                }
                case 2:{
                    string bookAuthor;
                    cout << "Enter book's author: ";
                    cin.ignore();
                    getline(cin, bookAuthor);
                    for (int i = 0; i < allBookAuthorsTxt.size(); i++){
                        if (bookAuthor == allBookAuthorsTxt[i]){
                            bookExist =  allBooksTxt[i];
                        }
                    }
                    if (bookExist != "")
                        cout << bookExist << endl;
                    else 
                        cout << "This book has not yet been added to the library.\n";
                    break;
                }
                case 3:{
                    string bookYear;
                    cout << "Enter book's year: ";
                    cin.ignore();
                    getline(cin, bookYear);
                    for (int i = 0; i < allBookYearsTxt.size(); i++){
                        if (bookYear == allBookYearsTxt[i]){
                            bookExist =  allBooksTxt[i];
                        }
                    }
                    if (bookExist != "")
                        cout << bookExist << endl;
                    else 
                        cout << "This book has not yet been added to the library.\n";
                    break;                    
                }
            }
            cout << endl;
        }
        else
            cout << "books.txt doesn't open" << endl;
        fin.close();
}

void allReaders(){
    cout << "List of readers:\n";
    ifstream fin;
        fin.open("readers.txt");
        if(fin.is_open()){
            while(!fin.eof() ){
                string reader;
                getline(fin, reader);
                int dividerPosition = reader.find(" ");
                string readerTxt = reader.substr(0, dividerPosition);
                cout << readerTxt << endl;
            }
            cout << endl;
        }
        else
            cout << "readers.txt doesn't open" << endl;
            
        fin.close();
}

void searchReader(){
    string reader;
    vector <string> readersList;
    ifstream fin;
        fin.open("readers.txt");
        if(fin.is_open()){
            while(getline(fin, reader)){
                string readerTxt = reader.substr(0, reader.find(" "));
                readersList.push_back(readerTxt);
            }
            string readerName;
            bool readerExist = 0;
            cout << "Enter reader's name: ";
            cin >> readerName;
            for (int i = 0; i < readersList.size(); i++){
                if (readerName == readersList[i]){
                    readerExist = 1;
                    break;
                }
            }
            if (readerExist)
                cout << "User is found.\n" << endl;
            else
                cout << "User is not found.\n" << endl;
        }
        else
            cout << "readers.txt doesn't open" << endl;
            
        fin.close();
    
}

void favReadersBook (vector <vector <string> > &favourites){
    string lineTxt;
    vector <string> readersList, a;
    
    a.assign(1, "");
    
    ifstream fin;
    fin.open("readers.txt");
    if(fin.is_open()){
        while(getline(fin, lineTxt))
            readersList.push_back(lineTxt.substr(0, lineTxt.find(" ")));
    }
    else
        cout << "readers.txt doesn't open" << endl;
    fin.close();
    
    for (int i = 0; i < readersList.size(); i++){
        a[0] = readersList[i];
        favourites.push_back(a);
    }
    
    favourites[0].push_back("Charlotte’s Web");
    favourites[2].push_back("Little Women");
    favourites[2].push_back("Harry Potter");
    favourites[3].push_back("Charlotte’s Web");
    favourites[4].push_back("The Hobbit");
    favourites[4].push_back("The Great Gatsby");
}

void addFavourite(string loginUser, vector <vector <string> > &favourites){
    cout << "Which book you want to add to favourites?\n";
    string favouriteBook;
    cin.ignore();
    getline(cin, favouriteBook);
    
    string bookName;
    vector <string> allBookNamesTxt;
    ifstream ffin;
    ffin.open("books.txt");
    if(ffin.is_open()){
        while(getline(ffin, bookName)){
            int dividerPosition1 = bookName.find("\"");
                
            int dividerPosition2;
            int findDividerPosition2 = -1;
            do {
                findDividerPosition2 = bookName.find("\"", findDividerPosition2 + 1);
                if (findDividerPosition2 != -1)
                    dividerPosition2 = findDividerPosition2 - dividerPosition1 - 1;
            } while (findDividerPosition2 != -1);
            
            string bookNameTxt = bookName.substr(dividerPosition1 + 1, dividerPosition2);
            allBookNamesTxt.push_back(bookNameTxt);
        }
    }
    else
        cout << "books.txt doesn't open" << endl;
    ffin.close();
    
    bool bookExist = false;
    for (int i = 0; i < allBookNamesTxt.size(); i++){
        if (allBookNamesTxt[i] == favouriteBook){
            bookExist = true;
            break;
        }
    }
    
    for (int i = 0; i < favourites.size(); i++){
        if (favourites[i][0] == loginUser){
            if (bookExist){
                favourites[i].push_back(favouriteBook);
                cout << "This book added to favourites.\n\n";
                break;
            }
            else{
                cout << "This book has not yet been added to the library.\n\n";
                break;
            }
        }
    }
}

void showFavourite(string loginUser, vector <vector <string> > favourites){
    cout << "List of your favourite books:\n";
    for (int i = 0; i < favourites.size(); i++){
        if(loginUser == favourites[i][0]){
            for (int j = 1; j < favourites[i].size(); j++){
                cout << favourites[i][j] << endl;
            }
        }
    }
    cout << endl;
}

void borrowedReadersBook (vector <vector <string> > &borrowed){
    string lineTxt;
    vector <string> readersList, a;
    
    a.assign(1, "");
    
    ifstream fin;
    fin.open("readers.txt");
    if(fin.is_open()){
        while(getline(fin, lineTxt))
            readersList.push_back(lineTxt.substr(0, lineTxt.find(" ")));
    }
    else
        cout << "readers.txt doesn't open" << endl;
    fin.close();
    
    for (int i = 0; i < readersList.size(); i++){
        a[0] = readersList[i];
        borrowed.push_back(a);
    }
    
    borrowed[0].push_back("The Great Gatsby");
    borrowed[1].push_back("Charlotte’s Web");
    borrowed[1].push_back("Little Women");
    borrowed[2].push_back("Pride and Prejudice");
    borrowed[3].push_back("Anne Frank");
    borrowed[3].push_back("The Hobbit");
    borrowed[4].push_back("Harry Potter");
}

void borrowBook(string loginUser, vector <vector <string> > &borrowed){
    cout << "Which book you want to borrow?\n";
    string borrowBook;
    cin.ignore();
    getline(cin, borrowBook);
    
    string bookName;
    vector <string> allBookNamesTxt;
    ifstream ffin;
    ffin.open("books.txt");
    if(ffin.is_open()){
        while(getline(ffin, bookName)){
            int dividerPosition1 = bookName.find("\"");
                
            int dividerPosition2;
            int findDividerPosition2 = -1;
            do {
                findDividerPosition2 = bookName.find("\"", findDividerPosition2 + 1);
                if (findDividerPosition2 != -1)
                    dividerPosition2 = findDividerPosition2 - dividerPosition1 - 1;
            } while (findDividerPosition2 != -1);
            
            string bookNameTxt = bookName.substr(dividerPosition1 + 1, dividerPosition2);
            allBookNamesTxt.push_back(bookNameTxt);
        }
    }
    else
        cout << "books.txt doesn't open" << endl;
    ffin.close();
    
    bool bookExist = false;
    for (int i = 0; i < allBookNamesTxt.size(); i++){
        if (allBookNamesTxt[i] == borrowBook){
            bookExist = true;
            break;
        }
    }
    
    for (int i = 0; i < borrowed.size(); i++){
        if (borrowed[i][0] == loginUser){
            if (bookExist){
                borrowed[i].push_back(borrowBook);
                cout << "You borrowed this book.\n\n";
                break;
            }
            else{
                cout << "This book has not yet been added to the library.\n\n";
                break;
            }
        }
    }
}

void showBorrowedBooks(string loginUser, vector <vector <string> > borrowed){
    cout << "List of your borrowed books:\n";
    for (int i = 0; i < borrowed.size(); i++){
        if(loginUser == borrowed[i][0]){
            for (int j = 1; j < borrowed[i].size(); j++){
                cout << borrowed[i][j] << endl;
            }
        }
    }
    cout << endl;
}

void borrowedBooksList(vector <vector <string> > borrowed){
    cout << "List of borrowed books:\n";
    for (int i = 0; i < borrowed.size(); i++){
        for (int j = 0; j < borrowed[i].size(); j++){
            cout << borrowed[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main()
{
    string accType, loginUser, passwordUser;
    vector <vector <string> > favourites;
    favReadersBook(favourites);
    vector <vector <string> > borrowed;
    borrowedReadersBook(borrowed);
    
    accountType(&accType);
    loginInfo (&loginUser, &passwordUser);
    
    if(accType == "1" && readerLogin(loginUser, passwordUser)){
        int option;
        readerMenu();
        
        while(option != 7) {
            cout << "Choose an option: " ;
            cin >> option;
            cout << endl;
                
            switch(option){
                case 1:
                    allBooks();
                    break;
                case 2:
                    searchBook();
                    break;
                case 3:
                    addFavourite(loginUser, favourites);
                    break;
                case 4:
                    showFavourite(loginUser, favourites);
                    break;
                case 5:
                    borrowBook(loginUser, borrowed);
                    break;
                case 6:
                    showBorrowedBooks(loginUser, borrowed);
                    break;
            }
            string goBackMenu;
            if (option != 7){
                cout << "Want to go to menu? ";
                cin >> goBackMenu;
                cout << endl;
                if (goBackMenu == "yes")
                    readerMenu();
                else
                    exit(0);        
                } 
        }
    }
    
    else if(accType == "2" && librarianLogin(loginUser, passwordUser)){
        int option;
        librarianMenu();
        
        while(option != 5) {
            cout << "Choose an option: " ;
            cin >> option;
            cout << endl;
                
            switch(option){
                case 1:
                    allBooks();
                    break;
                case 2:
                    searchBook();
                    break;
                case 3:
                    allReaders();
                    break;
                case 4:
                    searchReader();
                    break;
                case 5:
                    borrowedBooksList(borrowed);
                    break;
            }
            string goBackMenu;
            if (option != 6){
                cout << "Want to go to menu? ";
                cin >> goBackMenu;
                cout << endl;
                if (goBackMenu == "yes")
                    librarianMenu();
                else
                    exit(0);        
            } 
        }
    }
    
    return 0;
}