#include <iostream>

using namespace std;

constexpr int plusOp(const int n1, const int n2)
{ return n1 + n2; }
constexpr int minusOp(const int n1, const int n2)
{ return n1 - n2; }
constexpr int multOp(const int n1, const int n2)
{ return n1 * n2; }
constexpr int divOp(const int n1, const int n2)
{ return n1 / n2; }

template<int n1, constexpr int(*F)(const int,const int), int n2>
struct Op {
	static const int eq = F(n1, n2);
};


int main(int argc, char const *argv[])
{
	cout << "It works!" << endl;
	cout << "2+2=" << Op<2,plusOp,2>::eq << endl;
	cout << "2-5=" << Op<2,minusOp,5>::eq << endl;
	cout << "3*6=" << Op<3,multOp,6>::eq << endl;
	cout << "10/5=" << Op<10,divOp,5>::eq << endl;
	return 0;
}