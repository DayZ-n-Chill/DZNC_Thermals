modded class DayZPlayerCameraBase extends DayZPlayerCamera
{
	bool is_using_thermal_optic;
	
	void SetThermalOptic(bool type)
	{
		is_using_thermal_optic = type;
	}
	
	bool GetThermalOptic()
	{
		return is_using_thermal_optic;
	}
	
	override void UpdateCameraNV(PlayerBase player)
	{
		if ( !player )
			return;
		
		if ( player.IsNVGWorking() != IsCameraNV() )
		{
			SetCameraNV(player.IsNVGWorking());
			SetCameraPP(true, this);
		}

		SetThermalOptic(player.IsUsingThermal());
		
		if (player.IsUsingThermal() && player.IsNVGWorking())
		{
			player.SetNVGWorking(false);
		}
		
		if (player.IsUsingThermal())
		{
			SetCameraPP(true, this);
		}
		
		
	}
	
	//! by default sets camera PP to zero, regardless of parameter. Override if needed.
	override void SetCameraPP(bool state, DayZPlayerCamera launchedFrom)
	{
		PPEffects.ResetPPMask();
		PPEffects.SetLensEffect(0, 0, 0, 0);
		PPEffects.OverrideDOF(false, 0, 0, 0, 0, 1);
		PPEffects.SetBlurOptics(0);
		
		if (IsCameraNV())
		{
			PPEffects.SetColorValue(PPEffects.m_BurlapBlindness, 0, 0, 0, 0, 0);
			PPEffects.SetColorValue(PPEffects.m_ThermalOverlay, 0, 0, 0, 0, 0);
			
			PPEffects.UpdateColor();

			SetNVPostprocess(NVTypes.NV_GOGGLES);
		}
		else if (GetThermalOptic())
		{
			float is_day = GetGame().GetWorld().GetSunOrMoon();

			if (is_day == 1)
			{						
				PPEffects.SetEVValuePP(-7.25);
				PPEffects.SetColorizationNV(1, 1, 1);
				PPEffects.SetNVParams(1.0, 15.0, 15.0, 1.0);

				// White Hot Thermals
				// PPEffects.SetColorValue(PPEffects.m_ThermalOverlay, 1, 1, 1, 0, 0.025);

			    // Red Hot Thermals
				PPEffects.SetColorValue(PPEffects.m_ThermalOverlay, 2.5, 0.125, 0, 0, 0.025);
				
				// Wierd Brown Thermals but very visiable
				// PPEffects.SetColorValue(PPEffects.m_ThermalOverlay, 0.768, 0.349, 0, 0.01, 0.02);

				PPEffects.UpdateColor();
			}
			else 
			{
					
				PPEffects.SetEVValuePP(-1.25);
				PPEffects.SetColorizationNV(1, 1, 1);
				PPEffects.SetNVParams(1.0, 2.0, 15.0, 1.0);
				
				// White Hot Thermals
				// PPEffects.SetColorValue(PPEffects.m_ThermalOverlay, 1, 1, 1, 0, 0.001);

			    // Red Hot Thermals
				PPEffects.SetColorValue(PPEffects.m_ThermalOverlay, 2.5, 0.125, 0, 0, 0.015);

				// Wierd Brown Thermals but very visiable
				// PPEffects.SetColorValue(PPEffects.m_ThermalOverlay, 0.768, 0.349, 0, 0.01, 0.01);
				
				PPEffects.UpdateColor();
			}
		
		}
		else
		{
			SetNVPostprocess(NVTypes.NONE);
			
			PPEffects.SetColorValue(PPEffects.m_BurlapBlindness, 0, 0, 0, 0, 0);	
			PPEffects.SetColorValue(PPEffects.m_ThermalOverlay, 0, 0, 0, 0, 0);
	
			PPEffects.UpdateColor();
		}
		
		m_weaponUsed = Weapon_Base.Cast(m_pPlayer.GetHumanInventory().GetEntityInHands());
		
		if (m_weaponUsed)
		{
			m_weaponUsed.HideWeaponBarrel(false);
		}
	}
	
	override float GetCurrentPitch()
	{
		return m_CurrentCameraPitch;
	}
}


