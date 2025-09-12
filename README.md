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

### SetGameSpeed

**SetGameSpeed**(float Speed)

Quick and hacky way to set the game speed without any restrictions. Press '-' to update the game speed after running this.

It've created it only to be used for quick testing of the simulation.

Use it only for testing - it **will** OOS in a muliplayer game, as it doesn't broadcast the setting change (like it would normally do when using the +/- key).

## Folders overview

- BindingExtensions - here you can put your own functions that will be registered by the engine
- Classes - classes used by the engine
- GuildGameScriptBinding - implementation of bindings used by GuildGameScriptBinding
