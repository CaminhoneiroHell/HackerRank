// SymbolMangling.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// To avoid symbol mangling use extern "C" when declaring your function
#include "pch.h"
#include "stdio.h"
#include <iostream>
#include <typeinfo>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <array>
#include <numeric>
#include <map>
#include <ostream>
#include <memory>
#include <valarray>
#include <string>
#include <cassert>
#include <stdexcept>
#include <exception>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::abs;
using std::vector;
using std::array;
using std::to_string;
std::ostream operator<<(const std::ostream& lhs, const string& cs);


//*****************DATA STRUCTURES***************//

//***Vector
//
//**Popular methods
//
//push_back()				0(1) = constant
//[] brackets operator		0(1) = constant
//size()					0(1) = constant

void Vector()
{
	vector<int> v;					//v{}
	cout << v.size() << "\n";		//output 0
	v.push_back(20);			//v = {20}
	v.push_back(10);			//v = {20,10}
	v.push_back(10);			//v = {20,10, 10}
	cout << v[1];					//output 10
	cout << v.size();				//output 3
};


//***Set
//
//**Popular methods
//
//insert()				0(logn)
//find()				0(logn)
//size()				0(1) = constant

#include <set>
using std::set;
void Set()
{
	set<int> s;									//s{}
	cout << s.size();							//outputs 0
	s.insert(20);								//s = {20}
	s.insert(10);								//s = {10, 20}
	s.insert(10);								//s = {10, 20}
	auto it = s.find(10);						//it is an iterator that points to 10
	cout << (it != s.end() ? " FOUND" : " ");	//outputs FOUND
	cout << s.size();							//output 2
}


//***Unordered Set
//
//**Popular methods
//
//insert()				0(1)
//find()				0(1)
//size()				0(1) = constant


#include <unordered_set>
using std::unordered_set;
void UnorderedSet()
{
	unordered_set<int> s;							//s{}
	cout << s.size();								//outputs 0
	s.insert(20);								//s = {20}
	s.insert(10);								//s = {10, 20}	//Could be in any order//
	s.insert(10);								//s = {10, 20}
	auto it = s.find(10);						//it is an iterator that points to 10
	cout << (it != s.end() ? " FOUND" : " ");		//outputs FOUND
	cout << s.size();								//output 2
}


//***Map
//
//**Popular methods
//
//insert()					0(logn)	insert using make_pair
//find()					0(logn)	returns pair
//[] brackets operations	0(logn)	returns ref to value
//size()					0(1)

using std::map;
using std::make_pair;

void Map()
{
	map<int, int> m;							//m={}
	cout << m.size();							//outputs 0
	m.insert(make_pair(20, 1));					//m={(20,1)}
	m.insert(make_pair(10, 1));					//m={(10,1), (20,1)}
	m[10]++;									//m={(10,2), (20,1)}
	auto it = m.find(10);					//it is an iterator that points to (10, 2)
	cout << (it != m.end() ? it->second : 0);	//outputs 2
	auto it2 = m.find(20);				//it is an iterator that points to (20, 1)
	cout << (it2 != m.end() ? it2->first : 0);	//outputs 20
	cout << m.size();							//outputs 2		
}


//***Unordered Map
//
//**Popular methods
//
//insert()					0(1)	insert using make_pair
//find()					0(1)	returns pair
//[] brackets operations	0(1)	returns ref to value
//size()					0(1)

#include<unordered_map>
using std::unordered_map;
void UnorderedMap()
{
	unordered_map<int, int> m;					//m={}
	cout << m.size();							//outputs 0
	m.insert(make_pair(20, 1));					//m={(20,1)}
	m.insert(make_pair(10, 1));					//m={(10,1), (20,1)}	//Could in any order
	m[10]++;									//m={(10,2), (20,1)}
	auto it = m.find(10);					//it is an iterator that points to (10, 2)
	cout << (it != m.end() ? it->second : 0);	//outputs 2
	auto it2 = m.find(20);				//it is an iterator that points to (20, 1)
	cout << (it2 != m.end() ? it2->first : 0);	//outputs 20
	cout << m.size();							//outputs 2		
}

//**************STACK
//			LIFO data structure
//**Popular methods
//
//push()			0(1)*  the star is because push complexity is acctually equivalent to the push_back on the line container 
//pop()				0(1)
//top()				0(1)
//size()			0(1)

#include<stack>

using std::stack;

void Stack()
{
	stack<int> s;
	cout << s.size(); //Outputs 0
	s.push(1);
	s.push(2);
	cout << s.top(); //outputs 2
	s.pop();
	cout << s.top(); //outputs 1
	cout << s.size();//outputs 1
};

//**************QUEUE
//			FIFO data structure
//**Popular methods
//
//push()			0(1)* 
//pop()				0(1)
//front()			0(1)
//size()			0(1)

#include <queue>
using std::queue;

void Queue()
{
	queue<int>q;
	cout << q.size();//0
	q.push(1);
	q.push(2);
	cout << q.front();//1
	q.pop();
	cout << q.front();//2
	cout << q.size();//1
};

//**************PRIORITY QUEUE
//Excentially a Heap
//
//**Popular methods
//
//push()			0(logn) When you call push you make 1 call to push_back(), 1 call to push_heap()
//pop()				0(logn) 1 call to pop_heap(), 1 call to pop_back()
//top()				0(1)
//size()			0(1)

#include <concurrent_priority_queue.h>
using std::priority_queue;

void PriorityQueue()
{
	priority_queue<int> pq;
	cout << pq.size();	//0
	pq.push(3);
	pq.push(1);
	pq.push(2);
	cout << pq.top();	//3
	pq.pop();
	cout << pq.top();	//2 - It shows the number by priority greater to lower.
	cout << pq.size();	//2
};


//***Multi Set
//
//**Popular methods
//
//insert()				0(logn)
//find()				0(logn)
//size()				0(1) 

using std::multiset;

