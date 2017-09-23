# include <fstream>
using namespace std;

class Streamable{
		virtual fstream& store(fstream& file, bool addNewLine = true) const = 0;
		virtual fstream& load(fstream& file) = 0;
		virtual ostream& display(ostream& os) const = 0;
		virtual istream& read(istream& is) = 0;

};

