/** * Author: Beril Canbulan
*/

#ifndef HASHTABLE_HASHTABLE_H
#define HASHTABLE_HASHTABLE_H

#include<bits/stdc++.h>
using namespace std;

class HashTable {
private:
    int *hash, option, tableSize, currentSize;
    bool *visited;
    const int bos = INT_MIN, removed = -1;


    int searchLinear(int key, int hashIndex, int &n, bool extraFunc);

    int searchQuadratic(int key, int hashIndex, int &n, bool extraFunc);

    int searchDoubleHash(int key, int hashIndex, int &n, bool extraFunc);

    static int reverseNumber(int number);

    int hashFunc(int key);

public:
    enum CollisionStrategy {LINEAR, QUADRATIC, DOUBLE};

    HashTable(int tableSize, CollisionStrategy option);

    ~HashTable();

    bool insert( const int item );

    bool remove( const int item );

    bool search( const int item, int& numProbes );

    void display();

    void analyze( double& numSuccProbes, double& numUnsuccProbes );

    int hashCode(int key);


    int hashIndex(const int key, const int hashIndex, int &numOfProbes, bool ignoreRemoved);

    int needToTerminate(int hashID, bool *visited, int &countSeen);

    int print(int l, int r);

    int size();
};


#endif //HASHTABLE_HASHTABLE_H
