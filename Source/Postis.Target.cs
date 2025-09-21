using UnrealBuildTool;
using System.Collections.Generic;

public class PostisTarget : TargetRules
{
	public PostisTarget( TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		ExtraModuleNames.AddRange( new string[] { "Postis" } );
	}
}
