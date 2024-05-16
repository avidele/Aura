// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "StarRailCoreRuntime/Public/Game/StarRailPlayerStart.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeStarRailPlayerStart() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_APlayerStart();
STARRAILCORERUNTIME_API UClass* Z_Construct_UClass_AStarRailPlayerStart();
STARRAILCORERUNTIME_API UClass* Z_Construct_UClass_AStarRailPlayerStart_NoRegister();
UPackage* Z_Construct_UPackage__Script_StarRailCoreRuntime();
// End Cross Module References

// Begin Class AStarRailPlayerStart
void AStarRailPlayerStart::StaticRegisterNativesAStarRailPlayerStart()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AStarRailPlayerStart);
UClass* Z_Construct_UClass_AStarRailPlayerStart_NoRegister()
{
	return AStarRailPlayerStart::StaticClass();
}
struct Z_Construct_UClass_AStarRailPlayerStart_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Collision Lighting LightColor Force" },
		{ "IncludePath", "Game/StarRailPlayerStart.h" },
		{ "ModuleRelativePath", "Public/Game/StarRailPlayerStart.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AStarRailPlayerStart>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_AStarRailPlayerStart_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_APlayerStart,
	(UObject* (*)())Z_Construct_UPackage__Script_StarRailCoreRuntime,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AStarRailPlayerStart_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AStarRailPlayerStart_Statics::ClassParams = {
	&AStarRailPlayerStart::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x008000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AStarRailPlayerStart_Statics::Class_MetaDataParams), Z_Construct_UClass_AStarRailPlayerStart_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AStarRailPlayerStart()
{
	if (!Z_Registration_Info_UClass_AStarRailPlayerStart.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AStarRailPlayerStart.OuterSingleton, Z_Construct_UClass_AStarRailPlayerStart_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AStarRailPlayerStart.OuterSingleton;
}
template<> STARRAILCORERUNTIME_API UClass* StaticClass<AStarRailPlayerStart>()
{
	return AStarRailPlayerStart::StaticClass();
}
AStarRailPlayerStart::AStarRailPlayerStart(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(AStarRailPlayerStart);
AStarRailPlayerStart::~AStarRailPlayerStart() {}
// End Class AStarRailPlayerStart

// Begin Registration
struct Z_CompiledInDeferFile_FID_Aura_Plugins_GameFeatures_StarRailCore_Source_StarRailCoreRuntime_Public_Game_StarRailPlayerStart_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AStarRailPlayerStart, AStarRailPlayerStart::StaticClass, TEXT("AStarRailPlayerStart"), &Z_Registration_Info_UClass_AStarRailPlayerStart, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AStarRailPlayerStart), 3276769593U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Aura_Plugins_GameFeatures_StarRailCore_Source_StarRailCoreRuntime_Public_Game_StarRailPlayerStart_h_3425962144(TEXT("/Script/StarRailCoreRuntime"),
	Z_CompiledInDeferFile_FID_Aura_Plugins_GameFeatures_StarRailCore_Source_StarRailCoreRuntime_Public_Game_StarRailPlayerStart_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Aura_Plugins_GameFeatures_StarRailCore_Source_StarRailCoreRuntime_Public_Game_StarRailPlayerStart_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
