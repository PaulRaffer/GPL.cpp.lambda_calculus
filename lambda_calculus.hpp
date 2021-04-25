
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


namespace std {
#include "short_begin.hpp"

function True = F(t,F(f, t));
function False = F(t,F(f, f));

function If = F(x,F(t,F(f, x(t)(f))));

function Not = F(x, x(False)(True));
function And = F(x,F(y, x(y)(x)));
function Or = F(x,F(y, x(x)(y)));


function Succ = F(n, F(f,F(x, f(n(f)(x)))));

function Zero = F(f,F(s, s));
function One = Succ(Zero);
function Two = Succ(One);
function Three = Succ(Two);
function Four = Succ(Three);
function Five = Succ(Four);
function Six = Succ(Five);
function Seven = Succ(Six);
function Eight = Succ(Seven);
function Nine = Succ(Eight);
function Ten = Succ(Nine);
function Eleven = Succ(Ten);
function Twelve = Succ(Eleven);
function Thirteen = Succ(Twelve);
function Fourteen = Succ(Thirteen);
function Fifteen = Succ(Fourteen);

function IsZero = F(n, n(F(,False))(True));

function Add = F(x,F(y, y(Succ)(x)));
function Mul = F(x,F(y, F(f, y(x(f)))));
function Pow = F(b,F(e, e(b)));


function Cons = F(a,F(b, F(s, s(a)(b))));
function Car = F(p, p(True));
function Cdr = F(p, p(False));


function T = F(p, Cons(Succ(Car(p)))(Car(p)));
function Pred = F(n, Cdr(n(T)(Cons(Zero)(Zero))));
function Sub = F(x,F(y, y(Pred)(x)));

function Fact = F(n, IsZero(n)(One)(Mul(n)(Fact(Pred(n)))));

#include "short_end.hpp"
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
	function inc_count = [&count](function x) {
				++count;
				return x;
			};
	N(inc_count)(std::True);
	return count;
}

} // namespace helper

} // namespace lambda_calculus
} // namespace gpl


//#endif // __cplusplus >= 201103L
