
// Copyright Paul Raffer 2021.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE or copy at
// https://www.boost.org/LICENSE_1_0.txt)

//#if __cplusplus >= 201103L


#include <functional>
#include <iostream>


namespace gpl { // interface/implementation
namespace lambda_calculus {

class function :
        private ::std::function<function (function)> {
    public: using type =
            ::std::function<function (function)>;
    public: using type::function;
	public: using type::operator();
	public: using type::operator bool;
};

#include "short_begin.hpp"
namespace std {


function True = F(t,F(f, t(0)));
function False = F(t,F(f, f(0)));
/*
function D = True;

function If = F(x,F(t,F(f, x(t)(f))));

function Not = F(x, x(False)(True));
function And = F(x,F(y, x(y)(x)));
function Or = F(x,F(y, x(x)(y)));

*/
function Succ = F(n, F(f,F(x, f(0)(F(,n(0)(f)(x)))))); //?
function Zero = F(f,F(s, s(0)));
function One = Succ(F(,Zero));
function Two = Succ(F(,One));
function Three = Succ(F(,Two));
function Four = Succ(F(,Three));
function Five = Succ(F(,Four));
function Six = Succ(F(,Five));
function Seven = Succ(F(,Six));
function Eight = Succ(F(,Seven));
function Nine = Succ(F(,Eight));
function Ten = Succ(F(,Nine));
function Eleven = Succ(F(,Ten));
function Twelve = Succ(F(,Eleven));
function Thirteen = Succ(F(,Twelve));
function Fourteen = Succ(F(,Thirteen));
function Fifteen = Succ(F(,Fourteen));

function IsZero = F(n, n(0)(F(,F(_,False)))(F(,True)));


function Add = F(x,F(y, y(0)(F(,Succ))(x)));
function Mul = F(x,F(y, F(f, y(0)(x(0)(f)))));
function Pow = F(b,F(e, e(0)(b)));


function Cons = F(a,F(b, F(s, s(0)(a)(b))));
function Car = F(p, p(0)(F(,True)));
function Cdr = F(p, p(0)(F(,False)));


function T = F(p, Cons(F(,Succ(F(,Car(p)))))(F(,Car(p))));
function Pred = F(n, Cdr(F(,n(0)(F(,T))(F(,Cons(F(,Zero))(F(,Zero)))))));
//function Sub = F(x,F(y, y(Pred)(x)));

//function Fact = F(n, IsZero(n)(One)(Mul(n)(Fact(Pred(n)))));
/*function Fact = F(f, F(n, IsZero(n)(One)(Mul(F(,n))(F(,f(f)(Pred(n)))))))
		(F(f, F(n, IsZero(n)(One)(Mul(F(,n))(F(,f(f)(Pred(n))))))));*/

//function Fib = F(f, F(n, IsZero(n)(n)(F(,IsZero(Pred(n))(n)(F(,Add(f(f)(Pred(Pred(n))))(f(f)(Pred(n)))))))))
//		(F(f, F(n, IsZero(n)(n)(F(,IsZero(Pred(n))(n)(F(,Add(f(f)(Pred(Pred(n))))(f(f)(Pred(n))))))))));

function Fib =
		F(f, F(n, IsZero(n)
			(n)
			(F(,IsZero(F(,Pred(n)))
				(n)
				(F(,Add
					(F(,f(f)(F(,Pred(n)))))
					(F(,f(f)(F(,Pred(F(,Pred(n)))))))
				))
			))
		))(
		F(f, F(n, IsZero(n)
			(n)
			(F(,IsZero(F(,Pred(n)))
				(n)
				(F(,Add
					(F(,f(f)(F(,Pred(n)))))
					(F(,f(f)(F(,Pred(F(,Pred(n)))))))
				))
			))
		))
		);


} // namespace std


namespace helper { // interface

auto Null = function{};

auto from_bool(bool b) -> function;
auto to_bool(function fb) -> bool;

auto from_int(int n, function fn = std::Zero) -> function;
auto to_int(function fn) -> int;

} // namespace helper


namespace helper { // implementation

auto from_bool(bool const b) -> function
{
	return b ? std::True : std::False;
}

auto to_bool(function B) -> bool
try {
	using namespace std;
	if (
	   !B(Null)(Null)
	&& !B(Null)(True)
	&&  B(True)(Null)
	&&  B(True)(True))
		return true;
	else if (
	   !B(Null)(Null)
	&&  B(Null)(True)
	&& !B(True)(Null)
	&&  B(True)(True))
		return false;
	else
		throw -1;
}
catch (::std::bad_function_call&) {
	throw -1;
}


auto from_int(int const n, function N) -> function
{
	return n == 0 ? N : from_int(n - 1, std::Succ(N));
}

auto to_int(function N) -> int
{
	auto count = 0;
	function inc_count = [&count](function) { return [&count](function x) {
				++count;
				return x(0);
			};};
	N(inc_count)(N);
	return count;
}


} // namespace helper
#include "short_end.hpp"

} // namespace lambda_calculus
} // namespace gpl


//#endif // __cplusplus >= 201103L
