// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class AIArena : ModuleRules
{
	public AIArena(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] 
										{ 
										"Core",
										"CoreUObject",
										"Engine", 
										"InputCore", 
										"HeadMountedDisplay", 
										"AIModule",
										"GameplayTasks",
										"NavigationSystem"
										});


    }
}
