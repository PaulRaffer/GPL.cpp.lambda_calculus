
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


function True = F(,F(t,F(f, t(0))));
function False = F(,F(t,F(f, f(0))));
/*
function D = True;

function If = F(x,F(t,F(f, x(t)(f))));

function Not = F(x, x(False)(True));
function And = F(x,F(y, x(y)(x)));
function Or = F(x,F(y, x(x)(y)));

*/
function Succ = F(,F(n, F(f,F(x, f(0)(F(,n(0)(f)(x)))))));
function Zero = F(,F(f,F(s, s(0))));
function One = F(,Succ(0)(Zero));
function Two = F(,Succ(0)(One));
function Three = F(,Succ(0)(Two));
function Four = F(,Succ(0)(Three));
function Five = F(,Succ(0)(Four));
function Six = F(,Succ(0)(Five));
function Seven = F(,Succ(0)(Six));
function Eight = F(,Succ(0)(Seven));
function Nine = F(,Succ(0)(Eight));
function Ten = F(,Succ(0)(Nine));
function Eleven = F(,Succ(0)(Ten));
function Twelve = F(,Succ(0)(Eleven));
function Thirteen = F(,Succ(0)(Twelve));
function Fourteen = F(,Succ(0)(Thirteen));
function Fifteen = F(,Succ(0)(Fourteen));

function IsZero = F(,F(n, n(0)(F(_,False))(True)));


function Add = F(,F(x,F(y, y(0)(Succ)(x))));
function Mul = F(,F(x,F(y, F(f, y(0)(F(,x(0)(f)))))));
function Pow = F(,F(b,F(e, e(0)(b))));


function Cons = F(,F(a,F(b, F(s, s(0)(a)(b)))));
function Car = F(,F(p, p(0)(True)));
function Cdr = F(,F(p, p(0)(False)));


function T = F(,F(p, Cons(0)(F(,Succ(0)(F(,Car(0)(p)))))(F(,Car(0)(p)))));
function Pred = F(,F(n, Cdr(0)(F(,n(0)(T)(F(,Cons(0)(Zero)(Zero)))))));
function Sub = F(,F(x,F(y, y(0)(Pred)(x))));

//function Y = F(,F(f, F(x, f(0)(F(,x(0)(x))))(F(,F(x,F(z,f(0)(F(,x(0)(x)(z))))))))));
function Y1 = F(,F(f, F(x, f(0)(F(,F(z,x(0)(x)(z))))(F(,F(x,F(z,f(0)(F(,x(0)(x)(z))))))))));

function Y =
	F(,F(f,
		F(x,
			f(0)(F(,x(0)(x)))
		)(F(,F(x,
			f(0)(F(,x(0)(x)))
		)))
	));

//function Fact = F(,F(f, F(n, IsZero(0)(n)(One)(F(,Mul(0)(n)(F(,f(0)(F(,Pred(0)(n))))))))));
function R = F(,F(f, F(n, IsZero(0)(n)(One)(F(,Mul(0)(n)(F(,f(0)(F(,Pred(0)(n))))))))));
function R2 = F(,F(f, F(n, IsZero(0)(n)(One)(Two))));
function Fact3 = F(,R(0)(Fact3));
function Fact = F(,Y(0)(R));
//(F(f, F(n, IsZero(0)(n)(One)(F(,Mul(0)(n)(F(,f(f)(F(,Pred(0)(n))))))))));
/*
F(x,
	F(n, IsZero(0)(n)(One)(F(,Mul(0)(n)(F(, x(0)(x) (F(,Pred(0)(n)))))))))
)(F(,F(x,
	F(n, IsZero(0)(n)(One)(F(,Mul(0)(n)(F(, x(0)(x) (F(,Pred(0)(n)))))))))
)))*/

//function Fact = F(n, IsZero(n)(One)(Mul(n)(Fact(Pred(n)))));
function Fact1 =
		F(,
			F(f,
				F(n,IsZero(0)(n)
					(One)
					(F(,Mul(0)
						(n)
						(F(,
							f(f)(F(,Pred(0)(n)))
						))
					))
				)
			)
			(F(f,
				F(n,IsZero(0)(n)
					(One)
					(F(,Mul(0)
						(n)
						(F(,
							f(f)(F(,Pred(0)(n)))
						))
					))
				)
			))
		);

function Fact2 = F(,F(f, F(n, IsZero(0)(n)(One)(F(,Mul(0)(n)(F(,f(0)(F(,Pred(0)(n)))))))))(Fact2));



function FibR =
		//F(,F(f,F(n, n)));
		F(,F(f,F(n, IsZero(0)(n)
			(n)
			(F(,IsZero(0)(F(,Pred(0)(n)))
				(n)
				(F(,Add(0)
					(F(,f(0)(f)(F(,Pred(0)(n)))))
					(F(,f(0)(f)(F(,Pred(0)(F(,Pred(0)(n)))))))
				))
			))
		)));

function Fib =
		F(,F(f,F(n, IsZero(0)(n)
			(n)
			(F(,IsZero(0)(F(,Pred(0)(n)))
				(n)
				(F(,Add(0)
					(F(,f(f)(F(,Pred(0)(n)))))
					(F(,f(f)(F(,Pred(0)(F(,Pred(0)(n)))))))
				))
			))
		))(
		F(f,F(n, IsZero(0)(n)
			(n)
			(F(,IsZero(0)(F(,Pred(0)(n)))
				(n)
				(F(,Add(0)
					(F(,f(f)(F(,Pred(0)(n)))))
					(F(,f(f)(F(,Pred(0)(F(,Pred(0)(n)))))))
				))
			))
		))
		));


} // namespace std


namespace helper { // interface

auto Null = F(,function{});

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
	   !B(0)(Null)(Null)
	&& !B(0)(Null)(True)
	&&  B(0)(True)(Null)
	&&  B(0)(True)(True))
		return true;
	else if (
	   !B(0)(Null)(Null)
	&&  B(0)(Null)(True)
	&& !B(0)(True)(Null)
	&&  B(0)(True)(True))
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
	N(0)(inc_count)(N);
	return count;
}


} // namespace helper
#include "short_end.hpp"

} // namespace lambda_calculus
} // namespace gpl


//#endif // __cplusplus >= 201103L
