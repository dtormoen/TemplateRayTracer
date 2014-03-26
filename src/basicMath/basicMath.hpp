#ifndef TEMPLATEFUN_BASIC_MATH_HPP
#define TEMPLATEFUN_BASIC_MATH_HPP

#include <iostream>

constexpr double PRECISION = 1000;
 
template <class T>
constexpr T plusOp(const T n1, const T n2)
{ return n1 + n2; }

template <class T>
constexpr T minusOp(const T n1, const T n2)
{ return n1 - n2; }

template <class T>
constexpr T multOp(const T n1, const T n2)
{ return n1 * n2; }

template <class T>
constexpr T divOp(const T n1, const T n2)
{ return n1 / n2; }

template <class T>
constexpr T power(const T base, const size_t exp)
{ return exp > 0 ? base * power(base, exp-1) : 1; }

constexpr int getBase(const double val)
{ return static_cast<int>(val); }

constexpr int getDec(const double val)
{ return (val - static_cast<int>(val)) * PRECISION; }

constexpr double toDouble(const int base, const int dec)
{ return static_cast<double>(base) + (static_cast<double>(dec) / PRECISION); }

template <int baseT, int decT>
struct Double
{
    static constexpr double getVal()
    { return toDouble(baseT, decT); }

    static std::ostream& print(std::ostream& out) {
        return out << getVal();
    }
};

template <typename xT, typename yT, typename zT>
struct Point
{
    static xT x;
    static yT y;
    static zT z;
};

template <typename p1T, typename p2T, constexpr double(*F)(const double,const double)>
struct VecVecOp
{
private:
    static constexpr double x = F(p1T::x::getVal(), p2T::x::getVal());
    static constexpr double y = F(p1T::y::getVal(), p2T::y::getVal());
    static constexpr double z = F(p1T::z::getVal(), p2T::z::getVal());
public:
    static Point<
        Double<getBase(x),getDec(x)>,
        Double<getBase(y),getDec(y)>,
        Double<getBase(z),getDec(z)> > ret;
};

template <typename p1T, typename s1T, constexpr double(*F)(const double,const double)>
struct VecScaOp
{
private:
    static constexpr double x = F(p1T::x::getVal(), s1T::getVal());
    static constexpr double y = F(p1T::y::getVal(), s1T::getVal());
    static constexpr double z = F(p1T::z::getVal(), s1T::getVal());
public:
    static Point<
        Double<getBase(x),getDec(x)>,
        Double<getBase(y),getDec(y)>,
        Double<getBase(z),getDec(z)> > ret;
};

template <typename p1T, typename p2T>
struct dotOp
{
    typedef VecVecOp<p1T, p2T, multOp> temp;
    static constexpr double result = temp::x::getVal() + temp::y::getVal() + temp::z::getVal();
    typedef Double<getBase(result), getDec(result)> ret;
};

template <typename startT, typename pointT>
struct Ray
{
    typedef startT start;
    typedef VecVecOp<pointT, startT, minusOp>::ret dir;
};

template <typename locT, typename radiusT, typename colorT>
struct Sphere
{
    typedef locT loc;
    typedef radiusT radius;
    static colorT color;
};

template <int R, int G, int B>
struct Color
{

};

template <typename rayT, typename sphereT>
struct IsHit
{
private:
    typedef VecVecOp<rayT::start,sphereT::loc> temp;
    static constexpr double a = dotOp<rayT::dir, rayT::dir>::ret;
    static constexpr double b = 2 * dotOp<rayT::start, temp>::ret;
    static constexpr double c = dotOp<temp, temp>::ret - radius::getVal();
public:
};


//This method of applying constexpr is not necessary now, but may be useful for mapping functions to lists?
template<int n1, constexpr int(*F)(const int,const int), int n2>
struct Op {
	static const int eq = F(n1, n2);
};

struct End
{};

template<typename...args>
struct VarList;

template<typename T, typename... args>
struct VarList<T,args...>
{
	static T head;
	static VarList<args...> tail;

    static std::ostream& print(std::ostream& out) {
        out << "(";
        T::print(out);
        out << ", ";
        VarList<args...>::print(out);
        return out << ")";
    }
};  

template<typename T>
struct VarList<T>
{
	static T head;
	static End tail;

    static std::ostream& print(std::ostream& out) {
        T::print(out);
        return out;
    }
};

 
#endif
