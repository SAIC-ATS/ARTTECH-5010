#pragma once


#include <deque>
#include <map>
#include <vector>


//template<typename KeyType, typename ValueType, std::size_t KeySize = 2>
//class EntryStatistics
//{
//public:
//    EntryStatistics(const ValueType& value):
//        _value(value),
//        _count(0)
//    {
//    }
//
//    virtual ~EntryStatistics()
//    {
//    }
//
//private:
//    ValueType   _value;
//    std::size_t _count;
//};


//
//template<typename KeyType, typename ValueType, std::size_t KeySize = 2>
//class MarkovStateTable_
//{
//public:
//    struct EntryStatistics;
//
//    MarkovStateTable_()
//    {
//    }
//
//    virtual ~MarkovStateTable_()
//    {
//    }
//
//    virtual void addEntry(const KeyType& key, const ValueType& value)
//    {
//
//    }
//
//    virtual double getProbability(const KeyType& key, const ValueType& value)
//    {
//
//    }
//
//private:
//    typedef std::deque<KeyType> Key;
//    typedef std::vector<ValueType> Value;
////    typedef std::map<Value, std::size_t> CountTable;
//    typedef std::map<Key, std::vector<Value> > EntryTable;
////    typedef std::map<Key, > EntryTable;
//
//
//    std::map<Key, Value> entryTable;
////    std::map<Key, std::map<ValueType, std::size_t> > probabilityTable;
//
//};