void MultiSet()
{
	multiset<int> ms;								//s{}
	cout << ms.size();								//outputs 0
	ms.insert(1);								//s = {1}
	ms.insert(2);								//s = {1, 2}	
	ms.insert(1);								//s = {1, 1, 2} //Auto sort order
	auto it = ms.find(1);
	cout << (it != ms.end() ? " FOUND" : " ");		//outputs FOUND
	cout << ms.size();								//output 3
};

//***MultiMap
//
//**Popular methods
//
//insert()					0(logn)	insert using make_pair
//find()					0(logn)	returns pair
//size()					0(1)
using std::multimap;
void MultiMap()
{
	multimap<int, int> mm;					//m={}
	cout << mm.size();						//outputs 0
	mm.insert({ 1,2 });						//mm={(1,2)}
	mm.insert({ 2,4 });						//mm={(1,2), (2,4)}
	mm.insert({ 1,3 });						//mm={(1,2), (1,3), (2,4)}	//Auto sort order
	auto it = mm.find(2);
	cout << (it != mm.end() ? it->second : 0);	//outputs 4
	cout << mm.size();							//outputs 3		
}

//*****************ALGORITHMS***************//
//
//
//
//
//*** std::sort
//	This is an algorithm with linearithmic time
//complexity [0(nlogn)] that you can use to order the
//elements of container from begin to end. The ordering by default is ascendiing for numeric values
//and lexicographical ascending for string values
//Ordering of equivalent elements are guaranteed to keep there same order.

void Sort() {
	vector<int> v{ 3,5,1,2,4,5,3,0 };
	sort(begin(v), end(v)); //Sort in order
	sort(begin(v), begin(v) + 2); //Sort in order until the third element

	//Test
	/*for (int i = 0; i < v.size(); i++)
		cout << v[i];*/
}


//*** std::binary_search
//	This is an algorithm with logarithmic time
//complexity [0(nlogn)] that will return true if the
//value searched for exists in the sorted sequence
//or at least partitioned withg respect to the value searched for
void BinarySearch() {
	vector<int> v = { 1,3,5,7 };
	cout << (binary_search(begin(v), end(v), 3) ? "Found" : "NotFound"); //Outputs found
	cout << (binary_search(begin(v), end(v), 4) ? "Found" : "NotFound"); //Outputs notfound
}

//*** std::lower_bound
//	This is an algorithm with logarithmic time
//complexity [0(logn)] that will return an iterator to
//the first element equal to or greater than a given
//value in a sorted sequence.
//
//In resume: "first equal to or greater than"


void LowerBound() {
	vector<int> v = { 1,3,3,5,7 };

	auto it = lower_bound(begin(v), end(v), 3);
	auto it2 = lower_bound(begin(v), end(v), 4);
	auto it3 = lower_bound(begin(v), end(v), 8);

	cout << (it != end(v) ? to_string(*it) : "Not Found"); //outputs 3
	cout << (it2 != end(v) ? to_string(*it2) : "Not Found"); //outputs 5
	cout << (it3 != end(v) ? to_string(*it3) : "Not Found"); //outputs Not Found


	cout << distance(begin(v), it); //outputs 1
};


//*** std::upper_bound
//	This is an algorithm with logarithmic time
//complexity [0(logn)] that will return an iterator to
//the first element greater than a given
//value in a sorted sequence.
//
//In resume: "first greater than"
void UpperBound() {
	vector<int> v = { 1,3,3,5,7 };

	auto it = upper_bound(begin(v), end(v), 3);
	auto it2 = upper_bound(begin(v), end(v), 4);
	auto it3 = upper_bound(begin(v), end(v), 8);

	cout << (it != end(v) ? to_string(*it) : "Not Found"); //outputs 5
	cout << (it2 != end(v) ? to_string(*it2) : "Not Found"); //outputs 5
	cout << (it3 != end(v) ? to_string(*it3) : "Not Found"); //outputs Not Found
};

//***First less than
//Create an algorithm to fill the quest above...
template<typename ForwardIterator, typename T>
ForwardIterator first_less_than(ForwardIterator first, ForwardIterator last, T value) {
	auto it = lower_bound(first, last, value);
	return (it == first ? last : --it);
} 

void LessBound() {
	vector<int> v = { 1,3,3,5,7 };

	auto it = first_less_than(begin(v), end(v), 3);
	auto it2 = first_less_than(begin(v), end(v), 4);
	auto it3 = first_less_than(begin(v), end(v), 8);

	cout << (it != end(v) ? to_string(*it) : "Not Found"); //outputs 1
	cout << (it2 != end(v) ? to_string(*it2) : "Not Found"); //outputs 3
	cout << (it3 != end(v) ? to_string(*it3) : "Not Found"); //7
}






//Hacker Rank:
void passByReference(int* x)
{
	*x = 66;
}

//****PRINT TYPES
void PrintTypesOperation()
{

	//Int("%d") : 32 Bit integer
	//Long("%ld") : 64 bit integer
	//Char("%c") : Character type
	//Float("%f") : 32 bit real value
	//Double("%lf") : 64 bit real value

	//Input:
	//458873627 37274594125879112 g -79720.555 7441739.542437971

	int a; long b; char c; float d; double e;
	cin >> a >> b >> c >> d >> e;
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
	cout.precision(3);
	cout << std::fixed << d << endl;
	cout.precision(9);
	cout << std::fixed << e << endl;
}

//****BOOLEANS
void BooleanOperations(){
//	int n;
//	cin >> n;
//	string name1 = "One", name2 = "Two", name3 = "Three", name4 = "Four",
//		name5 = "Five", name6 = "Six", name7 = "Seven", name8 = "Eight", name9 = "Nine",
//	MessageOutput1 = "Greater than nine";
//	if (1 <= n && n <= 9)
//	{
//		switch (n)
//		{
//		case 1:
//			cout << name1;
//			break;
//		case 2:
//			cout << name2;
//			break;
//		case 3:
//			cout << name3;
//			break;
//
//		case 4:
//			cout << name4;
//			break;
//
//		case 5:
//			cout << name5;
//			break;
//
//		case 6:
//			cout << name6;
//			break;
//
//		case 7:
//			cout << name7;
//			break;
//
//		case 8:
//			cout << name8;
//			break;
//
//		case 9:
//			cout << name9;
//			break;
//		default:
//			cout << "Error";
//		}
//	}
//	else if (n > 9)
//		cout << MessageOutput1;
};

