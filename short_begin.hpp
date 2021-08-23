
// Copyright Paul Raffer 2021.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE or copy at
// https://www.boost.org/LICENSE_1_0.txt)


#define FUNC(f, b) \
        template <typename Function> Function basic_##f = b; \
        auto f = basic_##f<lazy_function>
#define F(x, y) (Function{[=]([[maybe_unused]] Function x) { return y; }})
#define _(f) (basic_##f<Function>)
#define LF(x, y) (lazy_function{[=]([[maybe_unused]] lazy_function x) { return y; }})
#define L(x) ([=] { return x(); })
