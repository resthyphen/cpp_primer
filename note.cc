> g++ a.cc

> line begin with 'Enter' that will be thought as empty

> int char long float double (2.1 Primitive Built-in Types)     P60

> The compiler appends a null character (’\0’) to every string literal.		P69

> default initialized  	 	P74

> Writing Our Own Header Files    P116

> Using getline to Read an Entire Line	P129

> constexpr 	P102
     Generally, it is a good idea to use constexpr for variables that you intend
     to use as constant expressions

> binary search 	P161  	example_3.4.2.cc

> there are no const references   P97

> Complicated Array Declarations	P165
  int *ptrs[10];                      //ptrs is an array of ten pointers to int
	int (*Parray)[10] = &arr;           //Parray points to an array of ten ints
	int (&arrRef)[10] = arr;             //arrRef refers to an array of ten ints
	int *(&arry)[10] = ptrs;            // arry is a reference to an array of ten pointers

> we cannot use a range for if the body of the loop adds elements to the vector 	P148

> range for 	P149

> The string::size_type Type    P131
> The subscript operator (the [ ] operator) takes a string::size_type     P138

> size_type	                      P149
  vector<int>::size_type


> int ia[] = {0,1,2,3,4,5,6,7,8,9};	 // ia is an array of ten ints
   auto ia2(ia);		 // ia2 is an int* that points to the first element in ia		P168

> size_t is a machine-specific unsigned type that is guaranteed to be large enough to
   hold the size of any object in memory			P166
> constexpr size_t sz = 5 	P170

> ptrdiff_t is a signed integral type.	 P171

> int *p = &ia[2]; 	// p points to the element indexed by 2
   int j = p[1]; 	// p[1] is equivalent to *(p + 1),
		// p[1] is the same element as ia[3]
   int k = p[-2]; 	// p[-2] is the same element as ia[0]

> important to remember that string literals end with a null character 	P164
	char a3[] = "C++"; // null terminator added automatically

>  3.5.4. C-Style Character Strings             P174
> Strings that follow this convention are stored in character arrays and are null terminated

> Exercise 3.40 	P176

> C-style character string


> constexpr  						P103
> constexpr int *q = nullptr;	 	// q is a const pointer to int	                 P104
> constexpr const int *p = &i; // p is a constant pointer to the const int i

> Using an Array to Initialize a vector                       P178

> typedef int int_array[4]	exercise_3.44 	P184


> Overloaded Operators??  	P189

> (-m)/n and m/(-n) are always equal to -(m/n), m%(-n) is equal to
    m%n, and (-m)%n is equal to -(m%n)				P196

    -21 % -8; 	/* result is -5 */		P196


> there are no const references. A reference is not an object,   	P97
  References to const

> The Member Access Operators
      (*p).size() == p->size()		P208

> Lvalues and Rvalues ??	P190


> Remember That Operands Can Be Evaluated in Any order      P207
  while(beg != s.end() && !isspace(*beg))
    *beg = toupper(*beg++);

> exercise 4.24 	P211

> wraps around 	P66

> exercise 4.25 	P216

> const_cast	P225

> const char *cp;					P225
    // error: static_cast can't cast away const
   char *q = static_cast<char*>(cp);
   static_cast<string>(cp);       // ok: converts string literal to string
   const_cast<string>(cp);     // error: const_cast only changes constness

> reinterpret_cast			P226

> Operator Precedence Table		P228

> Variable Definitions inside the Body of a switch	??	P246

>  '>>' operator will omit whitespace characters	exercise 5.11	P247

> exercise 5.13		P247

> We can only default initialize (§ 2.2.1, p. 43) exception, bad_alloc, and
bad_cast objects; it is not possible to provide an initializer for objects of these
exception types. 	??		P264

  We can initialize those objects from either a string or a C-style string,
  but we cannot default initialize them	??     	P264

> "hello"     const char*       P270

> Local static Objects          P272

> The source file that defines a function should include the header that
    contains that function’s declaration            P274

> Compiling and Linking Multiple Source Files       P275





> Using Reference Parameters to Return Additional Information ??	P279


> exercise6.18	P284

> int main(int argc, char **argv)   indicating that argv points to a char*.		P289
  int main(int argc, char *argv[])  argv, is an array of pointers to C-style character strings
    exercise 6.25		P290
    exercise 6.26

> Exercise 6.29	P293
   use a reference as the loop control variable.
   So that we don't need to copy the value from the initializer_list.