//****LOOPS
void LoopOperation()
{
	int a, b;

	cin >> a >> b;

	for (; a < (b + 1); ++a)
	{
		//cout << a << "\n\n\n\n";
		// int *n_ptr{ &n };
		//cout << *n_ptr;

		switch (a)
		{
			case 1:
				cout << "one" << "\n";
				break;
			case 2:
				cout << "two" << "\n";
				break;
			case 3:
				cout << "three" << "\n";
				break;

			case 4:
				cout << "four" << "\n";
				break;

			case 5:
				cout << "five" << "\n";
				break;

			case 6:
				cout << "six" << "\n";
				break;

			case 7:
				cout << "seven" << "\n";
				break;

			case 8:
				cout << "eight" << "\n";
				break;

			case 9:
				cout << "nine" << "\n";
				break;

			default:
				if (a > 9)
				{
					if (a % 2 != 0) { cout << "odd" << "\n"; }
					else { cout << "even" << "\n"; }
				}
			
		}
	};
}

//****FUNCTIONS
int max_of_four(int a, int b, int c, int d) {
	std::vector<int> v = { a,b,c,d };
	std::sort(begin(v), end(v), [](int elem1, int elem2) {return elem1 > elem2; });
	cout <<	v[0];
	return v[0];
}

//****POINTERS
int increment(int*v)
{
	return ++(*v);
}

void PointersOperation()
{
	int value = 918;
	int * value_ptr = &value;
	cout << *value_ptr;
	increment(&value);
	cout << value;
}

void update(int *a, int *b) {
	const int sum = (*a) + (*b);
	const int sub = abs((*a) - (*b));
	*a = sum;
	*b = sub;
}

//****ARRAYS
void ArraysOperation()
{
	int size;
	cin >> size;
	int elemToEnter;
	std::vector<int> v;

	for (int i = 0; i < size; ++i)
	{
		cin >> elemToEnter;
		v.push_back(elemToEnter);
	}

	for (const auto& value : v) {
		std::cout << value << " ";
	}
	std::cout << '\n';

	std::vector<int> destination(size);
	std::reverse_copy(std::begin(v), std::end(v), std::begin(destination));
	for (const auto& value : destination) {
		std::cout << value << " ";
	}
	std::cout << '\n';
}

std::ostream operator<<(const std::ostream& lhs, const vector<int>& is);

void VariableSizedArrays()
{
	//n = arrays q = queries
	std::map<vector<int>, vector<int>> nq;
	std::map<char, int> mymap;

	int n = 2;
	int q = 2;
	//cin >> n; cin >> q; cout << "\n";
	nq.insert(std::pair <vector<int>, vector<int>>(n , q));
	nq.insert(std::pair <vector<int>, vector<int>>(2, 4));
	nq.insert(std::pair <vector<int>, vector<int>>(6, 7));
	nq.insert(std::pair <vector<int>, vector<int>>(1, 5));

	int size;
	cin >> size;
	for (auto elem : nq)
	{
		int elemToEnter;
		cin >> elemToEnter;
		//elem.first.push_back(elemToEnter);
		vector<int> temp = elem.first;
		//std::cout << value << " ";

		//elem.first[0] = 213;
	}

	std::map<vector<int>, int> arraysMap; //Store all elem arrays
	int arrayNumbers = -1;
	for (auto elem : nq)
	{
		arrayNumbers++;
		//cout << elem.first[0];
		arraysMap.insert(std::pair <vector<int> ,int>(elem.first[arrayNumbers] /* must pass vector n */, arrayNumbers));
	}

	std::map<int, int> queriesMap; //Store all elem queries
	int queryNumbers = -1;
	for (auto elem : nq)
	{
		queryNumbers++;
		//cout << elem.second[0];
		queriesMap.insert(std::pair <int, int>(elem.second[queryNumbers], queryNumbers));
	}
	cout << "\n";
}

