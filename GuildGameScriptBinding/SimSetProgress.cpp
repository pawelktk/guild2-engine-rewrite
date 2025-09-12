#include "../ScriptManagerUtil.hpp"
#include "../RTTIInternalDynamicCast.hpp"
#include "../lua.hpp"
#include "../LogSystem.hpp"
#include "../Classes.hpp"

#include <string>

/*

Script documentation claims SimSetProgress returns a number with progress, 
and the binding also treats it like a number,
but the internal Sim->SetProgress returns a bool (retval is passed in the AL register and it's not a char).
So the SimSetProgress lua binding returns a number that is either 
-1 (in case of type casting fail), 
0 (Sim->SetProgress retured false), or 
1 (Sim->SetProgress returned true)

In the rewrite I fixed that, so that it returns a bool correctly
*/


// It's unused for now, as it's broken

#if 0

int __cdecl SimSetProgress(lua_State *L) {
  ScriptManager_InitDebugInfo_magic(L, "whatever_its_not_used_anyway", 12345, 1);

  cl_Sim *pSim = internal_dynamic_cast<cl_Sim>(ResolveObjectFromAlias(L, 1, 0, 1));
  if (pSim != nullptr) {
    int progress = ReadIntArgument(L,2,0,1);
    
    /*#ifdef GUILDGAMESCRIPTBINDING_ADDITIONAL_DBG
    	ER_LogWarning("@ADDITIONAL_DBG SimSetProgress Setting name..");
    	std::string simName = pSim->name ? pSim->name : "";
    	ER_LogWarning("@ADDITIONAL_DBG SimSetProgress Setting oldlover name..");
    	int oldLover = (int)pSim->courtingSim;
    	//std::string oldLoverName = (pSim->courtingSim && pSim->courtingSim->name) ? pSim->courtingSim->name : "";
    #endif*/
    
    if(pSim->SetProgress(progress)){
    	/*#ifdef GUILDGAMESCRIPTBINDING_ADDITIONAL_DBG
    		//std::string newLoverName = (pSim->courtingSim && pSim->courtingSim->name) ? pSim->courtingSim->name : "";
    		int newLover = (int)pSim->courtingSim;
    		if(oldLover != newLover)
    			ER_LogWarning("@ADDITIONAL_DBG WARNING SimSetProgress(%s, %d) -> true - Changed lover from <%d> to <%d>!", lua_tostring(L,1), progress, oldLover, newLover);
    	#endif*/
    	lua_pushboolean(L,true);
    	return 1;
    } else{
    	/*#ifdef GUILDGAMESCRIPTBINDING_ADDITIONAL_DBG
    		std::string newLoverName = (pSim->courtingSim && pSim->courtingSim->name) ? pSim->courtingSim->name : "";
    		if(oldLoverName != newLoverName)
    			ER_LogWarning("@ADDITIONAL_DBG WARNING SimSetProgress(%s, %d) -> false - Changed lover from <%s> to <%s>!", lua_tostring(L,1), progress, oldLoverName, newLoverName);
    	#endif*/
    }
  }
  lua_pushboolean(L,false);
  return 1;

}

#endif