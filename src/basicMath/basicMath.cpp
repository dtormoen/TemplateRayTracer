#include <iostream>

using namespace std;

constexpr int plusFunc(const int n1, const int n2)
{ return n1 + n2; }
constexpr int minusFunc(const int n1, const int n2)
{ return n1 - n2; }
constexpr int multFunc(const int n1, const int n2)
{ return n1 * n2; }
constexpr int divFunc(const int n1, const int n2)
{ return n1 / n2; }

template<int n1, constexpr int(*F)(const int,const int), int n2>
struct TempOp {
	static const int result = F(n1, n2);
};


int main(int argc, char const *argv[])
{
	cout << "It works!" << endl;
	cout << "2+2=" << TempOp<2,plusFunc,2>::result << endl;
	cout << "2-5=" << TempOp<2,minusFunc,5>::result << endl;
	cout << "3*6=" << TempOp<3,multFunc,6>::result << endl;
	cout << "10/5=" << TempOp<10,divFunc,5>::result << endl;
	return 0;
}