void VariableSizedArray2()
{
	std::map<char, int> mymap;

	// first insert function version (single parameter):
	mymap.insert(std::pair<char, int>('a', 100));
	mymap.insert(std::pair<char, int>('z', 200));

	//std::pair<std::map<char, int>::iterator, bool> ret;
	//ret = mymap.insert(std::pair<char, int>('z', 500));
	//if (ret.second == false) {
	//	std::cout << "element 'z' already existed";
	//	std::cout << " with a value of " << ret.first->second << '\n';
	//}

	//// second insert function version (with hint position):
	std::map<char, int>::iterator it = mymap.begin();
	mymap.insert(it, std::pair<char, int>('b', 300));  // max efficiency inserting
	mymap.insert(it, std::pair<char, int>('c', 400));  // no max efficiency inserting

	//// third insert function version (range insertion):
	//std::map<char, int> anothermap;
	//anothermap.insert(mymap.begin(), mymap.find('c'));

	// showing contents:
	std::cout << "mymap contains:\n";
	for (it = mymap.begin(); it != mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	/*std::cout << "anothermap contains:\n";
	for (it = anothermap.begin(); it != anothermap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';*/
}

//Worked
void VariableSizedArrays4(){

	// get length of array 'a' and number of queries
	int n, q;
	cin >> n >> q;

	// create vector of vectors
	vector<vector<int>> a(n);

	// fill each 2D vector i with k_i values
	for (int i = 0; i < n; i++) {
		// get the length k of the vector at a[i]
		int k;
		cin >> k;

		// fill the vector with k values		
		a[i].resize(k);
		for (int j = 0; j < k; j++) {
			cin >> a[i][j]; //Add elem on vector i inside the vector a
		}
	}

	// run queries on a
	for (int q_num = 0; q_num < q; q_num++) {
		// get i, j as the 'query' to get a value from a
		int i, j;
		cin >> i >> j;
		cout << a[i][j] << endl; //RunqueryOnElem
	}
}

//*****PRE PROCESSOR 
#define LIMIT 5 
#define AREA(a, b)(a * b)
#define DIFFERENCE(a, b)(a - b)
#define str(x) #x
void PreprocessorSolution()
{

	cout << str(test);


	//int size;
	//cin >> size;
	//vector<int> elems(size);
	//for(int i = 0; i < size; ++i)
	//{
	//	int elem;
	//	cin >> elem;
	//	elems.push_back(elem);
	//}


	//auto max = *std::max_element(begin(elems), end(elems));
	//auto min = *std::min_element(begin(elems), end(elems));

	//cout << DIFFERENCE(max, min);

}


#define foreach(v, i) for (int i = 0; i < v.size(); ++i)
#define toStr(x) #x
#define io(v) cin >> v
#define FUNCTION(name,operator) inline void name(int &current, int candidate) {!(current operator candidate) ? current = candidate : false;}
#define INF (unsigned)!((int)0)

#if !defined toStr || !defined io || !defined FUNCTION || !defined INF
#error Missing preprocessor definitions
#endif 

FUNCTION(minimum, < )
FUNCTION(maximum, > )

void PreprocessorSolution2() {
	int n; cin >> n;
	vector<int> v(n);

	foreach(v, i) {
		io(v)[i];
	}

	int mn = INF;
	int mx = INF; // -INF

	foreach(v, i) {
		minimum(mn, v[i]);
		maximum(mx, v[i]);
	}

	int ans = mx - mn;
	cout << toStr(Result = ) << ' ' << ans;
}

//*****INLINE
class InlineExample {
	int a, b;
public:
	inline void initialize(int x, int y) { a = x; b = y; };
	void display() { cout << a << " " << b << "\n" ; } //automatic inline
};

	
//*****OPERATOR OVERLOAD
class Matrix	
{
public:
	vector<vector<int>> a;
	Matrix& operator + (const Matrix &other)
	{
		for(int i = 0; i < other.a.size(); i++)
		{
			for(int j = 0; j < other.a[0].size(); j++)
			{
				this->a[i][j] = this->a[i][j] + other.a[i][j];
			}
		}
		return *this; // Return a clone of the component of this current object witch is on the stack
	};

///Old solution
//	vector<int> resultVec1, resultVec2;
//public:
//	vector<vector<int>> a;
//
//	Matrix() = default;
//
//	explicit Matrix(const vector<vector<int>>& vectors)
//		: a(vectors)
//	{
//
//	}
//
//	Matrix *pMatrix;
//
//	Matrix operator +(Matrix const &other)
//	{
//		Matrix matrix;
//		pMatrix = &matrix;
//
//		unsigned n_size = this->a.size();
//
//		for (unsigned i = 0; i < n_size; i++)
//		{
//			unsigned m_size = a[i].size();
//			for (unsigned j = 0; j < m_size; j++)
//			{
//				resultVec1.push_back(a[i][j]);
//				//cout << "\n" << "Returns: " << a[i][j] << "\n";
//			}
//		}
//
//		unsigned n_size2 = other.a.size();
//		for (unsigned i = 0; i < n_size2; i++)
//		{
//			unsigned m_size2 = other.a[i].size();
//			for (unsigned j = 0; j < m_size2; j++)
//			{
//				resultVec2.push_back(other.a[i][j]);
//				//cout << "\n" << "Returns: " << other.a[i][j] << "\n";
//			}
//		}
//
//		int result;
//		vector<int> glueVec;
//		unsigned n_size3 = resultVec1.size();
//		for (int i = 0; i < n_size3; i++)
//		{
//			result = resultVec1[i] + resultVec2[i];
//			glueVec.push_back(result);
//		}
//		matrix.a.push_back(glueVec);
//		return matrix;
//	};
//
//	~Matrix()
//	{
//		delete pMatrix;
//	};		

	
};

void OperatorOverload()
{
	int cases, k;
	cin >> cases;
	for (k = 0; k < cases; k++) //FOR
	{
		Matrix x;
		Matrix y;
		Matrix result;
		int n, m, i, j; //n & m rows and colums
		cin >> n >> m;
		for (i = 0; i < n; i++)//For
		{ 
			vector<int> b;	//Act like a glue for x
			int num;
			for (j = 0; j < m; j++) {
				cin >> num;
				b.push_back(num);
			}
			x.a.push_back(b);
		}
		for (i = 0; i < n; i++)//For 
		{ 
			vector<int> b; //Act like a glue for y
			int num;
			for (j = 0; j < m; j++) {
				cin >> num;
				b.push_back(num);
			}
			y.a.push_back(b);
		}

		result = x + y;
		for (i = 0; i < n; i++) {
			for (j = 0; j < m; j++) {
				cout << result.a[i][j] << " ";
			}
			cout << endl;
		}
	}
}

class Complex
{
public:
	int a, b;
	void input(string s)
	{
		int v1 = 0;
		int i = 0;
		while (s[i] != '+')
		{
			v1 = v1 * 10 + s[i] - '0';
			i++;
		}
		while (s[i] == ' ' || s[i] == '+' || s[i] == 'i')
		{
			i++;
		}
		int v2 = 0;
		while (i < s.length())
		{
			v2 = v2 * 10 + s[i] - '0';
			i++;
		}
		a = v1;
		b = v2;
	}
};

//*TO OUTPUT COMPLEX

#include <string>

Complex& operator +(Complex& clx, Complex& clx2)
{
	Complex complex;
	complex.a = clx.a + clx2.a;
	complex.b = clx.b + clx2.b;
	return complex;
};

std::ostream& operator<<(std::ostream& lhs, const Complex& rhs)
{
	return lhs << rhs.a << "+" << "i" << rhs.b;
};

//*More elaborated solution:

//constexpr Complex operator+(const Complex& lhs, const Complex& rhs) noexcept
//{
//	return { lhs.a + rhs.a, lhs.b + rhs.b };
//}
//
//template <class StreamT>
//constexpr StreamT& operator<<(StreamT& s, const Complex& c)
//{
//	return s << c.a << (c.b >= 0 ? "+" : "-") << "i" << c.b;
//}

void OverloadOperators_ComplexNumberCalculator()
{
	Complex x, y;
	string s1, s2;
	cin >> s1;
	cin >> s2;
	x.input(s1);
	y.input(s2);
	Complex z = x + y;
	cout << z << endl;
}


//*************STRINGS (to_string example)
class Demon
{
public:
	string a = "HAAAAAA";
	int len = a.size();
	int maxlen = a.max_size();
	char c = a[2];
	string b = "Satanas";
	int age;
	int *p_age = &age;

	int set_age(int age1) 
	{
		return age = age1;
	}

	std::string str1 = std::to_string(12.10);
	std::string str2 = std::to_string(9999);
	std::string str3 = std::to_string(age);

	string to_string() { return str3 + "," + str1; };
};


//***********CLASSES AND OBJECTS
class Student
{
	Student(const Student& student) {  }
	vector<int> scores;
public:
	Student() = default;
	void input()
	{
		for(int i = 0; i < 5; i++)
		{
			int temp;
			cin >> temp;
			scores.push_back(temp);
		}
	};

	int calculateTotalScore()
	{
		int temp = 0;
		int totalScore = 0;
		
		for(int i = 0; i < scores.size(); ++i)
		{
			if(i == 1)
			{
				totalScore += scores[i] + temp;
			}
			if (i >= 2)
			{
				totalScore += scores[i];
			}
			temp = scores[i];
		}

		return totalScore;
	}

};

void  ClassesAndObjectsOperations() {
	int n; // number of students
	cin >> n;
	const auto s = new Student[n]; // an array of n students

	for (auto i = 0; i < n; i++) {
		s[i].input();
	}

	 //calculate kristen's score
	const int kristen_score = s[0].calculateTotalScore();

	// determine how many students scored higher than kristen
	int count = 0;
	for (int i = 1; i < n; i++) {
		int total = s[i].calculateTotalScore();
		if (total > kristen_score) {
			count++;
		}
	}

	// print result
	cout << count;
}


//****Box It!
//Implement the class Box  
//l,b,h are integers representing the dimensions of the box

// The class should have the following functions : 

// Constructors: 
// Box();
// Box(int,int,int);
// Box(Box);


// int getLength(); // Return box's length
// int getBreadth (); // Return box's breadth
// int getHeight ();  //Return box's height
// long long CalculateVolume(); // Return the volume of the box

//Overload operator < as specified
//bool operator<(Box& b)

//Overload operator << as specified
//ostream& operator<<(ostream& out, Box& B)

class Box
{
	//l,b,h are integers representing the dimensions of the box
private:
	int l=0, b=0, h = 0;
public:

	// The class should have the following functions : 

	// Constructors: 
	// Box();
	// Box(int,int,int);
	// Box(Box);
	Box() = default;
	Box(int l, int b, int h) : l(l), b(b), h(h) {};
	Box(const Box& box)
	{
		l = box.getLength();
		b = box.getBreadth();
		h = box.getHeight();
	}
	// int getLength(); // Return box's length
	// int getBreadth (); // Return box's breadt h
	// int getHeight ();  //Return box's height
	int getLength() const{
		return l;
	};
	int getBreadth() const {
		return b;
	};
	int getHeight() const {
		return h;
	};
	// long long CalculateVolume(); // Return the volume of the box
	long long CalculateVolume() {
		return (long long)l*b*h;
	}

	//Overload operator < as specified
	//bool operator<(Box& b)
	friend bool operator <(Box& A, Box& B)
	{
		if ((A.l < B.l) || ((A.b < B.b) && (A.l == B.l)) || ((A.h < B.h) && (A.l == B.l) && (A.b == B.b))) {
			return true;
		}
		else {
			return false;
		};

	}

	//Overload operator << as specified
	friend std::ostream& operator<<(std::ostream& out, Box& B)
	{
		out << B.getLength() << " " << B.getBreadth() << " " << B.getHeight();
		return out;
 	}
};

void checkBox()
{
	int n;
	cin >> n;
	Box temp;
	for (int i = 0; i < n; i++)
	{
		int type;
		cin >> type;
		if (type == 1)
		{
			cout << temp << endl;
		}
		if (type == 2)
		{
			int l, b, h;
			cin >> l >> b >> h;
			Box NewBox(l, b, h);
			temp = NewBox;
			cout << temp << endl;
		}
		if (type == 3)
		{
			int l, b, h;
			cin >> l >> b >> h;
			Box NewBox(l, b, h);
			if (NewBox < temp)
			{
				cout << "Lesser\n";
			}
			else
			{
				cout << "Greater\n";
			}
		}
		if (type == 4)
		{
			cout << temp.CalculateVolume() << endl;
		}
		if (type == 5)
		{
			Box NewBox(temp);
			cout << NewBox << endl;
		}

	}
}
#include <algorithm>
//*********Vector-Sort 
void VectorSortOperations()
{
	vector<int> v;
	int size = v.size();
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		v.push_back(temp);
	};

	std::sort(std::begin(v), std::end(v));

	for(int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	};
}

