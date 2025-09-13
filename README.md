# guild2-engine-rewrite

This project allows to overwrite and extend capabilities of The Guild 2 engine.

It also serves as a repository of knowledge about its reverse engineering progress and internal data structures.

## Patching

1. Copy Patcher.exe and G2ER.dll into GuildII.exe directory

2. Run Patcher.exe

3. You should see a message "\[G2ER\] Using GuildGameScriptBinding from Guild2EngineRewrite" in the logfile after running the game

## Updating

If there is no update to the patcher just copy the new DLL, otherwise also repatch the game with the new patcher.

## Building

```sh
./build_dll.sh
./build_patcher.sh
```

## Some cool additions

There are some additions in Guild2EngineRewrite that aren't available in the base game script binding:

### BuildingSetAISetting

**BuildingSetAISetting**(\[Alias of type cl_Building\] pBuilding, string option, Number setTo) - Sets the AI setting for building.

In the base game it's not possible to change it from the script level, and thus it severely limits what you can do with AI using Lua scripts. This addition changes that.

**All AI options:**

```
Enable
 BuySell
  BuySell_Radius
  BuySell_PriceLevel
  BuySell_SellStock
  BuySell_Carts
 Workers
  Workers_Quality
  Workers_Favor
 Budget
  Budget_Repair
  Budget_Upgrades
 Produce
  Produce_Selection
  Produce_Stock
```

Those can be either 0 or 1 (disabled/enabled) for the higher level options (Enable, BuySell, Workers, Budget, Produce)

The lower level options get set automatically to -1 if the higher order option is disabled.

The lower level options also can have higher values if they have more than 1 option, for example:

BuySell_Radius (Sales and purchases):

```
0 - "Not at all"
1 - "In the city"
2 - "On the whole map
```

They more or less correspond to their place in ai management menu.

Example usage:

```lua
BuildingSetAISetting("", "Produce", 0) -- disables the AI management of production completelly for building of alias ""
```

### RunLua

**RunLua**(string toRun) - runs lua script from string dynamically. Great for some lua console!

Example usage:

```lua
	local toRun = [[
		LogMessage("@RUNLUA Hello world! from RunLua")
	]]
	RunLua(toRun)
	LogMessage("@RUNLUA Hello world! outside of RunLua")
```


### SetGameSpeed

**SetGameSpeed**(float Speed)

Quick and hacky way to set the game speed without any restrictions. Press '-' to update the game speed after running this.

I've created it only to be used for quick testing of the simulation.

Use it only for testing - it **will** OOS in a muliplayer game, as it doesn't broadcast the setting change (like it would normally do when using the +/- key).


## Adding your own extensions

New extensions can be added and registered in *BindingExtensions/GuildGameScriptBinding_Extensions.hpp*

1. Write the function for the extension:

```cpp
int MyFunction(lua_State *L){
	ScriptManager_InitDebugInfo_magic(L, "whatever_its_not_even_used", 12345, 1);
	...
	return 1;
}
```

2. Register it in *GuildGameScriptBinding_RegisterExtensions* function:

```cpp
void GuildGameScriptBinding_RegisterExtensions(lua_State *L) {
	...
	registerExtension(L, MyFunction, "MyFunction");
}
```

3. After recompiling it should be avilable in lua scripts as:

```lua
MyFunction()
```

## Implementing/Modifying existing functions

If function is already implemented in G2ER just modify its source in *GuildGameScriptBinding* folder

If the function doesn't have its own implementation in G2ER yet and you want to implement it:

1. Write the function body in *GuildGameScriptBinding* folder

2. Include the file with function implementation in *GuildGameScriptBinding.cpp*

3. Uncomment line with the function name in *GuildGameScriptBinding/UNIMPLEMENTED.hpp*


## Folders overview

- BindingExtensions - here you can put your own functions that will be registered by the engine
- Classes - classes used by the engine
- GuildGameScriptBinding - implementation of bindings used by GuildGameScriptBinding