modded class PlayerBase extends ManBase
{
	bool is_using_thermal;
	bool user_applied_thermal;

	override void Init()
	{
		super.Init();
		
		is_using_thermal = false;
		user_applied_thermal = false;
	}
	
	bool GetUserAppliedThermal()
	{
		return user_applied_thermal;
	}

	void SetThermalApplied(bool state)
	{
		user_applied_thermal = state;
	}
	
	bool IsUsingThermal()
	{
		return is_using_thermal;
	}

	void SetThermal(bool state)
	{
		is_using_thermal = state;
	}
	
	override void EEKilled( Object killer )
	{
		super.EEKilled(killer);
		
		//this code is here to restore the head when dead to prevent glowing effect on dead bodies
		if (GetUserAppliedThermal())
		{
			PluginLifespan m_ModuleLifespan_ = PluginLifespan.Cast( GetPlugin( PluginLifespan ) );
										
			if (m_ModuleLifespan_)
				m_ModuleLifespan_.UpdateLifespan( this, true );
		}
	}
}

modded class ModItemRegisterCallbacks
{
	override void RegisterOneHanded(DayZPlayerType pType, DayzPlayerItemBehaviorCfg pBehavior)
	{
		super.RegisterOneHanded( pType, pBehavior );
		pType.AddItemInHandsProfileIK("Thermal_RangeFinder", "dz/anims/workspaces/player/player_main/props/player_main_1h_rangefinder.asi", pBehavior, "dz/anims/anm/player/ik/gear/rangefinder.anm");
	}
};
	
class Thermal_Optic extends ItemOptics
{	
	void Thermal_Optic()
	{
		
	}
	
	override bool CanPutAsAttachment(EntityAI parent)
	{
		return true;
	}
}

class Thermal_RangeFinder extends Rangefinder
{
	void Thermal_RangeFinder()
	{
		
	}
	
	override void OnWorkStart()
	{
		if( GetGame().IsClient() || !GetGame().IsMultiplayer())
		{
			PlayerBase player_this = PlayerBase.Cast( GetGame().GetPlayer() );
			PlayerBase player_owner = PlayerBase.Cast( GetHierarchyRootPlayer() );
			
			if ( player_this == player_owner )
			{
				StartPeriodicMeasurement();
				
				for (int i = 0; i < 5; i++)
				{
					if (player_owner)
					{
						player_owner.SetThermal(true);
						player_owner.CreateThermalTimer();
					}
				}
			}
		}
	}
	
	override void OnWorkStop()
	{
		if( GetGame().IsClient() || !GetGame().IsMultiplayer())
		{
			PlayerBase player_this = PlayerBase.Cast( GetGame().GetPlayer() );
			PlayerBase player_owner = PlayerBase.Cast( GetHierarchyRootPlayer() );
			
			if ( player_this == player_owner )
			{
				StopPeriodicMeasurement();
				player_owner.RemoveThermalCode(player_owner);
			}
		}
	}
}


modded class ActionViewBinoculars : ActionViewOptics
{
	bool m_workingRangefinder;
	bool m_workingRangeFinderThermal;
	
	override string GetText()
	{
		if (!m_workingRangefinder && !m_workingRangeFinderThermal)
			return "#Look_Through";
		
		if (m_workingRangeFinderThermal)
			return "Use Thermal RangeFinder";
		
		return "#use_range_finder";
	}
	
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		ItemOptics optic;
		
		if( Class.CastTo(optic, item) && !optic.IsInOptics() && !player.IsNVGLowered() )
		{
			Rangefinder rangefinder = Rangefinder.Cast(item);
			
			if ( rangefinder && rangefinder.GetCompEM().CanWork() )
			{
				m_workingRangefinder = true;
			}
			else
			{
				m_workingRangefinder = false;
			}
			
			Thermal_RangeFinder thermal_finder = Thermal_RangeFinder.Cast(item);
			
			if (thermal_finder)
				m_workingRangeFinderThermal = true;
			
			return true;
		}
		return false;
	}
	
	override void ExitOptics(ItemOptics optic, PlayerBase player)
	{
		optic.ShowSelection("hide");
		
		if ( NVGoggles.Cast(optic) && optic.ConfigIsExisting("simpleHiddenSelections") ) //HACK
		{
			optic.SetSimpleHiddenSelectionState(0,true);
		}
		
		optic.ExitOptics();
		player.SetHandheldOpticsInUse(false);
		
		if (m_workingRangeFinderThermal && player)
			player.RemoveThermalCode(player);
		
		if ( optic.HasEnergyManager() )
		{
			PoweredOptic_Base rf = PoweredOptic_Base.Cast(optic);
			
			if (!rf)
				return;
			
			rf.SetPlayer( null );
			
			if ( GetGame().IsServer() )
				rf.GetCompEM().SwitchOff();
		}
	}
}