> Never Return a Reference or Pointer to a Local Object     P296

> Exercise 6.33 	P300

> Returning a Pointer to an Array       P301
    typedef int arrT[10];
    using arrtT = int[10];
    arrT* func(int i);

> exercese 6.37           p303

> exercise 6.46     P316

> Aids for debugging      P316
  The NDEBUG Preprocessor Variable      P317

> Exercise 6.47   Exercise 6.48

> Exercise 6.53:   Error, redeclare the same function, top-level `const` is ignored

> 6.3.3. Returning a Pointer to an Array          P301
    typedef int arrT[10];
    using arrtT = int[10];

> Returning a Pointer to Function               P327
    using PF = int(*)(int*, int)
    PF f1(int) == int (*f1(int))(int*, int)


>  Trailing Return Type  :               P302
    auto func(int i) -> int(*)[10]

    auto func(int i) -> string(&) [10]{
      return str
    }

    auto f1(int) -> int (*)(int*, int)


> Introducing this        P336
    this is a const pointer

> Using References to Avoid Copies            P279

> Programmers accustomed to programming in C often use pointer parameters
  to access objects outside a function. In C++, programmers generally use
  reference parameters instead            P278


> By default, the type of this is a const pointer to the nonconst version of the
class type. For example, by default, the type of this in a Sales_data member
function is Sales_data *const. Although this is implicit, it follows the normal
initialization rules, which means that (by default) we cannot bind this to a const
object (§ 2.4.2, p. 62). This fact, in turn, means that we cannot call an ordinary
member function on a const object.      P337

> 7.1.5. Copy, Assignment, and Destruction ??         P348

> Exercise 7.32       P366

> However, in a class, if a member uses a
name from an outer scope and that name is a type, then the class may not
subsequently redefine that name:        P370

> ConstRef::ConstRef(int ii): i(ii), ci(ii), ri(i) { }      P375

> Delegating Constructors       P378
    > Exercise 7.41:

> What may be less obvious is the impact on classes that have data members that do
not have a default constructor ??     P380

> exercise 7.43       P381

> Delegating Constructors       P378

> explicit Constructor      P383

> cannot use the copy form of initialization with an explicit constructor   P384

> Some of the library classes that we’ve used have single-parameter constructors    P385

> Literal Classes     P387

> associative containers.

> inline  P355      P313

> The iterator arithmetic operations listed in Table 3.7 (p.111) apply only     P423
  to iterators for string, vector, deque, and array

> Exercise 9.16         P435

> Exercise 9.22         P441

> Exercise 9.31         P452

> const string s = "hello,world";         //can't assign constant string to plain string;
  string str = s;                         Exercise 9.43

> Exercise 9.44       P462

> Exercise 9.51

> for (double i; std::cin >> i; vi.push_back(i)) {}

> Exercise 10.7

> stable_sort       P488

> When we need to define a return type for a lambda,
  we must use a trailing return type:
  [](int i) -> int
    { if (i < 0) return -i; else return i;  }       P500


> using std::placeholders::_1;
    using namespace std::placeholders;        P503


> Exercise 10.24
> Exercise 10.33


> Exercise 11.4
> Exercise 11.10
> Exercise 11.11

> Container Operations        P420

> Exercise 11.17:   A multiset doesn't have push_back memeber function.??

> Exercise 11.18

> Iterators       P423

> ++word_count.insert({word, 0}).first->second;       P544

> Using a key that is not already present adds an element with that
  key to the map   ??                     P546

> both will refer to the point at which the key can be inserted
  without disrupting the order                        P550

> If there is no such element, then beg refers to the first element
  with a key larger than search_item, which could be the off-the-end
  iterator. ??          P550


> direct initialization         P384


> Introducing const Member Functions      P337
  std::string isbn() const { return this->bookNo; }
// pseudo-code illustration of how the implicit this pointer is used
// this code is illegal: we may not explicitly define the this pointer ourselves
// note that this is a pointer to const because isbn is a const member
std::string Sales_data::isbn(const Sales_data *const this)
{ return this->isbn; }


> example_12.1.6
  Exercise 12.19:       P594
  error: class StrBlobPtr' is incomplete


> Although we can use empty parentheses to value initialize the elements of an array,
we cannot supply an element initializer inside the parentheses. The fact that we
cannot supply an initial value inside the parentheses means that we cannot use auto
to allocate an array          p597


> Exercise 12.23        P600
> Exercise 12.32        P612


