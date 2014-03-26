#ifndef TEMPLATEFUN_BASIC_MATH_HPP
#define TEMPLATEFUN_BASIC_MATH_HPP

constexpr double PRECISION = 100000;
 
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

//constexpr int getDec(const double val)

template <int baseT, int decT>
struct Double
{
    static constexpr double val = toDouble(baseT, decT);
};


//template <size_t, size_t

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
};  

template<typename T>
struct VarList<T>
{
	static T head;
	static End tail;
};

 
#endif
