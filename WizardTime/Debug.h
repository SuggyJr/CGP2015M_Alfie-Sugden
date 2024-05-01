#include <iostream>
#include <string>

using namespace std;

class Debug
{
public:
	void setDebugger(bool bug) { debug = bug; }
	bool getDebugger() const { return debug; }
	void getDebug(string string) const { if (getDebugger()) { cout << string << "\n"; } }

private:
	bool debug = false;
};