// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class AKZFVroomVroom : ModuleRules
{
	public AKZFVroomVroom(TargetInfo Target)
	{
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "UMG", "HeadMountedDisplay" });
        PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore", "OnlineSubsystem", "OnlineSubSystemUtils", "Steamworks" });
        AddEngineThirdPartyPrivateStaticDependencies(Target, "Steamworks");
    }
}
