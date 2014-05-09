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
    cout << "abs(-1) " << conAbs(-1) << endl;
    cout << "abs(-.1) " << conAbs(-.1) << endl;
    cout << "abs(11) " << conAbs(11) << endl;
    cout << "sqrt" << endl;
    cout << "sqrt(1.0) " << conSqrt(1.0) << endl;
    cout << "sqrt(2.0) " << conSqrt(2.0) << endl;

    cout << "Floating point type: " << endl;
    constexpr double test = 1.23456789;
    cout << "1.23456789 " << Double<getBase(test), getDec(test)>::getVal() << endl;

    cout << "Lists: " << endl;
//	VarList<1,2,3,4,5> list;
    VarList<Double<1,0>,Double<2,0>,Double<3,0>,Double<4,0>>::print(cout);
    typedef VarList<Double<1,0>,Double<2,0>,Double<3,0>,Double<4,0>> d1;
    cout << endl;
    VarList<d1,d1,d1,d1>::print(cout) << endl;

    typedef IsHit<Ray<Point<Double<0,0>,Double<0,0>,Double<0,0> >,
            Point<Double<0,0>,Double<0,0>,Double<1,0> > >,
        Sphere<Point<Double<0,0>,Double<0,0>,Double<5,0> >,
               Double<2,0>,
               Color<0,0,255> > > test1;

    cout << "Should hit: " << test1::hit << endl;
    cout << "a " << test1::a << endl;
    cout << "b " << test1::b << endl;
    cout << "c " << test1::c << endl;
    cout << "disc " << test1::disc << endl;




    cout << "Should not hit: " <<
            IsHit<Ray<Point<Double<0,0>,Double<0,0>,Double<0,0> >,
                      Point<Double<0,0>,Double<1,0>,Double<0,0> > >,
                  Sphere<Point<Double<0,0>,Double<0,0>,Double<5,0> >,
                         Double<2,0>,
                         Color<0,0,255> > >::hit << endl;


	return 0;
}