> Exercise 13.5         P620
> Exercise 13.13        P626

> string dots(10, '.');                 // direct initialization
  string s(dots);                       // direct initialization
  string s2 = dots;                     // copy initialization
  string null_book = "9-999-99999-9";   // copy initialization
  string nines = string(100, '9');      // copy initialization            P618


> Exercise 13.15:

> The Copy-Control Members May Be Synthesized as Deleted          P632

> The Synthesized Move Operations           P666

> Exercise 13.28                          P641

> std::string isbn() const { return this->bookNo; }             P337


> Default Arguments and Constructors          P376
> The Role of the Default Constructor         P379
    Sales_data() = default;                 //default constructor
    Sales_data(std::string s = ""): bookNo(s) { }


> example_13.4            P650

> Figure 13.2. StrVec Memory Allocation Strategy        P651

> Default Arguments         P310

> Exercise 13.39
> Exercise 13.40          P658    StrVec(initializer_list<string> il): StrVec()
> Exercise 13.43
> Exercise 13.44                  String(const char *s):String()


> Reference Returns Are Lvalues                         P298

> Exercise 13.46:                               P662


> copy initialize: insert or push member
  direct initialized : emplace member             P618


> NoCopy                                          P630


> Exercise 13.56:
Foo Foo::sorted() const & {
  Foo ret(*this);           //ret is lvalue
  return ret.sorted();
}


> Exercise 13.57:
Foo Foo::sorted() const & {
  return Foo(*this).sorted();           //Foo(*this) is rvalue
}


> Exercise 13.58:
  vector<int> &getVec()

> Exercise 14.16              P696

> Exercise 14.21                  P699
      // By using operator+ do the actual addition, the statements in operator+
      // remain same. But in operator+=, we will create a temporary object and call
      // assignment operator, which leads to much more work than the other version.
      Sales_data &Sales_data::operator+=(const Sales_data &rhs) {
        *this = *this + rhs;
        return *this;
      }

      Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs) {
        Sales_data sum = lhs;
        sum.units_sold += rhs.units_sold;
        sum.revenue += rhs.revenue;
        return sum;
      }



> Subscripts and Pointers                     P173

> Pointers Are Iterators                      P169
> Pointer Arithmetic                          P170

> Exercise 14.35                              P708
> Exercise 14.36


> Binding Arguments                   P501

> Exercise 14.38                      P711
> Exercise 14.41

> 10.4.2. iostream Iterators            P508

> Exercise 14.43:               P713
    captures variables in main:


> Caution: Avoid Overuse of Conversion Functions      P719

> Exercise 14.45                                        P721
  ambiguous overload for 'operator+'

> Exercise 14.50-51                   P727

> subobject                 P737

> A base object that is not part of a derived object has only the members
  defined by the base class; it doesn't have the members defined by
  the derived class.  ??            P744

> resulting in an infinite recursion??    P751

> Derived-to-Base Conversion          yes     P737
> Conversion from Base to Derived     no      P744

> Each Bulk_quote object has three subobjects: an (empty)             P754
  Bulk_quote part, a Disc_quote subobject, and a Quote subobject.


>  struct B {                                         P750
    virtual void f1(int) const;
    virtual void f2();
    void f3();
  };

  struct D1 : B {
    void f1(int) const override; // ok: f1 matches f1 in the base
    void f2(int) override; // error: B has no f2(int) function
    void f3() override; // error: f3 not virtual
    void f4() override; // error: B doesn't have a function named f4
  };

  struct D2 : B {
      // inherits f2() and f3() from B and overrides f1(int)
      void f1(int) const final;   // subsequent classes can't override f1 (int)
  };

  struct D3 : D2 {
    void f2(); // ok: overrides f2 inherited from the indirect base B
    void f1(int) const; // error: D2 declared f2 as final
  };


> Accessibility of Derived-to-Base Conversion         P758


> Exercise 15.18~20
> Exercise 15.21                      P762

> Bulk_quote bulk;                                  P763
  Bulk_quote *bulkP = &bulk; // static and dynamic types are the same
  Quote *itemP = &bulk; // static and dynamic types differ
  bulkP->discount_policy(); // ok: bulkP has type Bulk_quote*
  itemP->discount_policy(); // error: itemP has type Quote*

> The reference to mem inside get_mem is resolved to the name inside Derived    P764

> If the derived class defines a constructor with the same parameters as a
  constructor in the base, then that constructor is not inherited    ??


