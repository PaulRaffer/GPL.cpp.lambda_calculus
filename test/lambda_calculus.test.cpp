
// Copyright Paul Raffer 2021.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE or copy at
// https://www.boost.org/LICENSE_1_0.txt)


#include "lambda_calculus.hpp"

#include <cassert>

#include <iostream>

namespace test__ {

using namespace ::gpl::lambda_calculus::std;
using namespace ::gpl::lambda_calculus::helper;

template <typename Function>
void Bool()
{
	assert((to_bool(_(True)) == true));
	assert((to_bool(_(False)) == false));
	
	assert((to_bool(_(Not)_(True)) == false));
	assert((to_bool(_(Not)_(False)) == true));
	
	assert((to_bool(_(Or)_(False)_(False)) == false));
	assert((to_bool(_(Or)_(False)_(True)) == true));
	assert((to_bool(_(Or)_(True)_(False)) == true));
	assert((to_bool(_(Or)_(True)_(True)) == true));
	
	assert((to_bool(_(And)_(False)_(False)) == false));
	assert((to_bool(_(And)_(False)_(True)) == false));
	assert((to_bool(_(And)_(True)_(False)) == false));
	assert((to_bool(_(And)_(True)_(True)) == true));
	
	assert((to_int(_(If)_(True)_(Seven)_(Three)) == 7));
	assert((to_int(_(If)_(False)_(Eight)_(Twelve)) == 12));
}

template <typename Function>
void Int()
{
	assert((to_int(_(Succ)_(Four)) == to_int(_(Five))));
	assert((to_int(_(Pred)_(Four)) == to_int(_(Three))));
	
	assert((to_bool(_(IsZero)_(Zero))));
	assert((!to_bool(_(IsZero)_(One))));

	assert((to_int(_(Add)_(Nine)_(Three)) == 9 + 3));
	
	assert((to_int(_(Mul)_(Twelve)_(Nine)) == 12 * 9));

	//assert((to_int(Mul(F(,from_int(4)))(F(,from_int(6)))) == 4 * 6));

	assert((to_int(_(Pow)_(Two)_(Five)) == 32));
	assert((to_int(_(Pow)_(Ten)_(Three)) == 1e3));

	//assert(to_int(Sub(from_int(10))(from_int(6))) == 10 - 6);
}

template <typename Function>
void Fact()
{
	assert((to_int(_(Fact)_(Zero )) == 1));
	assert((to_int(_(Fact)_(One  )) == 1));
	assert((to_int(_(Fact)_(Two  )) == 1*2));
	assert((to_int(_(Fact)_(Three)) == 1*2*3));
	assert((to_int(_(Fact)_(Four )) == 1*2*3*4));
	assert((to_int(_(Fact)_(Five )) == 1*2*3*4*5));
	assert((to_int(_(Fact)_(Six  )) == 1*2*3*4*5*6));
	assert((to_int(_(Fact)_(Seven)) == 1*2*3*4*5*6*7));
}

template <typename Function>
void Fib()
{
	assert((to_int(_(Fib)_(Zero )) ==  0));
	assert((to_int(_(Fib)_(One  )) ==  1));
	assert((to_int(_(Fib)_(Two  )) ==  1));
	assert((to_int(_(Fib)_(Three)) ==  2));
	assert((to_int(_(Fib)_(Four )) ==  3));
	assert((to_int(_(Fib)_(Five )) ==  5));
	assert((to_int(_(Fib)_(Six  )) ==  8));
	assert((to_int(_(Fib)_(Seven)) == 13));
}

template <typename Function>
void all()
{
	Bool<Function>();
	Int<Function>();
}

} // namespace test__

auto main2() -> int
{
	#include "short_begin.hpp"
	
	using namespace ::gpl::lambda_calculus;

	test__::all<lazy_function>();
	test__::all<function>();
	test__::Fact<lazy_function>();
	test__::Fib<lazy_function>();

	::std::cout << "All tests passed!\n";

	#include "short_end.hpp"
}

auto main() -> int
{
	#include "short_begin.hpp"

	using namespace ::gpl::lambda_calculus::bckw;

	I(S)(K)(K);

	#include "short_end.hpp"
}
