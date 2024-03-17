#pragma once
#include <iostream>
#include <fstream>
#include <string>

class Message
{
private:
    std::string _text;
    std::string _sender;
    std::string _receiver;

public:
    Message() = default;

    Message(std::string sender, std::string receiver, std::string text): _receiver(receiver), _sender(sender), _text(text)
    {}

    std::string getSender() const;
    std::string getReceiver() const;
    std::string getText() const;

    void setMessage();

    friend std::istream& operator>>(std::istream& is, Message& message);
    friend std::ostream& operator<<(std::ostream& os, Message& message);
};

void ReadFromMessageFile(std::fstream& messageF);

void WriteToMessageFile(Message message, std::fstream& messageF);

void WriteToMessageFile(std::fstream& messageF);
