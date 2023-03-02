
#include <fstream>
#include <iostream>
#include <chrono>
#include <string.h>

#include "Queries_AR.h"
using namespace std;



Queries_AR::Queries_AR() {
    genomeQueries = NULL;
    filePath = "";
    queriesLineCount = 0;
    genomeArray = NULL;
    rows = 0;
    cols = 32;
    TEN_THOUSAND = 10000;
    HUNDRED_THOUSAND = 100000;
    ONE_MILLION = 1000000;
}

Queries_AR::Queries_AR(string filePath) : Queries_AR() {
    this->filePath = filePath;
}

void Queries_AR::readQueriesFile() {
    queriesLineCount = 0;
    string line;

    /* Time function returns the time since the
    Epoch(jan 1 1970). Returned time is in seconds. */
    time_t start, end;
    std::time(&start);
    std::ios_base::sync_with_stdio(false);

    /* Creating input filestream */
    ifstream file(this->filePath);
    while (getline(file, line))
        queriesLineCount++;

    file.close();

    /* Creating input filestream */
    ifstream fin(this->filePath);

    this->rows = queriesLineCount / 2;

    this->genomeQueries = new char*[this->rows];
    char c;

    int genomeQueryIdx = 0;
    for (int i = 0; i < queriesLineCount ; i++)
    {
        getline(fin, line);
        if (i % 2 == 0)
            continue;
        

        this->genomeQueries[genomeQueryIdx] = new char[32];
        int j = 0;
         for (; j < 32; j++) {
             this->genomeQueries[genomeQueryIdx][j] = line[j];
         }
         this->genomeQueries[genomeQueryIdx][j] = '\0';
         genomeQueryIdx++;
    }
    
    time(&end);

    // Calculating total time taken by the program.
    double time_taken = double(end - start);
    cout << "Time taken to read the queries file : " << fixed
        << time_taken;
    cout << " sec " << endl;

    cout << "Numbers of lines in the file : " << queriesLineCount << endl;
}

void Queries_AR::readHumanGenomeFile(string genomeFilePath) {
    // read file char by char
    char ch;
    fstream fin(genomeFilePath, fstream::in);
    char* headerCharArray;

    /* Time function returns the time since the
    Epoch(jan 1 1970). Returned time is in seconds. */
    time_t start, end;
    std::time(&start);
    std::ios_base::sync_with_stdio(false);

    // Calculating the size of the file
    fin.seekg(0, std::ios::end);
    long long size = fin.tellg();
    fin.seekg(0, std::ios::beg);

    // Dynamically allocating memory for the array
    genomeArray = new char[size];
    bool isHeader = false;
    long long int charArridx = 0;
    long long int headerCharidx = 0;
    //long long int genomeLength = 0;

    while (fin >> noskipws >> ch) {

        // 62 = >
        if (ch == 62) {
            isHeader = true;

            /*totalGenomeLength += genomeLength;
            genomeLength = 0;*/
        }

        if (isHeader) {
            if (ch == 10) {
                isHeader = false;
            }
        }
        else if (ch != 10)
        {
            genomeArray[charArridx++] = ch;
            totalGenomeLength++;
        }
    }
    fin.close();

    genomeArray[charArridx] = '\0';

    std::ios_base::sync_with_stdio(false);
    time(&end);

    // Calculating total time taken by the program.
    double time_taken = double(end - start);
    cout << "Time taken to read the genome file : " << fixed
        << time_taken;
    cout << " sec " << endl;
}

//void Queries_AR::search() {
//    int numberOfHits = 0;
//    long long int size = strlen(this->genomeArray);
//    for (int i = 0; i < this->rows; i++)
//    {
//        for (int j = 0; j < size - 31; j++)
//        {
//            for (int k = 0; k < 32; k++) {
//                //cout << this->genomeQueries[i][j];
//                if (this->genomeQueries[i][k] != this->genomeArray[j + k]) {
//                    break;
//                }
//                if (k == 31 && numberOfHits < 10 ) {
//                    for (int l = 0; l < 32; l++) {
//                        cout << this->genomeQueries[i][l];
//                    }
//                    cout << endl;
//                }
//
//            }
//        }
//        cout << endl;
//    }
//
//}

