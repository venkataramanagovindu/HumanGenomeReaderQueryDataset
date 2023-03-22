// HumanGenomeReaderQueryDataset.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Queries_AR.h"
#include <iostream>
#include <stdio.h>

using namespace std;

int main(int argc, char** argv)
{
    std::cout << "Hello World!\n";

    //string Queries_File_Path = argv[1], genomeFilePath = argv[2];
    //char* end;
    //long long int count = strtoll(argv[3], &end, 10);
    //    cout << Queries_File_Path << endl;
    //cout << genomeFilePath << endl;
    //cout << count << endl;


    //Queries_AR *dataSet = new Queries_AR("../human_reads.fa");
    Queries_AR* dataSet = new Queries_AR("human_reads_small2.fa");

    int tenThousand = 10000, HundredThousand = 100000, OneMillion = 1000000;





    cout << "Reading human reads file" << endl;
    dataSet->readQueriesFile();

    dataSet->readHumanGenomeFile("human_genome.txt");
    //dataSet->readHumanGenomeFile("human.txt");
    //dataSet->readHumanGenomeFile("human.txt");
    cout << "Linear search started" << endl;
    dataSet->linearSearch(100);
    cout << "Before sort" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << dataSet->genomeQueries[i] << endl;
    }
    cout << "Sorting start" << endl;
    dataSet->sort();
    cout << "Sorting end" << endl;
    

    cout << "After sort" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << dataSet->genomeQueries[i] << endl;
    }

    dataSet->searchAfterSort(tenThousand);


    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
