#ifndef CHARACTERTYPE_H
#define CHARACTERTYPE_H

#include <iostream>
#include <string>

class CharacterType
{
public:
	// Default constructor
	CharacterType();
	// Overloaded constructor
	CharacterType(const std::string& newFirstName,
		const std::string& newLastName, int newID);

	// setCharacterInfo
	void setCharacterInfo(const std::string& newFirstName,
		const std::string& newLastName, int newID);

	// getFirstName
	std::string getFirstName() const;
	// getLastName
	std::string getLastName() const;
	// getID
	int getID() const;

	// printName
	void printName() const;
	// printCharacterInfo
	void printCharacterInfo() const;
	// printID
	void printID() const;

	// Destructor
	~CharacterType();
private:
	std::string firstName;	
	std::string lastName;	
	int id;					
};

#endif