#ifndef CANDIDATELIST_H
#define CANDIDATELIST_H

#include "CandidateType.h"

#include <iostream>
#include <string>
#include <iomanip>
#include <list>

class CandidateList
{
public:
    // Default constructor
    CandidateList();

    // addCandidate
    void addCandidate(const CandidateType&);

    // getWinner
    int getWinner() const;

    // isEmpty
    bool isEmpty() const;
    // searchCandidate
    bool searchCandidate(int) const;

    // printCandidateName
    void printCandidateName(int) const;
    // printAllCandidates
    void printAllCandidates() const;
    // printKingdomVotes
    void printKingdomVotes(int, int) const;
    // printCandidateTotalVotes
    void printCandidateTotalVotes(int) const;
    // printFinalResults
    void printFinalResults() const;
/**********************************************
* FUNCTION ADDED FOR SECLECTION #6
**********************************************/
    // printEvenVotes
    void printEvenVotes() const;

    // Destructor
    ~CandidateList();

private:
    // searchCandidate
    std::list<CandidateType> candidates;

    bool searchCandidate(int, std::list<CandidateType>::const_iterator&) const;
    
    void printHeader() const;
    void printCandidate(std::list<CandidateType>::const_iterator&, int&) const;
};

#endif