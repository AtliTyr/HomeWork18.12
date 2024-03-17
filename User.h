#pragma once
#include <iostream>
#include <fstream>

class User
{
private:
    std::string _name;
    std::string _login;
    std::string _pass;
public:
    User() = default;

    User(std::string name, std::string login, std::string pass) : _name(name), _login(login), _pass(pass)
    {}

    void setUserData();

    friend std::istream& operator>>(std::istream& is, User& user);
    friend std::ostream& operator<<(std::ostream& os, User& user);
};

void ReadFromUserFile(std::fstream& userF);

void WriteToUserFile(User user, std::fstream& userF);

void WriteToUserFile(std::fstream& userF);
