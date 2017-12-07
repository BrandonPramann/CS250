#ifndef _SMART_DYNAMIC_ARRAY_HPP
#define _SMART_DYNAMIC_ARRAY_HPP

#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

class SmartDynamicArray
{
    public:
    SmartDynamicArray();
    ~SmartDynamicArray();

    void Push( const string& newItem ) noexcept;
    void Insert( int index, const string& newItem );
    void Extend( const SmartDynamicArray& other );
    void Pop() noexcept;
    void Remove( int index );
    string Get( int index ) const;
    void Resize();
    void Resize( int newSize );

    int Size() const;
    bool IsFull() const;
    bool IsEmpty() const noexcept;

    string operator[]( int index );
    SmartDynamicArray& operator=( const SmartDynamicArray& other );
    bool operator==( const SmartDynamicArray& other );
    bool operator!=( const SmartDynamicArray& other );

    private:
    void ShiftRight( int index ) noexcept;
    void ShiftLeft( int index );
    bool IsInvalidIndex( int index ) const noexcept;
    bool IsNonContiguousIndex( int index ) const noexcept;
    void AllocateMemory();
    void AllocateMemory( int newSize );
    void DeallocateMemory();

    string* m_data;
    int m_itemCount;
    int m_arraySize;

    friend class Tester;
};

#endif
