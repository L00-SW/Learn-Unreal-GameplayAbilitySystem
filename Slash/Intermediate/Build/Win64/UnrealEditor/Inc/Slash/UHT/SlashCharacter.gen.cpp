// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Slash/Public/Characters/SlashCharacter.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSlashCharacter() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_ACharacter();
	ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USpringArmComponent_NoRegister();
	ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputAction_NoRegister();
	ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputMappingContext_NoRegister();
	SLASH_API UClass* Z_Construct_UClass_ASlashCharacter();
	SLASH_API UClass* Z_Construct_UClass_ASlashCharacter_NoRegister();
	UPackage* Z_Construct_UPackage__Script_Slash();
// End Cross Module References
	void ASlashCharacter::StaticRegisterNativesASlashCharacter()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ASlashCharacter);
	UClass* Z_Construct_UClass_ASlashCharacter_NoRegister()
	{
		return ASlashCharacter::StaticClass();
	}
	struct Z_Construct_UClass_ASlashCharacter_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SlashMappingContext_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_SlashMappingContext;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MovementAction_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_MovementAction;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_LookAction_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_LookAction;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_JumpAction_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_JumpAction;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SpringArmComp_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_SpringArmComp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CameraComp_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_CameraComp;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ASlashCharacter_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ACharacter,
		(UObject* (*)())Z_Construct_UPackage__Script_Slash,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ASlashCharacter_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASlashCharacter_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Characters/SlashCharacter.h" },
		{ "ModuleRelativePath", "Public/Characters/SlashCharacter.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASlashCharacter_Statics::NewProp_SlashMappingContext_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Public/Characters/SlashCharacter.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASlashCharacter_Statics::NewProp_SlashMappingContext = { "SlashMappingContext", nullptr, (EPropertyFlags)0x0020080000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASlashCharacter, SlashMappingContext), Z_Construct_UClass_UInputMappingContext_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ASlashCharacter_Statics::NewProp_SlashMappingContext_MetaData), Z_Construct_UClass_ASlashCharacter_Statics::NewProp_SlashMappingContext_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASlashCharacter_Statics::NewProp_MovementAction_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Public/Characters/SlashCharacter.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASlashCharacter_Statics::NewProp_MovementAction = { "MovementAction", nullptr, (EPropertyFlags)0x0020080000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASlashCharacter, MovementAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ASlashCharacter_Statics::NewProp_MovementAction_MetaData), Z_Construct_UClass_ASlashCharacter_Statics::NewProp_MovementAction_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASlashCharacter_Statics::NewProp_LookAction_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Public/Characters/SlashCharacter.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASlashCharacter_Statics::NewProp_LookAction = { "LookAction", nullptr, (EPropertyFlags)0x0020080000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASlashCharacter, LookAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ASlashCharacter_Statics::NewProp_LookAction_MetaData), Z_Construct_UClass_ASlashCharacter_Statics::NewProp_LookAction_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASlashCharacter_Statics::NewProp_JumpAction_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Public/Characters/SlashCharacter.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASlashCharacter_Statics::NewProp_JumpAction = { "JumpAction", nullptr, (EPropertyFlags)0x0020080000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASlashCharacter, JumpAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ASlashCharacter_Statics::NewProp_JumpAction_MetaData), Z_Construct_UClass_ASlashCharacter_Statics::NewProp_JumpAction_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASlashCharacter_Statics::NewProp_SpringArmComp_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "SlashCharacter" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Characters/SlashCharacter.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASlashCharacter_Statics::NewProp_SpringArmComp = { "SpringArmComp", nullptr, (EPropertyFlags)0x0040000000080009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASlashCharacter, SpringArmComp), Z_Construct_UClass_USpringArmComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ASlashCharacter_Statics::NewProp_SpringArmComp_MetaData), Z_Construct_UClass_ASlashCharacter_Statics::NewProp_SpringArmComp_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASlashCharacter_Statics::NewProp_CameraComp_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "SlashCharacter" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Characters/SlashCharacter.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASlashCharacter_Statics::NewProp_CameraComp = { "CameraComp", nullptr, (EPropertyFlags)0x0040000000080009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASlashCharacter, CameraComp), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ASlashCharacter_Statics::NewProp_CameraComp_MetaData), Z_Construct_UClass_ASlashCharacter_Statics::NewProp_CameraComp_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ASlashCharacter_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASlashCharacter_Statics::NewProp_SlashMappingContext,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASlashCharacter_Statics::NewProp_MovementAction,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASlashCharacter_Statics::NewProp_LookAction,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASlashCharacter_Statics::NewProp_JumpAction,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASlashCharacter_Statics::NewProp_SpringArmComp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASlashCharacter_Statics::NewProp_CameraComp,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ASlashCharacter_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASlashCharacter>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ASlashCharacter_Statics::ClassParams = {
		&ASlashCharacter::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_ASlashCharacter_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_ASlashCharacter_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ASlashCharacter_Statics::Class_MetaDataParams), Z_Construct_UClass_ASlashCharacter_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ASlashCharacter_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_ASlashCharacter()
	{
		if (!Z_Registration_Info_UClass_ASlashCharacter.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ASlashCharacter.OuterSingleton, Z_Construct_UClass_ASlashCharacter_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ASlashCharacter.OuterSingleton;
	}
	template<> SLASH_API UClass* StaticClass<ASlashCharacter>()
	{
		return ASlashCharacter::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ASlashCharacter);
	ASlashCharacter::~ASlashCharacter() {}
	struct Z_CompiledInDeferFile_FID_Slash_Source_Slash_Public_Characters_SlashCharacter_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Slash_Source_Slash_Public_Characters_SlashCharacter_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ASlashCharacter, ASlashCharacter::StaticClass, TEXT("ASlashCharacter"), &Z_Registration_Info_UClass_ASlashCharacter, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ASlashCharacter), 2253066167U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Slash_Source_Slash_Public_Characters_SlashCharacter_h_768013605(TEXT("/Script/Slash"),
		Z_CompiledInDeferFile_FID_Slash_Source_Slash_Public_Characters_SlashCharacter_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Slash_Source_Slash_Public_Characters_SlashCharacter_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