void Queries_AR::search() {
    int numberOfHits = 0;
    long long int size = strlen(this->genomeArray);
    double time_taken = 0;

    /* Time function returns the time since the
    Epoch(jan 1 1970). Returned time is in seconds. */
    time_t start, end;
    std::time(&start);
    std::ios_base::sync_with_stdio(false);

    //cout << "o/p from search ";

    for (long long int i = 0; i < size - 31; i++) {
        char substr[33];
        strncpy(substr, this->genomeArray + i, 32);
        substr[32] = '\0';
        for (long long int j = 0; j < this->rows; j++) {
            //for (int k = 0; k < 32; k++) {
            //    //cout << this->genomeQueries[i][j];
            //    if (this->genomeQueries[j][k] != this->genomeArray[i + k]) {
            //        break;
            //    }
            //    if (k == 31 && numberOfHits < 10) {
            //        for (int l = 0; l < 32; l++) {
            //            cout << this->genomeQueries[i][l];
            //        }
            //        cout << endl;
            //    }
            //}

            //cout << substr << endl;
            //cout << this->genomeQueries[j] << endl;
            if (strcmp(substr, this->genomeQueries[j]) == 0 && numberOfHits < 10)
            {
                cout << this->genomeQueries[j] << " index " << i << endl;

                numberOfHits++;
            }
        }

        if (i == this->TEN_THOUSAND)
        {
            numberOfHits = 0;
            time(&end);

            // Calculating total time taken by the program.
            time_taken = double(end - start);
            cout << "Time taken to search the 10K characters : " << fixed
                << time_taken;
            cout << " sec " << endl;
        }
        if (i == this->HUNDRED_THOUSAND) 
        {
            numberOfHits = 0;
            time(&end);

            // Calculating total time taken by the program.
            time_taken = double(end - start);
            cout << "Time taken to search the 100K characters : " << fixed
                << time_taken;
            cout << " sec " << endl;
        }

        if (i == this->ONE_MILLION)
        {
            numberOfHits = 0;
            time(&end);

            // Calculating total time taken by the program.
            time_taken = double(end - start);
            cout << "Time taken to search the 1M characters : " << fixed
                << time_taken;
            cout << " sec " << endl;
        }
    }


}

void Queries_AR::searchAfterSort() {
    int numberOfHits = 0;
    long long int size = strlen(this->genomeArray);
    double time_taken = 0;

    /* Time function returns the time since the
    Epoch(jan 1 1970). Returned time is in seconds. */
    time_t start, end;
    std::time(&start);
    std::ios_base::sync_with_stdio(false);

    for (long long int i = 0; i < size - 31; i++) {
        char substr[33];
        strncpy(substr, this->genomeArray + i, 32);
        substr[32] = '\0';

        long long int idx = this->binarySearch(0, this->rows - 1, substr);
        if (numberOfHits < 10 && idx != -1) {
            cout << substr << " index " << i << endl;
            numberOfHits++;
        }
        int x = 0;
    }

    time(&end);

    // Calculating total time taken by the program.
    time_taken = double(end - start);
    // Calculating total time taken by the program.
    time_taken = double(end - start);
    cout << "Time taken to search the file after sort : " << fixed
        << time_taken;
    cout << " sec " << endl;
}

long long int Queries_AR::binarySearch(long long int s, long long int e, char substr[33]) {
    if (e >= s) {
        long long int idx = s + (e - s) / 2;

        int compareop = strcmp(substr, this->genomeQueries[idx]);
        if (compareop == 0) {
            return idx;
        }
        else if(compareop == -1)
        {
            return this->binarySearch(s, idx - 1, substr);
        }
        else
        {
            return this->binarySearch(idx + 1, e, substr);
        }
    }

    return -1;
}

void Queries_AR::sort() {
    QuickSort(this->genomeQueries, 0, this->rows - 1 );
}

void Queries_AR::QuickSort(char** arr, long long int start, long long int end) {
    if (start < end) {
        long long int p = partition(arr, start, end);

        QuickSort(arr, start, p - 1);
        QuickSort(arr, p + 1, end);
    }
}

long long int Queries_AR::partition(char** arr, long long int start, long long int end) {
    char* pivot = arr[start];

    long long int i = start;
    long long int j = end;
    while (i < j) {
        while (strcmp(arr[i], pivot) <= 0)
        {
            i++;
        }
        while (strcmp(arr[j], pivot) > 0 )
        {
            j--;
        }

        if (i < j) {
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[start], arr[j]);
    return j;
}







Queries_AR::~Queries_AR() {
	delete this->genomeQueries;
}
