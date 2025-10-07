#include "GuildGameScriptBinding.hpp"
#include "BindingExtensions/GuildGameScriptBinding_Extensions.hpp"

#define USE_NATIVE_BINDINGS //TODO

#ifndef USE_NATIVE_BINDINGS
    #include "GuildGameScriptBinding/UNIMPLEMENTED.hpp"
    #include "GuildGameScriptBinding/GetHP.cpp"
    #include "GuildGameScriptBinding/GetHPRelative.cpp"
    #include "GuildGameScriptBinding/SimSetCourtLover.cpp"
    #include "GuildGameScriptBinding/SimSetProgress.cpp"
#endif


#ifdef USE_NATIVE_BINDINGS
    #include "GuildGameScriptBinding/UNIMPLEMENTED.hpp"
#endif

#include "Profiling.hpp"
#include <chrono>
#include <iostream>

#define LUA_PROLOG() \
    auto profiler_start_time = std::chrono::high_resolution_clock::now();

#define LUA_EPILOG(func_name_str) \
    auto profiler_end_time = std::chrono::high_resolution_clock::now(); \
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(profiler_end_time - profiler_start_time).count(); \
    Profiling::LogCall(func_name_str, duration);

auto tolua_init = reinterpret_cast<void(__cdecl *)(lua_State *)>(0x006f6780);

auto BuildingScriptBinding = reinterpret_cast<void(__cdecl *)(lua_State *)>(0x006f66f0);
auto WeatherScriptBinding = reinterpret_cast<void(__cdecl *)(lua_State *)>(0x006f60b0);
auto CameraScriptBinding = reinterpret_cast<void(__cdecl *)(lua_State *)>(0x006f5540);
auto OfficeScriptBinding = reinterpret_cast<void(__cdecl *)(lua_State *)>(0x006f3700);

#ifndef LUA_PROLOG
#define LUA_PROLOG()
#endif

#ifndef LUA_EPILOG
#define LUA_EPILOG(func_name_str)
#endif


