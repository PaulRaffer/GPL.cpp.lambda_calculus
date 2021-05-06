
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

	assert(to_bool(True) == true);
	assert(to_bool(False) == false);
	
	/*assert(to_bool(Not(True)) == false);
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
	assert(to_bool(Or(True)(True)) == true);*/

	/*assert(to_bool(IsZero(Zero)));
	assert(!to_bool(IsZero(One)));

	assert(to_int(Add(from_int(27))(F(,from_int(14)))) == 27 + 14);

	assert((to_int(Mul(F(,from_int(4)))(F(,from_int(6)))) == 4 * 6));

	assert(to_int(Pow(Two)(Five)) == 32);
	assert(to_int(Pow(Ten)(Three)) == 1e3);

	assert(to_int(Sub(from_int(10))(from_int(6))) == 10 - 6);

	assert(to_int(Fact(Zero)) == 1);*/
	//assert(to_int(Fact(One)) == 1);
	//::std::cout << '<' << to_int(Fact(Three)) << ">\n";
	//assert(to_int(Fact(Five)) == 121);
	//IsZero(F(,Two));
//Fib(F(,One));
//Fact(0)(Six);
	//::std::cout << '<' << to_int(Fib(0)(Six)) << ">\n";
	::std::cout << '<' << to_int(Zero) << ">\n";
	::std::cout << '<' << to_int(One) << ">\n";
	::std::cout << '<' << to_int(Two) << ">\n";
	::std::cout << '<' << to_int(Three) << ">\n";
	::std::cout << '<' << to_int(Four) << ">\n";
	::std::cout << '<' << to_int(Five) << ">\n";

	::std::cout << "<" << to_int(F(,IsZero(0)(One)(Ten)(Eleven))) << ">\n";

	::std::cout << "Fib: <" << to_int(F(,Fib(0)(Zero))) << ">\n";
	::std::cout << "Fib: <" << to_int(F(,Fib(0)(One))) << ">\n";
	::std::cout << "Fib: <" << to_int(F(,Fib(0)(Two))) << ">\n";
	::std::cout << "Fib: <" << to_int(F(,Fib(0)(Three))) << ">\n";
	::std::cout << "Fib: <" << to_int(F(,Fib(0)(Four))) << ">\n";
	::std::cout << "Fib: <" << to_int(F(,Fib(0)(Five))) << ">\n";
	::std::cout << "Fib: <" << to_int(F(,Fib(0)(Six))) << ">\n";
	::std::cout << "Fib: <" << to_int(F(,Fib(0)(Seven))) << ">\n";


	::std::cout << "Fact1: <" << to_int(F(,Fact2(0)(Zero))) << ">\n";
	::std::cout << '<' << to_int(F(,Fact(0)(One))) << ">\n";
	::std::cout << '<' << to_int(F(,Fact(0)(Two))) << ">\n";
	::std::cout << '<' << to_int(F(,Fact(0)(Three))) << ">\n";
	::std::cout << '<' << to_int(F(,Fact(0)(Four))) << ">\n";
	::std::cout << '<' << to_int(F(,Fact(0)(Five))) << ">\n";
Fact(0);//(Zero);
	//::std::cout << '<' << to_int(Ten) << ">\n";
// Fact: 1   1   2   6  24 120
// Fib:  0   1   1   2   3   5   8  13
	::std::cout << "All tests passed!\n";
	#include "short_end.hpp"
}
