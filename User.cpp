#include "User.h"

std::istream& operator>>(std::istream& is, User& user)
{
	is >> user._name;
	is >> user._login;
	is >> user._pass;
	return is;
}

std::ostream& operator<<(std::ostream& os, User& user)
{
	return os << user._name << " "
			  << user._login << " " 
			  << user._pass << "\n";
}

void WriteToUserFile(User user, std::fstream& userF)
{
	userF.seekp(0, std::ios::end);
	userF << user;
	std::cout << "User successfully added\n";
}

void WriteToUserFile(std::fstream& userF)
{
	userF.seekp(0, std::ios::end);
	User tmp;
	tmp.setUserData();
	userF << tmp;
	std::cout << "User successfully added\n";
}

void ReadFromUserFile(std::fstream& userF)
{
	userF.clear();
	userF.seekg(0, std::ios::beg);

	while (!userF.eof())
	{
		User tmp;
		userF >> tmp;
		std::cout << tmp;
	}

	userF.clear();
	userF.seekg(0, std::ios::beg);

	std::cout << "-----END OF FILE -----\n";
}

void User::setUserData()
{
	std::cout << "name: "; std::cin >> _name;
	std::cout << "login: "; std::cin >> _login;
	std::cout << "password: "; std::cin >> _pass;
}