> Copy-and-Swap Assignment Operators and Move             P669

> Using References to Avoid Copies                  P279

> multiset<Sales_data, decltype(compareIsbn)*>bookstore(compareIsbn);     P535

> std::multiset<std::shared_ptr<Quote>, decltype(compare)*>items{compare};    P780

> 3.1. Namespace using Declarations               P123

> 10.4.2.iostream Iterator            P508

> 9.3.6. Container Operations May Invalidate Iterators      P449
> 9.5. Additional string Operations     P457
> 9.5.3.string Search Operations        P463

> 15.8. Containers and Inheritance        P778

> Exercise 15.41          P799

>  Conversions between strings and Numbers      P467
      to_string(val)
      stoi

> Character and Character String Literals       P69

> General and Specific Template Friendship      P819

> Simplifying Use of a Template Class Name inside Class Code      P817

> exercise 16.11            P823
> Exercise 16.14:


> forward declarations needed for friend declarations in Blob     P819
> friend bool operator==<T>(const Blob<T>&, const Blob<T>&);      P819
> Exercise 16.14:   P823

> 13.4. A Copy-Control Example            P645

> array: No Copy or Assignment            P164
> Understanding Complicated Array Declarations

> Caution: Smart Pointer Pitfalls         P586

> Using an Array to Initialize a vector       P178

> 16.1.5. Controlling Instantiations ??     P831
> Exercises Section 16.1.5          P834

> ...and Don’t Use get to Initialize or Assign Another Smart Pointer
  get()           P582


> Exercise 16.28              P835
  function<void(T*)>

> f3’s function parameter would be an rvalue reference to the type int&.
Ordinarily, we cannot (directly) define a reference to a reference     P848

>  X& &, X& &&, and X&& & all collapse to type X&
  The type X&& && collapses to X&&                  P848

> void f3<int&>(int& &&); // when T is int&, function parameter is int& &&    P849

> 14.8.1. Lambdas Are Function Objects        P709

> We use a class-type conversion when we use a C-style character string
where a library string is expected
  string s, t = "a value";  // character string literal converted to type string

>  const Reference is a Reference to const        P97

> Recursion         P299

> Exercise 16.61        P871

> bucket_count > size/max_load_factor   ??   P558

> Exercise 16.64      P878

> Key Concept: Ordinary Scope Rules Apply to Specializations    P873

> bitvec[0].flip();   // flip the value of the bit at position 0        P894
  ~bitvec[0];     // equivalent operation; flips the bit at position 0

>  ECMAScript regular-expression language           P908

> Escape Sequences            P69

> why you need two backlash               P900

> Exercise 17.21                  P910

> seek and tell functions will behave differently that in windows(CRLF) and unix(LF)                P939

>  It may not appear in a typedef or type alias.      P956

> Template Default Arguments and Class Templates      P827

> Exercise 18.14            P970

>  a placement new expression constructs an object but does
   not allocate memory.??         P1008

> exercise 19.3     P1011
 (b) B *pb = new B;
     C *pc = dynamic_cast< C* >(pb);      //fail


>  14.8.3. Callable Objects and function      P713

> Exercise 19.17          P1029
  (total.*total.Sales_data::avg)()

> sort(v.begin(), v.end(), compareIsbn);  //before using 'equal_range' must sort
  17.1.2. Using a tuple to Return Multiple Values         P887

> Exercise 19.19        P1032

> Exercise 19.23        P1042

> Bitwise AND , OR, and XOR Operators       P213

> decltype(*p) is int&.       P190

> The NDEBUG Preprocessor Variable
    _ _FILE_ _ string literal containing the name of the file           P317

> ::j to obtain the variable defined in global scope      P974

> 16.1.2. Class Templates           P811

> Avoid Storing the Iterator Returned from end        P451

> initializer_list          P291

> 10.3.2. Lambda Expressions      P489

> 6.3.3. Returning a Pointer to an Array    P301

> 6.2.4. Array Parameters   P283

> & or &&, indicating that this may point to an rvalue or lvalue      P677

> string name{ "cpluspluser" };       //std::initializer_list to initialize the string with 

> Old-Style Casts
    Depending on the types involved, an old-style cast has the same behavior as a
    const_cast, a static_cast, or a reinterpret_cast. When we use an old-style
    cast where a static_cast or a const_cast would be legal
    
    char *pc = (char*) ip; // ip is a pointer to int