#define BIND_LUA_FUNCTION(L_STATE, FUNC_NAME) \
    do { \
        auto wrapper_lambda = [](lua_State* l) -> int { \
            LUA_PROLOG(); \
            int result = FUNC_NAME(l); \
            LUA_EPILOG(#FUNC_NAME); \
            return result; \
        }; \
        lua_pushcclosure(L_STATE, wrapper_lambda, 0); \
        lua_pushstring(L_STATE, #FUNC_NAME); \
        lua_insert(L_STATE, -2); \
        lua_settable(L_STATE, LUA_GLOBALSINDEX); \
    } while (0)

void GuildGameScriptBinding(lua_State *L) {
  //Profiling::Init();
  tolua_init(L);
  BuildingScriptBinding(L);
  WeatherScriptBinding(L);
  CameraScriptBinding(L);
  OfficeScriptBinding(L);

  BIND_LUA_FUNCTION(L, SimFindProduction);

  BIND_LUA_FUNCTION(L, SquadCreate);

  BIND_LUA_FUNCTION(L, SquadGet);

  BIND_LUA_FUNCTION(L, SimFindSquad);

  BIND_LUA_FUNCTION(L, DynastyFindSquad);

  BIND_LUA_FUNCTION(L, SquadDestroy);

  BIND_LUA_FUNCTION(L, SquadAddRandom);

  BIND_LUA_FUNCTION(L, SquadGetProfession);

  BIND_LUA_FUNCTION(L, SquadGetMemberCount);

  BIND_LUA_FUNCTION(L, SquadGetVacantPlace);

  BIND_LUA_FUNCTION(L, SquadIsReady);

  BIND_LUA_FUNCTION(L, SquadSetReady);

  BIND_LUA_FUNCTION(L, SquadIsNeeded);

  BIND_LUA_FUNCTION(L, SquadAddMember);

  BIND_LUA_FUNCTION(L, SquadRemoveMember);

  BIND_LUA_FUNCTION(L, SquadGetLeader);

  BIND_LUA_FUNCTION(L, SquadGetLeaderId);

  BIND_LUA_FUNCTION(L, SquadGetMember);

  BIND_LUA_FUNCTION(L, SquadMemberExists);

  BIND_LUA_FUNCTION(L, SquadGetMeetingPlace);

  BIND_LUA_FUNCTION(L, SquadSetMeetingPlace);

  BIND_LUA_FUNCTION(L, SquadGetState);

  BIND_LUA_FUNCTION(L, SetArg);

  BIND_LUA_FUNCTION(L, OutputDebugString);

  BIND_LUA_FUNCTION(L, CMsgNews);

  BIND_LUA_FUNCTION(L, MsgQuick);

  BIND_LUA_FUNCTION(L, MsgMeasure);

  BIND_LUA_FUNCTION(L, MsgSystem);

  BIND_LUA_FUNCTION(L, CMsgSay);

  BIND_LUA_FUNCTION(L, ShowOverheadSymbol);

  BIND_LUA_FUNCTION(L, RemoveOverheadSymbol);

  BIND_LUA_FUNCTION(L, RemoveOverheadSymbols);

  BIND_LUA_FUNCTION(L, RemoveAllOverheadSymbols);

  BIND_LUA_FUNCTION(L, StartGameTimer);

  BIND_LUA_FUNCTION(L, CheckGameTimerEnd);

  BIND_LUA_FUNCTION(L, RemoveDialogBox);

  BIND_LUA_FUNCTION(L, SetCampaignEndText);

  BIND_LUA_FUNCTION(L, ScenarioGetObjectByName);

  BIND_LUA_FUNCTION(L, ScenarioGetKontorGoodCount);

  BIND_LUA_FUNCTION(L, ScenarioGetKontorGoodInfo);

  BIND_LUA_FUNCTION(L, ScenarioGetItemIdCount);

  BIND_LUA_FUNCTION(L, ScenarioGetItemIdByNumber);

  BIND_LUA_FUNCTION(L, ScenarioGetRandomObject);

  BIND_LUA_FUNCTION(L, ScenarioGetObjects);

  BIND_LUA_FUNCTION(L, ScenarioGetImperialCapitalId);

  BIND_LUA_FUNCTION(L, ScenarioGetImperialCapital);

  BIND_LUA_FUNCTION(L, ScenarioSetImperialCapital);

  BIND_LUA_FUNCTION(L, ScenarioCreateResource);

  BIND_LUA_FUNCTION(L, ScenarioGetTimePlayed);

  BIND_LUA_FUNCTION(L, ScenarioCreatePosition);

  BIND_LUA_FUNCTION(L, ScenarioFindBuildingProto);

  BIND_LUA_FUNCTION(L, ScenarioFindBuildingProtoForCharacter);

  BIND_LUA_FUNCTION(L, ScenarioFindPosition);

  BIND_LUA_FUNCTION(L, ScenarioSetYearsPerRound);

  BIND_LUA_FUNCTION(L, GetScenario);

  BIND_LUA_FUNCTION(L, ScenarioCreateCart);

  BIND_LUA_FUNCTION(L, ScenarioGetUnspawnedEnemiesCount);

  BIND_LUA_FUNCTION(L, ScenarioGetYearsPerRound);

  BIND_LUA_FUNCTION(L, ScenarioStopUsingOutdoorScrollBoundaries);

  BIND_LUA_FUNCTION(L, ScenarioSetOutdoorScrollBoundaries);

  BIND_LUA_FUNCTION(L, ScenarioGetDifficulty);

  BIND_LUA_FUNCTION(L, ScenarioPauseAI);

  BIND_LUA_FUNCTION(L, IsMultiplayerGame);

  BIND_LUA_FUNCTION(L, PlayerCreate);

  BIND_LUA_FUNCTION(L, DynastyCreate);

  BIND_LUA_FUNCTION(L, BossCreate);

  BIND_LUA_FUNCTION(L, FindNearestBuilding);

  BIND_LUA_FUNCTION(L, CourtingGetMaxCourtingId);

  BIND_LUA_FUNCTION(L, CourtingId2Measure);

  BIND_LUA_FUNCTION(L, MeasureCreate);

  BIND_LUA_FUNCTION(L, MeasureAddAlias);

  BIND_LUA_FUNCTION(L, MeasureAddData);

  BIND_LUA_FUNCTION(L, MeasureStart);

  BIND_LUA_FUNCTION(L, MeasureRun);

  BIND_LUA_FUNCTION(L, MeasureIsValid);

  BIND_LUA_FUNCTION(L, MeasureGetID);

  BIND_LUA_FUNCTION(L, CanBeInterruptetBy);

  BIND_LUA_FUNCTION(L, GetGametime);

  BIND_LUA_FUNCTION(L, GetSeason);

  BIND_LUA_FUNCTION(L, GetRound);

  BIND_LUA_FUNCTION(L, GetYear);

  BIND_LUA_FUNCTION(L, SetTime);

  BIND_LUA_FUNCTION(L, Gametime2Realtime);

  BIND_LUA_FUNCTION(L, Gametime2Total);

  BIND_LUA_FUNCTION(L, Realtime2Gametime);

  BIND_LUA_FUNCTION(L, SystemGetMeasurePriority);

  BIND_LUA_FUNCTION(L, SystemGetMeasureName);

  BIND_LUA_FUNCTION(L, GetFleePosition);

  BIND_LUA_FUNCTION(L, GetEvadePosition);

  BIND_LUA_FUNCTION(L, CMoveTo);

  BIND_LUA_FUNCTION(L, CMoveToWeak);

  BIND_LUA_FUNCTION(L, MoveStop);

  BIND_LUA_FUNCTION(L, MoveSetActivity);

  BIND_LUA_FUNCTION(L, MoveSetStance);

  BIND_LUA_FUNCTION(L, MoveGetStance);

  BIND_LUA_FUNCTION(L, MoveGetPrefPattern);

  BIND_LUA_FUNCTION(L, CFollow);

  BIND_LUA_FUNCTION(L, StopFollow);

  BIND_LUA_FUNCTION(L, CFight);

  BIND_LUA_FUNCTION(L, SatisfyNeed);

  BIND_LUA_FUNCTION(L, SimGetNeed);

  BIND_LUA_FUNCTION(L, SimResumePreFightMeasure);

  BIND_LUA_FUNCTION(L, ClearMeasureCache);

  BIND_LUA_FUNCTION(L, StartProduction);

  BIND_LUA_FUNCTION(L, StopProduction);

  BIND_LUA_FUNCTION(L, GetLocatorByName);

  BIND_LUA_FUNCTION(L, LocatorStatus);

  BIND_LUA_FUNCTION(L, GetFreeLocatorByName);

  BIND_LUA_FUNCTION(L, CPlayAnimation);

  BIND_LUA_FUNCTION(L, CChangeAnimation);

  BIND_LUA_FUNCTION(L, StopAnimation);

  BIND_LUA_FUNCTION(L, StopAllAnimations);

  BIND_LUA_FUNCTION(L, CLoopAnimation);

  BIND_LUA_FUNCTION(L, GetAnimationLength);

  BIND_LUA_FUNCTION(L, Fire);

  BIND_LUA_FUNCTION(L, BlockLocator);

  BIND_LUA_FUNCTION(L, ReleaseLocator);

  BIND_LUA_FUNCTION(L, CUseLocator);

  BIND_LUA_FUNCTION(L, LocatorGetBlocker);

  BIND_LUA_FUNCTION(L, GetLocatorIndex);

  BIND_LUA_FUNCTION(L, CarryObject);

  BIND_LUA_FUNCTION(L, HideObject);

  BIND_LUA_FUNCTION(L, ShowObject);

  BIND_LUA_FUNCTION(L, CExitCurrentBuilding);

  BIND_LUA_FUNCTION(L, ExitCurrentVehicle);

  BIND_LUA_FUNCTION(L, EnterVehicle);

  BIND_LUA_FUNCTION(L, Kill);

  BIND_LUA_FUNCTION(L, InternalDie);

  BIND_LUA_FUNCTION(L, InternalRemove);

  BIND_LUA_FUNCTION(L, CStroll);

  BIND_LUA_FUNCTION(L, AlignTo);

  BIND_LUA_FUNCTION(L, AlignToNearest);

  BIND_LUA_FUNCTION(L, Evacuate);

  BIND_LUA_FUNCTION(L, BuildingRallyWorkers);

  BIND_LUA_FUNCTION(L, ChangeResidence);

  BIND_LUA_FUNCTION(L, GetOutdoorMovePosition);

  BIND_LUA_FUNCTION(L, CheckSkill);

  BIND_LUA_FUNCTION(L, SetSkillValue);

  BIND_LUA_FUNCTION(L, GetSkillValue);

  BIND_LUA_FUNCTION(L, IncrementSkillValue);

  BIND_LUA_FUNCTION(L, Talk);

  BIND_LUA_FUNCTION(L, QuestTalk);

  BIND_LUA_FUNCTION(L, IsDynastySim);

  BIND_LUA_FUNCTION(L, IsPartyMember);

  BIND_LUA_FUNCTION(L, IsOnlyPartyMember);

  BIND_LUA_FUNCTION(L, SetProcessProgress);

  BIND_LUA_FUNCTION(L, SetProcessMaxProgress);

  BIND_LUA_FUNCTION(L, ResetProcessProgress);

  BIND_LUA_FUNCTION(L, SimGetHandsel);

  BIND_LUA_FUNCTION(L, SimGetWage);

  BIND_LUA_FUNCTION(L, SimIsInside);

  BIND_LUA_FUNCTION(L, SimSetClass);

  BIND_LUA_FUNCTION(L, SimGetClass);

  BIND_LUA_FUNCTION(L, SimGetGender);

  BIND_LUA_FUNCTION(L, TradeMemoryEvents);

  BIND_LUA_FUNCTION(L, CIncrementXP);

  BIND_LUA_FUNCTION(L, GetSimType);

  BIND_LUA_FUNCTION(L, SimGetLevel);

  BIND_LUA_FUNCTION(L, SimCreate);

  BIND_LUA_FUNCTION(L, SimCanBeHired);

  BIND_LUA_FUNCTION(L, SimHire);

  BIND_LUA_FUNCTION(L, SimIsMortal);

  BIND_LUA_FUNCTION(L, SimSetMortal);

  BIND_LUA_FUNCTION(L, SimSetHireable);

  BIND_LUA_FUNCTION(L, SimHasAbility);

  BIND_LUA_FUNCTION(L, SimIsWorkingTime);

  BIND_LUA_FUNCTION(L, GetName);

  BIND_LUA_FUNCTION(L, SimGetProfession);

  BIND_LUA_FUNCTION(L, SimGetWorkingPlace);

  BIND_LUA_FUNCTION(L, SimGetAssignedAreaID);

  BIND_LUA_FUNCTION(L, SimGetAssignedArea);

  BIND_LUA_FUNCTION(L, SimGetWorkingPlaceID);

  BIND_LUA_FUNCTION(L, GetFavor);

  BIND_LUA_FUNCTION(L, GetFavorToSim);

  BIND_LUA_FUNCTION(L, GetFavorToDynasty);

  BIND_LUA_FUNCTION(L, ModifyFavorToSim);

  BIND_LUA_FUNCTION(L, ModifyFavorToDynasty);

  BIND_LUA_FUNCTION(L, SetFavorToSim);

  BIND_LUA_FUNCTION(L, SetFavorToDynasty);

  BIND_LUA_FUNCTION(L, SimGetBestEvidence);

  BIND_LUA_FUNCTION(L, SimMarry);

  BIND_LUA_FUNCTION(L, SimGetBeloved);

  BIND_LUA_FUNCTION(L, SimGetSpouse);

  BIND_LUA_FUNCTION(L, SimGetDeadSpouseCount);

  BIND_LUA_FUNCTION(L, SimGetChildren);

  BIND_LUA_FUNCTION(L, SimGetChildrenCount);

  BIND_LUA_FUNCTION(L, SimCanStartCourtLover);

  BIND_LUA_FUNCTION(L, SimSetCourtLover);

  BIND_LUA_FUNCTION(L, SimGetCourtLover);

  BIND_LUA_FUNCTION(L, SimGetCourtingSim);

  BIND_LUA_FUNCTION(L, SimIsCourting);

  BIND_LUA_FUNCTION(L, SimGetLiaison);

  BIND_LUA_FUNCTION(L, SimDoCourtingAction);

  BIND_LUA_FUNCTION(L, SimAddCourtingProgress);

  BIND_LUA_FUNCTION(L, SimGetFather);

  BIND_LUA_FUNCTION(L, SimGetMother);

  BIND_LUA_FUNCTION(L, SimGetChildCount);

  BIND_LUA_FUNCTION(L, SimGetChild);

  BIND_LUA_FUNCTION(L, SimGetAlignment);

  BIND_LUA_FUNCTION(L, SimPauseWorking);

  BIND_LUA_FUNCTION(L, SimSetBehavior);

  BIND_LUA_FUNCTION(L, SimGetBehavior);

  BIND_LUA_FUNCTION(L, SimStartIdleMeasure);

  BIND_LUA_FUNCTION(L, SimResetBehavior);

  BIND_LUA_FUNCTION(L, SimSetBehaviorDataFloat);

  BIND_LUA_FUNCTION(L, SimSetBehaviorDataAlias);

  BIND_LUA_FUNCTION(L, SimLock);

  BIND_LUA_FUNCTION(L, SimSetFamily);

  BIND_LUA_FUNCTION(L, SimSetFirstname);

  BIND_LUA_FUNCTION(L, SimSetLastname);

  BIND_LUA_FUNCTION(L, SimGetLastname);

  BIND_LUA_FUNCTION(L, SimGetWealth);

  BIND_LUA_FUNCTION(L, SimCreateCompanion);

  BIND_LUA_FUNCTION(L, SimSetParents);

  BIND_LUA_FUNCTION(L, SetInvisible);

  BIND_LUA_FUNCTION(L, SimSetProduceItemID);

  BIND_LUA_FUNCTION(L, SimGetProduceItemID);

  BIND_LUA_FUNCTION(L, SimGetAge);

  BIND_LUA_FUNCTION(L, SimSetAge);

  BIND_LUA_FUNCTION(L, SimGetProductivity);

  BIND_LUA_FUNCTION(L, SimGetPregnant);

  BIND_LUA_FUNCTION(L, SimGetProgress);

  BIND_LUA_FUNCTION(L, SimSetProgress);

  BIND_LUA_FUNCTION(L, SimGetFavourableCourtingAction);

  BIND_LUA_FUNCTION(L, SimBeamMeUp);

  BIND_LUA_FUNCTION(L, SimStopMeasure);

  BIND_LUA_FUNCTION(L, EvidenceGetSeverity);

  BIND_LUA_FUNCTION(L, EvidenceGetActor);

  BIND_LUA_FUNCTION(L, SimConsumeGoods);

  BIND_LUA_FUNCTION(L, SimGetRank);

  BIND_LUA_FUNCTION(L, SimArrangeLiaison);

  BIND_LUA_FUNCTION(L, SimChargeCharacter);

  BIND_LUA_FUNCTION(L, SimAddDate);

  BIND_LUA_FUNCTION(L, SimAddDatebookEntry);

  BIND_LUA_FUNCTION(L, SimGetReligion);

  BIND_LUA_FUNCTION(L, SimGetChurch);

  BIND_LUA_FUNCTION(L, SimSetReligion);

  BIND_LUA_FUNCTION(L, SimGetFaith);

  BIND_LUA_FUNCTION(L, SimSetFaith);

  BIND_LUA_FUNCTION(L, SimReleaseCourtLover);

  BIND_LUA_FUNCTION(L, CalculateCourtingDifficulty);

  BIND_LUA_FUNCTION(L, BuildingGetInsideSimList);

  BIND_LUA_FUNCTION(L, SimCanWorkHere);

  BIND_LUA_FUNCTION(L, BuildingFindSimByName);

  BIND_LUA_FUNCTION(L, BuildingFindSimByProperty);

  BIND_LUA_FUNCTION(L, BuildingInternalLevelUp);

  BIND_LUA_FUNCTION(L, BuildingCanLevelUp);

  BIND_LUA_FUNCTION(L, BuildingFindWaterPos);

  BIND_LUA_FUNCTION(L, GetDynastyID);

  BIND_LUA_FUNCTION(L, GetDynasty);

  BIND_LUA_FUNCTION(L, GetAccessPriceTake);

  BIND_LUA_FUNCTION(L, GetAccessPriceGive);

  BIND_LUA_FUNCTION(L, GetInventory);

  BIND_LUA_FUNCTION(L, SimGetServantDynasty);

  BIND_LUA_FUNCTION(L, SimGetServantDynastyId);

  BIND_LUA_FUNCTION(L, BuildingHasUpgrade);

  BIND_LUA_FUNCTION(L, BuildingGetMaxWorkerCount);

  BIND_LUA_FUNCTION(L, BuildingGetWorkerCount);

  BIND_LUA_FUNCTION(L, BuildingGetWorker);

  BIND_LUA_FUNCTION(L, BuildingGetSimCount);

  BIND_LUA_FUNCTION(L, BuildingGetSim);

  BIND_LUA_FUNCTION(L, BuildingGetFlag);

  BIND_LUA_FUNCTION(L, BuildingSetFlagColor);

  BIND_LUA_FUNCTION(L, BuildingSetWaterPos);

  BIND_LUA_FUNCTION(L, BuildingGetWaterPos);

  BIND_LUA_FUNCTION(L, BuildingGetPrisoner);

  BIND_LUA_FUNCTION(L, BuildingGetNPC);

  BIND_LUA_FUNCTION(L, BuildingGetProfession);

  BIND_LUA_FUNCTION(L, DoNewBornStuff);

  BIND_LUA_FUNCTION(L, BuildingBuy);

  BIND_LUA_FUNCTION(L, BuildingBuyCart);

  BIND_LUA_FUNCTION(L, BuildingCanBeOwnedBy);

  BIND_LUA_FUNCTION(L, BuildingGetProto);

  BIND_LUA_FUNCTION(L, BuildingGetWorkingStart);

  BIND_LUA_FUNCTION(L, BuildingGetWorkingEnd);

  BIND_LUA_FUNCTION(L, BuildingGetFixedCosts);

  BIND_LUA_FUNCTION(L, BuildingGetFreeBudget);

  BIND_LUA_FUNCTION(L, GetBuildingBasePrice);

  BIND_LUA_FUNCTION(L, BuildingGetBuyPrice);

  BIND_LUA_FUNCTION(L, BuildingGetValue);

  BIND_LUA_FUNCTION(L, BuildingGetPriceProto);

  BIND_LUA_FUNCTION(L, BuildingGetRepairPrice);

  BIND_LUA_FUNCTION(L, BuildingGetBaseHP);

  BIND_LUA_FUNCTION(L, BuildingCanBeEntered);

  BIND_LUA_FUNCTION(L, BuildingHasIndoor);

  BIND_LUA_FUNCTION(L, BuildingCanHireNewWorker);

  BIND_LUA_FUNCTION(L, BuildingGetProducerCount);

  BIND_LUA_FUNCTION(L, BuildingGetClass);

  BIND_LUA_FUNCTION(L, BuildingGetCharacterClass);

  BIND_LUA_FUNCTION(L, BuildingGetType);

  BIND_LUA_FUNCTION(L, BuildingGetLevel);

  BIND_LUA_FUNCTION(L, BuildingGetOwner);

  BIND_LUA_FUNCTION(L, BuildingSetOwner);

  BIND_LUA_FUNCTION(L, BuildingSetForSale);

  BIND_LUA_FUNCTION(L, BuildingGetForSale);

  BIND_LUA_FUNCTION(L, BuildingGetCity);

  BIND_LUA_FUNCTION(L, BuildingGetReligion);

  BIND_LUA_FUNCTION(L, FindWorker);

  BIND_LUA_FUNCTION(L, HireWorker);

  BIND_LUA_FUNCTION(L, BuildingGetCartCount);

  BIND_LUA_FUNCTION(L, BuildingGetCart);

  BIND_LUA_FUNCTION(L, IsLocatorFree);

  BIND_LUA_FUNCTION(L, Name2BuildingType);

  BIND_LUA_FUNCTION(L, BuildingLevelMeUp);

  BIND_LUA_FUNCTION(L, BuildingCanProduce);

  BIND_LUA_FUNCTION(L, BuildingGetAISetting);

  BIND_LUA_FUNCTION(L, RoomGetInsideSimList);

  BIND_LUA_FUNCTION(L, ShowBuildingFlags);

  BIND_LUA_FUNCTION(L, BuildingIsWorkingTime);

  BIND_LUA_FUNCTION(L, CommandStructure);

  BIND_LUA_FUNCTION(L, VehicleGetModelName);

  BIND_LUA_FUNCTION(L, VehicleChangeModel);

  BIND_LUA_FUNCTION(L, BankSetCreditOffer);

  BIND_LUA_FUNCTION(L, BankGetOffer);

  BIND_LUA_FUNCTION(L, CreditGetSum);

  BIND_LUA_FUNCTION(L, CreditGetTotal);

  BIND_LUA_FUNCTION(L, CreditGetInterest);

  BIND_LUA_FUNCTION(L, CreditGetRuntime);

  BIND_LUA_FUNCTION(L, CreditGetRemainingTime);

  BIND_LUA_FUNCTION(L, GetMoney);

  BIND_LUA_FUNCTION(L, SpendMoney);

  BIND_LUA_FUNCTION(L, CreditMoney);

  BIND_LUA_FUNCTION(L, SetEndlessMoney);

  BIND_LUA_FUNCTION(L, DynastyGetMemberCount);

  BIND_LUA_FUNCTION(L, DynastyGetMember);

  BIND_LUA_FUNCTION(L, DynastyGetFamilyMemberCount);

  BIND_LUA_FUNCTION(L, DynastyGetFamilyMember);

  BIND_LUA_FUNCTION(L, DynastyGetMemberRandom);

  BIND_LUA_FUNCTION(L, DynastyGetHomeCity);

  BIND_LUA_FUNCTION(L, DynastyGetBuildingCount);

  BIND_LUA_FUNCTION(L, DynastyGetRandomBuilding);

  BIND_LUA_FUNCTION(L, DynastyFindIdleWorker);

  BIND_LUA_FUNCTION(L, DynastyGetWorkerCount);

  BIND_LUA_FUNCTION(L, DynastyGetWorker);

  BIND_LUA_FUNCTION(L, DynastyGetBuildingCount2);

  BIND_LUA_FUNCTION(L, DynastyGetBuilding2);

  BIND_LUA_FUNCTION(L, DynastyGetRandomVictim);

  BIND_LUA_FUNCTION(L, DynastyGetDiplomacyState);

  BIND_LUA_FUNCTION(L, DynastyGetDiplomacyOffer);

  BIND_LUA_FUNCTION(L, DynastySetMinDiplomacyState);

  BIND_LUA_FUNCTION(L, DynastySetMaxDiplomacyState);

  BIND_LUA_FUNCTION(L, DynastyGetMinDiplomacyState);

  BIND_LUA_FUNCTION(L, DynastyGetMaxDiplomacyState);

  BIND_LUA_FUNCTION(L, DynastySetDiplomacyState);

  BIND_LUA_FUNCTION(L, DynastyMakeImpact);

  BIND_LUA_FUNCTION(L, DynastyFindNewBuilding);

  BIND_LUA_FUNCTION(L, DynastyIsPlayer);

  BIND_LUA_FUNCTION(L, DynastyIsDead);

  BIND_LUA_FUNCTION(L, DynastyGetTeam);

  BIND_LUA_FUNCTION(L, DynastyGetTotalSeaTradeValue);

  BIND_LUA_FUNCTION(L, DynastySetTeam);

  BIND_LUA_FUNCTION(L, CanBuildWorkshop);

  BIND_LUA_FUNCTION(L, GetMaxWorkshopCount);

  BIND_LUA_FUNCTION(L, DynastyIsShadow);

  BIND_LUA_FUNCTION(L, DynastyIsAI);

  BIND_LUA_FUNCTION(L, GetLocalPlayerDynasty);

  BIND_LUA_FUNCTION(L, DynastyAddMember);

  BIND_LUA_FUNCTION(L, DynastyRemoveMember);

  BIND_LUA_FUNCTION(L, DynastyTakeCredit);

  BIND_LUA_FUNCTION(L, DynastyPaybackCredit);

  BIND_LUA_FUNCTION(L, DynastyGetCredit);

  BIND_LUA_FUNCTION(L, DynastyGetRanking);

  BIND_LUA_FUNCTION(L, DynastyGetColor);

  BIND_LUA_FUNCTION(L, DynastyForceCalcDiplomacy);

  BIND_LUA_FUNCTION(L, DynastyRemoveDiplomacyStateImpact);

  BIND_LUA_FUNCTION(L, DynastyAvoidControl);

  BIND_LUA_FUNCTION(L, GetHomeBuilding);

  BIND_LUA_FUNCTION(L, SetHomeBuilding);

  BIND_LUA_FUNCTION(L, GetHomeBuildingId);

  BIND_LUA_FUNCTION(L, SetState);

  BIND_LUA_FUNCTION(L, SetStateImpact);

  BIND_LUA_FUNCTION(L, ClearStateImpact);

  BIND_LUA_FUNCTION(L, GetStateImpact);

  BIND_LUA_FUNCTION(L, GetState);

  BIND_LUA_FUNCTION(L, IsDead);

  BIND_LUA_FUNCTION(L, PlaySound);

  BIND_LUA_FUNCTION(L, PlaySoundVariation);

  BIND_LUA_FUNCTION(L, PlaySound3D);

  BIND_LUA_FUNCTION(L, PlaySound3DVariation);

  BIND_LUA_FUNCTION(L, StartHighPriorMusic);

  BIND_LUA_FUNCTION(L, ShowBoundingBox);

  BIND_LUA_FUNCTION(L, ReadyToRepeat);

  BIND_LUA_FUNCTION(L, SetRepeatTimer);

  BIND_LUA_FUNCTION(L, GetRepeatTimerLeft);

  BIND_LUA_FUNCTION(L, GetRepeatTimerEndtime);

  BIND_LUA_FUNCTION(L, SetMeasureRepeat);

  BIND_LUA_FUNCTION(L, GetMeasureRepeatName);

  BIND_LUA_FUNCTION(L, GetMeasureRepeatName2);

  BIND_LUA_FUNCTION(L, GetMeasureRepeat);

  BIND_LUA_FUNCTION(L, CreateScriptcall);

  BIND_LUA_FUNCTION(L, RemoveScriptcall);

  BIND_LUA_FUNCTION(L, CanAddItems);

  BIND_LUA_FUNCTION(L, AddItems);

  BIND_LUA_FUNCTION(L, RemoveItems);

  BIND_LUA_FUNCTION(L, RemoveEmptySlots);

  BIND_LUA_FUNCTION(L, TransferItems);

  BIND_LUA_FUNCTION(L, Transfer);

  BIND_LUA_FUNCTION(L, ThrowObject);

  BIND_LUA_FUNCTION(L, GetRemainingInventorySpace);

  BIND_LUA_FUNCTION(L, FindResourceProto);

  BIND_LUA_FUNCTION(L, ResourceFind);

  BIND_LUA_FUNCTION(L, ResourceGetLevel);

  BIND_LUA_FUNCTION(L, ResourceGetEntry);

  BIND_LUA_FUNCTION(L, ResourceGetItemId);

  BIND_LUA_FUNCTION(L, ResourceGetScriptFunc);

  BIND_LUA_FUNCTION(L, ResourceGetMeasureID);

  BIND_LUA_FUNCTION(L, ResourceCanBeChanged);

  BIND_LUA_FUNCTION(L, ResourceGetTypeCount);

  BIND_LUA_FUNCTION(L, ResourceGetTypeItem);

  BIND_LUA_FUNCTION(L, ResourceSow);

  BIND_LUA_FUNCTION(L, GetInsideBuilding);

  BIND_LUA_FUNCTION(L, GetInsideRoom);

  BIND_LUA_FUNCTION(L, GetInsideBuildingID);

  BIND_LUA_FUNCTION(L, CanBeControlled);

  BIND_LUA_FUNCTION(L, ObjectSetMeasureIcon);

  BIND_LUA_FUNCTION(L, ObjectClearMeasureIcon);

  BIND_LUA_FUNCTION(L, ObjectSetStateIcon);

  BIND_LUA_FUNCTION(L, ObjectClearStateIcon);

  BIND_LUA_FUNCTION(L, SetExclusiveMeasure);

  BIND_LUA_FUNCTION(L, ForbidMeasure);

  BIND_LUA_FUNCTION(L, AllowMeasure);

  BIND_LUA_FUNCTION(L, AllowAllMeasures);

  BIND_LUA_FUNCTION(L, GetHP);

  BIND_LUA_FUNCTION(L, GetHPRelative);

  BIND_LUA_FUNCTION(L, ModifyHP);

  BIND_LUA_FUNCTION(L, GetMaxHP);

  BIND_LUA_FUNCTION(L, AddImpact);

  BIND_LUA_FUNCTION(L, ImpactGetMaxTimeleft);

  BIND_LUA_FUNCTION(L, RemoveImpact);

  BIND_LUA_FUNCTION(L, GetImpactValue);

  BIND_LUA_FUNCTION(L, IsType);

  BIND_LUA_FUNCTION(L, IsTypeExact);

  BIND_LUA_FUNCTION(L, SetName);

  BIND_LUA_FUNCTION(L, FadeOutAllFE);

  BIND_LUA_FUNCTION(L, AddObjectDependendImpact);

  BIND_LUA_FUNCTION(L, RemoveAllObjectDependendImpacts);

  BIND_LUA_FUNCTION(L, GetNearestSettlement);

  BIND_LUA_FUNCTION(L, AddImpactDependendImpact);

  BIND_LUA_FUNCTION(L, RemoveAllImpactDependendImpacts);

  BIND_LUA_FUNCTION(L, ObjectSetHighlight);

  BIND_LUA_FUNCTION(L, ShowOverheadMeasureSymbol);

  BIND_LUA_FUNCTION(L, Plunder);

  BIND_LUA_FUNCTION(L, BattleJoin);

  BIND_LUA_FUNCTION(L, BattleLeave);

  BIND_LUA_FUNCTION(L, BattleFlee);

  BIND_LUA_FUNCTION(L, BattleGetNextEnemy);

  BIND_LUA_FUNCTION(L, BattleGetWeaponName);

  BIND_LUA_FUNCTION(L, BattleWeaponPresent);

  BIND_LUA_FUNCTION(L, BattleWeaponStore);

  BIND_LUA_FUNCTION(L, BattleIsFighting);

  BIND_LUA_FUNCTION(L, GetArmor);

  BIND_LUA_FUNCTION(L, GetDirectionTo);

  BIND_LUA_FUNCTION(L, GetRotationTo);

  BIND_LUA_FUNCTION(L, GetNobilityTitle);

  BIND_LUA_FUNCTION(L, GetNobilityTitleLabel);

  BIND_LUA_FUNCTION(L, SetNobilityTitle);

  BIND_LUA_FUNCTION(L, SimGetDivorced);

  BIND_LUA_FUNCTION(L, SimSetDoctorTitle);

  BIND_LUA_FUNCTION(L, SimGetWeaponDamage);

  BIND_LUA_FUNCTION(L, SetAvoidanceRange);

  BIND_LUA_FUNCTION(L, SetActiveAvoidance);

  BIND_LUA_FUNCTION(L, SetPassiveAvoidance);

  BIND_LUA_FUNCTION(L, SetAvoidanceGroup);

  BIND_LUA_FUNCTION(L, ReleaseAvoidanceGroup);

  BIND_LUA_FUNCTION(L, GetRadius);

  BIND_LUA_FUNCTION(L, GetVehicle);

  BIND_LUA_FUNCTION(L, SetContext);

  BIND_LUA_FUNCTION(L, SetDestroyed);

  BIND_LUA_FUNCTION(L, CopyAlias);

  BIND_LUA_FUNCTION(L, GetPosition);

  BIND_LUA_FUNCTION(L, GetPositionOfSubobject);

  BIND_LUA_FUNCTION(L, SetPosition);

  BIND_LUA_FUNCTION(L, PositionModify);

  BIND_LUA_FUNCTION(L, PositionGetArea);

  BIND_LUA_FUNCTION(L, PositionSetArea);

  BIND_LUA_FUNCTION(L, PositionGetVector);

  BIND_LUA_FUNCTION(L, PositionGetRotation);

  BIND_LUA_FUNCTION(L, PositionSetVector);

  BIND_LUA_FUNCTION(L, Position2GuildObject);

  BIND_LUA_FUNCTION(L, PositionMove);

  BIND_LUA_FUNCTION(L, GetWorldPositionXYZ);

  BIND_LUA_FUNCTION(L, GetPositionXYZ);

  BIND_LUA_FUNCTION(L, GetDistance);

  BIND_LUA_FUNCTION(L, ObjectGetRotationY);

  BIND_LUA_FUNCTION(L, GetRotation);

  BIND_LUA_FUNCTION(L, GetSettlement);

  BIND_LUA_FUNCTION(L, GetSettlementID);

  BIND_LUA_FUNCTION(L, CityGetRandomBuilding);

  BIND_LUA_FUNCTION(L, CityGetNearestBuilding);

  BIND_LUA_FUNCTION(L, CityGetBuildingCount);

  BIND_LUA_FUNCTION(L, CityGetBuildings);

  BIND_LUA_FUNCTION(L, CityGetBuildingForCharacter);

  BIND_LUA_FUNCTION(L, CityGetBuildingCountForCharacter);

  BIND_LUA_FUNCTION(L, CityGetBuildingByName);

  BIND_LUA_FUNCTION(L, CityGetServantCount);

  BIND_LUA_FUNCTION(L, CityGetServant);

  BIND_LUA_FUNCTION(L, CityBuildNewBuilding);

  BIND_LUA_FUNCTION(L, CityGetCitizenCount);

  BIND_LUA_FUNCTION(L, CityGetCrimeRate);

  BIND_LUA_FUNCTION(L, CityModifyCrimeRate);

  BIND_LUA_FUNCTION(L, CityGetLevel);

  BIND_LUA_FUNCTION(L, CitySetMaxWorkerhutLevel);

  BIND_LUA_FUNCTION(L, CitySetFixedPrice);

  BIND_LUA_FUNCTION(L, CityGetMaxWorkerhutLevel);

  BIND_LUA_FUNCTION(L, CityGuardScan);

  BIND_LUA_FUNCTION(L, CityGetWantedTime);

  BIND_LUA_FUNCTION(L, CityGetPenalty);

  BIND_LUA_FUNCTION(L, CityLevel2Label);

  BIND_LUA_FUNCTION(L, CitySimBreakout);

  BIND_LUA_FUNCTION(L, CityScheduleCutsceneEvent);

  BIND_LUA_FUNCTION(L, CityAssignTrialRoles);

  BIND_LUA_FUNCTION(L, CityAddPenalty);

  BIND_LUA_FUNCTION(L, CityGetNumEvents);

  BIND_LUA_FUNCTION(L, CityGetEventText);

  BIND_LUA_FUNCTION(L, CityGetDynastyCharList);

  BIND_LUA_FUNCTION(L, SimCanBeCharged);

  BIND_LUA_FUNCTION(L, CityFindCrowdedPlace);

  BIND_LUA_FUNCTION(L, CityFindSquad);

  BIND_LUA_FUNCTION(L, CityGetLocalMarket);

  BIND_LUA_FUNCTION(L, CityIsKontor);

  BIND_LUA_FUNCTION(L, CityGetSeller);

  BIND_LUA_FUNCTION(L, PenaltyFinish);

  BIND_LUA_FUNCTION(L, PenaltyGetPrisonTime);

  BIND_LUA_FUNCTION(L, PenaltyGetType);

  BIND_LUA_FUNCTION(L, PenaltyReset);

  BIND_LUA_FUNCTION(L, PenaltyGetOffender);

  BIND_LUA_FUNCTION(L, SettlementEventGetTime);

  BIND_LUA_FUNCTION(L, Attach3DSound);

  BIND_LUA_FUNCTION(L, Detach3DSound);

  BIND_LUA_FUNCTION(L, CartGetOperator);

  BIND_LUA_FUNCTION(L, CartCreateEscort);

  BIND_LUA_FUNCTION(L, CartRemoveEscort);

  BIND_LUA_FUNCTION(L, CartCheckEscort);

  BIND_LUA_FUNCTION(L, CartCheckFighting);

  BIND_LUA_FUNCTION(L, CartGetEscortCount);

  BIND_LUA_FUNCTION(L, CartGetType);

  BIND_LUA_FUNCTION(L, ItemGetName);

  BIND_LUA_FUNCTION(L, ItemGetSlot);

  BIND_LUA_FUNCTION(L, ItemGetProductionTime);

  BIND_LUA_FUNCTION(L, ItemGetProductionAmount);

  BIND_LUA_FUNCTION(L, ItemGetBasePrice);

  BIND_LUA_FUNCTION(L, ItemGetPriceBuy);

  BIND_LUA_FUNCTION(L, ItemGetPriceSell);

  BIND_LUA_FUNCTION(L, ItemGetSubstLevel);

  BIND_LUA_FUNCTION(L, ItemGetLabel);

  BIND_LUA_FUNCTION(L, ItemGetID);

  BIND_LUA_FUNCTION(L, ItemGetType);

  BIND_LUA_FUNCTION(L, ItemGetCategory);

  BIND_LUA_FUNCTION(L, GetItemCount);

  BIND_LUA_FUNCTION(L, IsInLoadingRange);

  BIND_LUA_FUNCTION(L, StartSingleShotParticle);

  BIND_LUA_FUNCTION(L, CommitAction);

  BIND_LUA_FUNCTION(L, StopAction);

  BIND_LUA_FUNCTION(L, ActionLock);

  BIND_LUA_FUNCTION(L, ActionIsEvidence);

  BIND_LUA_FUNCTION(L, ActionIsStopped);

  BIND_LUA_FUNCTION(L, InventoryGetSlotCount);

  BIND_LUA_FUNCTION(L, InventoryGetSlotSize);

  BIND_LUA_FUNCTION(L, InventoryGetSlotInfo);

  BIND_LUA_FUNCTION(L, FadeOutFE);

  BIND_LUA_FUNCTION(L, FadeInFE);

  BIND_LUA_FUNCTION(L, PlayFE);

  BIND_LUA_FUNCTION(L, BaseFE);

  BIND_LUA_FUNCTION(L, SetAppearance);

  BIND_LUA_FUNCTION(L, StartEmote);

  BIND_LUA_FUNCTION(L, StopEmote);

  BIND_LUA_FUNCTION(L, GetEvidenceAlignmentSum);

  BIND_LUA_FUNCTION(L, GetEvidenceValues);

  BIND_LUA_FUNCTION(L, RemoveEvidences);

  BIND_LUA_FUNCTION(L, SimGetCrimeList);

  BIND_LUA_FUNCTION(L, CrimeForfeit);

  BIND_LUA_FUNCTION(L, CrimeGetEvidenceValue);

  BIND_LUA_FUNCTION(L, ListCrimeReport);

  BIND_LUA_FUNCTION(L, GetHoursToNextTrial);

  BIND_LUA_FUNCTION(L, CampaignExit);

  BIND_LUA_FUNCTION(L, CheckPlayerExtinct);

  BIND_LUA_FUNCTION(L, CheckPlayerBankrupt);

  BIND_LUA_FUNCTION(L, SetQuestDestination);

  BIND_LUA_FUNCTION(L, NotifyOnStateChange);

  BIND_LUA_FUNCTION(L, SetQuestSource);

  BIND_LUA_FUNCTION(L, BindQuest);

  BIND_LUA_FUNCTION(L, StartQuest);

  BIND_LUA_FUNCTION(L, StartMission);

  BIND_LUA_FUNCTION(L, ResetQuest);

  BIND_LUA_FUNCTION(L, KillQuest);

  BIND_LUA_FUNCTION(L, SetQuestTitle);

  BIND_LUA_FUNCTION(L, SetQuestDescription);

  BIND_LUA_FUNCTION(L, SetQuestDescriptionByQuestname);

  BIND_LUA_FUNCTION(L, HasRunningQuest);

  BIND_LUA_FUNCTION(L, SetMainQuest);

  BIND_LUA_FUNCTION(L, SetMainQuestTitle);

  BIND_LUA_FUNCTION(L, SetMainQuestDescription);

  BIND_LUA_FUNCTION(L, EndCutscene);

  BIND_LUA_FUNCTION(L, BuildingLockForCutscene);

  BIND_LUA_FUNCTION(L, CutsceneAddEvent);

  BIND_LUA_FUNCTION(L, CutsceneCallScheduled);

  BIND_LUA_FUNCTION(L, CutsceneCallUnscheduled);

  BIND_LUA_FUNCTION(L, CutsceneCallThread);

  BIND_LUA_FUNCTION(L, CutsceneCollectEvidences);

  BIND_LUA_FUNCTION(L, AddEvidence);

  BIND_LUA_FUNCTION(L, CutsceneSetData);

  BIND_LUA_FUNCTION(L, CutsceneGetData);

  BIND_LUA_FUNCTION(L, CutsceneSendEventTrigger);

  BIND_LUA_FUNCTION(L, CutsceneAddTriggerEvent);

  BIND_LUA_FUNCTION(L, CreateCutscene);

  BIND_LUA_FUNCTION(L, CopyAliasToCutscene);

  BIND_LUA_FUNCTION(L, CopyAliasFromCutscene);

  BIND_LUA_FUNCTION(L, SimGetCutscene);

  BIND_LUA_FUNCTION(L, ListAllCutscenes);

  BIND_LUA_FUNCTION(L, BuildingGetCutscene);

  BIND_LUA_FUNCTION(L, ProfessionGetLabel);

  BIND_LUA_FUNCTION(L, AIExecutePlan);

  BIND_LUA_FUNCTION(L, AICheckWorkingPlace);

  BIND_LUA_FUNCTION(L, AIFindGoodClass);

  BIND_LUA_FUNCTION(L, GetCrimeLocation);

  BIND_LUA_FUNCTION(L, GfxAttachObject);

  BIND_LUA_FUNCTION(L, GfxDetachObject);

  BIND_LUA_FUNCTION(L, GfxStartParticle);

  BIND_LUA_FUNCTION(L, AttachModel);

  BIND_LUA_FUNCTION(L, DynastyGetFlagNumber);

  BIND_LUA_FUNCTION(L, ScenarioSetNameLanguage);

  BIND_LUA_FUNCTION(L, BlackBoardAddPamphlet);

  BIND_LUA_FUNCTION(L, BlackBoardRemovePamphlet);

  BIND_LUA_FUNCTION(L, Mount);

  BIND_LUA_FUNCTION(L, Unmount);

  BIND_LUA_FUNCTION(L, IsMount);

  BIND_LUA_FUNCTION(L, IsMounted);

  BIND_LUA_FUNCTION(L, GetMount);

  BIND_LUA_FUNCTION(L, BuildingGetRoom);

  BIND_LUA_FUNCTION(L, GetRandomPlayerDynasty);

  BIND_LUA_FUNCTION(L, ScenarioGetBuildingCount);

  BIND_LUA_FUNCTION(L, RoomLockForCutscene);

  BIND_LUA_FUNCTION(L, IncrementXPQuiet);

  GuildGameScriptBinding_RegisterExtensions(L);
}
