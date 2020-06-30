#ifndef CANDIDATETYPE_H
#define CANDIDATETYPE_H

#include "CharacterType.h"

const int NUM_OF_KINGDOMS = 7;	// this is the capacity of the array
const std::string KINGDOMS[] = {
	"The North",
	"The Vale",
	"The Stormlands",
	"The Reach",
	"The Westerlands",
	"The Iron Islands",
	"Dorne" 
};

class CandidateType	: public CharacterType
{
public:
	// Overloading Operator ==
	bool operator==(int) const;

	// Default constructor
	CandidateType();
	// Copy constructor
	CandidateType(const CandidateType&);

	// Copy assignment operator
	CandidateType& operator=(const CandidateType&);

	// updateVotesByKingdom
	void updateVotesByKingdom(int, int);

	// getTotalVotes
	int getTotalVotes() const;
	// getVotesByKingdom
	int getVotesByKingdom(int) const;

	// printCandidateInfo
	void printCandidateInfo() const;
	// printCandidateTotalVotes
	void printCandidateTotalVotes() const;

	// Destructor
	~CandidateType();
	
private:
	int totalVotes;
	int numOfKingdoms;
	int *kingdomVotes;
};

#endif