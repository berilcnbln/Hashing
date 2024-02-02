# Hashing

Part 1:
I designed the hash table the way it was taught during the course. For the collision resolution, I calculated the number of times I have consecutively visited the numbers that I have already probed before and if that number was equal to the number of elements I hold in my hash table, I would stop probing.
Part 2:
I created 3 test cases in the test.txt that covers every possible scenario that I could think of. Below, I dumped the test cases and outputs to them.
The test case design is as follows:
Number of testcases
operationNumber_i hashTableSize_i collisionStrategy(L or Q or D)
3
12 10 L I 14
I 15
I4
I3
S4
S 14
R 14
S 14
I5
I5
R 15 S5
12 10 Q I 14
I 15
I4
I3
S4
S 14
R 14
S 14
I5
I5
R 15 S5
14 10 D I 14
I 15 I4
I 104 I3 S4 S 14 R 14 R 14 S 14 I5 I5
R 15 S5
14 inserted
15 inserted
4 inserted
3 inserted
4 found after 3 probes 14 found after 1 probes 14 removed
14 not found after 4 probes 5 inserted
5 not inserted
15 removed
5 found after 3 probes
The values stored in the table of size 10 with collision resolution L There are currently 3 elements in the table
0:
1:
2:
3: 3
4: Removed
5: Removed
6: 4
7: 5

8: 9:
Analysis of the Hash table
Average number of successful probes = 3.666667
Average number of failed probes = 2.000000 ##########################################################
14 inserted
15 inserted
4 inserted
3 inserted
4 found after 3 probes 14 found after 1 probes 14 removed
14 not found after 5 probes 5 inserted
5 not inserted
15 removed
5 found after 2 probes
The values stored in the table of size 10 with collision resolution Q There are currently 3 elements in the table
0:
1:
2:
3: 3
4: Removed
5: Removed
6: 5
7: 8: 4 9:
Analysis of the Hash table
Average number of successful probes = 3.333333
Average number of failed probes = 1.800000 ##########################################################
14 inserted 15 inserted 4 inserted 104 inserted 3 inserted

4 found after 2 probes 14 found after 1 probes 14 removed
14 not removed
14 not found after 4 probes 5 inserted
5 not inserted
15 removed
5 found after 2 probes
The values stored in the table of size 10 with collision resolution D There are currently 4 elements in the table
0: 5
1:
2:
3: 3
4: Removed
5: Removed
6: 104
7: 8: 4 9:
Analysis of the Hash table
Average number of successful probes = 3.250000
Average number of failed probes = -1.000000 ##########################################################
Part 3:
Linear probing successful and unsuccessful comparison for test 1. Load factor for the first test case was: 3 / 10
Theoretical successful: 1.21 Practical successful: 3.66 Theoretical unsuccessful: 1.52 Practical unsuccessful: 2.00
Since my results are around 3 times higher than the theoretical ones, you can see that I am more conservative than the best probing algorithm, I don’t give up looking for the element early.

  Quadratic probing and Double hashing successful and unsuccessful probing for test 2 and 3.
Load factor for the first test case was: 3 / 10
Theoretical successful: 1.19 Practical successful: 3.33(Quadratic), 3.25(Double) Theoretical unsuccessful: 1.42 Practical unsuccessful: 1.8(Quadratic), -1(Double)
Since my results are around 1.5 times higher than the theoretical ones, you can see that I am more conservative than the best probing algorithm. At the same time, the results for the quadratic probing ended up being better than for the linear one.
  
