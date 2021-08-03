class CfgPatches
{
	class ThermalScripts
	{
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Characters","DZ_Characters_Pants","DZ_Characters_Tops","DZ_Characters_Headgear","DZ_Data","DZ_Scripts"};
		units[] = {};
	};
};
class CfgMods
{
	class ThermalScripts
	{
		dir = "ThermalScripts";
		picture = "";
		action = "";
		hideName = 1;
		hidePicture = 1;
		name = "ThermalScripts";
		credits = "DayZ n' Chill";
		author = "DayZ n' Chill";
		authorID = "0";
		version = "1";
		extra = 0;
		type = "mod";
		dependencies[] = {"World","Game"};
		class defs
		{
			class worldScriptModule
			{
				value = "";
				files[] = {"ThermalScripts/4_World"};
			};
			class gameScriptModule
			{
				value = "";
				files[] = {"ThermalScripts/3_Game"};
			};
		};
	};
};
