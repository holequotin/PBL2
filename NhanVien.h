#include<iostream>
#include<fstream>
#include<cstring>
#include<conio.h>
#include<cstdio>
#include<ctime>
#include<iomanip>
#include<string>
#pragma once
using namespace std;
class NhanVien{
    protected:
        int _id;
        string _name;
        string _user;
        string _pass;
    public:
        NhanVien(int = 0, string = " ", string = "", string = " ");
        ~NhanVien();
        int getID();
        void updeatID();
        string getName();
        string getUser();
        string getPass();
        void Show();
        void Update();
};