void VectorErraseOperations()
{
	vector<int> v;
	int size;
	cin >> size;
	for (int i = 0; i < size; i++) {
		int b = 0;
		cin >> b;
		v.push_back(b);
	};
	int r1;
	cin >> r1;
	v.erase(v.begin() + r1 - 1);
	int b, e, r2;
	cin >> r2;
	cin >> b >> e;
	v.erase(v.begin() + b - 1, v.begin() + e - 1);

	for (int i = 0; i < size; i++) {
		cout << v[i];
	};
};

//**********Lower Bound - STL
void LowerBoundSTLOperations()
{
	vector<int> v;
	int size;
	cin >> size;
	for(int i = 0; i < size; i++)
	{
		int temp= 0;
		cin >> temp;
		v.push_back(temp);
	};

	std::sort(v.begin(), v.end());

	std::vector<int>::iterator low;
	int queries = 0;
	cin >> queries;
	for(int i = 0; i < queries; i++)
	{
		int numToSearch = 0;
		cin >> numToSearch;

		low = std::lower_bound(begin(v), end(v), numToSearch);
		if (numToSearch == (low - v.begin()))
			cout << "Yes " << (low - v.begin());
		else
			cout << "No " << (low - v.begin());
	}
}


void TestLowerBound()
{
	vector<int> v;
	int s, n;
	cin >> s;
	for (int i = 0; i < s; i++) {
		cin >> n;
		v.push_back(n);
	};
	int qn, q;
	cin >> qn;
	for (int i = 0; i < qn; i++) {
		cin >> q;
		auto it = lower_bound(begin(v), end(v), q);
		cout << (*it == q ? "Yes " + to_string(distance(begin(v), it) + 1) + "\n" : "No " + to_string(distance(begin(v), it) + 1) + "\n");
	}
};


