#include <filesystem>
#include <fstream>
#include <iostream>
#include "User.h"
#include "Message.h"

using namespace std;
namespace fs = std::filesystem;

int main()
{
   
    fstream userF("UserData.txt", ios::in | ios::out);
    if(!userF)
	{
		userF.open("UserData.txt", ios::in | ios::out | ios::trunc);
   		 fs::permissions("UserData.txt", fs::perms::owner_exec | fs::perms::group_all | fs::perms::others_all,
		            fs::perm_options::remove);
		
	}
    fstream messageF("Messages.txt", ios::in | ios::out);
    if(!messageF)
    {
	    messageF.open("Messages.txt", ios::in | ios::out | ios::trunc);
    	fs::permissions("Messages.txt", fs::perms::owner_exec | fs::perms::group_all | fs::perms::others_all,                                                                   fs::perm_options::remove);   
    }

    char ch = ' ';
    bool cont = true;
    while (cont)
    {
        cout << "########################## \n";
        cout << "Press 1 to get User's info \n";
        cout << "Press 2 to read messages \n";
        cout << "Press 3 to add new user \n";
        cout << "Press 4 to write a message \n";
        cout << "Press 0 to exit \n";
        cout << "########################## \n";
        cout << "> ";
        string temp;
        cin >> temp;
        ch = temp[0];

        switch (ch)
        {
        case '1':
            ReadFromUserFile(userF);
            break;
        case '2':
            ReadFromMessageFile(messageF);
            break;
        case '3':
            WriteToUserFile(userF);
            break;
        case '4':
            WriteToMessageFile(messageF);
            break;
        case '0':
            cont = false;
            break;
        default:
            break;
        }
    }

	userF.close();
	messageF.close();

    return 0;
}
