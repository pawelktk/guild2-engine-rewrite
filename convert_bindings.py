#!/usr/bin/env python3
import re
import sys

pat = re.compile(
    r'lua_pushcclosure\(L,\s*([A-Za-z0-9_]+)\s*,\s*0\);\s*'
    r'lua_pushstring\(L,\s*"\1"\);\s*'
    r'lua_insert\(L,\s*-2\);\s*'
    r'lua_settable\(L,\s*LUA_GLOBALSINDEX\);',
    re.MULTILINE
)

def replace_block(match):
    func = match.group(1)
    return f'BIND_LUA_FUNCTION(L, {func});'

def main():
    if len(sys.argv) < 2:
        print("Usage: convert_bindings.py input.cpp > output.cpp")
        return
    with open(sys.argv[1], encoding="utf-8") as f:
        src = f.read()
    newsrc = pat.sub(lambda m: replace_block(m), src)
    sys.stdout.write(newsrc)

if __name__ == "__main__":
    main()