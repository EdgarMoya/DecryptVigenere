#include <string>
#ifndef DECRYPT_H
#define DECRYPT_H

std::string generateKey(std::string, std::string);
int searchPos(char, char[]);
int* chartoInt(std::string, char[]);
std::string toLower(std::string);
std::string decrypt(std::string, std::string, char[]);

#endif