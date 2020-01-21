#ifndef Dec_Hash_h
#define Dec_Hash_h
#include <vector>
#include <string.h>
#include <string>

using namespace std;

template <class HashedObj>
class HashTable
{
public:
    explicit HashTable( const HashedObj & notFound, int size = 4096 )
    :array(nextPrime(size)),currentSize(0)
    {}
    
    HashTable( const HashTable & rhs )
    : ITEM_NOT_FOUND( rhs.ITEM_NOT_FOUND ),
    array( rhs.array ), currentSize( rhs.currentSize ) { }
    
    
    
    
    const HashedObj & find( const HashedObj & x ) const{
        int currentPos = findPos( x );
        if (isActive( currentPos ))
            return array[ currentPos ].element;
        
        return   ITEM_NOT_FOUND;
    }
    
    void insert( const HashedObj & x ){
        // Insert x as active
        int currentPos = findPos( x );
        if( isActive( currentPos ) )
            return;
        array[ currentPos ] = HashEntry( x, ACTIVE );
        
    }
    void remove( const HashedObj & x ){
        int currentPos = findPos( x );
        if( isActive( currentPos ) )
            array[ currentPos ].info = DELETED;
    }
    
    
    enum EntryType { ACTIVE, EMPTY, DELETED };
    
private:
    struct HashEntry
    {
        HashedObj element;
        EntryType info;
        
        HashEntry( const HashedObj & e = HashedObj( ), EntryType i = EMPTY )
        : element( e ), info( i ) { }
    };
    
    vector<HashEntry> array;
    int currentSize;
    const HashedObj ITEM_NOT_FOUND;
    
    bool isActive( int currentPos ) const{
        return array[ currentPos ].info == ACTIVE;
    }
    
    int hasher ( const HashedObj & x,  int b) const
    {
        string k = x.chars;
        if(k.length() == 1)
        {
            return (unsigned char) (k.at(0));
        }
        return 256;
    }
    int findPos( const HashedObj & x ) const{
        int currentPos = hasher( x, array.size( ) );
        
        while( array[ currentPos ].info != EMPTY &&
              array[ currentPos ].element != x )
        {
            currentPos++;
            if( currentPos >= array.size( ) )
                currentPos -= array.size( );
        }
        
        return currentPos;
    }
    bool isPrime( int n )
    {
        if( n == 2 || n == 3 )
            return true;
        
        if( n == 1 || n % 2 == 0 )
            return false;
        
        for( int i = 3; i * i <= n; i += 2 )
            if( n % i == 0 )
                return false;
        
        return true;
    }
    
    int nextPrime( int n )
    {
        if( n % 2 == 0 )
            n++;
        
        for( ; !isPrime( n ); n += 2 )
            ;
        
        return n;
    }
};
#endif /* Dec_Hash_h */
