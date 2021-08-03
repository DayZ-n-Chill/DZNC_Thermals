#define _ARMA_

class CfgPatches
{
	class ThermalAssets
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data", "DZ_Characters_Heads"};
	};
};
class CfgMods
{
	class ThermalAssets
	{
		dir = "ThermalAssets";
		picture = "";
		action = "";
		hideName = 0;
		hidePicture = 1;
		name = "ThermalAssets";
		credits = "Dylan";
		author = "Dylan";
		authorID = "";
		extra = 0;
		type = "mod";
	};
};

class CfgVehicles
{
	class ItemOptics;
	class Thermal_RangeFinder: ItemOptics
	{
		scope=2;
		displayName="$STR_CfgVehicles_Rangefinder0";
		descriptionShort="Thermal RangeFinder";
		model="\dz\gear\optics\Rangefinder.p3d";
		simulation="itemoptics";
		animClass="Binoculars";
		itemSize[]={2,1};
		weight=270;
		rotationFlags=17;
		memoryPointCamera="eyeScope";
		cameraDir="cameraDir";
		class OpticsInfo
		{
			memoryPointCamera="eyeScope";
			cameraDir="cameraDir";
			modelOptics="\dz\gear\optics\opticview_rangefinder.p3d";
			distanceZoomMin=500;
			distanceZoomMax=500;
			opticsZoomMin="0.3926/4";
			opticsZoomMax="0.3926/4";
			opticsZoomInit="0.3926/4";
		};
		attachments[]=
		{
			"BatteryD"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=70;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"DZ\gear\optics\data\Rangefinder.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\gear\optics\data\Rangefinder.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\gear\optics\data\Rangefinder_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\gear\optics\data\Rangefinder_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"DZ\gear\optics\data\Rangefinder_destruct.rvmat"
							}
						}
					};
				};
			};
		};
		repairableWithKits[]={7};
		repairCosts[]={25};
		class EnergyManager
		{
			hasIcon=1;
			energyUsagePerSecond=0.0099999998;
			plugType=1;
			attachmentAction=1;
		};
		class MeleeModes
		{
			class Default
			{
				ammo="MeleeLightBlunt";
				range=1;
			};
			class Heavy
			{
				ammo="MeleeLightBlunt_Heavy";
				range=1;
			};
			class Sprint
			{
				ammo="MeleeLightBlunt_Heavy";
				range=2.8;
			};
		};
	};
};