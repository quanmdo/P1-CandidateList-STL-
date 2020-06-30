#include "CandidateType.h"

using namespace std;

// Overloading Operator ==
bool CandidateType::operator==(int id) const
{
	return (this->getID() == id);
}

// Default constructor
CandidateType::CandidateType()
{
	totalVotes = 0;
	numOfKingdoms = NUM_OF_KINGDOMS;
	kingdomVotes = new int[numOfKingdoms] {0};
}

// Copy constructor
CandidateType::CandidateType(const CandidateType& other)
	:CharacterType(other.getFirstName(),
		other.getLastName(), other.getID())
{
	totalVotes = other.totalVotes;
	numOfKingdoms = other.numOfKingdoms;
	kingdomVotes = new int[numOfKingdoms];

	for (int i = 0; i < numOfKingdoms; ++i)
		kingdomVotes[i] = other.kingdomVotes[i];
}

// Copy assignment operator
CandidateType& CandidateType::operator=(
	const CandidateType& rightSide)
{
	if (this != &rightSide)
	{
		if (numOfKingdoms != rightSide.numOfKingdoms)
		{
			delete[] kingdomVotes;
			kingdomVotes = new int[rightSide.numOfKingdoms];
		}
		numOfKingdoms = rightSide.numOfKingdoms;
		for (int i = 0; i < rightSide.numOfKingdoms; ++i)
			kingdomVotes[i] = rightSide.kingdomVotes[i];

		totalVotes = rightSide.totalVotes;
		this->setCharacterInfo(rightSide.getFirstName(),
			rightSide.getLastName(), rightSide.getID());
	}
	else
		cerr << "Attempted assignment to itself.";
	return *this;
}

// updateVotesByKingdom
void CandidateType::updateVotesByKingdom(int index, int votes)
{
	kingdomVotes[index] = votes;
	totalVotes += votes;
}

// getTotalVotes
int CandidateType::getTotalVotes() const
{
	return totalVotes;
}

// getVotesByKingdom
int CandidateType::getVotesByKingdom(int index) const
{
	return kingdomVotes[index];
}

// printCandidateInfo
void CandidateType::printCandidateInfo() const
{
	printID();
	cout << " - ";
	printName();
}

// printCandidateTotalVotes
void CandidateType::printCandidateTotalVotes() const
{
	printName();
	cout << "\n=> Total Votes (all kingdoms): " << totalVotes;
}

// Destructor
CandidateType::~CandidateType()
{
	delete [] kingdomVotes;
	kingdomVotes = nullptr;
}