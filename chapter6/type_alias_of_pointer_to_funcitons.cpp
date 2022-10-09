typedef double wages;


// third parameter is a function type and is automatically treated as a pointer to function
void useBigger(const string &s1, const string &s2,
bool pf(const string &, const string &));
// equivalent declaration: explicitly define the parameter as a pointer to function
void useBigger(const string &s1, const string &s2,
bool (*pf)(const string &, const string &));

typedef bool Func(const string&, const string&);
typedef decltype(lengthCompare) Func2; // equivalent type

typedef bool(*FuncP)(const string&, const string&);
typedef decltype(lengthCompare) *FuncP2; // equivalent type

void useBigger(const string&, const string&, Func);
void useBigger(const string&, const string&, FuncP2);


typedef int arrT[42];