#include "Message.h"

std::istream& operator>>(std::istream& is, Message& message)
{
	//is >> message._sender;
	//is >> message._receiver;
	getline(is, message._sender, ' ');
	getline(is, message._receiver, ' ');
	getline(is, message._text, '\n');
	//is >> message._text;
	return is;
}

std::ostream& operator<<(std::ostream& os, Message& message)
{
	std::string output = message._sender + " " + message._receiver + " " + message._text + "\n";
	return os << output;
}



void ReadFromMessageFile(std::fstream& messageF)
{
	messageF.clear();
	messageF.seekg(0, std::ios::beg);

	while (messageF.eof() != true)
	{
		Message tmp;
		messageF >> tmp;

		if(tmp.getSender() == "" || tmp.getReceiver() == "" || tmp.getText() == "")
			break;
		std::cout << "<" << tmp.getSender() 
				  << "> to <" << tmp.getReceiver() 
			      << ">: " << tmp.getText() 
				  << "\n";
	}

	std::cout << "-----END OF FILE -----\n";
}

void WriteToMessageFile(Message message, std::fstream& messageF)
{
	messageF.seekp(0, std::ios::end);
	messageF << message;
	std::cout << "Message successfully sent\n";
}

void WriteToMessageFile(std::fstream& messageF)
{
	messageF.seekp(0, std::ios::end);
	Message tmp;
	tmp.setMessage();
	messageF << tmp;
	std::cout << "Message successfully sent\n";
}

std::string Message::getSender() const
{
	return std::string(_sender);
}

std::string Message::getReceiver() const
{
	return std::string(_receiver);
}

std::string Message::getText() const
{
	return (_text);
}

void Message::setMessage()
{
	std::cout << "Sender: "; std::cin >> _sender;
	std::cout << "Receiver: "; std::cin >> _receiver;
	std::cin.ignore(1000, '\n');
	std::cout << "Text: "; getline(std::cin, _text);
	std::cout << _text << std::endl;
}
