#include "CharacterType.h"

using namespace std;

// Default constructor
CharacterType::CharacterType(): id(0) {}

// Overloaded constructor
CharacterType::CharacterType
	(const string& newFirstName,
		const string& newLastName, int newID)
{
	firstName = newFirstName;
	lastName = newLastName;
	id = newID;
}

// setCharacterInfo
void CharacterType::setCharacterInfo
	(const string& newFirstName,
		const string& newLastName, int newID)
{
	firstName = newFirstName;
	lastName = newLastName;
	id = newID;
}

// getFirstName
string CharacterType::getFirstName() const
{
	return firstName;
}

// getLastName
string CharacterType::getLastName() const
{
	return lastName;
}

// getID
int CharacterType::getID() const
{
	return id;
}

// printName
void CharacterType::printName() const
{
	cout << lastName << ", " << firstName;
}

// printCharacterInfo
void CharacterType::printCharacterInfo() const
{
	printID();
	cout << " " << firstName << " " << lastName;
}

// printID
void CharacterType::printID() const
{
	cout << "ID# " << id;
}

// Destructor
CharacterType::~CharacterType() {}