/** * Author: Beril Canbulan
*/


#include <iostream>
#include "HashTable.h"
using namespace std;

int main() {
    int n;

    FILE *file = fopen("test.txt", "r");
    fscanf(file, "%d", &n);

    while(n--){
        int operationNo, tableSize, key, numOfProbes;
        double success, fail;
        char option, operation, nl;

        fscanf(file, "%d %d %c\n", &operationNo, &tableSize, &option);
        HashTable *table;

        if(option == 'L')
            table = new HashTable(tableSize, HashTable::LINEAR);
        else if(option == 'Q')
            table = new HashTable(tableSize, HashTable::QUADRATIC);
        else
            table = new HashTable(tableSize, HashTable::DOUBLE);

        for(int i = 0; i < operationNo; i++){
            fscanf(file, "%c %d\n", &operation, &key);

            if(operation == 'I'){
                if(table -> insert(key))
                    printf("%d inserted\n", key);
                else
                    printf("%d not inserted\n", key);
            }
            else if(operation == 'S'){
                if(table -> search(key, numOfProbes))
                    printf("%d found after %d probes\n", key, numOfProbes);
                else
                    printf("%d not found after %d probes\n", key, numOfProbes);
            }
            else{
                if(table -> remove(key))
                    printf("%d removed\n", key);
                else
                    printf("%d not removed\n", key);
            }
        }

        printf("\nThe values stored in the table of size %d with collision resolution %c\n", table -> size(), option);
        table -> display();
        printf("\nAnalysis of the Hash table\n");

        table -> analyze(success, fail);
        printf("Average number of successful probes = %lf\nAverage number of failed probes = %lf\n", success, fail);
        printf("##########################################################\n\n");
    }

    fclose(file);

    return 0;
}
