/** * Author: Beril Canbulan
*/

#include "HashTable.h"

HashTable::HashTable( const int tableSize, const CollisionStrategy option ){
    hash = new int[tableSize];
    visited = new bool[tableSize];
    for(int i = 0; i < tableSize; i++)
        hash[i] = bos;
    this -> option = option;
    this -> tableSize = tableSize;
    this -> currentSize = 0;
}

HashTable::~HashTable() {
    delete []hash;
    delete []visited;
    hash = NULL;
    visited = NULL;
}

int HashTable::needToTerminate(int hashID, bool *visited, int &countSeen){
    if(visited[hashID]){
        countSeen++;
        if(countSeen == currentSize + 1)
            return -1;
    }
    else {
        countSeen = 0;
        visited[hashID] = true;
    }
    return 0;
}

int HashTable::size(){
    return tableSize;
}

int HashTable::print(int l, int r){
    for(int i = l; i < r; i++)
        printf("%d ", hash[i]);
    printf("\n");
}


int HashTable::searchLinear(const int key, const int hashIndex, int &numOfProbes, bool extraFunc = false){
    int hashID = hashIndex;
    int countSeen = 0;

    for(int i = 0; i < tableSize; i++)
        visited[i] = false;

    numOfProbes++;
    while(hash[hashID] != bos && hash[hashID] != key &&
                     ((!extraFunc && hash[hashID] != removed) || (extraFunc))){
        int status = needToTerminate(hashID, visited, countSeen);
        if(status == -1){
            printf("Couldn't find an empty space for %d iterations\n", currentSize + 1);
            return -1;
        }

        hashID = (hashID + 1) % tableSize;
        numOfProbes++;
    }
    return hashID;
}


int HashTable::searchQuadratic(const int key, const int hashIndex, int &numOfProbes, bool extraFunc = false){
    int hashID = hashIndex, originalHashID = hashIndex;
    int iteration = 1;
    int countSeen = 0;
    memset(visited, 0, sizeof(visited));

    numOfProbes++;
    while(hash[hashID] != bos && hash[hashID] != key &&
            ((!extraFunc && hash[hashID] != removed) || (extraFunc))){
        int status = needToTerminate(hashID, visited, countSeen);
        if(status == -1){
            printf("Couldn't find an empty space for %d iterations\n", currentSize + 1);
            return -1;
        }

        hashID = (originalHashID + (iteration * iteration)) % tableSize;
        iteration++;
        numOfProbes++;
    }

    return hashID;
}

int HashTable::searchDoubleHash(const int key, const int hashIndex, int &numOfProbes, bool extraFunc = false){
    int hashID = hashIndex, originalHashID = hashIndex;
    int iteration = 1, countSeen = 0;
    memset(visited, 0, sizeof(visited));

    numOfProbes++;
    while(hash[hashID] != bos && hash[hashID] != key &&
            ((!extraFunc && hash[hashID] != removed) || (extraFunc))){
        int status = needToTerminate(hashID, visited, countSeen);
        if(status == -1){
            printf("Couldn't find an empty space for %d iterations\n", currentSize + 1);
            return -1;
        }

        hashID = (originalHashID + reverseNumber(key) * iteration) % tableSize;
        iteration++;
        numOfProbes++;
    }

    return hashID;
}

int HashTable::hashIndex(const int key, const int hashIndex, int &numProbes, bool ignoreRemoved = false){
    int hashID;

    if(option == LINEAR)
        hashID = searchLinear(key, hashIndex, numProbes, ignoreRemoved);
    else if(option == QUADRATIC)
        hashID = searchQuadratic(key, hashIndex, numProbes, ignoreRemoved);
    else
        hashID = searchDoubleHash(key, hashIndex, numProbes, ignoreRemoved);
    return hashID;
}

bool HashTable::insert(const int key) {
    int numOfProbes, hashID = hashIndex(key, hashCode(key), numOfProbes);

    //if new node to be inserted increase the current size
    if(hash[hashID] == bos || hash[hashID] == removed) {
        currentSize++;
        hash[hashID] = key;
        return true;
    }
    return false;
}

bool HashTable::remove(const int key) {
    int numOfProbes, hashID = hashIndex(key, hashFunc(key), numOfProbes, true);

    if (hash[hashID] == bos || hash[hashID] == removed) {
//        printf("%d is not found to be deleted\n", key);
        return false;
    }
    else {
        hash[hashID] = removed;
        currentSize--;
//        printf("%d is deleted\n", key);
        return true;
    }
}



bool HashTable::search(const int key, int &numProbes) {
    numProbes = 0;
    int hashID = hashIndex(key, hashCode(key), numProbes, true);
    return !(hash[hashID] == bos || hash[hashID] != key);
}

void HashTable::display() {
    printf("There are currently %d elements in the table\n", currentSize);
    for(int i = 0; i < tableSize; i++){
        printf("%d: ", i);
        if(hash[i] != bos && hash[i] != removed)
            printf("%d", hash[i]);
        else if(hash[i] == removed)
            printf("Removed");
        printf("\n");
    }
}

void HashTable::analyze(double &success, double &fail) {
    success = fail = 0;
    int currentSuccess = 0, currentFail = 0;

    for(int i = 0; i < tableSize; i++){
        if(hash[i] != bos){
            search(hashFunc(hash[i]), currentSuccess);
            success += currentSuccess;
        }
    }
    success /= currentSize;

    if(tableSize == currentSize){
        cout << "There are no empty slots to analyze";
    }
    else if(option != DOUBLE){
        for (int i = 0; i < tableSize; i++) {
            if (hash[i] != bos) {
                hashIndex(i, i, currentFail);
                fail += currentFail;
            }
        }
        fail /= tableSize;
    }
    else
        fail = -1;
}

int HashTable::hashCode(int key){
    return key % tableSize;
}

int HashTable::reverseNumber(int number) {
    int ret = 0;
    while (number != 0){
        ret = ret * 10;
        ret = ret + number % 10;
        number = number / 10;
    }
    return ret;
}

int HashTable::hashFunc(int key) {
    return key % tableSize;
}






