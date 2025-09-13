#pragma once

#include "Classes.hpp"

// RTTI structures pointers //
#define RTTI_cl_GuildObject (char **)(0x00ac63ac)
#define RTTI_cl_Sim (char **)(0x00ac6c0c)

// dynamic_cast //

template <typename T> inline char **GetRttiForType();

template <> inline char **GetRttiForType<cl_GuildObject>() { return RTTI_cl_GuildObject; }

template <> inline char **GetRttiForType<cl_Sim>() { return RTTI_cl_Sim; }

// IsInstanceOf is basically game's dynamic_cast, but the actual casting part gets lost during compilation (that's why we need to reimplement it in internal_dynamic_cast)
typedef void *(*tIsInstanceOf)(void *object, char **class_rtti_ptr);
const tIsInstanceOf IsInstanceOf = (tIsInstanceOf)(0x00701420);

// T - target class name
// ptr - class to be casted
// Basically reimplemented dynamic_cast, but using the internal RTTI from GuildII.exe
// Reintroduces some syntactic sugar instead of using raw void pointers and IsInstanceOf
template <typename T> T *internal_dynamic_cast(void *ptr) {
  char **rtti = GetRttiForType<T>();

  if (IsInstanceOf(ptr, rtti)) {
    return reinterpret_cast<T *>(ptr);
  }

  return nullptr;
}
