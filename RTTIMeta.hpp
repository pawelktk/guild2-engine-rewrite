#pragma once
#include <cstdint>


// Vtable padding macros //

#define BOOST_PP_LIMIT_REPEAT 512
#include <boost/preprocessor/repetition/repeat.hpp>

// we need to pad out the vtables, but the C++ preprocessor is not complex enough to do that in a clean way, so we need to use Boost.Preprocessor

// z - recursion depth
// n - iterator
// data_prefix - prefix
// don't use it by itself
#define DEFINE_VTABLE_ENTRY(z, n, data_prefix) \
    virtual void data_prefix##_##n() = 0;


// Generate x dummy vtable entries. 
// We need to do it this way, because there is no way to define low-level RTTI data in C++ and we're basically abusing an implementation detail
#define GENERATE_VTABLE_PADDING(prefix, count) \
    BOOST_PP_REPEAT(count, DEFINE_VTABLE_ENTRY, prefix)




