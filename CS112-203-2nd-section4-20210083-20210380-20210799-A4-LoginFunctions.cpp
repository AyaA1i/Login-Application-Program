#include"CS112-203-2nd-section4-20210083-20210380-20210799-A4-LoginFunctions.h"
using namespace std;

string password1, PN, email, name, username, password;
int c1, m, l;
fstream Data_File;
profiles User_Pass[30];

//----------------------------------------------------------
int Show_Options(){
    string choice;
    cout << "___Welcome to Login Application___\n\n";
    while(true){
        load_profiles();
        cout << "Choose:\n1-Register\n2-Login\n3-Change Password\n4-Exit\nYour Choice is: ";
        getline(cin, choice, '\n');
        cout << "___________________\n\n";
        while (choice != "1" && choice != "2" && choice != "3" && choice != "4"){
            cout << "Invalid choice\n";
            cout << "Choose:\n1-Register\n2-Login\n3-Change Password\n4-Exit\nYour Choice is: ";
            getline(cin, choice, '\n');
            cout << "___________________\n\n";
        }
        if(choice == "1"){
            Register();
        }
        else if(choice == "2"){
            Enter_Username();
            Enter_Password();
            Login(password, l, c1);
        }
        else if(choice == "3"){
            Change_Password();
        }
        else if(choice == "4"){
            return 0;
        }
    }
}
//-----------------------------------------------------------
void Register(){
    Username();
    Email();
    Mobile();
    Full_Name();
    Password();
    encryptPassword();
    Save_Registration_file(username, email, password1, PN, name);
    cout << "Registration has been completed successfully...\n\n";
}
//-----------------------------------------------------------
void Username(){
    cout << "Please enter username: ";
    getline(cin, username, '\n');
    while(!Check_UN(username)){
        cout << "Please enter username: ";
        getline(cin, username, '\n');
    }
    cout << "\n\n";
}
//-----------------------------------------------------------
void Email(){
    int  y = 0 ;
    string FirstPart,SecondPart;
    cout << "Enter Email : ";
    while(y == 0 || FirstPart.length() > 64 || SecondPart.length() > 63) {
        getline(cin, email, '\n');
        int at;
        for (int i = 0; i < email.length(); i++){
            if (email[i] == '@') {
                at = i;
                break;
            }
        }
        for(int i =0;i<at;i++){
            FirstPart += email[i];
        }
        for(int i = at + 1; i < email.length(); i++){
            SecondPart += email[i];
        }
        regex EMail("[a-zA-Z0-9#!%$‘&+–/=?^_`{|}~]+(\\.[a-zA-Z0-9#!%$‘&+–/=?^_`{|}~]+)?@[0-9][a-zA-Z]+((\\.[a-zA-Z0-9]+)(-[a-zA-Z0-9]+))");
        y = regex_match(email, EMail);
        if (y == 0 or FirstPart.length() > 64 or SecondPart.length() > 63) {
            cout << "Please enter a valid Email : ";
        }
    }
    while(!Check_E(email)){
        y = 0 ;
        FirstPart = "",SecondPart = "";
        cout << "Enter Email : ";
        while(y == 0 || FirstPart.length() > 64 || SecondPart.length() > 63) {
            cin.ignore();
            getline(cin, email, '\n');
            int at;
            for (int i = 0; i < email.length(); i++){
                if (email[i] == '@') {
                    at = i;
                    break;
                }
            }
            for(int i =0;i<at;i++){
                FirstPart += email[i];
            }
            for(int i = at + 1; i < email.length(); i++){
                SecondPart += email[i];
            }
            regex EMail("[a-zA-Z0-9#!%$‘&+–/=?^_`{|}~]+(\\.[a-zA-Z0-9#!%$‘&+–/=?^_`{|}~]+)?@[0-9][a-zA-Z]+((\\.[a-zA-Z0-9]+)(-[a-zA-Z0-9]+))");
            y = regex_match(email, EMail);
            if (y == 0 or FirstPart.length() > 64 or SecondPart.length() > 63) {
                cout << "Please enter a valid Email : ";
            }
        }
    }
    cout << "\n\n";
}
//-----------------------------------------------------------
void Mobile(){
    int x = 0;
    cout << "Enter your phone number : ";
    while(x==0) {
        getline(cin, PN, '\n');
        regex number("01[1205][0-9]{8}");
        x = regex_match(PN, number);
        if (x == 0) {
            cout << "Please enter a valid phone number :" << '\n';
        }
    }
    cout << "\n\n";
}
//-----------------------------------------------------------
void Full_Name(){
    int  z = 0;
    cout << "Enter your name : ";
    while(z == 0) {
        getline(cin, name, '\n');
        regex valid("[A-Za-z_]+");
        z = regex_match(name, valid);
        if (z == 0) {
            cout << "Please enter a valid name :" << '\n';
        }
    }
    cout << "\n\n";
}
//-----------------------------------------------------------
bool Check_password(const string& p){
    int upper=0, lower=0, digit=0, symbol=0;
    for(char k : p){
        if(isupper(k)){
            upper++;
        }
        else if(islower(k)){
            lower++;
        }
        else if(isdigit(k)){
            digit++;
        }
        else{
            symbol++;
        }
    }
    if (upper == 0 || lower == 0 || digit == 0 || symbol == 0){
        return false;
    }
    return true;
}
//-----------------------------------------------------------
void Password(){
    string password2 = "b";
    password1 = "a";
    while(password1 != password2){
        password1 = "";
        password2 = "";
        char ch = 0;
        cout << "To make strong password:\n1- Enter a password whose length at least 12\n"
                "2- Your password should contain letters (upper and lower case), numbers and symbols\n";
        cout << "Your Password is: ";
        while(ch != 13){
            ch = getch();
            if(ch != 13 && ch != 8){
                password1 += ch;
                cout << "*";
            }
            if(ch == 8){
                password1.pop_back();
                cout << "\b \b";
            }
        }
        cout << "\n\n";
        while(password1.length() < 12 || !Check_password(password1)){
            password1 = "";
            password2 = "";
            ch = 0;
            cout << "Weak password\n";
            cout << "To make strong password:\n1- Enter a password whose length at least 12\n"
                    "2- Your password should contain letters (upper and lower case), numbers and symbols\n";
            cout << "Your Password is: ";
            while(ch != 13){
                ch = getch();
                if(ch != 13 && ch != 8){
                    password1 += ch;
                    cout << "*";
                }
                if(ch == 8){
                    password1.pop_back();
                    cout << "\b \b";
                }
            }
            cout << "\n\n";
        }
        ch = 0;
        cout << "Please enter the password again to confirm it: ";
        while(ch != 13){
            ch = getch();
            if(ch != 13 && ch != 8){
                password2 += ch;
                cout << "*";
            }
            if(ch == 8){
                password2.pop_back();
                cout << "\b \b";
            }
        }
        cout << "\n\n";
        if(password1 != password2){

            cout << "__Passwords are not equivalent___\n\n";
        }
    }
    cout << "\n\n";
}
//-----------------------------------------------------------
bool Check_UN(const string& un){
    int c = 0;
    for(int i = 0 ;i< 30;++i){
        if(un == User_Pass[i].username){
            cout << "This username is used before please choose another username\n";
            c++;
        }
    }
    if(c == 0){
        return true;
    }
    else{
        return false;
    }
}
//-----------------------------------------------------------
bool Check_E(const string& e){
    int c = 0;
    for(int i = 0;i < 30;i++){
        if(e == User_Pass[i].email){
            cout << "This email is used before please choose another email\n";
            c++;
        }
    }
    if(c == 0){
        return true;
    }
    else{
        return false;
    }
}
//-----------------------------------------------------------
void Save_Registration_file(const string& UN, const string& E, const string& P, const string& M, const string& N) {
    Data_File.open("Data.txt", ios::app);
    Data_File << "1-";
    Data_File << UN;
    Data_File << '\n' << "2-" <<  E << '\n' << "3-" <<  P << '\n' << "4-" << M << '\n' << "5-" << N << "\n\n";
    Data_File.close();
}
void load_profiles(){
    string line, s;
    m = 0;
    Data_File.open("Data.txt", ios::in);
    while (getline(Data_File, line)) {
        if (!line.empty()) {
            s = line;
            if (s[0] == '1') {
                s.erase(0,2);
                User_Pass[m].username = s;
            }
            if (s[0] == '2') {
                s.erase(0,2);
                User_Pass[m].email = s;
            }
            if (s[0] == '3') {
                s.erase(0,2);
                User_Pass[m].password = s;
            }
            if (s[0] == '4') {
                s.erase(0,2);
                User_Pass[m].mobile = s;
            }
            if (s[0] == '5') {
                s.erase(0,2);
                User_Pass[m].FullName = s;
            }
        }
        else{
            m++;
        }
    }
    Data_File.close();
}
//-----------------------------------------------------------
void encryptPassword() {
    for (char &i: password1) {
        i = i + 1;
    }
}
//-----------------------------------------------------------
void Enter_Username(){
    c1 = 0, l = 0;
    string userName;
    cout << "Please enter your username: ";
    getline(cin, userName, '\n');
    cout << '\n';
    for (l = 0;l < 30; l++) {
        if (userName == User_Pass[l].username) {
            c1++;
            break;
        }
    }
}
//-----------------------------------------------------------
void Enter_Password(){
    int ch = 0;
    cout << "Please enter your password: ";
    while(ch != 13){
        ch = getch();
        if(ch != 13 && ch != 8){
            password += ch;
            cout << "*";
        }
        if(ch == 8){
            password.pop_back();
            cout << "\b \b";
        }
    }
    cout << "\n\n";
    for (char & j :password) {
        j = j + 1;
    }
}
//-----------------------------------------------------------
int Login(string p, const int& index, const int& counter) {
    int c = 0;

    while(c < 3){
        if (counter == 0) {
            cout << "Failed Login, Try again\n\n";
            c++;
        }
        else{
            if(p == User_Pass[index].password){
                cout << "Successful Login, Welcome " << User_Pass[index].FullName << "\n\n___________\n";
                break;
            }
            else{
                cout << "Failed Login, Try again\n\n";
                c++;
            }
        }
        Enter_Username();
        Enter_Password();
    }
    return 0;
}
//-----------------------------------------------------------
void Change_Password(){
    string new1, new2, past1, past2, uname;
    int ch = 0;
    cout << "Enter your username:";
    getline(cin, uname, '\n');
    cout << "\n\n";
    cout << "Enter your old password:";
    while(ch != 13){
        ch = getch();
        if(ch != 13 && ch != 8){
            past1 += ch;
            cout << "*";
        }
        if(ch == 8){
            past1.pop_back();
            cout << "\b \b";
        }
    }
    cout << "\n\n";
    past2 = past1;
    for(char & j:past2){
        j = j + 1;
    }
    cout << "\n\n";
    for (int i = 0; i < 30; i++) {
        if (past2 == User_Pass[i].password && uname == User_Pass[i].username) {
            while (true) {
                cout << "Enter a new password that you have not entered before: ";
                ch = 0;
                cout << "To make strong password:\n1- Enter a password whose length at least 12\n"
                        "2- Your password should contain letters (upper and lower case), numbers and symbols\n";
                cout << "Your Password is: ";
                while (ch != 13) {
                    ch = getch();
                    if (ch != 13 && ch != 8) {
                        new1 += ch;
                        cout << "*";
                    }
                    if (ch == 8) {
                        new1.pop_back();
                        cout << "\b \b";
                    }
                }
                cout << "\n\n";
                while (new1.length() < 12 || !Check_password(new1)) {
                    ch = 0;
                    cout << "Weak password\n";
                    cout << "To make strong password:\n1- Enter a password whose length at least 12\n"
                            "2- Your password should contain letters (upper and lower case), numbers and symbols\n";
                    cout << "Your Password is: ";
                    while (ch != 13) {
                        ch = getch();
                        if (ch != 13 && ch != 8) {
                            new1 += ch;
                            cout << "*";
                        }
                        if (ch == 8) {
                            new1.pop_back();
                            cout << "\b \b";
                        }
                    }
                    cout << "\n\n";
                }
                if (new1 != past1) {
                    break;
                }
            }
            ch = 0;
            cout << "Enter the new password again PLEASE:";
            while (ch != 13) {
                ch = getch();
                if (ch != 13 && ch != 8) {
                    new2 += ch;
                    cout << "*";
                }
                if (ch == 8) {
                    new2.pop_back();
                    cout << "\b \b";
                }
            }
            cout << "\n\n";
            if (new1 != new2) {
                while (true) {
                    if (new1 != new2) {
                        cout << "__Passwords are not equivalent___\n\n";
                        ch = 0;
                        while (ch != 13) {
                            ch = getch();
                            if (ch != 13 && ch != 8) {
                                new2 += ch;
                                cout << "*";
                            }
                            if (ch == 8) {
                                new2.pop_back();
                                cout << "\b \b";
                            }
                        }
                        cout << "\n\n";
                    } else if (new1 == new2) {
                        cout << "Password changed successfully\n\n";
                        break;
                    }
                    for (char &n: new1) {
                        n = n + 1;
                    }
                    User_Pass[i].password = new1;
                }
            } else {
                cout << "Password changed successfully\n\n";
            }
        }
    }
}
