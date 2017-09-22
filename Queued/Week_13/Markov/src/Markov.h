// Copyright (C) 1999 Lucent Technologies
// Excerpted from 'The Practice of Programming'
// by Brian W. Kernighan and Rob Pike
//
// Portions Copyright (c) 2013 Christopher Baker <http://christopherbaker.net>
//


#pragma once


#include <time.h>
#include <iostream>
#include <string>
#include <deque>
#include <map>
#include <vector>
#include "ofLog.h"


class Markov
{
public:
    typedef std::deque<std::string> Prefix;

    Markov();
    virtual ~Markov();

    void setup();

    void add(const std::vector<std::string>& sequence);

    void build(Prefix&, std::istream& inputStream);
    void add(Prefix& prefix, const std::string& text);
    void generate(Prefix prefix, std::size_t numWords);

    static const int            NUM_PREF;
    static const std::string    NON_WORD;
    static const int            MAX_GENERATED;

    std::map<Prefix, std::vector<std::string> > stateTable; // prefix -> suffixes

};
