#include <cstddef>
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
		Queries_AR() {
			genomeQueries = NULL;
			filePath = "";
			queriesLineCount = 0;
			genomeArray = NULL;
			rows = 0;
			cols = 32;
		}
		Queries_AR(string filePath);

		void readQueriesFile();
		void readHumanGenomeFile(string genomeFilePath);
		void search();
		void sort();

		~Queries_AR();
};

