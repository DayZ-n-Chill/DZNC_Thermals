modded class DayZPlayerImplement
{
	protected ref Timer ThermalTimer;
	
	void RemovalThermalOnEntity(PlayerBase player_backup)
	{	
		if (player_backup)
		{
			player_backup.SetThermalApplied(false);

			EntityAI restore_players_head = player_backup.GetInventory().FindAttachment(InventorySlots.GetSlotIdFromString("Head"));
			EntityAI restore_players_body = player_backup.GetInventory().FindAttachment(InventorySlots.GetSlotIdFromString("Body"));
			EntityAI restore_players_back = player_backup.GetInventory().FindAttachment(InventorySlots.GetSlotIdFromString("Back"));
			EntityAI restore_players_hips = player_backup.GetInventory().FindAttachment(InventorySlots.GetSlotIdFromString("Hips"));
			EntityAI restore_players_vest = player_backup.GetInventory().FindAttachment(InventorySlots.GetSlotIdFromString("Vest"));
			EntityAI restore_players_gloves = player_backup.GetInventory().FindAttachment(InventorySlots.GetSlotIdFromString("Gloves"));
			EntityAI restore_players_legs = player_backup.GetInventory().FindAttachment(InventorySlots.GetSlotIdFromString("legs"));
			EntityAI restore_players_feet = player_backup.GetInventory().FindAttachment(InventorySlots.GetSlotIdFromString("Feet"));

			array<string> tone_mat_array = new array<string>;
			array<string> tone_texture_array = new array<string>;

			if (restore_players_head)
			{
				PluginLifespan m_ModuleLifespan_ = PluginLifespan.Cast(GetPlugin(PluginLifespan));

				if (m_ModuleLifespan_)
				{
					m_ModuleLifespan_.UpdateLifespan(player_backup, true);
				}
				
				restore_players_head.SetObjectTexture(0, "");
				restore_players_head.SetObjectMaterial(0, "");
				
				string head_texture_ = "DZ\\characters\\heads\\data\\m_cyril\\hhl_m_cyril_body_shaved_co.paa";
				string head_material_ = "DZ\\characters\\heads\\data\\m_cyril\\hhl_m_cyril_body_unshaved.rvmat";

				player_backup.SetFaceTexture(head_texture_);
				player_backup.SetFaceMaterial(head_material_);
			}
			else
			{
				EntityAI players_default_head_restore = player_backup.GetInventory().FindPlaceholderForSlot(InventorySlots.GetSlotIdFromString("Head"));

				PluginLifespan m_ModuleLifespan = PluginLifespan.Cast(GetPlugin(PluginLifespan));

				if (m_ModuleLifespan)
				{
					m_ModuleLifespan.UpdateLifespan(player_backup, true);
				}

				players_default_head_restore.SetObjectTexture(0, "");
				players_default_head_restore.SetObjectMaterial(0, "");

				string head_texture = "DZ\\characters\\heads\\data\\m_cyril\\hhl_m_cyril_body_shaved_co.paa";
				string head_material = "DZ\\characters\\heads\\data\\m_cyril\\hhl_m_cyril_body_unshaved.rvmat";

				player_backup.SetFaceTexture(head_texture);
				player_backup.SetFaceMaterial(head_material);
			}

			if (restore_players_body)
			{
				if (tone_mat_array && tone_mat_array.Count() > 0)
					tone_mat_array.Clear();

				if (tone_texture_array && tone_texture_array.Count() > 0)
					tone_texture_array.Clear();

				GetGame().ConfigGetTextArray("cfgVehicles " + restore_players_body.GetType() + " hiddenSelectionsMaterials", tone_mat_array);
				GetGame().ConfigGetTextArray("cfgVehicles " + restore_players_body.GetType() + " hiddenSelectionsTextures", tone_texture_array);

				restore_players_body.SetObjectTexture(0, tone_texture_array.Get(0));
				restore_players_body.SetObjectTexture(1, tone_texture_array.Get(1));
				restore_players_body.SetObjectTexture(2, tone_texture_array.Get(2));

				restore_players_body.SetObjectMaterial(0, tone_mat_array.Get(0));
				restore_players_body.SetObjectMaterial(1, tone_mat_array.Get(2));
				restore_players_body.SetObjectMaterial(2, tone_mat_array.Get(2));
			}
			else
			{
				EntityAI players_default_body_restore = player_backup.GetInventory().FindPlaceholderForSlot(InventorySlots.GetSlotIdFromString("Body"));

				if (players_default_body_restore)
				{
					if (tone_mat_array && tone_mat_array.Count() > 0)
						tone_mat_array.Clear();

					if (tone_texture_array && tone_texture_array.Count() > 0)
						tone_texture_array.Clear();

					GetGame().ConfigGetTextArray("cfgVehicles " + players_default_body_restore.GetType() + " hiddenSelectionsMaterials", tone_mat_array);
					GetGame().ConfigGetTextArray("cfgVehicles " + players_default_body_restore.GetType() + " hiddenSelectionsTextures", tone_texture_array);

					players_default_body_restore.SetObjectTexture(0, tone_texture_array.Get(0));
					players_default_body_restore.SetObjectMaterial(0, tone_mat_array.Get(0));
				}
			}

			if (restore_players_back)
			{

				if (tone_mat_array && tone_mat_array.Count() > 0)
					tone_mat_array.Clear();

				if (tone_texture_array && tone_texture_array.Count() > 0)
					tone_texture_array.Clear();

				GetGame().ConfigGetTextArray("cfgVehicles " + restore_players_back.GetType() + " hiddenSelectionsMaterials", tone_mat_array);
				GetGame().ConfigGetTextArray("cfgVehicles " + restore_players_back.GetType() + " hiddenSelectionsTextures", tone_texture_array);

				restore_players_back.SetObjectTexture(0, tone_texture_array.Get(0));
				restore_players_back.SetObjectTexture(1, tone_texture_array.Get(1));
				restore_players_back.SetObjectTexture(2, tone_texture_array.Get(2));

				restore_players_back.SetObjectMaterial(0, tone_mat_array.Get(0));
				restore_players_back.SetObjectMaterial(1, tone_mat_array.Get(2));
				restore_players_back.SetObjectMaterial(2, tone_mat_array.Get(2));
			}
			else
			{
				EntityAI players_default_back_restore = player_backup.GetInventory().FindPlaceholderForSlot(InventorySlots.GetSlotIdFromString("Back"));

				if (players_default_back_restore)
				{
					if (tone_mat_array && tone_mat_array.Count() > 0)
						tone_mat_array.Clear();

					if (tone_texture_array && tone_texture_array.Count() > 0)
						tone_texture_array.Clear();

					GetGame().ConfigGetTextArray("cfgVehicles " + players_default_back_restore.GetType() + " hiddenSelectionsMaterials", tone_mat_array);
					GetGame().ConfigGetTextArray("cfgVehicles " + players_default_back_restore.GetType() + " hiddenSelectionsTextures", tone_texture_array);
				}
			}

			if (restore_players_hips)
			{
				if (tone_mat_array && tone_mat_array.Count() > 0)
					tone_mat_array.Clear();

				if (tone_texture_array && tone_texture_array.Count() > 0)
					tone_texture_array.Clear();

				GetGame().ConfigGetTextArray("cfgVehicles " + restore_players_hips.GetType() + " hiddenSelectionsMaterials", tone_mat_array);
				GetGame().ConfigGetTextArray("cfgVehicles " + restore_players_hips.GetType() + " hiddenSelectionsTextures", tone_texture_array);

				restore_players_hips.SetObjectTexture(0, tone_texture_array.Get(0));
				restore_players_hips.SetObjectMaterial(0, tone_mat_array.Get(0));

				restore_players_hips.SetObjectTexture(1, tone_texture_array.Get(1));
				restore_players_hips.SetObjectMaterial(1, tone_mat_array.Get(1));

				restore_players_hips.SetObjectTexture(2, tone_texture_array.Get(2));
				restore_players_hips.SetObjectMaterial(2, tone_mat_array.Get(2));
			}
			else
			{
				EntityAI players_default_hips_restore = player_backup.GetInventory().FindPlaceholderForSlot(InventorySlots.GetSlotIdFromString("hips"));

				if (players_default_hips_restore)
				{
					if (tone_mat_array && tone_mat_array.Count() > 0)
						tone_mat_array.Clear();

					if (tone_texture_array && tone_texture_array.Count() > 0)
						tone_texture_array.Clear();

					GetGame().ConfigGetTextArray("cfgVehicles " + players_default_hips_restore.GetType() + " hiddenSelectionsMaterials", tone_mat_array);
					GetGame().ConfigGetTextArray("cfgVehicles " + players_default_hips_restore.GetType() + " hiddenSelectionsTextures", tone_texture_array);

					players_default_hips_restore.SetObjectTexture(0, tone_texture_array.Get(0));
					players_default_hips_restore.SetObjectMaterial(0, tone_mat_array.Get(0));
				}
			}

			if (restore_players_vest)
			{
				if (tone_mat_array && tone_mat_array.Count() > 0)
					tone_mat_array.Clear();

				if (tone_texture_array && tone_texture_array.Count() > 0)
					tone_texture_array.Clear();

				GetGame().ConfigGetTextArray("cfgVehicles " + restore_players_vest.GetType() + " hiddenSelectionsMaterials", tone_mat_array);
				GetGame().ConfigGetTextArray("cfgVehicles " + restore_players_vest.GetType() + " hiddenSelectionsTextures", tone_texture_array);

				restore_players_vest.SetObjectTexture(0, tone_texture_array.Get(0));
				restore_players_vest.SetObjectMaterial(0, tone_mat_array.Get(0));

				restore_players_vest.SetObjectTexture(1, tone_texture_array.Get(1));
				restore_players_vest.SetObjectMaterial(1, tone_mat_array.Get(1));

				restore_players_vest.SetObjectTexture(2, tone_texture_array.Get(2));
				restore_players_vest.SetObjectMaterial(2, tone_mat_array.Get(2));
			}
			else
			{
				EntityAI players_default_vest_restore = player_backup.GetInventory().FindPlaceholderForSlot(InventorySlots.GetSlotIdFromString("vest"));

				if (players_default_vest_restore)
				{
					if (tone_mat_array && tone_mat_array.Count() > 0)
						tone_mat_array.Clear();

					if (tone_texture_array && tone_texture_array.Count() > 0)
						tone_texture_array.Clear();

					GetGame().ConfigGetTextArray("cfgVehicles " + players_default_vest_restore.GetType() + " hiddenSelectionsMaterials", tone_mat_array);
					GetGame().ConfigGetTextArray("cfgVehicles " + players_default_vest_restore.GetType() + " hiddenSelectionsTextures", tone_texture_array);

					players_default_vest_restore.SetObjectTexture(0, tone_texture_array.Get(0));
					players_default_vest_restore.SetObjectMaterial(0, tone_mat_array.Get(0));
				}
			}

			if (restore_players_gloves)
			{
				if (tone_mat_array && tone_mat_array.Count() > 0)
					tone_mat_array.Clear();

				if (tone_texture_array && tone_texture_array.Count() > 0)
					tone_texture_array.Clear();

				GetGame().ConfigGetTextArray("cfgVehicles " + restore_players_gloves.GetType() + " hiddenSelectionsMaterials", tone_mat_array);
				GetGame().ConfigGetTextArray("cfgVehicles " + restore_players_gloves.GetType() + " hiddenSelectionsTextures", tone_texture_array);

				restore_players_gloves.SetObjectTexture(0, tone_texture_array.Get(0));
				restore_players_gloves.SetObjectMaterial(0, tone_mat_array.Get(0));

				restore_players_gloves.SetObjectTexture(1, tone_texture_array.Get(1));
				restore_players_gloves.SetObjectMaterial(1, tone_mat_array.Get(1));

				restore_players_gloves.SetObjectTexture(2, tone_texture_array.Get(2));
				restore_players_gloves.SetObjectMaterial(2, tone_mat_array.Get(2));
			}
			else
			{
				EntityAI players_default_gloves_restore = player_backup.GetInventory().FindPlaceholderForSlot(InventorySlots.GetSlotIdFromString("gloves"));

				if (tone_mat_array && tone_mat_array.Count() > 0)
					tone_mat_array.Clear();

				if (tone_texture_array && tone_texture_array.Count() > 0)
					tone_texture_array.Clear();

				if (players_default_gloves_restore)
				{
					GetGame().ConfigGetTextArray("cfgVehicles " + players_default_gloves_restore.GetType() + " hiddenSelectionsMaterials", tone_mat_array);
					GetGame().ConfigGetTextArray("cfgVehicles " + players_default_gloves_restore.GetType() + " hiddenSelectionsTextures", tone_texture_array);

					players_default_gloves_restore.SetObjectTexture(0, tone_texture_array.Get(0));
					players_default_gloves_restore.SetObjectMaterial(0, tone_mat_array.Get(0));
				}
			}

			if (restore_players_legs)
			{
				if (tone_mat_array && tone_mat_array.Count() > 0)
					tone_mat_array.Clear();

				if (tone_texture_array && tone_texture_array.Count() > 0)
					tone_texture_array.Clear();

				GetGame().ConfigGetTextArray("cfgVehicles " + restore_players_legs.GetType() + " hiddenSelectionsMaterials", tone_mat_array);
				GetGame().ConfigGetTextArray("cfgVehicles " + restore_players_legs.GetType() + " hiddenSelectionsTextures", tone_texture_array);

				restore_players_legs.SetObjectTexture(0, tone_texture_array.Get(0));
				restore_players_legs.SetObjectMaterial(0, tone_mat_array.Get(0));

				restore_players_legs.SetObjectTexture(1, tone_texture_array.Get(1));
				restore_players_legs.SetObjectMaterial(1, tone_mat_array.Get(1));

				restore_players_legs.SetObjectTexture(2, tone_texture_array.Get(2));
				restore_players_legs.SetObjectMaterial(2, tone_mat_array.Get(2));
			}
			else
			{
				EntityAI players_default_legs_restore = player_backup.GetInventory().FindPlaceholderForSlot(InventorySlots.GetSlotIdFromString("legs"));

				if (players_default_legs_restore)
				{
					if (tone_mat_array && tone_mat_array.Count() > 0)
						tone_mat_array.Clear();

					if (tone_texture_array && tone_texture_array.Count() > 0)
						tone_texture_array.Clear();

					GetGame().ConfigGetTextArray("cfgVehicles " + players_default_legs_restore.GetType() + " hiddenSelectionsMaterials", tone_mat_array);
					GetGame().ConfigGetTextArray("cfgVehicles " + players_default_legs_restore.GetType() + " hiddenSelectionsTextures", tone_texture_array);

					players_default_legs_restore.SetObjectTexture(0, tone_texture_array.Get(0));
					players_default_legs_restore.SetObjectMaterial(0, tone_mat_array.Get(0));
				}
			}

			if (restore_players_feet)
			{
				if (tone_mat_array && tone_mat_array.Count() > 0)
					tone_mat_array.Clear();

				if (tone_texture_array && tone_texture_array.Count() > 0)
					tone_texture_array.Clear();

				GetGame().ConfigGetTextArray("cfgVehicles " + restore_players_feet.GetType() + " hiddenSelectionsMaterials", tone_mat_array);
				GetGame().ConfigGetTextArray("cfgVehicles " + restore_players_feet.GetType() + " hiddenSelectionsTextures", tone_texture_array);

				restore_players_feet.SetObjectTexture(0, tone_texture_array.Get(0));
				restore_players_feet.SetObjectMaterial(0, tone_mat_array.Get(0));

				restore_players_feet.SetObjectTexture(1, tone_texture_array.Get(1));
				restore_players_feet.SetObjectMaterial(1, tone_mat_array.Get(1));

				restore_players_feet.SetObjectTexture(2, tone_texture_array.Get(2));
				restore_players_feet.SetObjectMaterial(2, tone_mat_array.Get(2));
			}
			else
			{
				EntityAI players_default_feet_restore = player_backup.GetInventory().FindPlaceholderForSlot(InventorySlots.GetSlotIdFromString("Feet"));

				if (players_default_feet_restore)
				{
					if (tone_mat_array && tone_mat_array.Count() > 0)
						tone_mat_array.Clear();

					if (tone_texture_array && tone_texture_array.Count() > 0)
						tone_texture_array.Clear();

					GetGame().ConfigGetTextArray("cfgVehicles " + players_default_feet_restore.GetType() + " hiddenSelectionsMaterials", tone_mat_array);
					GetGame().ConfigGetTextArray("cfgVehicles " + players_default_feet_restore.GetType() + " hiddenSelectionsTextures", tone_texture_array);

					players_default_feet_restore.SetObjectTexture(0, tone_texture_array.Get(0));
					players_default_feet_restore.SetObjectMaterial(0, tone_mat_array.Get(0));
				}
			}
		}
	}
	
	void CreateThermal()
	{
		PlayerBase m_player = PlayerBase.Cast(this);
		
		if (!m_player)
		{
			Print("m_player nullptr!");
			return;
		}
		
		//this is a function called when a player has a weapon and is scoped in if IsUsingThermal then we constantly update the thermal scope
		if (m_player.IsUsingThermal())
		{
			if ( !GetGame().IsServer() && GetGame().IsClient() )
			{
				ref array<Object> Objects = new array<Object>;
				ref array<CargoBase> proxyCargos = new array<CargoBase>;
				
				if (m_player.IsUsingThermal())
				{
					if (Objects && Objects.Count() > 0)
						Objects.Clear();
						
					if (proxyCargos && proxyCargos.Count() > 0)
						proxyCargos.Clear();
						
					GetGame().GetObjectsAtPosition(m_player.GetPosition(), 700, Objects, proxyCargos);
		
					for (int d = 0; d < Objects.Count(); d++)
					{
						Object Object_ = Objects[d];
						
						if (!Object_)
							continue;

						if (!Object_.IsMan())
							continue;
						
						/*if (Object_.GetType() == "Animal_BosTaurusF_Spotted")
						{
							EntityAI AnimalCast;
							Class.CastTo(AnimalCast, Objects.Get(d));
		
							if (AnimalCast)
							{
								string pathtexture_ = "ThermalAssets\\Scopes\\Green.paa";
								string pathmateriel_ = "ThermalAssets\\Scopes\\redeffect.rvmat";
		
								ref TStringArray materials_ = new TStringArray;
								ref TStringArray textures_ = new TStringArray;
		
								materials_.Insert(pathmateriel_);
								textures_.Insert(pathtexture_);
		
								AnimalCast.SetObjectTexture(0, textures_.Get(0));
								AnimalCast.SetObjectMaterial(0, materials_.Get(0));
							}
						}*/

						if (Object_.IsMan())
						{
							PlayerBase player_;
							Class.CastTo(player_, Objects.Get(d));
	
							// if the player is our local client we skip
							if (m_player == player_)
								continue;
															
							if (player_)
							{
									bool is_visible = false;
									
									EntityAI players_head   = player_.GetInventory().FindAttachment(InventorySlots.GetSlotIdFromString("Head"));
									EntityAI players_body   = player_.GetInventory().FindAttachment(InventorySlots.GetSlotIdFromString("Body"));
									EntityAI players_back   = player_.GetInventory().FindAttachment(InventorySlots.GetSlotIdFromString("Back"));
									EntityAI players_hips   = player_.GetInventory().FindAttachment(InventorySlots.GetSlotIdFromString("Hips"));
									EntityAI players_vest   = player_.GetInventory().FindAttachment(InventorySlots.GetSlotIdFromString("Vest"));
									EntityAI players_gloves = player_.GetInventory().FindAttachment(InventorySlots.GetSlotIdFromString("Gloves"));
									EntityAI players_legs   = player_.GetInventory().FindAttachment(InventorySlots.GetSlotIdFromString("legs"));
									EntityAI players_feet   = player_.GetInventory().FindAttachment(InventorySlots.GetSlotIdFromString("Feet"));
		
									float hitFraction;
									vector hitPosition, hitNormal;
			
									bool found_head;
									bool found_chest;
									bool found_left_arm;
									bool found_right_arm;
								
									vector from_head  = m_player.GetBonePositionWS(m_player.GetBoneIndexByName("Head"));
									vector to_head = player_.GetBonePositionWS(player_.GetBoneIndexByName("Head"));
									
									vector from_chest = m_player.GetBonePositionWS(m_player.GetBoneIndexByName("Head"));
									vector to_chest = player_.GetBonePositionWS(player_.GetBoneIndexByName("Chest"));
								
									vector from_left_arm = m_player.GetBonePositionWS(m_player.GetBoneIndexByName("Head"));
									vector to_left_arm = player_.GetBonePositionWS(player_.GetBoneIndexByName("leftforearm"));
								
									vector from_right_arm = m_player.GetBonePositionWS(m_player.GetBoneIndexByName("Head"));
									vector to_right_arm = player_.GetBonePositionWS(player_.GetBoneIndexByName("rightforearm"));
								
									Object hitObject;
									PhxInteractionLayers collisionLayerMask = PhxInteractionLayers.ITEM_LARGE | PhxInteractionLayers.BUILDING | PhxInteractionLayers.VEHICLE;
							
									found_head = DayZPhysics.RayCastBullet(from_head, to_head, collisionLayerMask, null, hitObject, hitPosition, hitNormal, hitFraction);
									found_chest = DayZPhysics.RayCastBullet(from_chest, to_chest, collisionLayerMask, null, hitObject, hitPosition, hitNormal, hitFraction);
									found_left_arm = DayZPhysics.RayCastBullet(from_left_arm, to_left_arm, collisionLayerMask, null, hitObject, hitPosition, hitNormal, hitFraction);
									found_right_arm = DayZPhysics.RayCastBullet(from_right_arm, to_right_arm, collisionLayerMask, null, hitObject, hitPosition, hitNormal, hitFraction);
									
									//opposite using thermal if we can find a body component that is visible to us we enable thermal
									if (!found_head || !found_chest || !found_left_arm || !found_right_arm)
										is_visible = true;
												
									if (found_head)
										Print("hit head");
									else 
										Print("Head Not Visibile");
																		
									if (!player_.IsAlive())
									{
										//if the player is dead we remove this player from the thermal preventing wallhacking
										RemovalThermalOnEntity(player_);	
									
										//if the player is dead we restore his head preventing the glow wallhack on head
										PluginLifespan m_ModuleLifespan_ = PluginLifespan.Cast( GetPlugin( PluginLifespan ) );
										
										if (m_ModuleLifespan_)
										{
											m_ModuleLifespan_.UpdateLifespan( player_, true );
										}
									
										continue;
									}
								
									if (!is_visible)
									{
										// if the player is not visible we remove this player from the thermal preventing wallhacking
										RemovalThermalOnEntity(player_);
										continue;
									}
									
									player_.SetThermalApplied(true);

									//path to the assets
									string pathtexture = "ThermalAssets\\Scopes\\Orange.paa";
									string pathmateriel = "ThermalAssets\\Scopes\\Glow.rvmat";
									
		
									ref TStringArray materials = new TStringArray;
									ref TStringArray textures = new TStringArray;
		
									//we set our texture/materiel array that we are going to use to apply to the player below
									materials.Insert(pathmateriel);
									textures.Insert(pathtexture);
									
									if (players_head)
									{
										players_head.SetObjectTexture(1, textures.Get(0));
										players_head.SetObjectMaterial(1, materials.Get(0));
		
										players_head.SetObjectTexture(0, textures.Get(0));
										players_head.SetObjectMaterial(0, materials.Get(0));

									}
									else
									{
										EntityAI players_default_head = player_.GetInventory().FindPlaceholderForSlot(InventorySlots.GetSlotIdFromString("Head"));
		
										if (players_default_head)
										{
											players_default_head.SetObjectTexture(0, "");
											players_default_head.SetObjectMaterial(0, "");
		
											player_.SetFaceTexture(textures.Get(0));
											player_.SetFaceMaterial(materials.Get(0));
											
										}
									}
		
									if (players_body)
									{
										players_body.SetObjectTexture(1, textures.Get(0));
										players_body.SetObjectMaterial(1, materials.Get(0));
		
										players_body.SetObjectTexture(0, textures.Get(0));
										players_body.SetObjectMaterial(0, materials.Get(0));
		
										players_body.SetObjectTexture(2, textures.Get(0));
										players_body.SetObjectMaterial(2, materials.Get(0));
									}
									else
									{
										EntityAI players_default_body = player_.GetInventory().FindPlaceholderForSlot(InventorySlots.GetSlotIdFromString("Body"));
		
										if (players_default_body)
										{
											players_default_body.SetObjectTexture(0, textures.Get(0));
											players_default_body.SetObjectMaterial(0, materials.Get(0));

										}
									}
		
									if (players_back)
									{
										players_back.SetObjectTexture(1, textures.Get(0));
										players_back.SetObjectMaterial(1, materials.Get(0));
		
										players_back.SetObjectTexture(0, textures.Get(0));
										players_back.SetObjectMaterial(0, materials.Get(0));
		
										players_back.SetObjectTexture(2, textures.Get(0));
										players_back.SetObjectMaterial(2, materials.Get(0));
									}
									else
									{
										EntityAI players_default_back = player_.GetInventory().FindPlaceholderForSlot(InventorySlots.GetSlotIdFromString("Back"));
		
										if (players_default_back)
										{
											players_default_back.SetObjectTexture(0, textures.Get(0));
											players_default_back.SetObjectMaterial(0, materials.Get(0));

										}
									}
		
									if (players_hips)
									{
										players_hips.SetObjectTexture(1, textures.Get(0));
										players_hips.SetObjectMaterial(1, materials.Get(0));
		
										players_hips.SetObjectTexture(0, textures.Get(0));
										players_hips.SetObjectMaterial(0, materials.Get(0));
		
										players_hips.SetObjectTexture(2, textures.Get(0));
										players_hips.SetObjectMaterial(2, materials.Get(0));
									}
									else
									{
										EntityAI players_default_hips = player_.GetInventory().FindPlaceholderForSlot(InventorySlots.GetSlotIdFromString("Hips"));
		
										if (players_default_hips)
										{
											players_default_hips.SetObjectTexture(0, textures.Get(0));
											players_default_hips.SetObjectMaterial(0, materials.Get(0));
										}
									}
		
									if (players_vest)
									{
										players_vest.SetObjectTexture(1, textures.Get(0));
										players_vest.SetObjectMaterial(1, materials.Get(0));
		
										players_vest.SetObjectTexture(0, textures.Get(0));
										players_vest.SetObjectMaterial(0, materials.Get(0));
		
										players_vest.SetObjectTexture(2, textures.Get(0));
										players_vest.SetObjectMaterial(2, materials.Get(0));
									}
									else
									{
										EntityAI players_default_vest = player_.GetInventory().FindPlaceholderForSlot(InventorySlots.GetSlotIdFromString("Vest"));
		
										if (players_default_vest)
										{
											players_default_vest.SetObjectTexture(0, textures.Get(0));
											players_default_vest.SetObjectMaterial(0, materials.Get(0));
										}
									}
		
		
									if (players_gloves)
									{
										players_gloves.SetObjectTexture(1, textures.Get(0));
										players_gloves.SetObjectMaterial(1, materials.Get(0));
		
										players_gloves.SetObjectTexture(0, textures.Get(0));
										players_gloves.SetObjectMaterial(0, materials.Get(0));
		
										players_gloves.SetObjectTexture(2, textures.Get(0));
										players_gloves.SetObjectMaterial(2, materials.Get(0));
									}
									else
									{
										EntityAI players_default_gloves = player_.GetInventory().FindPlaceholderForSlot(InventorySlots.GetSlotIdFromString("Gloves"));
		
										if (players_default_gloves)
										{
											players_default_gloves.SetObjectTexture(0, textures.Get(0));
											players_default_gloves.SetObjectMaterial(0, materials.Get(0));

										}
									}
		
									if (players_feet)
									{
										players_feet.SetObjectTexture(1, textures.Get(0));
										players_feet.SetObjectMaterial(1, materials.Get(0));
		
										players_feet.SetObjectTexture(0, textures.Get(0));
										players_feet.SetObjectMaterial(0, materials.Get(0));
		
										players_feet.SetObjectTexture(2, textures.Get(0));
										players_feet.SetObjectMaterial(2, materials.Get(0));
									}
									else
									{
										EntityAI players_default_feet = player_.GetInventory().FindPlaceholderForSlot(InventorySlots.GetSlotIdFromString("Feet"));
		
										if (players_default_feet)
										{
											players_default_feet.SetObjectTexture(0, textures.Get(0));
											players_default_feet.SetObjectMaterial(0, materials.Get(0));
	
										}
									}
		
									if (players_legs)
									{
										players_legs.SetObjectTexture(1, textures.Get(0));
										players_legs.SetObjectMaterial(1, materials.Get(0));
		
										players_legs.SetObjectTexture(0, textures.Get(0));
										players_legs.SetObjectMaterial(0, materials.Get(0));
		
										players_legs.SetObjectTexture(2, textures.Get(0));
										players_legs.SetObjectMaterial(2, materials.Get(0));
									}
									else
									{
										EntityAI players_default_legs = player_.GetInventory().FindPlaceholderForSlot(InventorySlots.GetSlotIdFromString("legs"));
		
										if (players_default_legs)
										{
											players_default_legs.SetObjectTexture(0, textures.Get(0));
											players_default_legs.SetObjectMaterial(0, materials.Get(0));
										}
									}
							}
						}
					}
				}
			}	
		}
		else 
		{
			if (ThermalTimer && ThermalTimer.IsRunning())
				ThermalTimer.Stop();
		}
	}
	
	void CreateThermalTimer()
	{
		ThermalTimer = new Timer();
		
		if (!ThermalTimer.IsRunning())
			ThermalTimer.Run(2, this, "CreateThermal", null, true);	

		// Force the creation of thermal before we "update" thermal using our timer
		CreateThermal();
	}
	
	void RemoveThermalCode(PlayerBase player)
	{	
		ref array<Object> Objects_Restore = new array<Object>;
		ref array<CargoBase> proxyCargos_Restore = new array<CargoBase>;
	
		if ( !GetGame().IsServer() || GetGame().IsClient())
		{	
				//the player has unscoped we check if the player was using thermal if they were we restore all players that had the thermal applied to them
				if (player.IsUsingThermal())
				{
					if (Objects_Restore && Objects_Restore.Count() > 0)
					    Objects_Restore.Clear();
					
					if (proxyCargos_Restore && proxyCargos_Restore.Count() > 0)
					    proxyCargos_Restore.Clear();
					
					GetGame().GetObjectsAtPosition(player.GetPosition(), 700, Objects_Restore, proxyCargos_Restore);
	
					for (int e = 0; e < Objects_Restore.Count(); e++)
					{
						if (!Objects_Restore[e].IsMan()) 
							continue;
								
						/*if (Objects_Restore[e].GetType() == "Animal_BosTaurusF_Spotted")
						{
							EntityAI AnimalCast_Restore;
							Class.CastTo(AnimalCast_Restore, Objects_Restore.Get(e));
	
							if (AnimalCast_Restore)
							{
								array<string> tone_mat_array_animals = new array<string>;
								array<string> tone_texture_array_animals = new array<string>;
								
								GetGame().ConfigGetTextArray("cfgVehicles " + AnimalCast_Restore.GetType() + " hiddenSelectionsMaterials", tone_mat_array_animals);
								GetGame().ConfigGetTextArray("cfgVehicles " + AnimalCast_Restore.GetType() + " hiddenSelectionsTextures", tone_texture_array_animals);
								
								AnimalCast_Restore.SetObjectTexture(0, tone_texture_array_animals.Get(0));
								AnimalCast_Restore.SetObjectMaterial(0, tone_mat_array_animals.Get(0));

							}
						}*/
	
						if (Objects_Restore[e].IsMan())
						{
							PlayerBase player_backup;
							Class.CastTo(player_backup, Objects_Restore.Get(e));
	
							if (player == player_backup)
								continue;
							
							if (player_backup)
							{
								EntityAI restore_players_head = player_backup.GetInventory().FindAttachment(InventorySlots.GetSlotIdFromString("Head"));
								EntityAI restore_players_body = player_backup.GetInventory().FindAttachment(InventorySlots.GetSlotIdFromString("Body"));
								EntityAI restore_players_back = player_backup.GetInventory().FindAttachment(InventorySlots.GetSlotIdFromString("Back"));
								EntityAI restore_players_hips = player_backup.GetInventory().FindAttachment(InventorySlots.GetSlotIdFromString("Hips"));
								EntityAI restore_players_vest = player_backup.GetInventory().FindAttachment(InventorySlots.GetSlotIdFromString("Vest"));
								EntityAI restore_players_gloves = player_backup.GetInventory().FindAttachment(InventorySlots.GetSlotIdFromString("Gloves"));
								EntityAI restore_players_legs = player_backup.GetInventory().FindAttachment(InventorySlots.GetSlotIdFromString("legs"));
								EntityAI restore_players_feet = player_backup.GetInventory().FindAttachment(InventorySlots.GetSlotIdFromString("Feet"));
	
								array<string> tone_mat_array = new array<string>;
								array<string> tone_texture_array = new array<string>;
	
								string head_texture = "DZ\\characters\\heads\\data\\m_cyril\\hhl_m_cyril_body_shaved_co.paa";
								string head_material = "DZ\\characters\\heads\\data\\m_cyril\\hhl_m_cyril_body_unshaved.rvmat";
					
								if (restore_players_head)
								{									
									PluginLifespan m_ModuleLifespan_ = PluginLifespan.Cast( GetPlugin( PluginLifespan ) );
										
									if (m_ModuleLifespan_)
									{
										m_ModuleLifespan_.UpdateLifespan( player_backup, true );
									}

									restore_players_head.SetObjectTexture(0, "");
									restore_players_head.SetObjectMaterial(0, "");
									
									player_backup.SetFaceTexture(head_texture);
									player_backup.SetFaceMaterial(head_material);
									
								}
								else
								{									
									PluginLifespan m_ModuleLifespan = PluginLifespan.Cast( GetPlugin( PluginLifespan ) );
										
									if (m_ModuleLifespan)
									{
										m_ModuleLifespan.UpdateLifespan( player_backup, true );
									}
									
									EntityAI players_default_head_restore = player_backup.GetInventory().FindPlaceholderForSlot(InventorySlots.GetSlotIdFromString("Head"));
									
									players_default_head_restore.SetObjectTexture(0, "");
									players_default_head_restore.SetObjectMaterial(0, "");
									
									player_backup.SetFaceTexture(head_texture);
									player_backup.SetFaceMaterial(head_material);
								}
	
								if (restore_players_body)
								{									
									if (tone_mat_array && tone_mat_array.Count() > 0)
										tone_mat_array.Clear();
										
									if (tone_texture_array && tone_texture_array.Count() > 0)
										tone_texture_array.Clear();
	
									GetGame().ConfigGetTextArray("cfgVehicles " + restore_players_body.GetType() + " hiddenSelectionsMaterials", tone_mat_array);
									GetGame().ConfigGetTextArray("cfgVehicles " + restore_players_body.GetType() + " hiddenSelectionsTextures", tone_texture_array);
	
									restore_players_body.SetObjectTexture(0, tone_texture_array.Get(0));
									restore_players_body.SetObjectTexture(1, tone_texture_array.Get(1));
									restore_players_body.SetObjectTexture(2, tone_texture_array.Get(2));
	
									restore_players_body.SetObjectMaterial(0, tone_mat_array.Get(0));
									restore_players_body.SetObjectMaterial(1, tone_mat_array.Get(2));
									restore_players_body.SetObjectMaterial(2, tone_mat_array.Get(2));
								}
								else
								{									
									EntityAI players_default_body_restore = player_backup.GetInventory().FindPlaceholderForSlot(InventorySlots.GetSlotIdFromString("Body"));
	
									if (players_default_body_restore)
									{
										if (tone_mat_array && tone_mat_array.Count() > 0)
											tone_mat_array.Clear();
										
										if (tone_texture_array && tone_texture_array.Count() > 0)
											tone_texture_array.Clear();
	
										GetGame().ConfigGetTextArray("cfgVehicles " + players_default_body_restore.GetType() + " hiddenSelectionsMaterials", tone_mat_array);
										GetGame().ConfigGetTextArray("cfgVehicles " + players_default_body_restore.GetType() + " hiddenSelectionsTextures", tone_texture_array);
	
										players_default_body_restore.SetObjectTexture(0, tone_texture_array.Get(0));
										players_default_body_restore.SetObjectMaterial(0, tone_mat_array.Get(0));
									}
								}
	
								if (restore_players_back)
								{									
									if (tone_mat_array && tone_mat_array.Count() > 0)
										tone_mat_array.Clear();
										
									if (tone_texture_array && tone_texture_array.Count() > 0)
										tone_texture_array.Clear();
	
									GetGame().ConfigGetTextArray("cfgVehicles " + restore_players_back.GetType() + " hiddenSelectionsMaterials", tone_mat_array);
									GetGame().ConfigGetTextArray("cfgVehicles " + restore_players_back.GetType() + " hiddenSelectionsTextures", tone_texture_array);
	
									restore_players_back.SetObjectTexture(0, tone_texture_array.Get(0));
									restore_players_back.SetObjectTexture(1, tone_texture_array.Get(1));
									restore_players_back.SetObjectTexture(2, tone_texture_array.Get(2));
	
									restore_players_back.SetObjectMaterial(0, tone_mat_array.Get(0));
									restore_players_back.SetObjectMaterial(1, tone_mat_array.Get(2));
									restore_players_back.SetObjectMaterial(2, tone_mat_array.Get(2));
								}
								else
								{									
									EntityAI players_default_back_restore = player_backup.GetInventory().FindPlaceholderForSlot(InventorySlots.GetSlotIdFromString("Back"));
	
									if (players_default_back_restore)
									{
										if (tone_mat_array && tone_mat_array.Count() > 0)
											tone_mat_array.Clear();
										
										if (tone_texture_array && tone_texture_array.Count() > 0)
											tone_texture_array.Clear();
	
										GetGame().ConfigGetTextArray("cfgVehicles " + players_default_back_restore.GetType() + " hiddenSelectionsMaterials", tone_mat_array);
										GetGame().ConfigGetTextArray("cfgVehicles " + players_default_back_restore.GetType() + " hiddenSelectionsTextures", tone_texture_array);
									}
								}
	
								if (restore_players_hips)
								{									
									if (tone_mat_array && tone_mat_array.Count() > 0)
										tone_mat_array.Clear();
										
									if (tone_texture_array && tone_texture_array.Count() > 0)
										tone_texture_array.Clear();
	
									GetGame().ConfigGetTextArray("cfgVehicles " + restore_players_hips.GetType() + " hiddenSelectionsMaterials", tone_mat_array);
									GetGame().ConfigGetTextArray("cfgVehicles " + restore_players_hips.GetType() + " hiddenSelectionsTextures", tone_texture_array);
	
									restore_players_hips.SetObjectTexture(0, tone_texture_array.Get(0));
									restore_players_hips.SetObjectMaterial(0, tone_mat_array.Get(0));
	
									restore_players_hips.SetObjectTexture(1, tone_texture_array.Get(1));
									restore_players_hips.SetObjectMaterial(1, tone_mat_array.Get(1));
	
									restore_players_hips.SetObjectTexture(2, tone_texture_array.Get(2));
									restore_players_hips.SetObjectMaterial(2, tone_mat_array.Get(2));
								}
								else
								{									
									EntityAI players_default_hips_restore = player_backup.GetInventory().FindPlaceholderForSlot(InventorySlots.GetSlotIdFromString("hips"));
	
									if (players_default_hips_restore)
									{
										if (tone_mat_array && tone_mat_array.Count() > 0)
											tone_mat_array.Clear();
										
										if (tone_texture_array && tone_texture_array.Count() > 0)
											tone_texture_array.Clear();
	
										GetGame().ConfigGetTextArray("cfgVehicles " + players_default_hips_restore.GetType() + " hiddenSelectionsMaterials", tone_mat_array);
										GetGame().ConfigGetTextArray("cfgVehicles " + players_default_hips_restore.GetType() + " hiddenSelectionsTextures", tone_texture_array);
	
										players_default_hips_restore.SetObjectTexture(0, tone_texture_array.Get(0));
										players_default_hips_restore.SetObjectMaterial(0, tone_mat_array.Get(0));
	
									}
								}
								
								if (restore_players_vest)
								{									
									if (tone_mat_array && tone_mat_array.Count() > 0)
										tone_mat_array.Clear();
										
									if (tone_texture_array && tone_texture_array.Count() > 0)
										tone_texture_array.Clear();
	
									GetGame().ConfigGetTextArray("cfgVehicles " + restore_players_vest.GetType() + " hiddenSelectionsMaterials", tone_mat_array);
									GetGame().ConfigGetTextArray("cfgVehicles " + restore_players_vest.GetType() + " hiddenSelectionsTextures", tone_texture_array);
	
									restore_players_vest.SetObjectTexture(0, tone_texture_array.Get(0));
									restore_players_vest.SetObjectMaterial(0, tone_mat_array.Get(0));
	
									restore_players_vest.SetObjectTexture(1, tone_texture_array.Get(1));
									restore_players_vest.SetObjectMaterial(1, tone_mat_array.Get(1));
	
									restore_players_vest.SetObjectTexture(2, tone_texture_array.Get(2));
									restore_players_vest.SetObjectMaterial(2, tone_mat_array.Get(2));
								}
								else
								{									
									EntityAI players_default_vest_restore = player_backup.GetInventory().FindPlaceholderForSlot(InventorySlots.GetSlotIdFromString("vest"));
	
									if (players_default_vest_restore)
									{
										if (tone_mat_array && tone_mat_array.Count() > 0)
											tone_mat_array.Clear();
										
										if (tone_texture_array && tone_texture_array.Count() > 0)
											tone_texture_array.Clear();
	
										GetGame().ConfigGetTextArray("cfgVehicles " + players_default_vest_restore.GetType() + " hiddenSelectionsMaterials", tone_mat_array);
										GetGame().ConfigGetTextArray("cfgVehicles " + players_default_vest_restore.GetType() + " hiddenSelectionsTextures", tone_texture_array);
	
										players_default_vest_restore.SetObjectTexture(0, tone_texture_array.Get(0));
										players_default_vest_restore.SetObjectMaterial(0, tone_mat_array.Get(0));
									}
								}
	
								if (restore_players_gloves)
								{									
									if (tone_mat_array && tone_mat_array.Count() > 0)
										tone_mat_array.Clear();
										
									if (tone_texture_array && tone_texture_array.Count() > 0)
										tone_texture_array.Clear();
	
									GetGame().ConfigGetTextArray("cfgVehicles " + restore_players_gloves.GetType() + " hiddenSelectionsMaterials", tone_mat_array);
									GetGame().ConfigGetTextArray("cfgVehicles " + restore_players_gloves.GetType() + " hiddenSelectionsTextures", tone_texture_array);
	
									restore_players_gloves.SetObjectTexture(0, tone_texture_array.Get(0));
									restore_players_gloves.SetObjectMaterial(0, tone_mat_array.Get(0));
	
									restore_players_gloves.SetObjectTexture(1, tone_texture_array.Get(1));
									restore_players_gloves.SetObjectMaterial(1, tone_mat_array.Get(1));
	
									restore_players_gloves.SetObjectTexture(2, tone_texture_array.Get(2));
									restore_players_gloves.SetObjectMaterial(2, tone_mat_array.Get(2));
								}
								else
								{									
									EntityAI players_default_gloves_restore = player_backup.GetInventory().FindPlaceholderForSlot(InventorySlots.GetSlotIdFromString("gloves"));
	
									if (tone_mat_array && tone_mat_array.Count() > 0)
											tone_mat_array.Clear();
										
										if (tone_texture_array && tone_texture_array.Count() > 0)
											tone_texture_array.Clear();
	
									if (players_default_gloves_restore)
									{
										GetGame().ConfigGetTextArray("cfgVehicles " + players_default_gloves_restore.GetType() + " hiddenSelectionsMaterials", tone_mat_array);
										GetGame().ConfigGetTextArray("cfgVehicles " + players_default_gloves_restore.GetType() + " hiddenSelectionsTextures", tone_texture_array);
	
										players_default_gloves_restore.SetObjectTexture(0, tone_texture_array.Get(0));
										players_default_gloves_restore.SetObjectMaterial(0, tone_mat_array.Get(0));
									}
								}
	
								if (restore_players_legs)
								{									
									if (tone_mat_array && tone_mat_array.Count() > 0)
										tone_mat_array.Clear();
										
									if (tone_texture_array && tone_texture_array.Count() > 0)
										tone_texture_array.Clear();
									
									GetGame().ConfigGetTextArray("cfgVehicles " + restore_players_legs.GetType() + " hiddenSelectionsMaterials", tone_mat_array);
									GetGame().ConfigGetTextArray("cfgVehicles " + restore_players_legs.GetType() + " hiddenSelectionsTextures", tone_texture_array);
	
									restore_players_legs.SetObjectTexture(0, tone_texture_array.Get(0));
									restore_players_legs.SetObjectMaterial(0, tone_mat_array.Get(0));
	
									restore_players_legs.SetObjectTexture(1, tone_texture_array.Get(1));
									restore_players_legs.SetObjectMaterial(1, tone_mat_array.Get(1));
	
									restore_players_legs.SetObjectTexture(2, tone_texture_array.Get(2));
									restore_players_legs.SetObjectMaterial(2, tone_mat_array.Get(2));
								}
								else
								{									
									EntityAI players_default_legs_restore = player_backup.GetInventory().FindPlaceholderForSlot(InventorySlots.GetSlotIdFromString("legs"));
	
									if (players_default_legs_restore)
									{
										if (tone_mat_array && tone_mat_array.Count() > 0)
											tone_mat_array.Clear();
										
										if (tone_texture_array && tone_texture_array.Count() > 0)
											tone_texture_array.Clear();
	
										GetGame().ConfigGetTextArray("cfgVehicles " + players_default_legs_restore.GetType() + " hiddenSelectionsMaterials", tone_mat_array);
										GetGame().ConfigGetTextArray("cfgVehicles " + players_default_legs_restore.GetType() + " hiddenSelectionsTextures", tone_texture_array);
	
										players_default_legs_restore.SetObjectTexture(0, tone_texture_array.Get(0));
										players_default_legs_restore.SetObjectMaterial(0, tone_mat_array.Get(0));
									}
								}
	
								if (restore_players_feet)
								{									
									if (tone_mat_array && tone_mat_array.Count() > 0)
										tone_mat_array.Clear();
										
									if (tone_texture_array && tone_texture_array.Count() > 0)
										tone_texture_array.Clear();
	
									GetGame().ConfigGetTextArray("cfgVehicles " + restore_players_feet.GetType() + " hiddenSelectionsMaterials", tone_mat_array);
									GetGame().ConfigGetTextArray("cfgVehicles " + restore_players_feet.GetType() + " hiddenSelectionsTextures", tone_texture_array);
	
									restore_players_feet.SetObjectTexture(0, tone_texture_array.Get(0));
									restore_players_feet.SetObjectMaterial(0, tone_mat_array.Get(0));
	
									restore_players_feet.SetObjectTexture(1, tone_texture_array.Get(1));
									restore_players_feet.SetObjectMaterial(1, tone_mat_array.Get(1));
	
									restore_players_feet.SetObjectTexture(2, tone_texture_array.Get(2));
									restore_players_feet.SetObjectMaterial(2, tone_mat_array.Get(2));
								}
								else
								{									
									EntityAI players_default_feet_restore = player_backup.GetInventory().FindPlaceholderForSlot(InventorySlots.GetSlotIdFromString("Feet"));
	
									if (players_default_feet_restore)
									{
										if (tone_mat_array && tone_mat_array.Count() > 0)
											tone_mat_array.Clear();
										
										if (tone_texture_array && tone_texture_array.Count() > 0)
											tone_texture_array.Clear();
	
										GetGame().ConfigGetTextArray("cfgVehicles " + players_default_feet_restore.GetType() + " hiddenSelectionsMaterials", tone_mat_array);
										GetGame().ConfigGetTextArray("cfgVehicles " + players_default_feet_restore.GetType() + " hiddenSelectionsTextures", tone_texture_array);
	
										players_default_feet_restore.SetObjectTexture(0, tone_texture_array.Get(0));
										players_default_feet_restore.SetObjectMaterial(0, tone_mat_array.Get(0));
									}
								}
							}
						}
					}
			}
		}
			
		if (player)
			player.SetThermal(false);	
	
	}
	
	//this is the function that gets called when a player holds a weapon to check their optic state
	override void SwitchOptics(ItemOptics optic, bool state)
	{			
		static bool bot = true;
				
		PlayerBase player = PlayerBase.Cast(this);
			
		Thermal_Optic ItemThermal = Thermal_Optic.Cast(optic); // Checks if the scope is based from the JD_FLIR class
		
		if (state)
		{
			m_CameraOptics = true;
			
			if (optic.HasEnergyManager())
				optic.GetCompEM().SwitchOn();
			
			optic.HideSelection("hide");
			optic.EnterOptics();

			if (ItemThermal && player)
				player.SetThermal(true);

			CreateThermalTimer();
		}
		else
		{
			
			optic.ShowSelection("hide");
			optic.ExitOptics();
			
			if (optic.HasEnergyManager())
				optic.GetCompEM().SwitchOff();
			
			if (ItemThermal && player)
				RemoveThermalCode(player);
			
			m_CameraOptics = false;
		}
	}
}