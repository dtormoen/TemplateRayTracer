#ifndef TEMPLATEFUN_BASIC_MATH_HPP
#define TEMPLATEFUN_BASIC_MATH_HPP
 
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



//This method of applying constexpr is not necessary now, but may be useful for mapping functions to lists?
template<int n1, constexpr int(*F)(const int,const int), int n2>
struct Op {
	static const int eq = F(n1, n2);
};
 
#endif