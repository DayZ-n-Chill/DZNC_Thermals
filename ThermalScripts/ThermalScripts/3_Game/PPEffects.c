modded class PPEffects
{
	static int	 	m_ThermalOverlay;

	override static void Init()
	{
		Print("---Init PPEffects---");
		if ( m_BlurValues )
		{
			delete m_BlurValues;
		}
		if ( m_ChromAbbValues )
		{
			delete m_ChromAbbValues;
		}
		if ( m_VignetteEffects )
		{
			delete m_VignetteEffects;
		}
		if ( m_VignetteValues )
		{
			delete m_VignetteValues;
		}
		if ( m_ColorEffect )
		{
			delete m_ColorEffect;
		}
		
		m_MatColors = GetGame().GetWorld().GetMaterial("graphics/materials/postprocess/glow");
		m_BlurValues = new array<float>;
		m_ChromAbbValues = new array<float>;
		m_VignetteEffects = new array<int>;
		m_VignetteValues = new map<int, ref array<float>>;
		
		// add new blur effects here
		m_BlurInventory		= RegisterBlurEffect();
		m_BlurDrunk			= RegisterBlurEffect();
		m_BlurFever			= RegisterBlurEffect();
		m_BlurMenu			= RegisterBlurEffect();
		m_BlurOptics 		= RegisterBlurEffect();
		m_BlurFlashbang		= RegisterBlurEffect();
		
		// add chromatic abberation effects here
		m_ChromAbbOptic 	= RegisterChromAbbEffect();
		//m_ChromAbbShock 	= RegisterChromAbbEffect();
		
		// add vignette effects here
		m_VignetteUnconscious 	= RegisterVignetteEffect();
		m_VignetteShock 		= RegisterVignetteEffect();
		m_VignetteTunnel 		= RegisterVignetteEffect();
		m_VignetteMenu 			= RegisterVignetteEffect();
		
		m_ColorEffect = new array<float>;
		m_ColorValues = new map<int, ref array<float>>;
		
		// add new color effects here
		m_BurlapBlindness 	= RegisterColorEffect();
		m_DyingEffect 		= RegisterColorEffect();
		m_ShockEffect 		= RegisterColorEffect();
		m_ThermalOverlay 	= RegisterColorEffect();
		
		// ------------------------NV-related stuff below------------------------
		ref array<float> colorizeDefault = {0.0, 0.0, 0.0};
		m_ColorizeEffects = new map<int, ref array<float>>;
		
		// colorize: r, g, b
		// colorize effects registration
		m_ColorizeEffects.Set(PPEffects.COLORIZE_NV, colorizeDefault);
		SetNVParams(55.0, 0.0, 2.35, 2.75); //default values
		// ------------------------End of NV-related stuff------------------------
	}
}