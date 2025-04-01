#include <iostream>
#include <string>
#include "SingleLinkedList.h"
using namespace std;

int main()
{
	List<string> movies;
	movies.insert("Saw", 0);
	movies.insert("Texas Chainsaw Massacare", 1);
	movies.insert("Halloween", 2);
	movies.insert("Nightmare on Elm Street", 3);
	movies.insert("Ring", 4);
	movies.insert("Stranger Things", 5);
	movies.insert("Tokyo Ghoul", 6);

	cout << movies.search("Saw") << endl;

	movies.insert("PH at 3 am with max volume", movies.locate("Ring"));
	movies.remove(4);
	movies.remove(0);
	movies.remove(movies.locate("Tokyo Ghoul"));
	movies.remove(movies.locate("Ring"));
	movies.display();
}