//************SET
void SetChallenge() {
	int q;
	cin >> q;
	set<int> s;
	for (int i = 0; i < q; i++) {
		int x;
		cin >> x;
		if (x == 1) {	//Add an element to Set
			int y = 0;
			cin >> y;
			s.insert(y);
		}
		else if (x == 2) {	//erase an element to Set
			int y = 0;
			cin >> y;
			s.erase(y);
		}
		else if (x == 3) {	//Search an element in set
			int y;
			cin >> y;
			auto it = s.find(y);						//it is an iterator that points to 10
			cout << (it != s.end() ? " Yes" : "No ");	//outputs FOUND

		}
		
	}


}

//************MAP
void MapChallenge() {

	//map<int, int> m;							//m={}
	//cout << m.size();							//outputs 0
	//m.insert(make_pair(20, 1));					//m={(20,1)}
	//m.insert(make_pair(10, 1));					//m={(10,1), (20,1)}
	//m[10]++;									//m={(10,2), (20,1)}
	//auto it = m.find(10);					//it is an iterator that points to (10, 2)
	//cout << (it != m.end() ? it->second : 0);	//outputs 2
	//auto it2 = m.find(20);				//it is an iterator that points to (20, 1)
	//cout << (it2 != m.end() ? it2->first : 0);	//outputs 20
	//cout << m.size();							//outputs 2		

	map<string, int> m;
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		int type;
		cin >> type;
		if (type == 1) {
			//Create
			string name;
			int mark;
			cin >> name;
			cin >> mark;
			auto it = m.find(name);
			if (it != m.end()) {
				cout << "Here";
				it->second = it->second + mark;
			}
			else
				m.insert(make_pair(name, mark));
		}
		else if (type == 2) {
			//Delete
			string name;
			cin >> name;
			m.erase(name);
		}
		else if (type == 3) {
			//Read
			string name;
			cin >> name;
			auto it = m.find(name);				
			cout << (it != m.end() ? it->second : 0) << "\n";
		}
	}
}

//************DEQUE						---Incomplete 

#include<deque>
using std::deque;
void Deque() {

	deque<int> mydeque; //Creates a double ended queue of deque of int type
	
	int length = mydeque.size(); //Gives the size of the deque
	
	mydeque.push_back(1); //Pushes element at the end
	mydeque.push_front(2); //Pushes element at the beginning

	mydeque.pop_back(); //Pops element from the end
	mydeque.pop_front(); //Pops element from the beginning

	mydeque.empty(); //Returns a boolean value which tells whether the deque is empty or not

}

//************Classes

class Rectangle {
public:
	int width, height;
	void display() { cout << width << " " << height << "\n"; };
};

class RectangleArea : public Rectangle {
public:
	void read_input() {
		cin >> width >> height;
	};

	void display() {
		cout << width * height << "\n";
	};
};

//***************Exception Handling
using std::invalid_argument;
int largest_proper_divisor(int n) {
	if (n == 0) {
		throw invalid_argument("largest proper divisor is not defined for n=0");
	}
	if (n == 1) {
		throw invalid_argument("largest proper divisor is not defined for n=1");
	}
	for (int i = n / 2; i >= 1; --i) {
		if (n % i == 0) {
			return i;
		}
	}
	return -1; // will never happen
}


void process_input(int n) {
	try {
		int d = largest_proper_divisor(n);
		cout << "result=" << d << endl;
	}
	catch (const invalid_argument& ia) {
		cout << ia.what() << endl;
	}
	cout << "returning control flow to caller" << endl;
}

//******Inherited Code
class BadLengthException {
	int elem;
public:
	BadLengthException(int n) { elem = n; };
	int what() { return elem; };
};

bool checkUsername(string username) {
	bool isValid = true;
	int n = username.length();
	if (n < 5) {
		throw BadLengthException(n);
	}
	for (int i = 0; i < n - 1; i++) {
		if (username[i] == 'w' && username[i + 1] == 'w') {
			isValid = false;
		}
	}
	return isValid;
}

int InheritedOperations() {
	int T; cin >> T;
	while (T--) {
		string username;
		cin >> username;
		try {
			bool isValid = checkUsername(username);
			if (isValid) {
				cout << "Valid" << '\n';
			}
			else {
				cout << "Invalid" << '\n';
			}
		}
		catch (BadLengthException e) {
			cout << "Too short: " << e.what() << '\n';
		}
	}
	return 0;
};

//*********Accessing Inherited Functions
class A
{
public:
	A() {
		callA = 0;
	}
private:
	int callA;
	void inc() {
		callA++;
	}

protected:
	void func(int & a)
	{
		a = a * 2;
		inc();
	}
public:
	int getA() {
		return callA;
	}
};

