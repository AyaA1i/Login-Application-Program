// FCI - Programming 1 - 2022 - Assignment 4
// Program Name:Login System.cpp
// Last Modification Date: 05-13-2022
// Author1 and ID and Group: Aya Ali Hassan & 20210083 & A
// Author2 and ID and Group: Mariam Ayman Taha & 20210380 & A
// Author3 and ID and Group: Amira Basaam Dabbak & 20210799 & A
// Teaching Assistant: Eng. Nesma Mohamed & Eng. Yousra Ayman


#ifndef LOGINSYSTEM_LOGINFUNCTIONS_H
#define LOGINSYSTEM_LOGINFUNCTIONS_H

#include <bits/stdc++.h>
#include <regex>
#include "conio.h"
using namespace std;

struct profiles{
    string username;
    string email;
    string FullName;
    string password;
    string mobile;
};

int Show_Options();//aya
void Register();//aya
void Username();//aya
void Full_Name();//aya
void Email();//aya
void Mobile();//aya
void Password();//mariam
bool Check_password(const string& p);//mariam
void Save_Registration_file(const string& UN, const string& E, const string& P, const string& M, const string& N);//mariam
bool Check_UN(const string& un);//mariam
bool Check_E(const string& e);//mariam
void load_profiles();//mariam
int Login(string p, const int& index, const int& counter);//amira
void encryptPassword();//amira
void Enter_Username();//amira
void Enter_Password();//amira
void Change_Password();//amira






#endif //LOGINSYSTEM_LOGINFUNCTIONS_H
