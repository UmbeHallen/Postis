using UnrealBuildTool;

public class Postis : ModuleRules
{
	public Postis(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { 
			"Core", 
			"CoreUObject", 
			"Engine", 
			"InputCore" 
		});

		PrivateDependencyModuleNames.AddRange(new string[] {  });
	}
}