class B
{
public:
	B() {
		callB = 0;
	}
private:
	int callB;
	void inc() {
		callB++;
	}
protected:
	void func(int & a)
	{
		a = a * 3;
		inc();
	}
public:
	int getB() {
		return callB;
	}
};

class C
{
public:
	C() {
		callC = 0;
	}
private:
	int callC;
	void inc() {
		callC++;
	}
protected:
	void func(int & a)
	{
		a = a * 5;
		inc();
	}
public:
	int getC() {
		return callC;
	}
};

class D: public A, public B, public C
{
	int val;
public:
	//Initially val is 1
	D()
	{
		val = 1;
	}

	//Implement this function
	void update_val(int &new_val)
	{
		val = new_val;
		A::func(new_val);
		B::func(new_val);
		C::func(new_val);	//In site I did this different dont know what is happening
	}
	//For Checking Purpose
	void check(int); //Do not delete this line.
};

void D::check(int new_val)
{
	update_val(new_val);
	cout << "Value = " << val << endl << "A's func called " << getA() << " times " << endl << "B's func called "
		<< getB() << " times" << endl << "C's func called " << getC() << " times" << endl;
}

//**********Virtual Functions
class Person {
protected:
	int age;
	string name;
public:
	virtual void getdata();
	virtual void putdata();
};

void Person::getdata() {};
void Person::putdata() {};

class Professor : public Person {
private:
	const int id;
	static int cur_id;
	string name;
	int publications, age;

public:

	Professor() : id(++cur_id)
	{};

	void getdata() override {
		cin >> this->name;
		cin >> this->age;
		cin >> this->publications;
	};

	void putdata() override {
		cout << name << " " << age << " " << publications << " " << this->id << "\n";
	};
};

int Professor::cur_id = 0;

class Student2 : public Person {
	const int id;
	static int cur_id;

	string name;
	int age;
	int mark[6];

public:

	Student2() : id(++cur_id)
	{};

	void getdata() override {
		cin >> this->name;
		cin >> this->age;

		for (int i = 0; i < 6; i++) {
			cin >> this->mark[i];
		};
	};

	void putdata() override {
		int sum = 0;
		for (int i = 0; i < 6; i++) {
			int previous = mark[i];
			sum += mark[i];
		}

		cout << name << " " << age << " " << sum << " " << id << "\n";
	};
};

int Student2::cur_id = 0;

void VirtualFuncOperations() {

	int val;
	const int n = 4; //The number of objects that is going to be created.
	Person *per[n];

	for (int i = 0; i < n; i++) {
		cin >> val;
		if (val == 1) {
			// If val is 1 current object is of type Professor
			per[i] = new Professor;
		}
		else per[i] = new Student2; // Else the current object is of type Student

		per[i]->getdata(); // Get the data from the user.
	}

	for (int i = 0; i < n; i++)
		per[i]->putdata(); // Print the required output for each object.


	for (int i = 0; i < n; i++)
	{
		delete per[i];//Clean memory
		per[i] = 0;
	}
}

//*******CLASS TEMPLATES
//Sum tempalte method
template <class T>
T sum(T a, T b)
{
	T result;
	result = a + b;
	return result;
}

//Multiply template class
template <class T>
class Multiply {
	T product1, product2;
public:
	Multiply(T arg1, T arg2) { product1 = arg1, product2 = arg2; };
	T Execute() { return product1 * product2; };
};

//Divide template class
template <class T>
class Divide {
	T element;
public:
	Divide(T arg) { element = arg; };
	T Execute() { return element / 2; };
};

// class template specialization:
template<>
class Divide<char>
{
	char element;
public:
	Divide(char arg) { element = arg; };
	char PrintElement() { return element; };
};

class Calculator {
	int e = 8;
	int s{ 0 };
	Divide<int> d = e;
	Multiply<int> m = { 3,3 };
public:
	void DivisorCalc() {
		cout << d.Execute() << "\n";
	}

	void SumCalc() {
		s = sum<int>(3, 5);
		cout << s << "\n";
	}

	void Multiply() {
		cout << m.Execute();
	}
};

//Exercise:
/*Write the class AddElements here*/
template <class T>
class AddElements
{
private:
	T element;
public:
	AddElements(T arg) { element = arg; };
	T add(T p) {
		return element + p;
	};
};

//specialization
template <>
class AddElements <string>
{
private:
	string element;
public:
	AddElements(string arg) { element = arg; };

	string concatenate(string p) {
		return element + p;
	};
};

void ClassTemplateOperations()
{
	int n, i;
	cin >> n;
	for (i = 0; i < n; i++) {
		string type;
		cin >> type;
		if (type == "float") {
			double element1, element2;
			cin >> element1 >> element2;
			AddElements<double> myfloat(element1);
			cout << myfloat.add(element2) << endl;
		}
		else if (type == "int") {
			int element1, element2;
			cin >> element1 >> element2;
			AddElements<int> myint(element1);
			cout << myint.add(element2) << endl;
		}
		else if (type == "string") {
			string element1, element2;
			cin >> element1 >> element2;
			AddElements<string> mystring(element1);
			cout << mystring.concatenate(element2) << endl;
		}
	}
}

//***************** Class Template Specialization
#include <iostream>
using namespace std;
enum class Fruit { apple, orange, pear };
enum class Color { red, green, orange };

template <typename T> struct Traits;

template<>
struct Traits<Color> {
	static string name(int index) 
	{
		string asnwer;
		switch (static_cast<Color>(index)) {
		case Color::red:
			asnwer = "red";
			break;
		case Color::green:
			asnwer = "green";
			break;
		case Color::orange:
			asnwer = "orange";
			break;
		default:
			asnwer = "unknown";
			break;
			break;
		};
		return asnwer;
	};
};

template<>
struct Traits<Fruit>
{
	enum class Fruit { apple, orange, pear };

