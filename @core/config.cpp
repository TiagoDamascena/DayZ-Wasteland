class CfgPatches
{
	class Wasteland
	{
		requiredAddons[]=
		{
			"DZ_Data",
			"JM_CF_Scripts"
		};
	};
};

class CfgMods
{
	class Wasteland
	{
		type = "mod";

		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] = {
					"Wasteland/scripts/3_game",
				};
			}
			class worldScriptModule
			{
				value = "";
				files[] = {
					"Wasteland/scripts/4_world",
				};
			};
			class missionScriptModule
			{
				value = "";
				files[] = {
					"Wasteland/scripts/5_mission",
				};
			}
		};
	};
};