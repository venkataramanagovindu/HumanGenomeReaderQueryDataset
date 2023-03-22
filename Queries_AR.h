#ifndef Queries_AR_H
#define Queries_AR_H
#endif
#include <string>
using namespace std;

class Queries_AR
{
	private:
		//char** genomeQueries;
		string filePath;
		long long int queriesLineCount;
		char* genomeArray;
		long long int totalGenomeLength = 0;
		//long long int rows;
		int cols;
		int TEN_THOUSAND = 0;
		int HUNDRED_THOUSAND = 0;
		int ONE_MILLION = 0;

	public:
		long long int rows;
		char** genomeQueries;
		Queries_AR();
		Queries_AR(string filePath);

		void readQueriesFile();
		void readHumanGenomeFile(string genomeFilePath);
		void linearSearch(long long int searchLength);
		void searchAfterSort(long long int searchLength);
		long long int binarySearch(long long int s, long long int e, char substr[33]);
		void sort();
		void QuickSort(char** arr, long long int start, long long int end);
		void HeapSort(char** arr, long long int  len);
		void heapify(char** arr, int len, int i);
		long long int partition(char** arr, long long int start, long long int end);
		~Queries_AR();
};

