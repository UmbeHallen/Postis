using UnrealBuildTool;
using System.Collections.Generic;

public class PostisEditorTarget : TargetRules
{
	public PostisEditorTarget( TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		ExtraModuleNames.AddRange( new string[] { "Postis" } );
	}
}
