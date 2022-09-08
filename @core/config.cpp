class CfgPatches
{
	class Wasteland
	{
		requiredAddons[]=
		{
			"DZ_Data"
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