// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "StarRailCoreRuntime/Public/Game/StarRailPlayerStart.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeStarRailPlayerStart() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_APlayerStart();
	STARRAILCORERUNTIME_API UClass* Z_Construct_UClass_AStarRailPlayerStart();
	STARRAILCORERUNTIME_API UClass* Z_Construct_UClass_AStarRailPlayerStart_NoRegister();
	UPackage* Z_Construct_UPackage__Script_StarRailCoreRuntime();
// End Cross Module References
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
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AStarRailPlayerStart_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_APlayerStart,
		(UObject* (*)())Z_Construct_UPackage__Script_StarRailCoreRuntime,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AStarRailPlayerStart_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AStarRailPlayerStart_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Collision Lighting LightColor Force" },
		{ "IncludePath", "Game/StarRailPlayerStart.h" },
		{ "ModuleRelativePath", "Public/Game/StarRailPlayerStart.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AStarRailPlayerStart_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AStarRailPlayerStart>::IsAbstract,
	};
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
	struct Z_CompiledInDeferFile_FID_Aura_Plugins_GameFeatures_StarRailCore_Source_StarRailCoreRuntime_Public_Game_StarRailPlayerStart_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Aura_Plugins_GameFeatures_StarRailCore_Source_StarRailCoreRuntime_Public_Game_StarRailPlayerStart_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AStarRailPlayerStart, AStarRailPlayerStart::StaticClass, TEXT("AStarRailPlayerStart"), &Z_Registration_Info_UClass_AStarRailPlayerStart, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AStarRailPlayerStart), 3336843880U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Aura_Plugins_GameFeatures_StarRailCore_Source_StarRailCoreRuntime_Public_Game_StarRailPlayerStart_h_2217814022(TEXT("/Script/StarRailCoreRuntime"),
		Z_CompiledInDeferFile_FID_Aura_Plugins_GameFeatures_StarRailCore_Source_StarRailCoreRuntime_Public_Game_StarRailPlayerStart_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Aura_Plugins_GameFeatures_StarRailCore_Source_StarRailCoreRuntime_Public_Game_StarRailPlayerStart_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
