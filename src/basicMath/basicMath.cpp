#include <iostream>
#include "basicMath.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
	cout << "2+2=" << Op<2,plusOp,2>::eq << endl;
	cout << "2-5=" << Op<2,minusOp,5>::eq << endl;
	cout << "3*6=" << Op<3,multOp,6>::eq << endl;
	cout << "10/5=" << Op<10,divOp,5>::eq << endl;
	// cout << "2^3=" << Op<2,powOp,3>::eq << endl;
	cout << "Constexpr as template parameter: (2+(3*3))=" << Op<2,plusOp,multOp(3,3)>::eq << endl;
	cout << "Op as template parameter: (2+(3*3))=" << Op<2,plusOp,Op<3,multOp,3>::eq>::eq << endl;

    cout << "Floating point type: " << endl;
    constexpr double test = 1.23456789;
    cout << "1.23456789 " << Double<getBase(test), getDec(test)>::val << endl;

	cout << "Lists: " << endl;
//	VarList<1,2,3,4,5> list;

	return 0;
}
