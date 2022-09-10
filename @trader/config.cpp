class CfgPatches
{
	class WastelandTrader
	{
		requiredAddons[]=
		{
			"DZ_Data",
			"Wasteland"
		};
	};
};

class CfgMods
{
	class WastelandTrader
	{
		type = "mod";

		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] = {
					"WastelandTrader/scripts/3_game",
				};
			}
			class worldScriptModule
			{
				value = "";
				files[] = {
					"WastelandTrader/scripts/4_world",
				};
			};
			class missionScriptModule
			{
				value = "";
				files[] = {
					"WastelandTrader/scripts/5_mission",
				};
			}
		};
	};
};