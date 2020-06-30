#include "CandidateList.h"

using namespace std;

// Default constructor
CandidateList::CandidateList(){}

// addCandidate
void CandidateList::addCandidate(const 
	CandidateType& newCandidate)
{
	candidates.push_back(newCandidate);
}

// getWinner
int CandidateList::getWinner() const
{
	auto iterBegin = candidates.cbegin();
	auto iterEnd = candidates.cend();
	auto highestVotes = iterBegin;

	for (iterBegin; iterBegin != iterEnd; ++iterBegin)
	{
		if (iterBegin->getTotalVotes() > highestVotes->getTotalVotes())
		{
			highestVotes = iterBegin;
		}
	}

	return highestVotes->getID();
}

// isEmpty
bool CandidateList::isEmpty() const
{
	return candidates.empty();
}

// searchCandidate(public)
bool CandidateList::searchCandidate(int theID) const
{
	auto iterBegin = candidates.cbegin();
	return searchCandidate(theID, iterBegin);
}

// printCandidateName
void CandidateList::printCandidateName(int theID) const
{
	auto target = candidates.cbegin();

	if (searchCandidate(theID, target))
	{
		target->printName();
	}
}

// printAllCandidates
void CandidateList::printAllCandidates() const
{
	auto iterBegin = candidates.cbegin();
	auto iterEnd = candidates.cend();

	for (iterBegin; iterBegin != iterEnd; ++iterBegin)
	{
		iterBegin->printCandidateInfo();
		cout << endl;
	}
}

// printKingdomVotes
void CandidateList::printKingdomVotes(int theID, int index) const
{
	auto iterBegin = candidates.cbegin();
	
	if (searchCandidate(theID, iterBegin))
	{
		cout << setw(5) << right << "*";
		cout << setw(3) << right <<
			iterBegin->getVotesByKingdom(index);
		cout << "( => )" << KINGDOMS[index] << endl;
	}
}

// printCandidateTotalVotes
void CandidateList::printCandidateTotalVotes(int idNum) const
{
	auto iterBegin = candidates.cbegin();

	if (searchCandidate(idNum, iterBegin))
	{
		cout << setw(6) << right << "=>";
		cout << " Total votes: " <<
			iterBegin->getTotalVotes() << endl;
	}
}

void CandidateList::printHeader() const
{
	cout << "************ FINAL RESULTS ************\n" << endl;

	cout << "LAST" << setw(16) << "FIRST" << setw(10) << "TOTAL"
		 << setw(7) << "POS" << endl;

	cout << "NAME" << setw(15) << "NAME" << setw(11) << "VOTES"
		 << setw(7) << "#" << endl;

	cout << "_______________________________________\n" << endl;
}

void CandidateList::printCandidate(
	list<CandidateType>::const_iterator& candidate, int& ranking) const
{
	cout << setw(15) << left << candidate->getLastName()
		 << setw(10) << candidate->getFirstName()
		 << setw(5) << right << candidate->getTotalVotes()
		 << setw(7) << ranking << endl;

	int lastHigh = candidate->getTotalVotes();

	while (ranking < static_cast<int>(candidates.size()))
	{
		auto iterBegin = candidates.cbegin();
		auto highestVotes = iterBegin;

		while ((iterBegin != candidates.cend()) &&
				((*highestVotes).getTotalVotes() != lastHigh - 1))
		{
			while ((*highestVotes).getTotalVotes() > lastHigh - 1)
			{
				++highestVotes;
			}

			if (((*iterBegin).getTotalVotes() < lastHigh) &&
				((*iterBegin).getTotalVotes() >
					(*highestVotes).getTotalVotes()))
			{
				highestVotes = iterBegin;
			}
			++iterBegin;
		}

		lastHigh = (*highestVotes).getTotalVotes();
		++ranking;

		cout << setw(15) << left << (*highestVotes).getLastName()
			 << setw(10) << (*highestVotes).getFirstName()
			 << setw(5) << right << (*highestVotes).getTotalVotes()
			 << setw(7) << ranking << endl;

		if (ranking % 5 == 0)
			cout << "---------------------------------------" 
			<< endl;
	}
	cout << "_______________________________________" << endl;
}

// printFinalResults
void CandidateList::printFinalResults() const
{
	printHeader();

	auto iterBegin = candidates.cbegin();
	auto highestVotes = iterBegin;

	while (iterBegin != candidates.cend())
	{
		if ((*highestVotes).getTotalVotes() < (*iterBegin).getTotalVotes())
		{
			highestVotes = iterBegin;
		}
		++iterBegin;
	}

	int pos = 1;

	while (pos < static_cast<int>(candidates.size()))
	{
		printCandidate(highestVotes, pos);
	}	
}

/**********************************************
* FUNCTION ADDED FOR SECLECTION #6
**********************************************/
// printEvenVotes
void CandidateList::printEvenVotes() const
{
	auto iterBegin = candidates.cbegin();
	
	cout << "************* EVEN VOTES **************\n" << endl;

	cout << "LAST" << setw(16) << "FIRST" << setw(10) << "TOTAL"
		 << endl;

	cout << "NAME" << setw(15) << "NAME" << setw(11) << "VOTES"
		 << endl;
	
	cout << "_______________________________________\n" << endl;

	while (iterBegin != candidates.cend())
	{
		if (iterBegin->getTotalVotes() % 2 == 0)
		{
			cout <<  setw(15) << left << iterBegin->getLastName()
				 << setw(10) << iterBegin->getFirstName()
				 << setw(5) << right << iterBegin->getTotalVotes() << endl;
		}
		++iterBegin;
	}
	cout << "_______________________________________" << endl;
}

// Destructor
CandidateList::~CandidateList(){}

// searchCandidate(private)
bool CandidateList::searchCandidate(int theID,
	list<CandidateType>::const_iterator& iterBegin) const
{
	list<CandidateType>::const_iterator iter;
	iter = find(iterBegin, candidates.cend(), theID);

	if (iter != candidates.cend())
	{
		iterBegin = iter;
		return true;
	}
	else
	{
		cout << "    => ID not in the list." << endl;
		return false;
	}
}