#include "GuildGameScriptBinding.hpp"
#include "BindingExtensions/GuildGameScriptBinding_Extensions.hpp"

#include "GuildGameScriptBinding/UNIMPLEMENTED.hpp"

// TODO Including the definitions directly is quite ugly
// It will suffice for now
// I'll write some script to autogenerate header files later on
#include "GuildGameScriptBinding/GetHP.cpp"
#include "GuildGameScriptBinding/GetHPRelative.cpp"
#include "GuildGameScriptBinding/SimSetCourtLover.cpp"
//#include "GuildGameScriptBinding/SimSetProgress.cpp"

auto tolua_init = reinterpret_cast<void(__cdecl *)(lua_State *)>(0x006f6780);

auto BuildingScriptBinding = reinterpret_cast<void(__cdecl *)(lua_State *)>(0x006f66f0);
auto WeatherScriptBinding = reinterpret_cast<void(__cdecl *)(lua_State *)>(0x006f60b0);
auto CameraScriptBinding = reinterpret_cast<void(__cdecl *)(lua_State *)>(0x006f5540);
auto OfficeScriptBinding = reinterpret_cast<void(__cdecl *)(lua_State *)>(0x006f3700);

void GuildGameScriptBinding(lua_State *L) {
  tolua_init(L);
  BuildingScriptBinding(L);
  WeatherScriptBinding(L);
  CameraScriptBinding(L);
  OfficeScriptBinding(L);

  lua_pushcclosure(L, SimFindProduction, 0);
  lua_pushstring(L, "SimFindProduction");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SquadCreate, 0);
  lua_pushstring(L, "SquadCreate");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SquadGet, 0);
  lua_pushstring(L, "SquadGet");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SimFindSquad, 0);
  lua_pushstring(L, "SimFindSquad");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, DynastyFindSquad, 0);
  lua_pushstring(L, "DynastyFindSquad");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SquadDestroy, 0);
  lua_pushstring(L, "SquadDestroy");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SquadAddRandom, 0);
  lua_pushstring(L, "SquadAddRandom");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SquadGetProfession, 0);
  lua_pushstring(L, "SquadGetProfession");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SquadGetMemberCount, 0);
  lua_pushstring(L, "SquadGetMemberCount");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SquadGetVacantPlace, 0);
  lua_pushstring(L, "SquadGetVacantPlace");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SquadIsReady, 0);
  lua_pushstring(L, "SquadIsReady");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SquadSetReady, 0);
  lua_pushstring(L, "SquadSetReady");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SquadIsNeeded, 0);
  lua_pushstring(L, "SquadIsNeeded");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SquadAddMember, 0);
  lua_pushstring(L, "SquadAddMember");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SquadRemoveMember, 0);
  lua_pushstring(L, "SquadRemoveMember");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SquadGetLeader, 0);
  lua_pushstring(L, "SquadGetLeader");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SquadGetLeaderId, 0);
  lua_pushstring(L, "SquadGetLeaderId");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SquadGetMember, 0);
  lua_pushstring(L, "SquadGetMember");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SquadMemberExists, 0);
  lua_pushstring(L, "SquadMemberExists");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SquadGetMeetingPlace, 0);
  lua_pushstring(L, "SquadGetMeetingPlace");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SquadSetMeetingPlace, 0);
  lua_pushstring(L, "SquadSetMeetingPlace");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SquadGetState, 0);
  lua_pushstring(L, "SquadGetState");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SetArg, 0);
  lua_pushstring(L, "SetArg");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, OutputDebugString, 0);
  lua_pushstring(L, "OutputDebugString");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, CMsgNews, 0);
  lua_pushstring(L, "CMsgNews");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, MsgQuick, 0);
  lua_pushstring(L, "MsgQuick");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, MsgMeasure, 0);
  lua_pushstring(L, "MsgMeasure");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, MsgSystem, 0);
  lua_pushstring(L, "MsgSystem");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, CMsgSay, 0);
  lua_pushstring(L, "CMsgSay");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, ShowOverheadSymbol, 0);
  lua_pushstring(L, "ShowOverheadSymbol");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, RemoveOverheadSymbol, 0);
  lua_pushstring(L, "RemoveOverheadSymbol");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, RemoveOverheadSymbols, 0);
  lua_pushstring(L, "RemoveOverheadSymbols");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, RemoveAllOverheadSymbols, 0);
  lua_pushstring(L, "RemoveAllOverheadSymbols");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, StartGameTimer, 0);
  lua_pushstring(L, "StartGameTimer");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, CheckGameTimerEnd, 0);
  lua_pushstring(L, "CheckGameTimerEnd");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, RemoveDialogBox, 0);
  lua_pushstring(L, "RemoveDialogBox");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SetCampaignEndText, 0);
  lua_pushstring(L, "SetCampaignEndText");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, ScenarioGetObjectByName, 0);
  lua_pushstring(L, "ScenarioGetObjectByName");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, ScenarioGetKontorGoodCount, 0);
  lua_pushstring(L, "ScenarioGetKontorGoodCount");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, ScenarioGetKontorGoodInfo, 0);
  lua_pushstring(L, "ScenarioGetKontorGoodInfo");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, ScenarioGetItemIdCount, 0);
  lua_pushstring(L, "ScenarioGetItemIdCount");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, ScenarioGetItemIdByNumber, 0);
  lua_pushstring(L, "ScenarioGetItemIdByNumber");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, ScenarioGetRandomObject, 0);
  lua_pushstring(L, "ScenarioGetRandomObject");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, ScenarioGetObjects, 0);
  lua_pushstring(L, "ScenarioGetObjects");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, ScenarioGetImperialCapitalId, 0);
  lua_pushstring(L, "ScenarioGetImperialCapitalId");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, ScenarioGetImperialCapital, 0);
  lua_pushstring(L, "ScenarioGetImperialCapital");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, ScenarioSetImperialCapital, 0);
  lua_pushstring(L, "ScenarioSetImperialCapital");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, ScenarioCreateResource, 0);
  lua_pushstring(L, "ScenarioCreateResource");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, ScenarioGetTimePlayed, 0);
  lua_pushstring(L, "ScenarioGetTimePlayed");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, ScenarioCreatePosition, 0);
  lua_pushstring(L, "ScenarioCreatePosition");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, ScenarioFindBuildingProto, 0);
  lua_pushstring(L, "ScenarioFindBuildingProto");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, ScenarioFindBuildingProtoForCharacter, 0);
  lua_pushstring(L, "ScenarioFindBuildingProtoForCharacter");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, ScenarioFindPosition, 0);
  lua_pushstring(L, "ScenarioFindPosition");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, ScenarioSetYearsPerRound, 0);
  lua_pushstring(L, "ScenarioSetYearsPerRound");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, GetScenario, 0);
  lua_pushstring(L, "GetScenario");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, ScenarioCreateCart, 0);
  lua_pushstring(L, "ScenarioCreateCart");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, ScenarioGetUnspawnedEnemiesCount, 0);
  lua_pushstring(L, "ScenarioGetUnspawnedEnemiesCount");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, ScenarioGetYearsPerRound, 0);
  lua_pushstring(L, "ScenarioGetYearsPerRound");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, ScenarioStopUsingOutdoorScrollBoundaries, 0);
  lua_pushstring(L, "ScenarioStopUsingOutdoorScrollBoundaries");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, ScenarioSetOutdoorScrollBoundaries, 0);
  lua_pushstring(L, "ScenarioSetOutdoorScrollBoundaries");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, ScenarioGetDifficulty, 0);
  lua_pushstring(L, "ScenarioGetDifficulty");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, ScenarioPauseAI, 0);
  lua_pushstring(L, "ScenarioPauseAI");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, IsMultiplayerGame, 0);
  lua_pushstring(L, "IsMultiplayerGame");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, PlayerCreate, 0);
  lua_pushstring(L, "PlayerCreate");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, DynastyCreate, 0);
  lua_pushstring(L, "DynastyCreate");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, BossCreate, 0);
  lua_pushstring(L, "BossCreate");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, FindNearestBuilding, 0);
  lua_pushstring(L, "FindNearestBuilding");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, CourtingGetMaxCourtingId, 0);
  lua_pushstring(L, "CourtingGetMaxCourtingId");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, CourtingId2Measure, 0);
  lua_pushstring(L, "CourtingId2Measure");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, MeasureCreate, 0);
  lua_pushstring(L, "MeasureCreate");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, MeasureAddAlias, 0);
  lua_pushstring(L, "MeasureAddAlias");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, MeasureAddData, 0);
  lua_pushstring(L, "MeasureAddData");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, MeasureStart, 0);
  lua_pushstring(L, "MeasureStart");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, MeasureRun, 0);
  lua_pushstring(L, "MeasureRun");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, MeasureIsValid, 0);
  lua_pushstring(L, "MeasureIsValid");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, MeasureGetID, 0);
  lua_pushstring(L, "MeasureGetID");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, CanBeInterruptetBy, 0);
  lua_pushstring(L, "CanBeInterruptetBy");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, GetGametime, 0);
  lua_pushstring(L, "GetGametime");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, GetSeason, 0);
  lua_pushstring(L, "GetSeason");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, GetRound, 0);
  lua_pushstring(L, "GetRound");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, GetYear, 0);
  lua_pushstring(L, "GetYear");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SetTime, 0);
  lua_pushstring(L, "SetTime");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, Gametime2Realtime, 0);
  lua_pushstring(L, "Gametime2Realtime");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, Gametime2Total, 0);
  lua_pushstring(L, "Gametime2Total");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, Realtime2Gametime, 0);
  lua_pushstring(L, "Realtime2Gametime");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SystemGetMeasurePriority, 0);
  lua_pushstring(L, "SystemGetMeasurePriority");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SystemGetMeasureName, 0);
  lua_pushstring(L, "SystemGetMeasureName");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, GetFleePosition, 0);
  lua_pushstring(L, "GetFleePosition");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, GetEvadePosition, 0);
  lua_pushstring(L, "GetEvadePosition");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, CMoveTo, 0);
  lua_pushstring(L, "CMoveTo");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, CMoveToWeak, 0);
  lua_pushstring(L, "CMoveToWeak");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, MoveStop, 0);
  lua_pushstring(L, "MoveStop");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, MoveSetActivity, 0);
  lua_pushstring(L, "MoveSetActivity");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, MoveSetStance, 0);
  lua_pushstring(L, "MoveSetStance");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, MoveGetStance, 0);
  lua_pushstring(L, "MoveGetStance");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, MoveGetPrefPattern, 0);
  lua_pushstring(L, "MoveGetPrefPattern");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, CFollow, 0);
  lua_pushstring(L, "CFollow");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, StopFollow, 0);
  lua_pushstring(L, "StopFollow");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, CFight, 0);
  lua_pushstring(L, "CFight");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SatisfyNeed, 0);
  lua_pushstring(L, "SatisfyNeed");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SimGetNeed, 0);
  lua_pushstring(L, "SimGetNeed");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SimResumePreFightMeasure, 0);
  lua_pushstring(L, "SimResumePreFightMeasure");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, ClearMeasureCache, 0);
  lua_pushstring(L, "ClearMeasureCache");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, StartProduction, 0);
  lua_pushstring(L, "StartProduction");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, StopProduction, 0);
  lua_pushstring(L, "StopProduction");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, GetLocatorByName, 0);
  lua_pushstring(L, "GetLocatorByName");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, LocatorStatus, 0);
  lua_pushstring(L, "LocatorStatus");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, GetFreeLocatorByName, 0);
  lua_pushstring(L, "GetFreeLocatorByName");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, CPlayAnimation, 0);
  lua_pushstring(L, "CPlayAnimation");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, CChangeAnimation, 0);
  lua_pushstring(L, "CChangeAnimation");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, StopAnimation, 0);
  lua_pushstring(L, "StopAnimation");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, StopAllAnimations, 0);
  lua_pushstring(L, "StopAllAnimations");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, CLoopAnimation, 0);
  lua_pushstring(L, "CLoopAnimation");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, GetAnimationLength, 0);
  lua_pushstring(L, "GetAnimationLength");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, Fire, 0);
  lua_pushstring(L, "Fire");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, BlockLocator, 0);
  lua_pushstring(L, "BlockLocator");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, ReleaseLocator, 0);
  lua_pushstring(L, "ReleaseLocator");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, CUseLocator, 0);
  lua_pushstring(L, "CUseLocator");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, LocatorGetBlocker, 0);
  lua_pushstring(L, "LocatorGetBlocker");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, GetLocatorIndex, 0);
  lua_pushstring(L, "GetLocatorIndex");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, CarryObject, 0);
  lua_pushstring(L, "CarryObject");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, HideObject, 0);
  lua_pushstring(L, "HideObject");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, ShowObject, 0);
  lua_pushstring(L, "ShowObject");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, CExitCurrentBuilding, 0);
  lua_pushstring(L, "CExitCurrentBuilding");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, ExitCurrentVehicle, 0);
  lua_pushstring(L, "ExitCurrentVehicle");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, EnterVehicle, 0);
  lua_pushstring(L, "EnterVehicle");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, Kill, 0);
  lua_pushstring(L, "Kill");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, InternalDie, 0);
  lua_pushstring(L, "InternalDie");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, InternalRemove, 0);
  lua_pushstring(L, "InternalRemove");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, CStroll, 0);
  lua_pushstring(L, "CStroll");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, AlignTo, 0);
  lua_pushstring(L, "AlignTo");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, AlignToNearest, 0);
  lua_pushstring(L, "AlignToNearest");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, Evacuate, 0);
  lua_pushstring(L, "Evacuate");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, BuildingRallyWorkers, 0);
  lua_pushstring(L, "BuildingRallyWorkers");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, ChangeResidence, 0);
  lua_pushstring(L, "ChangeResidence");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, GetOutdoorMovePosition, 0);
  lua_pushstring(L, "GetOutdoorMovePosition");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, CheckSkill, 0);
  lua_pushstring(L, "CheckSkill");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SetSkillValue, 0);
  lua_pushstring(L, "SetSkillValue");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, GetSkillValue, 0);
  lua_pushstring(L, "GetSkillValue");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, IncrementSkillValue, 0);
  lua_pushstring(L, "IncrementSkillValue");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, Talk, 0);
  lua_pushstring(L, "Talk");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, QuestTalk, 0);
  lua_pushstring(L, "QuestTalk");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, IsDynastySim, 0);
  lua_pushstring(L, "IsDynastySim");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, IsPartyMember, 0);
  lua_pushstring(L, "IsPartyMember");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, IsOnlyPartyMember, 0);
  lua_pushstring(L, "IsOnlyPartyMember");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SetProcessProgress, 0);
  lua_pushstring(L, "SetProcessProgress");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SetProcessMaxProgress, 0);
  lua_pushstring(L, "SetProcessMaxProgress");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, ResetProcessProgress, 0);
  lua_pushstring(L, "ResetProcessProgress");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SimGetHandsel, 0);
  lua_pushstring(L, "SimGetHandsel");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SimGetWage, 0);
  lua_pushstring(L, "SimGetWage");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SimIsInside, 0);
  lua_pushstring(L, "SimIsInside");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SimSetClass, 0);
  lua_pushstring(L, "SimSetClass");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SimGetClass, 0);
  lua_pushstring(L, "SimGetClass");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SimGetGender, 0);
  lua_pushstring(L, "SimGetGender");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, TradeMemoryEvents, 0);
  lua_pushstring(L, "TradeMemoryEvents");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, CIncrementXP, 0);
  lua_pushstring(L, "CIncrementXP");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, GetSimType, 0);
  lua_pushstring(L, "GetSimType");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SimGetLevel, 0);
  lua_pushstring(L, "SimGetLevel");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SimCreate, 0);
  lua_pushstring(L, "SimCreate");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SimCanBeHired, 0);
  lua_pushstring(L, "SimCanBeHired");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SimHire, 0);
  lua_pushstring(L, "SimHire");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SimIsMortal, 0);
  lua_pushstring(L, "SimIsMortal");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SimSetMortal, 0);
  lua_pushstring(L, "SimSetMortal");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SimSetHireable, 0);
  lua_pushstring(L, "SimSetHireable");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SimHasAbility, 0);
  lua_pushstring(L, "SimHasAbility");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SimIsWorkingTime, 0);
  lua_pushstring(L, "SimIsWorkingTime");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, GetName, 0);
  lua_pushstring(L, "GetName");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SimGetProfession, 0);
  lua_pushstring(L, "SimGetProfession");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SimGetWorkingPlace, 0);
  lua_pushstring(L, "SimGetWorkingPlace");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SimGetAssignedAreaID, 0);
  lua_pushstring(L, "SimGetAssignedAreaID");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SimGetAssignedArea, 0);
  lua_pushstring(L, "SimGetAssignedArea");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SimGetWorkingPlaceID, 0);
  lua_pushstring(L, "SimGetWorkingPlaceID");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, GetFavor, 0);
  lua_pushstring(L, "GetFavor");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, GetFavorToSim, 0);
  lua_pushstring(L, "GetFavorToSim");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, GetFavorToDynasty, 0);
  lua_pushstring(L, "GetFavorToDynasty");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, ModifyFavorToSim, 0);
  lua_pushstring(L, "ModifyFavorToSim");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, ModifyFavorToDynasty, 0);
  lua_pushstring(L, "ModifyFavorToDynasty");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SetFavorToSim, 0);
  lua_pushstring(L, "SetFavorToSim");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SetFavorToDynasty, 0);
  lua_pushstring(L, "SetFavorToDynasty");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SimGetBestEvidence, 0);
  lua_pushstring(L, "SimGetBestEvidence");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SimMarry, 0);
  lua_pushstring(L, "SimMarry");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SimGetBeloved, 0);
  lua_pushstring(L, "SimGetBeloved");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SimGetSpouse, 0);
  lua_pushstring(L, "SimGetSpouse");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SimGetDeadSpouseCount, 0);
  lua_pushstring(L, "SimGetDeadSpouseCount");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SimGetChildren, 0);
  lua_pushstring(L, "SimGetChildren");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SimGetChildrenCount, 0);
  lua_pushstring(L, "SimGetChildrenCount");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SimCanStartCourtLover, 0);
  lua_pushstring(L, "SimCanStartCourtLover");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SimSetCourtLover, 0);
  lua_pushstring(L, "SimSetCourtLover");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SimGetCourtLover, 0);
  lua_pushstring(L, "SimGetCourtLover");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SimGetCourtingSim, 0);
  lua_pushstring(L, "SimGetCourtingSim");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SimIsCourting, 0);
  lua_pushstring(L, "SimIsCourting");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SimGetLiaison, 0);
  lua_pushstring(L, "SimGetLiaison");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SimDoCourtingAction, 0);
  lua_pushstring(L, "SimDoCourtingAction");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SimAddCourtingProgress, 0);
  lua_pushstring(L, "SimAddCourtingProgress");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SimGetFather, 0);
  lua_pushstring(L, "SimGetFather");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SimGetMother, 0);
  lua_pushstring(L, "SimGetMother");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SimGetChildCount, 0);
  lua_pushstring(L, "SimGetChildCount");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SimGetChild, 0);
  lua_pushstring(L, "SimGetChild");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SimGetAlignment, 0);
  lua_pushstring(L, "SimGetAlignment");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SimPauseWorking, 0);
  lua_pushstring(L, "SimPauseWorking");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SimSetBehavior, 0);
  lua_pushstring(L, "SimSetBehavior");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SimGetBehavior, 0);
  lua_pushstring(L, "SimGetBehavior");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SimStartIdleMeasure, 0);
  lua_pushstring(L, "SimStartIdleMeasure");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SimResetBehavior, 0);
  lua_pushstring(L, "SimResetBehavior");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SimSetBehaviorDataFloat, 0);
  lua_pushstring(L, "SimSetBehaviorDataFloat");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SimSetBehaviorDataAlias, 0);
  lua_pushstring(L, "SimSetBehaviorDataAlias");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SimLock, 0);
  lua_pushstring(L, "SimLock");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SimSetFamily, 0);
  lua_pushstring(L, "SimSetFamily");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SimSetFirstname, 0);
  lua_pushstring(L, "SimSetFirstname");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SimSetLastname, 0);
  lua_pushstring(L, "SimSetLastname");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SimGetLastname, 0);
  lua_pushstring(L, "SimGetLastname");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SimGetWealth, 0);
  lua_pushstring(L, "SimGetWealth");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SimCreateCompanion, 0);
  lua_pushstring(L, "SimCreateCompanion");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SimSetParents, 0);
  lua_pushstring(L, "SimSetParents");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SetInvisible, 0);
  lua_pushstring(L, "SetInvisible");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SimSetProduceItemID, 0);
  lua_pushstring(L, "SimSetProduceItemID");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SimGetProduceItemID, 0);
  lua_pushstring(L, "SimGetProduceItemID");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SimGetAge, 0);
  lua_pushstring(L, "SimGetAge");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SimSetAge, 0);
  lua_pushstring(L, "SimSetAge");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SimGetProductivity, 0);
  lua_pushstring(L, "SimGetProductivity");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SimGetPregnant, 0);
  lua_pushstring(L, "SimGetPregnant");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SimGetProgress, 0);
  lua_pushstring(L, "SimGetProgress");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SimSetProgress, 0);
  lua_pushstring(L, "SimSetProgress");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SimGetFavourableCourtingAction, 0);
  lua_pushstring(L, "SimGetFavourableCourtingAction");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SimBeamMeUp, 0);
  lua_pushstring(L, "SimBeamMeUp");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SimStopMeasure, 0);
  lua_pushstring(L, "SimStopMeasure");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, EvidenceGetSeverity, 0);
  lua_pushstring(L, "EvidenceGetSeverity");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, EvidenceGetActor, 0);
  lua_pushstring(L, "EvidenceGetActor");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SimConsumeGoods, 0);
  lua_pushstring(L, "SimConsumeGoods");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SimGetRank, 0);
  lua_pushstring(L, "SimGetRank");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SimArrangeLiaison, 0);
  lua_pushstring(L, "SimArrangeLiaison");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SimChargeCharacter, 0);
  lua_pushstring(L, "SimChargeCharacter");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SimAddDate, 0);
  lua_pushstring(L, "SimAddDate");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SimAddDatebookEntry, 0);
  lua_pushstring(L, "SimAddDatebookEntry");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SimGetReligion, 0);
  lua_pushstring(L, "SimGetReligion");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SimGetChurch, 0);
  lua_pushstring(L, "SimGetChurch");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SimSetReligion, 0);
  lua_pushstring(L, "SimSetReligion");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SimGetFaith, 0);
  lua_pushstring(L, "SimGetFaith");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SimSetFaith, 0);
  lua_pushstring(L, "SimSetFaith");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SimReleaseCourtLover, 0);
  lua_pushstring(L, "SimReleaseCourtLover");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, CalculateCourtingDifficulty, 0);
  lua_pushstring(L, "CalculateCourtingDifficulty");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, BuildingGetInsideSimList, 0);
  lua_pushstring(L, "BuildingGetInsideSimList");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SimCanWorkHere, 0);
  lua_pushstring(L, "SimCanWorkHere");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, BuildingFindSimByName, 0);
  lua_pushstring(L, "BuildingFindSimByName");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, BuildingFindSimByProperty, 0);
  lua_pushstring(L, "BuildingFindSimByProperty");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, BuildingInternalLevelUp, 0);
  lua_pushstring(L, "BuildingInternalLevelUp");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, BuildingCanLevelUp, 0);
  lua_pushstring(L, "BuildingCanLevelUp");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, BuildingFindWaterPos, 0);
  lua_pushstring(L, "BuildingFindWaterPos");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, GetDynastyID, 0);
  lua_pushstring(L, "GetDynastyID");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, GetDynasty, 0);
  lua_pushstring(L, "GetDynasty");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, GetAccessPriceTake, 0);
  lua_pushstring(L, "GetAccessPriceTake");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, GetAccessPriceGive, 0);
  lua_pushstring(L, "GetAccessPriceGive");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, GetInventory, 0);
  lua_pushstring(L, "GetInventory");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SimGetServantDynasty, 0);
  lua_pushstring(L, "SimGetServantDynasty");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SimGetServantDynastyId, 0);
  lua_pushstring(L, "SimGetServantDynastyId");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, BuildingHasUpgrade, 0);
  lua_pushstring(L, "BuildingHasUpgrade");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, BuildingGetMaxWorkerCount, 0);
  lua_pushstring(L, "BuildingGetMaxWorkerCount");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, BuildingGetWorkerCount, 0);
  lua_pushstring(L, "BuildingGetWorkerCount");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, BuildingGetWorker, 0);
  lua_pushstring(L, "BuildingGetWorker");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, BuildingGetSimCount, 0);
  lua_pushstring(L, "BuildingGetSimCount");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, BuildingGetSim, 0);
  lua_pushstring(L, "BuildingGetSim");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, BuildingGetFlag, 0);
  lua_pushstring(L, "BuildingGetFlag");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, BuildingSetFlagColor, 0);
  lua_pushstring(L, "BuildingSetFlagColor");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, BuildingSetWaterPos, 0);
  lua_pushstring(L, "BuildingSetWaterPos");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, BuildingGetWaterPos, 0);
  lua_pushstring(L, "BuildingGetWaterPos");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, BuildingGetPrisoner, 0);
  lua_pushstring(L, "BuildingGetPrisoner");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, BuildingGetNPC, 0);
  lua_pushstring(L, "BuildingGetNPC");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, BuildingGetProfession, 0);
  lua_pushstring(L, "BuildingGetProfession");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, DoNewBornStuff, 0);
  lua_pushstring(L, "DoNewBornStuff");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, BuildingBuy, 0);
  lua_pushstring(L, "BuildingBuy");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, BuildingBuyCart, 0);
  lua_pushstring(L, "BuildingBuyCart");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, BuildingCanBeOwnedBy, 0);
  lua_pushstring(L, "BuildingCanBeOwnedBy");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, BuildingGetProto, 0);
  lua_pushstring(L, "BuildingGetProto");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, BuildingGetWorkingStart, 0);
  lua_pushstring(L, "BuildingGetWorkingStart");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, BuildingGetWorkingEnd, 0);
  lua_pushstring(L, "BuildingGetWorkingEnd");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, BuildingGetFixedCosts, 0);
  lua_pushstring(L, "BuildingGetFixedCosts");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, BuildingGetFreeBudget, 0);
  lua_pushstring(L, "BuildingGetFreeBudget");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, GetBuildingBasePrice, 0);
  lua_pushstring(L, "GetBuildingBasePrice");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, BuildingGetBuyPrice, 0);
  lua_pushstring(L, "BuildingGetBuyPrice");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, BuildingGetValue, 0);
  lua_pushstring(L, "BuildingGetValue");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, BuildingGetPriceProto, 0);
  lua_pushstring(L, "BuildingGetPriceProto");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, BuildingGetRepairPrice, 0);
  lua_pushstring(L, "BuildingGetRepairPrice");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, BuildingGetBaseHP, 0);
  lua_pushstring(L, "BuildingGetBaseHP");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, BuildingCanBeEntered, 0);
  lua_pushstring(L, "BuildingCanBeEntered");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, BuildingHasIndoor, 0);
  lua_pushstring(L, "BuildingHasIndoor");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, BuildingCanHireNewWorker, 0);
  lua_pushstring(L, "BuildingCanHireNewWorker");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, BuildingGetProducerCount, 0);
  lua_pushstring(L, "BuildingGetProducerCount");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, BuildingGetClass, 0);
  lua_pushstring(L, "BuildingGetClass");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, BuildingGetCharacterClass, 0);
  lua_pushstring(L, "BuildingGetCharacterClass");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, BuildingGetType, 0);
  lua_pushstring(L, "BuildingGetType");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, BuildingGetLevel, 0);
  lua_pushstring(L, "BuildingGetLevel");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, BuildingGetOwner, 0);
  lua_pushstring(L, "BuildingGetOwner");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, BuildingSetOwner, 0);
  lua_pushstring(L, "BuildingSetOwner");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, BuildingSetForSale, 0);
  lua_pushstring(L, "BuildingSetForSale");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, BuildingGetForSale, 0);
  lua_pushstring(L, "BuildingGetForSale");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, BuildingGetCity, 0);
  lua_pushstring(L, "BuildingGetCity");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, BuildingGetReligion, 0);
  lua_pushstring(L, "BuildingGetReligion");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, FindWorker, 0);
  lua_pushstring(L, "FindWorker");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, HireWorker, 0);
  lua_pushstring(L, "HireWorker");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, BuildingGetCartCount, 0);
  lua_pushstring(L, "BuildingGetCartCount");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, BuildingGetCart, 0);
  lua_pushstring(L, "BuildingGetCart");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, IsLocatorFree, 0);
  lua_pushstring(L, "IsLocatorFree");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, Name2BuildingType, 0);
  lua_pushstring(L, "Name2BuildingType");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, BuildingLevelMeUp, 0);
  lua_pushstring(L, "BuildingLevelMeUp");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, BuildingCanProduce, 0);
  lua_pushstring(L, "BuildingCanProduce");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, BuildingGetAISetting, 0);
  lua_pushstring(L, "BuildingGetAISetting");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, RoomGetInsideSimList, 0);
  lua_pushstring(L, "RoomGetInsideSimList");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, ShowBuildingFlags, 0);
  lua_pushstring(L, "ShowBuildingFlags");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, BuildingIsWorkingTime, 0);
  lua_pushstring(L, "BuildingIsWorkingTime");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, CommandStructure, 0);
  lua_pushstring(L, "CommandStructure");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, VehicleGetModelName, 0);
  lua_pushstring(L, "VehicleGetModelName");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, VehicleChangeModel, 0);
  lua_pushstring(L, "VehicleChangeModel");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, BankSetCreditOffer, 0);
  lua_pushstring(L, "BankSetCreditOffer");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, BankGetOffer, 0);
  lua_pushstring(L, "BankGetOffer");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, CreditGetSum, 0);
  lua_pushstring(L, "CreditGetSum");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, CreditGetTotal, 0);
  lua_pushstring(L, "CreditGetTotal");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, CreditGetInterest, 0);
  lua_pushstring(L, "CreditGetInterest");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, CreditGetRuntime, 0);
  lua_pushstring(L, "CreditGetRuntime");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, CreditGetRemainingTime, 0);
  lua_pushstring(L, "CreditGetRemainingTime");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, GetMoney, 0);
  lua_pushstring(L, "GetMoney");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SpendMoney, 0);
  lua_pushstring(L, "SpendMoney");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, CreditMoney, 0);
  lua_pushstring(L, "CreditMoney");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SetEndlessMoney, 0);
  lua_pushstring(L, "SetEndlessMoney");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, DynastyGetMemberCount, 0);
  lua_pushstring(L, "DynastyGetMemberCount");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, DynastyGetMember, 0);
  lua_pushstring(L, "DynastyGetMember");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, DynastyGetFamilyMemberCount, 0);
  lua_pushstring(L, "DynastyGetFamilyMemberCount");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, DynastyGetFamilyMember, 0);
  lua_pushstring(L, "DynastyGetFamilyMember");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, DynastyGetMemberRandom, 0);
  lua_pushstring(L, "DynastyGetMemberRandom");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, DynastyGetHomeCity, 0);
  lua_pushstring(L, "DynastyGetHomeCity");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, DynastyGetBuildingCount, 0);
  lua_pushstring(L, "DynastyGetBuildingCount");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, DynastyGetRandomBuilding, 0);
  lua_pushstring(L, "DynastyGetRandomBuilding");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, DynastyFindIdleWorker, 0);
  lua_pushstring(L, "DynastyFindIdleWorker");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, DynastyGetWorkerCount, 0);
  lua_pushstring(L, "DynastyGetWorkerCount");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, DynastyGetWorker, 0);
  lua_pushstring(L, "DynastyGetWorker");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, DynastyGetBuildingCount2, 0);
  lua_pushstring(L, "DynastyGetBuildingCount2");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, DynastyGetBuilding2, 0);
  lua_pushstring(L, "DynastyGetBuilding2");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, DynastyGetRandomVictim, 0);
  lua_pushstring(L, "DynastyGetRandomVictim");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, DynastyGetDiplomacyState, 0);
  lua_pushstring(L, "DynastyGetDiplomacyState");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, DynastyGetDiplomacyOffer, 0);
  lua_pushstring(L, "DynastyGetDiplomacyOffer");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, DynastySetMinDiplomacyState, 0);
  lua_pushstring(L, "DynastySetMinDiplomacyState");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, DynastySetMaxDiplomacyState, 0);
  lua_pushstring(L, "DynastySetMaxDiplomacyState");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, DynastyGetMinDiplomacyState, 0);
  lua_pushstring(L, "DynastyGetMinDiplomacyState");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, DynastyGetMaxDiplomacyState, 0);
  lua_pushstring(L, "DynastyGetMaxDiplomacyState");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, DynastySetDiplomacyState, 0);
  lua_pushstring(L, "DynastySetDiplomacyState");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, DynastyMakeImpact, 0);
  lua_pushstring(L, "DynastyMakeImpact");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, DynastyFindNewBuilding, 0);
  lua_pushstring(L, "DynastyFindNewBuilding");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, DynastyIsPlayer, 0);
  lua_pushstring(L, "DynastyIsPlayer");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, DynastyIsDead, 0);
  lua_pushstring(L, "DynastyIsDead");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, DynastyGetTeam, 0);
  lua_pushstring(L, "DynastyGetTeam");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, DynastyGetTotalSeaTradeValue, 0);
  lua_pushstring(L, "DynastyGetTotalSeaTradeValue");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, DynastySetTeam, 0);
  lua_pushstring(L, "DynastySetTeam");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, CanBuildWorkshop, 0);
  lua_pushstring(L, "CanBuildWorkshop");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, GetMaxWorkshopCount, 0);
  lua_pushstring(L, "GetMaxWorkshopCount");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, DynastyIsShadow, 0);
  lua_pushstring(L, "DynastyIsShadow");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, DynastyIsAI, 0);
  lua_pushstring(L, "DynastyIsAI");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, GetLocalPlayerDynasty, 0);
  lua_pushstring(L, "GetLocalPlayerDynasty");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, DynastyAddMember, 0);
  lua_pushstring(L, "DynastyAddMember");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, DynastyRemoveMember, 0);
  lua_pushstring(L, "DynastyRemoveMember");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, DynastyTakeCredit, 0);
  lua_pushstring(L, "DynastyTakeCredit");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, DynastyPaybackCredit, 0);
  lua_pushstring(L, "DynastyPaybackCredit");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, DynastyGetCredit, 0);
  lua_pushstring(L, "DynastyGetCredit");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, DynastyGetRanking, 0);
  lua_pushstring(L, "DynastyGetRanking");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, DynastyGetColor, 0);
  lua_pushstring(L, "DynastyGetColor");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, DynastyForceCalcDiplomacy, 0);
  lua_pushstring(L, "DynastyForceCalcDiplomacy");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, DynastyRemoveDiplomacyStateImpact, 0);
  lua_pushstring(L, "DynastyRemoveDiplomacyStateImpact");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, DynastyAvoidControl, 0);
  lua_pushstring(L, "DynastyAvoidControl");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, GetHomeBuilding, 0);
  lua_pushstring(L, "GetHomeBuilding");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SetHomeBuilding, 0);
  lua_pushstring(L, "SetHomeBuilding");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, GetHomeBuildingId, 0);
  lua_pushstring(L, "GetHomeBuildingId");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SetState, 0);
  lua_pushstring(L, "SetState");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SetStateImpact, 0);
  lua_pushstring(L, "SetStateImpact");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, ClearStateImpact, 0);
  lua_pushstring(L, "ClearStateImpact");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, GetStateImpact, 0);
  lua_pushstring(L, "GetStateImpact");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, GetState, 0);
  lua_pushstring(L, "GetState");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, IsDead, 0);
  lua_pushstring(L, "IsDead");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, PlaySound, 0);
  lua_pushstring(L, "PlaySound");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, PlaySoundVariation, 0);
  lua_pushstring(L, "PlaySoundVariation");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, PlaySound3D, 0);
  lua_pushstring(L, "PlaySound3D");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, PlaySound3DVariation, 0);
  lua_pushstring(L, "PlaySound3DVariation");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, StartHighPriorMusic, 0);
  lua_pushstring(L, "StartHighPriorMusic");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, ShowBoundingBox, 0);
  lua_pushstring(L, "ShowBoundingBox");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, ReadyToRepeat, 0);
  lua_pushstring(L, "ReadyToRepeat");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SetRepeatTimer, 0);
  lua_pushstring(L, "SetRepeatTimer");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, GetRepeatTimerLeft, 0);
  lua_pushstring(L, "GetRepeatTimerLeft");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, GetRepeatTimerEndtime, 0);
  lua_pushstring(L, "GetRepeatTimerEndtime");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SetMeasureRepeat, 0);
  lua_pushstring(L, "SetMeasureRepeat");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, GetMeasureRepeatName, 0);
  lua_pushstring(L, "GetMeasureRepeatName");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, GetMeasureRepeatName2, 0);
  lua_pushstring(L, "GetMeasureRepeatName2");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, GetMeasureRepeat, 0);
  lua_pushstring(L, "GetMeasureRepeat");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, CreateScriptcall, 0);
  lua_pushstring(L, "CreateScriptcall");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, RemoveScriptcall, 0);
  lua_pushstring(L, "RemoveScriptcall");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, CanAddItems, 0);
  lua_pushstring(L, "CanAddItems");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, AddItems, 0);
  lua_pushstring(L, "AddItems");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, RemoveItems, 0);
  lua_pushstring(L, "RemoveItems");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, RemoveEmptySlots, 0);
  lua_pushstring(L, "RemoveEmptySlots");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, TransferItems, 0);
  lua_pushstring(L, "TransferItems");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, Transfer, 0);
  lua_pushstring(L, "Transfer");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, ThrowObject, 0);
  lua_pushstring(L, "ThrowObject");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, GetRemainingInventorySpace, 0);
  lua_pushstring(L, "GetRemainingInventorySpace");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, FindResourceProto, 0);
  lua_pushstring(L, "FindResourceProto");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, ResourceFind, 0);
  lua_pushstring(L, "ResourceFind");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, ResourceGetLevel, 0);
  lua_pushstring(L, "ResourceGetLevel");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, ResourceGetEntry, 0);
  lua_pushstring(L, "ResourceGetEntry");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, ResourceGetItemId, 0);
  lua_pushstring(L, "ResourceGetItemId");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, ResourceGetScriptFunc, 0);
  lua_pushstring(L, "ResourceGetScriptFunc");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, ResourceGetMeasureID, 0);
  lua_pushstring(L, "ResourceGetMeasureID");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, ResourceCanBeChanged, 0);
  lua_pushstring(L, "ResourceCanBeChanged");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, ResourceGetTypeCount, 0);
  lua_pushstring(L, "ResourceGetTypeCount");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, ResourceGetTypeItem, 0);
  lua_pushstring(L, "ResourceGetTypeItem");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, ResourceSow, 0);
  lua_pushstring(L, "ResourceSow");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, GetInsideBuilding, 0);
  lua_pushstring(L, "GetInsideBuilding");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, GetInsideRoom, 0);
  lua_pushstring(L, "GetInsideRoom");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, GetInsideBuildingID, 0);
  lua_pushstring(L, "GetInsideBuildingID");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, CanBeControlled, 0);
  lua_pushstring(L, "CanBeControlled");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, ObjectSetMeasureIcon, 0);
  lua_pushstring(L, "ObjectSetMeasureIcon");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, ObjectClearMeasureIcon, 0);
  lua_pushstring(L, "ObjectClearMeasureIcon");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, ObjectSetStateIcon, 0);
  lua_pushstring(L, "ObjectSetStateIcon");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, ObjectClearStateIcon, 0);
  lua_pushstring(L, "ObjectClearStateIcon");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SetExclusiveMeasure, 0);
  lua_pushstring(L, "SetExclusiveMeasure");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, ForbidMeasure, 0);
  lua_pushstring(L, "ForbidMeasure");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, AllowMeasure, 0);
  lua_pushstring(L, "AllowMeasure");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, AllowAllMeasures, 0);
  lua_pushstring(L, "AllowAllMeasures");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, GetHP, 0);
  lua_pushstring(L, "GetHP");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, GetHPRelative, 0);
  lua_pushstring(L, "GetHPRelative");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, ModifyHP, 0);
  lua_pushstring(L, "ModifyHP");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, GetMaxHP, 0);
  lua_pushstring(L, "GetMaxHP");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, AddImpact, 0);
  lua_pushstring(L, "AddImpact");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, ImpactGetMaxTimeleft, 0);
  lua_pushstring(L, "ImpactGetMaxTimeleft");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, RemoveImpact, 0);
  lua_pushstring(L, "RemoveImpact");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, GetImpactValue, 0);
  lua_pushstring(L, "GetImpactValue");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, IsType, 0);
  lua_pushstring(L, "IsType");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, IsTypeExact, 0);
  lua_pushstring(L, "IsTypeExact");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SetName, 0);
  lua_pushstring(L, "SetName");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, FadeOutAllFE, 0);
  lua_pushstring(L, "FadeOutAllFE");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, AddObjectDependendImpact, 0);
  lua_pushstring(L, "AddObjectDependendImpact");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, RemoveAllObjectDependendImpacts, 0);
  lua_pushstring(L, "RemoveAllObjectDependendImpacts");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, GetNearestSettlement, 0);
  lua_pushstring(L, "GetNearestSettlement");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, AddImpactDependendImpact, 0);
  lua_pushstring(L, "AddImpactDependendImpact");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, RemoveAllImpactDependendImpacts, 0);
  lua_pushstring(L, "RemoveAllImpactDependendImpacts");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, ObjectSetHighlight, 0);
  lua_pushstring(L, "ObjectSetHighlight");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, ShowOverheadMeasureSymbol, 0);
  lua_pushstring(L, "ShowOverheadMeasureSymbol");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, Plunder, 0);
  lua_pushstring(L, "Plunder");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, BattleJoin, 0);
  lua_pushstring(L, "BattleJoin");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, BattleLeave, 0);
  lua_pushstring(L, "BattleLeave");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, BattleFlee, 0);
  lua_pushstring(L, "BattleFlee");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, BattleGetNextEnemy, 0);
  lua_pushstring(L, "BattleGetNextEnemy");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, BattleGetWeaponName, 0);
  lua_pushstring(L, "BattleGetWeaponName");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, BattleWeaponPresent, 0);
  lua_pushstring(L, "BattleWeaponPresent");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, BattleWeaponStore, 0);
  lua_pushstring(L, "BattleWeaponStore");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, BattleIsFighting, 0);
  lua_pushstring(L, "BattleIsFighting");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, GetArmor, 0);
  lua_pushstring(L, "GetArmor");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, GetDirectionTo, 0);
  lua_pushstring(L, "GetDirectionTo");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, GetRotationTo, 0);
  lua_pushstring(L, "GetRotationTo");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, GetNobilityTitle, 0);
  lua_pushstring(L, "GetNobilityTitle");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, GetNobilityTitleLabel, 0);
  lua_pushstring(L, "GetNobilityTitleLabel");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SetNobilityTitle, 0);
  lua_pushstring(L, "SetNobilityTitle");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SimGetDivorced, 0);
  lua_pushstring(L, "SimGetDivorced");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SimSetDoctorTitle, 0);
  lua_pushstring(L, "SimSetDoctorTitle");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SimGetWeaponDamage, 0);
  lua_pushstring(L, "SimGetWeaponDamage");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SetAvoidanceRange, 0);
  lua_pushstring(L, "SetAvoidanceRange");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SetActiveAvoidance, 0);
  lua_pushstring(L, "SetActiveAvoidance");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SetPassiveAvoidance, 0);
  lua_pushstring(L, "SetPassiveAvoidance");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SetAvoidanceGroup, 0);
  lua_pushstring(L, "SetAvoidanceGroup");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, ReleaseAvoidanceGroup, 0);
  lua_pushstring(L, "ReleaseAvoidanceGroup");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, GetRadius, 0);
  lua_pushstring(L, "GetRadius");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, GetVehicle, 0);
  lua_pushstring(L, "GetVehicle");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SetContext, 0);
  lua_pushstring(L, "SetContext");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SetDestroyed, 0);
  lua_pushstring(L, "SetDestroyed");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, CopyAlias, 0);
  lua_pushstring(L, "CopyAlias");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, GetPosition, 0);
  lua_pushstring(L, "GetPosition");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, GetPositionOfSubobject, 0);
  lua_pushstring(L, "GetPositionOfSubobject");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SetPosition, 0);
  lua_pushstring(L, "SetPosition");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, PositionModify, 0);
  lua_pushstring(L, "PositionModify");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, PositionGetArea, 0);
  lua_pushstring(L, "PositionGetArea");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, PositionSetArea, 0);
  lua_pushstring(L, "PositionSetArea");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, PositionGetVector, 0);
  lua_pushstring(L, "PositionGetVector");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, PositionGetRotation, 0);
  lua_pushstring(L, "PositionGetRotation");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, PositionSetVector, 0);
  lua_pushstring(L, "PositionSetVector");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, Position2GuildObject, 0);
  lua_pushstring(L, "Position2GuildObject");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, PositionMove, 0);
  lua_pushstring(L, "PositionMove");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, GetWorldPositionXYZ, 0);
  lua_pushstring(L, "GetWorldPositionXYZ");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, GetPositionXYZ, 0);
  lua_pushstring(L, "GetPositionXYZ");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, GetDistance, 0);
  lua_pushstring(L, "GetDistance");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, ObjectGetRotationY, 0);
  lua_pushstring(L, "ObjectGetRotationY");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, GetRotation, 0);
  lua_pushstring(L, "GetRotation");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, GetSettlement, 0);
  lua_pushstring(L, "GetSettlement");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, GetSettlementID, 0);
  lua_pushstring(L, "GetSettlementID");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, CityGetRandomBuilding, 0);
  lua_pushstring(L, "CityGetRandomBuilding");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, CityGetNearestBuilding, 0);
  lua_pushstring(L, "CityGetNearestBuilding");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, CityGetBuildingCount, 0);
  lua_pushstring(L, "CityGetBuildingCount");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, CityGetBuildings, 0);
  lua_pushstring(L, "CityGetBuildings");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, CityGetBuildingForCharacter, 0);
  lua_pushstring(L, "CityGetBuildingForCharacter");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, CityGetBuildingCountForCharacter, 0);
  lua_pushstring(L, "CityGetBuildingCountForCharacter");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, CityGetBuildingByName, 0);
  lua_pushstring(L, "CityGetBuildingByName");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, CityGetServantCount, 0);
  lua_pushstring(L, "CityGetServantCount");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, CityGetServant, 0);
  lua_pushstring(L, "CityGetServant");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, CityBuildNewBuilding, 0);
  lua_pushstring(L, "CityBuildNewBuilding");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, CityGetCitizenCount, 0);
  lua_pushstring(L, "CityGetCitizenCount");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, CityGetCrimeRate, 0);
  lua_pushstring(L, "CityGetCrimeRate");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, CityModifyCrimeRate, 0);
  lua_pushstring(L, "CityModifyCrimeRate");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, CityGetLevel, 0);
  lua_pushstring(L, "CityGetLevel");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, CitySetMaxWorkerhutLevel, 0);
  lua_pushstring(L, "CitySetMaxWorkerhutLevel");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, CitySetFixedPrice, 0);
  lua_pushstring(L, "CitySetFixedPrice");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, CityGetMaxWorkerhutLevel, 0);
  lua_pushstring(L, "CityGetMaxWorkerhutLevel");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, CityGuardScan, 0);
  lua_pushstring(L, "CityGuardScan");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, CityGetWantedTime, 0);
  lua_pushstring(L, "CityGetWantedTime");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, CityGetPenalty, 0);
  lua_pushstring(L, "CityGetPenalty");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, CityLevel2Label, 0);
  lua_pushstring(L, "CityLevel2Label");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, CitySimBreakout, 0);
  lua_pushstring(L, "CitySimBreakout");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, CityScheduleCutsceneEvent, 0);
  lua_pushstring(L, "CityScheduleCutsceneEvent");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, CityAssignTrialRoles, 0);
  lua_pushstring(L, "CityAssignTrialRoles");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, CityAddPenalty, 0);
  lua_pushstring(L, "CityAddPenalty");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, CityGetNumEvents, 0);
  lua_pushstring(L, "CityGetNumEvents");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, CityGetEventText, 0);
  lua_pushstring(L, "CityGetEventText");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, CityGetDynastyCharList, 0);
  lua_pushstring(L, "CityGetDynastyCharList");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SimCanBeCharged, 0);
  lua_pushstring(L, "SimCanBeCharged");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, CityFindCrowdedPlace, 0);
  lua_pushstring(L, "CityFindCrowdedPlace");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, CityFindSquad, 0);
  lua_pushstring(L, "CityFindSquad");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, CityGetLocalMarket, 0);
  lua_pushstring(L, "CityGetLocalMarket");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, CityIsKontor, 0);
  lua_pushstring(L, "CityIsKontor");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, CityGetSeller, 0);
  lua_pushstring(L, "CityGetSeller");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, PenaltyFinish, 0);
  lua_pushstring(L, "PenaltyFinish");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, PenaltyGetPrisonTime, 0);
  lua_pushstring(L, "PenaltyGetPrisonTime");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, PenaltyGetType, 0);
  lua_pushstring(L, "PenaltyGetType");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, PenaltyReset, 0);
  lua_pushstring(L, "PenaltyReset");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, PenaltyGetOffender, 0);
  lua_pushstring(L, "PenaltyGetOffender");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SettlementEventGetTime, 0);
  lua_pushstring(L, "SettlementEventGetTime");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, Attach3DSound, 0);
  lua_pushstring(L, "Attach3DSound");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, Detach3DSound, 0);
  lua_pushstring(L, "Detach3DSound");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, CartGetOperator, 0);
  lua_pushstring(L, "CartGetOperator");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, CartCreateEscort, 0);
  lua_pushstring(L, "CartCreateEscort");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, CartRemoveEscort, 0);
  lua_pushstring(L, "CartRemoveEscort");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, CartCheckEscort, 0);
  lua_pushstring(L, "CartCheckEscort");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, CartCheckFighting, 0);
  lua_pushstring(L, "CartCheckFighting");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, CartGetEscortCount, 0);
  lua_pushstring(L, "CartGetEscortCount");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, CartGetType, 0);
  lua_pushstring(L, "CartGetType");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, ItemGetName, 0);
  lua_pushstring(L, "ItemGetName");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, ItemGetSlot, 0);
  lua_pushstring(L, "ItemGetSlot");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, ItemGetProductionTime, 0);
  lua_pushstring(L, "ItemGetProductionTime");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, ItemGetProductionAmount, 0);
  lua_pushstring(L, "ItemGetProductionAmount");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, ItemGetBasePrice, 0);
  lua_pushstring(L, "ItemGetBasePrice");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, ItemGetPriceBuy, 0);
  lua_pushstring(L, "ItemGetPriceBuy");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, ItemGetPriceSell, 0);
  lua_pushstring(L, "ItemGetPriceSell");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, ItemGetSubstLevel, 0);
  lua_pushstring(L, "ItemGetSubstLevel");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, ItemGetLabel, 0);
  lua_pushstring(L, "ItemGetLabel");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, ItemGetID, 0);
  lua_pushstring(L, "ItemGetID");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, ItemGetType, 0);
  lua_pushstring(L, "ItemGetType");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, ItemGetCategory, 0);
  lua_pushstring(L, "ItemGetCategory");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, GetItemCount, 0);
  lua_pushstring(L, "GetItemCount");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, IsInLoadingRange, 0);
  lua_pushstring(L, "IsInLoadingRange");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, StartSingleShotParticle, 0);
  lua_pushstring(L, "StartSingleShotParticle");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, CommitAction, 0);
  lua_pushstring(L, "CommitAction");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, StopAction, 0);
  lua_pushstring(L, "StopAction");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, ActionLock, 0);
  lua_pushstring(L, "ActionLock");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, ActionIsEvidence, 0);
  lua_pushstring(L, "ActionIsEvidence");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, ActionIsStopped, 0);
  lua_pushstring(L, "ActionIsStopped");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, InventoryGetSlotCount, 0);
  lua_pushstring(L, "InventoryGetSlotCount");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, InventoryGetSlotSize, 0);
  lua_pushstring(L, "InventoryGetSlotSize");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, InventoryGetSlotInfo, 0);
  lua_pushstring(L, "InventoryGetSlotInfo");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, FadeOutFE, 0);
  lua_pushstring(L, "FadeOutFE");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, FadeInFE, 0);
  lua_pushstring(L, "FadeInFE");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, PlayFE, 0);
  lua_pushstring(L, "PlayFE");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, BaseFE, 0);
  lua_pushstring(L, "BaseFE");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SetAppearance, 0);
  lua_pushstring(L, "SetAppearance");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, StartEmote, 0);
  lua_pushstring(L, "StartEmote");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, StopEmote, 0);
  lua_pushstring(L, "StopEmote");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, GetEvidenceAlignmentSum, 0);
  lua_pushstring(L, "GetEvidenceAlignmentSum");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, GetEvidenceValues, 0);
  lua_pushstring(L, "GetEvidenceValues");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, RemoveEvidences, 0);
  lua_pushstring(L, "RemoveEvidences");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SimGetCrimeList, 0);
  lua_pushstring(L, "SimGetCrimeList");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, CrimeForfeit, 0);
  lua_pushstring(L, "CrimeForfeit");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, CrimeGetEvidenceValue, 0);
  lua_pushstring(L, "CrimeGetEvidenceValue");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, ListCrimeReport, 0);
  lua_pushstring(L, "ListCrimeReport");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, GetHoursToNextTrial, 0);
  lua_pushstring(L, "GetHoursToNextTrial");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, CampaignExit, 0);
  lua_pushstring(L, "CampaignExit");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, CheckPlayerExtinct, 0);
  lua_pushstring(L, "CheckPlayerExtinct");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, CheckPlayerBankrupt, 0);
  lua_pushstring(L, "CheckPlayerBankrupt");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SetQuestDestination, 0);
  lua_pushstring(L, "SetQuestDestination");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, NotifyOnStateChange, 0);
  lua_pushstring(L, "NotifyOnStateChange");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SetQuestSource, 0);
  lua_pushstring(L, "SetQuestSource");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, BindQuest, 0);
  lua_pushstring(L, "BindQuest");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, StartQuest, 0);
  lua_pushstring(L, "StartQuest");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, StartMission, 0);
  lua_pushstring(L, "StartMission");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, ResetQuest, 0);
  lua_pushstring(L, "ResetQuest");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, KillQuest, 0);
  lua_pushstring(L, "KillQuest");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SetQuestTitle, 0);
  lua_pushstring(L, "SetQuestTitle");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SetQuestDescription, 0);
  lua_pushstring(L, "SetQuestDescription");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SetQuestDescriptionByQuestname, 0);
  lua_pushstring(L, "SetQuestDescriptionByQuestname");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, HasRunningQuest, 0);
  lua_pushstring(L, "HasRunningQuest");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SetMainQuest, 0);
  lua_pushstring(L, "SetMainQuest");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SetMainQuestTitle, 0);
  lua_pushstring(L, "SetMainQuestTitle");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SetMainQuestDescription, 0);
  lua_pushstring(L, "SetMainQuestDescription");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, EndCutscene, 0);
  lua_pushstring(L, "EndCutscene");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, BuildingLockForCutscene, 0);
  lua_pushstring(L, "BuildingLockForCutscene");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, CutsceneAddEvent, 0);
  lua_pushstring(L, "CutsceneAddEvent");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, CutsceneCallScheduled, 0);
  lua_pushstring(L, "CutsceneCallScheduled");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, CutsceneCallUnscheduled, 0);
  lua_pushstring(L, "CutsceneCallUnscheduled");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, CutsceneCallThread, 0);
  lua_pushstring(L, "CutsceneCallThread");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, CutsceneCollectEvidences, 0);
  lua_pushstring(L, "CutsceneCollectEvidences");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, AddEvidence, 0);
  lua_pushstring(L, "AddEvidence");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, CutsceneSetData, 0);
  lua_pushstring(L, "CutsceneSetData");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, CutsceneGetData, 0);
  lua_pushstring(L, "CutsceneGetData");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, CutsceneSendEventTrigger, 0);
  lua_pushstring(L, "CutsceneSendEventTrigger");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, CutsceneAddTriggerEvent, 0);
  lua_pushstring(L, "CutsceneAddTriggerEvent");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, CreateCutscene, 0);
  lua_pushstring(L, "CreateCutscene");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, CopyAliasToCutscene, 0);
  lua_pushstring(L, "CopyAliasToCutscene");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, CopyAliasFromCutscene, 0);
  lua_pushstring(L, "CopyAliasFromCutscene");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, SimGetCutscene, 0);
  lua_pushstring(L, "SimGetCutscene");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, ListAllCutscenes, 0);
  lua_pushstring(L, "ListAllCutscenes");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, BuildingGetCutscene, 0);
  lua_pushstring(L, "BuildingGetCutscene");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, ProfessionGetLabel, 0);
  lua_pushstring(L, "ProfessionGetLabel");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, AIExecutePlan, 0);
  lua_pushstring(L, "AIExecutePlan");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, AICheckWorkingPlace, 0);
  lua_pushstring(L, "AICheckWorkingPlace");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, AIFindGoodClass, 0);
  lua_pushstring(L, "AIFindGoodClass");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, GetCrimeLocation, 0);
  lua_pushstring(L, "GetCrimeLocation");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, GfxAttachObject, 0);
  lua_pushstring(L, "GfxAttachObject");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, GfxDetachObject, 0);
  lua_pushstring(L, "GfxDetachObject");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, GfxStartParticle, 0);
  lua_pushstring(L, "GfxStartParticle");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, AttachModel, 0);
  lua_pushstring(L, "AttachModel");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, DynastyGetFlagNumber, 0);
  lua_pushstring(L, "DynastyGetFlagNumber");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, ScenarioSetNameLanguage, 0);
  lua_pushstring(L, "ScenarioSetNameLanguage");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, BlackBoardAddPamphlet, 0);
  lua_pushstring(L, "BlackBoardAddPamphlet");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, BlackBoardRemovePamphlet, 0);
  lua_pushstring(L, "BlackBoardRemovePamphlet");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, Mount, 0);
  lua_pushstring(L, "Mount");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, Unmount, 0);
  lua_pushstring(L, "Unmount");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, IsMount, 0);
  lua_pushstring(L, "IsMount");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, IsMounted, 0);
  lua_pushstring(L, "IsMounted");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, GetMount, 0);
  lua_pushstring(L, "GetMount");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, BuildingGetRoom, 0);
  lua_pushstring(L, "BuildingGetRoom");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, GetRandomPlayerDynasty, 0);
  lua_pushstring(L, "GetRandomPlayerDynasty");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, ScenarioGetBuildingCount, 0);
  lua_pushstring(L, "ScenarioGetBuildingCount");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, RoomLockForCutscene, 0);
  lua_pushstring(L, "RoomLockForCutscene");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  lua_pushcclosure(L, IncrementXPQuiet, 0);
  lua_pushstring(L, "IncrementXPQuiet");
  lua_insert(L, -2);
  lua_settable(L, LUA_GLOBALSINDEX);

  GuildGameScriptBinding_RegisterExtensions(L);
}
