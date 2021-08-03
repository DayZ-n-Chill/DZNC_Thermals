class CfgPatches
{
	class Thermal_Optic
	{
		units[]=
		{
			"Thermal_Optic"
		};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data",
			"DZ_Weapons_Optics"
		};
	};
};
class cfgVehicles
{
	class ItemOptics;
	class Thermal_Optic: ItemOptics
	{
		scope=2;
		displayName="Thermal_Optic";
		descriptionShort="Thermal_Optic";
		model="Test_Scope\FLIR\FLIR_Scope.p3d";
		animClass="Binoculars";
		rotationFlags=4;
		reversed=0;
		ContinuousActions[]={236};
		weight=700;
		itemSize[]={4,1};
		inventorySlot[]={"weaponOptics", "weaponOpticsHunting"};
		simulation="itemoptics";
		dispersionModifier=-0.00025000001;
		dispersionCondition="true";
		recoilModifier[]={1,1,1};
		memoryPointCamera="eyeScope";
		cameraDir="cameraDir";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=100;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"DZ\weapons\attachments\data\scope_alpha_clear_ca.paa",
								"DZ\weapons\attachments\data\terra.rvmat"
							}
						},
						
						{
							0.69999999,
							{}
						},
						
						{
							0.5,
							
							{
								"DZ\weapons\attachments\data\scope_alpha_damaged_ca.paa",
								"DZ\weapons\attachments\data\terra_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							{}
						},
						
						{
							0,
							
							{
								"DZ\weapons\attachments\data\scope_alpha_destroyed_ca.paa",
								"DZ\weapons\attachments\data\terra_destruct.rvmat"
							}
						}
					};
				};
			};
		};
		class OpticsInfo
		{
			useModelOptics=1;
			memoryPointCamera="eyeScope";
			cameraDir="cameraDir";
			modelOptics="Test_Scope\Reticle\FLIR_Reticle.p3d";
			opticsDisablePeripherialVision=0.67000002;
			opticsFlare=1;
			opticsPPEffects[]=
			{
				"OpticsCHAbera3",
				"OpticsBlur1"
			};
			opticsZoomMin="0.3926/4";
			opticsZoomMax="0.3926/12";
			opticsZoomInit="0.3926/8";
			discretefov[]=
			{
				"0.3926/4",
				"0.3926/8",
				"0.3926/12"
			};
			discreteInitIndex=0;
			distanceZoomMin=100;
			distanceZoomMax=2000;
			discreteDistance[]={100,200,300,400,500,600,700,800,900,1000,1100,1200,1300,1400,1500};
			discreteDistanceInitIndex=0;
			PPMaskProperties[]={0.5,0.5,0.50000012,0.050000001};
			PPLensProperties[]={0.2,0.15000001,0,0};
			PPBlurProperties=0.30000001;
		};
	};
};