	static string name(int index)
	{
		string asnwer;
		switch (static_cast<Fruit>(index)) {
		case Fruit::apple:
			asnwer = "apple";
			break;
		case Fruit::orange:
			asnwer = "orange";
			break;
		case Fruit::pear:
			asnwer = "pear";
			break;
		default:
			asnwer = "unknown";
			break;
		};
		return asnwer;
	};
};


void TemplateSpecializationOperations()
{
	int t = 0; std::cin >> t;

	for (int i = 0; i != t; ++i) {
		int index1; std::cin >> index1;
		int index2; std::cin >> index2;
		cout << Traits<Color>::name(index1) << " ";
		cout << Traits<Fruit>::name(index2) << "\n";
	}
}

//********************Debugging Messages Order
class Message {
private:
	static int cur_id;
	string text;
public:
	int id;
	//Message() {};
	//Message(const Message& msg) : id(cur_id++) {};
	Message() : id(cur_id++) {};	

	const string& get_text() {
		return text;
	}

	string set_text(const string& elem) {
		return text = elem;
	}

	bool operator <(const Message& a) {
		if (a.id > this->id) return true;
		if (a.id < this->id) return false;
		return 0;
	};
};

int Message::cur_id = 0;

class MessageFactory {
public:
	MessageFactory() {}
	Message create_message(const string& text) {
		Message m;
		m.set_text(text);
		return m;
	}
};

//A solution using a precise clock (I really liked that one, and it is better)
//#include <chrono>
//
//class Message {
//	string msg;
//	chrono::time_point<chrono::high_resolution_clock> sent_at;
//public:
//	Message(string msg) : msg(msg) { sent_at = chrono::high_resolution_clock::now(); }
//	const string& get_text() {
//		return msg;
//	}
//
//	friend bool operator <(Message& left, Message& right) {
//		return left.sent_at < right.sent_at;
//	}
//};
//
//class MessageFactory {
//public:
//	MessageFactory() {}
//	Message create_message(const string& text) {
//		return Message(text);
//	}
//};

class Recipient {
public:
	Recipient() {}
	void receive(const Message& msg) {
		messages_.push_back(msg);
	}
	void print_messages() {
		fix_order();
		for (auto& msg : messages_) {
			cout << msg.get_text() << endl;
		}
		messages_.clear();
	}
private:
	void fix_order() {
		sort(messages_.begin(), messages_.end());
	}
	vector<Message> messages_;
};

class Network {
public:
	static void send_messages(vector<Message> messages, Recipient& recipient) {
		// simulates the unpredictable network, where sent messages might arrive in unspecified order
		random_shuffle(messages.begin(), messages.end());
		for (auto msg : messages) {
			recipient.receive(msg);
		}
	}
};

void MessagesExchangerClient() {
	MessageFactory message_factory;
	Recipient recipient;
	vector<Message> messages;
	string text;
	int msglimit = 0; // I just putted this to simulate an end to the task (:
	while (getline(cin, text) && msglimit < 3) {
		messages.push_back(message_factory.create_message(text));
		msglimit++;
	}
	Network::send_messages(messages, recipient);
	recipient.print_messages();
};

//****************************ATTENDING WORKSHOPS (Data and Structures problem) //Interval scheduling Problem
//#include<bits/stdc++.h>

//Define the structs Workshops and Available_Workshops.
struct Workshop
{
	int startTime, 
		duration,
		endtime;
};

struct Available_Workshops 
{
private:
	int signedWorkshops;
	Workshop* workShops = new Workshop[signedWorkshops];
};

//Implement the functions initialize and CalculateMaxWorkshops
Available_Workshops* initialize(int start_time[], int duration[], int n) {
	for (int i = 0; i < n; i++) {
		Workshop* w = new Workshop;
		w->startTime = start_time[i];
		w->duration = duration[i];
		w->endtime = abs(w->startTime + w->duration);	
	}
};

int CalculateMaxWorkshops(Available_Workshops* ptr) {

};

void ExecWorkshops() {
	int n; // number of workshops
	cin >> n;
	// create arrays of unknown size n
	int* start_time = new int[n];
	int* duration = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> start_time[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> duration[i];
	}

	Available_Workshops * ptr;
	ptr = initialize(start_time, duration, n);
	cout << CalculateMaxWorkshops(ptr) << endl;
}


void PlayLambdas() {
	int a = 3, b = 10;

};



int main()
 {


	//MessagesExchangerClient();
	
	/*Message m;
	string text;
	cin >> text;
	MessageFactory mf;
	while (getline(cin, text)) {
		m =	mf.create_message(text);
	}
	cout << "\n" << m.get_text();*/



	//Accessing Inherited Functions Tests:
	//D d;
	//int new_val;
	//new_val = 2;
	//d.check(new_val);

	//Exception test:
	//int n;
	//cin >> n;
	//process_input(n);


	//RectangleArea r_area;
	//r_area.read_input();
	//r_area.Rectangle::display();
	//r_area.display();

	//Calculator c;
	//c.DivisorCalc();
	//c.SumCalc();
	//c.Multiply();


	//DequeChalenge();

	//Demon d;
	//d.set_age(444);
	//cout << d.to_string();

	//InlineExample e;
	//e.initialize(10, 20);
	//e.display();

	//std::cout << ret2.returnArea();
	//LoopOperation();
	//max_of_four(3, 4, 6, 5);
	//PointersOperation();
	//cout << abs(-120);
	//int a = 4, b = 5;
	//int* a_ptr = &a, *b_ptr = &b;
	//update(a_ptr, b_ptr);
	//cout << a, b;
	//ArraysOperation();
	//VariableSizedArrays4();
	//for (int i = 0; i < LIMIT; ++i)
	//	cout << i << "\n";
	//int l1 = 2, l2 = 10;
	//cout << AREA(l1, l2);
	//PreprocessorSolution2();

	//OperatorOverload();
	//OverloadOperators_ComplexNumberCalculator();


	//ClassesAndObjectsOperations();

	//checkBox();

	//VectorSortOperations();

	//VectorErraseOperations();


	//LowerBoundSTLOperations();

	//TestLowerBound();
}

