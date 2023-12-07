/**
Deniz Polat
Section 1
22103590
**/

#include <iostream>
#include "ctime"
#include "maxSubSum.h"

using namespace std;
int main()
{
    const int n = 5;
    const int m = 10;
    const int x = 100;
    const int k = 1000;
    const int l = 5000;
    const int t = 10000;

    int rand1[n];
    int rand2[m];
    int rand6[x];
    int rand3[k];
    int rand4[l];
    int rand5[t];

    for(int i = 0; i < n; ++i)
    {
        rand1[i] = (rand()%10) - 5;
    }

    for(int i = 0; i < m; ++i)
    {
        rand2[i] = (rand()%20) - 10;
    }

    for(int i = 0; i < x; ++i)
    {
        rand6[i] = (rand()%200) - 100;
    }

    for(int i = 0; i < k; ++i)
    {
        rand3[i] = (rand()%2000) - 1000;
    }

    for(int i = 0; i < l; ++i)
    {
        rand4[i] = (rand()%10000) - 5000;
    }

    for(int i = 0; i < t; ++i)
    {
        rand5[i] = (rand()%20000) - 10000;
    }

    ///rand1 with size n
    double duration;
    clock_t startTime = clock();

    MaxSubSum_1(rand1, n);

    cout << "Algorithm 1: ";
    duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds for n = 5" << endl;

    double duration1;
    clock_t startTime1 = clock();

    MaxSubSum_2(rand1, n);
    cout << "Algorithm 2: ";
    duration1 = 1000 * double(clock() - startTime1) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration1 << " milliseconds for n = 5." << endl;

    double duration2;
    clock_t startTime2 = clock();

    MaxSubSum_3(rand1, n);
    cout << "Algorithm 3: ";
    duration2 = 1000 * double(clock() - startTime2) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration2 << " milliseconds for n = 5." << endl;

    double duration3;
    clock_t startTime3 = clock();

    MaxSubSum_4(rand1, n);
    cout << "Algorithm 4: ";
    duration3 = 1000 * double(clock() - startTime3) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration3 << " milliseconds for n = 5." << endl;

    ///rand2 with size m
    double duration4;
    clock_t startTime4 = clock();

    MaxSubSum_1(rand2, m);
    cout << "Algorithm 1: ";
    duration4 = 1000 * double(clock() - startTime4) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration4 << " milliseconds for n = 10." << endl;

    double duration5;
    clock_t startTime5 = clock();

    MaxSubSum_2(rand2, m);
    cout << "Algorithm 2: ";
    duration5 = 1000 * double(clock() - startTime5) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration5 << " milliseconds for n = 10." << endl;

    double duration6;
    clock_t startTime6 = clock();

    MaxSubSum_3(rand2, m);
    cout << "Algorithm 3: ";
    duration6 = 1000 * double(clock() - startTime6) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration6 << " milliseconds for n = 10." << endl;

    double duration7;
    clock_t startTime7 = clock();

    MaxSubSum_4(rand2, m);
    cout << "Algorithm 4: ";
    duration7 = 1000 * double(clock() - startTime7) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration7 << " milliseconds for n = 10." << endl;

    ///rand6 with size x
    double duration8;
    clock_t startTime8 = clock();

    MaxSubSum_1(rand6, m);
    cout << "Algorithm 1: ";
    duration8 = 1000 * double(clock() - startTime8) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration8 << " milliseconds for n = 100." << endl;

    double duration9;
    clock_t startTime9 = clock();

    MaxSubSum_2(rand6, m);
    cout << "Algorithm 2: ";
    duration9 = 1000 * double(clock() - startTime9) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration9 << " milliseconds for n = 100." << endl;

    double duration10;
    clock_t startTime10 = clock();

    MaxSubSum_3(rand6, m);
    cout << "Algorithm 3: ";
    duration10 = 1000 * double(clock() - startTime10) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration10 << " milliseconds for n = 100." << endl;

    double duration11;
    clock_t startTime11 = clock();

    MaxSubSum_4(rand6, m);
    cout << "Algorithm 4: ";
    duration11 = 1000 * double(clock() - startTime11) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration11 << " milliseconds for n = 100." << endl;


    ///rand3 with size k
    double duration12;
    clock_t startTime12 = clock();

    MaxSubSum_1(rand3, k);
    cout << "Algorithm 1: ";
    duration12 = 1000 * double(clock() - startTime12) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration12 << " milliseconds for n = 1000." << endl;

    double duration13;
    clock_t startTime13 = clock();

    MaxSubSum_2(rand3, k);
    cout << "Algorithm 2: ";
    duration13 = 1000 * double(clock() - startTime13) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration13 << " milliseconds for n = 1000." << endl;

    double duration14;
    clock_t startTime14 = clock();

    MaxSubSum_3(rand3, k);
    cout << "Algorithm 3: ";
    duration14 = 1000 * double(clock() - startTime14) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration14 << " milliseconds for n = 1000." << endl;

    double duration15;
    clock_t startTime15 = clock();

    MaxSubSum_4(rand3, k);
    cout << "Algorithm 4: ";
    duration15 = 1000 * double(clock() - startTime15) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration15 << " milliseconds for n = 1000." << endl;

    ///rand4 with size l
    double duration16;
    clock_t startTime16 = clock();

    MaxSubSum_1(rand4, l);
    cout << "Algorithm 1: ";
    duration16 = 1000 * double(clock() - startTime16) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration16 << " milliseconds for n = 5000." << endl;

    double duration17;
    clock_t startTime17 = clock();

    MaxSubSum_2(rand4, l);
    cout << "Algorithm 2: ";
    duration17 = 1000 * double(clock() - startTime17) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration17 << " milliseconds for n = 5000." << endl;

    double duration18;
    clock_t startTime18 = clock();

    MaxSubSum_3(rand4, l);
    cout << "Algorithm 3: ";
    duration18 = 1000 * double(clock() - startTime18) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration18 << " milliseconds for n = 5000." << endl;

    double duration19;
    clock_t startTime19 = clock();

    MaxSubSum_4(rand4,l);
    cout << "Algorithm 4: ";
    duration19 = 1000 * double(clock() - startTime19) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration19 << " milliseconds for n = 5000." << endl;

    ///rand5 with size t
    double duration20;
    clock_t startTime20 = clock();

    MaxSubSum_1(rand5, t);
    cout << "Algorithm 1: ";
    duration20 = 1000 * double(clock() - startTime20) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration20 << " milliseconds for n = 10000." << endl;

    double duration21;
    clock_t startTime21 = clock();

    MaxSubSum_2(rand5, t);
    cout << "Algorithm 2: ";
    duration21 = 1000 * double(clock() - startTime21) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration21 << " milliseconds for n = 10000." << endl;

    double duration22;
    clock_t startTime22 = clock();

    MaxSubSum_3(rand5, t);
    cout << "Algorithm 3: ";
    duration22 = 1000 * double(clock() - startTime22) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration22 << " milliseconds for n = 10000." << endl;

    double duration23;
    clock_t startTime23 = clock();

    MaxSubSum_4(rand5, t);
    cout << "Algorithm 3: ";
    duration23 = 1000 * double(clock() - startTime23) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration23 << " milliseconds for n = 10000." << endl;
}