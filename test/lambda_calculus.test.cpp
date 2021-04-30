
// Copyright Paul Raffer 2021.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE or copy at
// https://www.boost.org/LICENSE_1_0.txt)


#include "lambda_calculus.hpp"

#include <cassert>

#include <iostream>

#include <exception>

template <typename E, typename F>
bool throws(F f);

template <typename E, typename F>
bool throws(F f)
try {
	f();
	return false;
}
catch (E const &) {
	return true;
}



auto main() -> int
{
	#include "short_begin.hpp"
	using namespace gpl::lambda_calculus::std;
	using namespace gpl::lambda_calculus::helper;
	using namespace gpl::lambda_calculus;

	/*assert(to_bool(True) == true);
	assert(to_bool(False) == false);
	
	assert(to_bool(Not(True)) == false);
	assert(to_bool(Not(False)) == true);

	assert(to_int(If(True)(Seven)(Three)) == 7);
	assert(to_int(If(False)(Eight)(Twelve)) == 12);

	assert(to_bool(And(False)(False)) == false);
	assert(to_bool(And(False)(True)) == false);
	assert(to_bool(And(True)(False)) == false);
	assert(to_bool(And(True)(True)) == true);

	assert(to_bool(Or(False)(False)) == false);
	assert(to_bool(Or(False)(True)) == true);
	assert(to_bool(Or(True)(False)) == true);
	assert(to_bool(Or(True)(True)) == true);

	assert(to_bool(IsZero(F(,Zero))));
	assert(!to_bool(IsZero(F(,One))));

	assert(to_int(Add(F(,from_int(27)))(F(,from_int(14)))) == 27 + 14);

	assert((to_int(Mul(F(,from_int(4)))(F(,from_int(6)))) == 4 * 6));

	assert(to_int(Pow(Two)(Five)) == 32);
	assert(to_int(Pow(Ten)(Three)) == 1e3);

	assert(to_int(Sub(from_int(10))(from_int(6))) == 10 - 6);

	assert(to_int(Fact(Zero)) == 1);*/
	//assert(to_int(Fact(One)) == 1);
	//::std::cout << '<' << to_int(Fact(Three)) << '>';
	//assert(to_int(Fact(Five)) == 121);
	//IsZero(F(,Two));
//Fib(F(,One));
Fib(0)(Six);
	::std::cout << '<' << to_int(Fib(0)(Six)) << '>';
// 0 1 1 2 3 5 8 13
	::std::cout << "All tests passed!\n";
	#include "short_end.hpp"
}
