#ifndef Queries_AR_H
#define Queries_AR_H
#endif
#include <string>
using namespace std;

class Queries_AR
{
	private:
		char** genomeQueries;
		string filePath;
		long long int queriesLineCount;
		char* genomeArray;
		long long int totalGenomeLength = 0;
		long long int rows;
		int cols;

	public:
		Queries_AR();
		Queries_AR(string filePath);

		void readQueriesFile();
		void readHumanGenomeFile(string genomeFilePath);
		void search();
		void sort();

		~Queries_AR();
};

