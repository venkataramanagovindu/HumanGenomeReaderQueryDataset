
#include <fstream>
#include <iostream>
#include <chrono>
#include <string.h>

#include "Queries_AR.h"



Queries_AR::Queries_AR() {
    genomeQueries = NULL;
    filePath = "";
    queriesLineCount = 0;
    genomeArray = NULL;
    rows = 0;
    cols = 32;
}
Queries_AR::Queries_AR(string filePath) : Queries_AR() {
    this->filePath = filePath;
}



void Queries_AR::readQueriesFile() {
    queriesLineCount = 0;
    string line;

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
    cout << "Time taken to read the file : " << fixed
        << time_taken;
    cout << " sec " << endl;
}

void Queries_AR::search() {
    int numberOfHits = 0;
    long long int size = strlen(this->genomeArray);
    for (int i = 0; i < this->rows; i++)
    {
        for (int j = 0; j < size - 31; j++)
        {
            for (int k = 0; k < 32; k++) {
                //cout << this->genomeQueries[i][j];
                if (this->genomeQueries[i][k] != this->genomeArray[j + k]) {
                    break;
                }
                if (k == 31 && numberOfHits < 10 ) {
                    for (int l = 0; l < 32; l++) {
                        cout << this->genomeQueries[i][l];
                    }
                    cout << endl;
                }

            }
        }

        cout << endl;
    }

}

void Queries_AR::sort() {

}





Queries_AR::~Queries_AR() {
	delete this->genomeQueries;
}
