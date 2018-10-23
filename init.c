class CustomMission: MissionServer {
    override PlayerBase CreateCharacter(PlayerIdentity identity, vector pos, ParamsReadContext ctx, string characterName) {
        Entity playerEnt;
        playerEnt = GetGame().CreatePlayer(identity, characterName, pos, 0, "NONE");//Creates random player
        Class.CastTo(m_player, playerEnt);
        
        GetGame().SelectPlayer(identity, m_player);
        
        return m_player;
    }
    
    void CustomMission() {
    }

    override void StartingEquipSetup(PlayerBase player, bool clothesChosen) {
        EntityAI primary;
        EntityAI itemEnt;
        EntityAI gun;
        ItemBase itemBs;
        EntityAI optic_attach;
        
        switch(player.GetIdentity().GetPlainId()) {
            // Admin 1 Loadout
            case "XXXXXXXX":
                player.RemoveAllItems();
                
                addItem(itemEnt, itemBs, player, "TTsKOJacket_Camo", 1, 0, -1);
                addItem(itemEnt, itemBs, player, "TTSKOPants", 1, 0, -1);
                addItem(itemEnt, itemBs, player, "JungleBoots_Green", 1, 0, -1);
                addItem(itemEnt, itemBs, player, "BallisticHelmet_Green", 1, 0, -1);
                addItem(itemEnt, itemBs, player, "ThinFramesGlasses", 1, 0, -1);
                addItem(itemEnt, itemBs, player, "SmershVestBackpack", 1, 0, -1);
                addItem(itemEnt, itemBs, player, "Armband_Blue", 1, 0, -1);
                addItem(itemEnt, itemBs, player, "TacticalGloves_Green", 1, 0, -1);                
                addItem(itemEnt, itemBs, player, "TortillaBag", 1, 0, -1);
                
                addItem(itemEnt, itemBs, player, "Pear", 10, 0, -1);
                addItem(itemEnt, itemBs, player, "CombatKnife", 1, 0, -1);
                addItem(itemEnt, itemBs, player, "Rag", 3, 6, -1);
                addItem(itemEnt, itemBs, player, "Pot", 1, 2000, -1);
                addItem(itemEnt, itemBs, player, "BloodTestKit", 1, 0, -1);
                addItem(itemEnt, itemBs, player, "FirefighterAxe_Green", 1, 0, 0);
                
                addItem(itemEnt, itemBs, player, "Mag_AKM_Drum75Rnd_Green", 1, 1, 2);
                addItem(itemEnt, itemBs, player, "Mag_AKM_Drum75Rnd_Green", 1, 1, 3);
                addItem(itemEnt, itemBs, player, "Mag_AKM_Drum75Rnd_Green", 1, 1, 4);
                addItem(itemEnt, itemBs, player, "Mag_AKM_Drum75Rnd_Green", 1, 1, -1);
                addItem(itemEnt, itemBs, player, "Ammo_762x39", 1, 1, -1);
                addItem(itemEnt, itemBs, player, "KobraOptic", 1, 0, -1);
                addItem(itemEnt, itemBs, player, "Battery9V", 2, 0, -1);
                addItem(itemEnt, itemBs, player, "Matchbox", 1, 0, -1);
            
                primary = akmClass(player, itemBs, gun, itemEnt, optic_attach);
                itemBs = ItemBase.Cast(primary);
                player.SetQuickBarEntityShortcut(primary, 1, true);
                                
                break;
            // Admin 2 Loadout
            case "XXXXXXXX":
                player.RemoveAllItems();
                
                addItem(itemEnt, itemBs, player, "USMCJacket_Woodland", 1, 0, -1);
                addItem(itemEnt, itemBs, player, "USMCPants_Woodland", 1, 0, -1);
                addItem(itemEnt, itemBs, player, "JungleBoots_Green", 1, 0, -1);
                addItem(itemEnt, itemBs, player, "CowboyHat_green", 1, 0, -1);
                addItem(itemEnt, itemBs, player, "DesignerGlasses", 1, 0, -1);
                addItem(itemEnt, itemBs, player, "SmershVestBackpack", 1, 0, -1);
                addItem(itemEnt, itemBs, player, "Armband_Blue", 1, 0, -1);
                addItem(itemEnt, itemBs, player, "TacticalGloves_Green", 1, 0, -1);
                addItem(itemEnt, itemBs, player, "AssaultBag_Ttsko", 1, 0, -1);
                
                addItem(itemEnt, itemBs, player, "Pear", 10, 0, -1);
                addItem(itemEnt, itemBs, player, "CombatKnife", 1, 0, -1);
                addItem(itemEnt, itemBs, player, "Rag", 3, 6, -1);
                addItem(itemEnt, itemBs, player, "Pot", 1, 2000, -1);
                addItem(itemEnt, itemBs, player, "BloodTestKit", 1, 0, -1);
                addItem(itemEnt, itemBs, player, "FirefighterAxe_Green", 1, 0, 1);
                
                addItem(itemEnt, itemBs, player, "Mag_AKM_30Rnd", 1, 1, 2);
                addItem(itemEnt, itemBs, player, "Mag_AKM_30Rnd", 1, 1, 3);
                addItem(itemEnt, itemBs, player, "Mag_AKM_30Rnd", 1, 1, 4);
                addItem(itemEnt, itemBs, player, "Mag_AKM_30Rnd", 1, 1, 5);
                addItem(itemEnt, itemBs, player, "Mag_AKM_30Rnd", 1, 1, 6);
                addItem(itemEnt, itemBs, player, "Mag_AKM_30Rnd", 1, 1, 7);
                addItem(itemEnt, itemBs, player, "Mag_AKM_30Rnd", 1, 1, -1);
                addItem(itemEnt, itemBs, player, "Ammo_762x39", 1, 1, -1);
                addItem(itemEnt, itemBs, player, "KobraOptic", 1, 0, -1);
                addItem(itemEnt, itemBs, player, "Battery9V", 1, 0, -1);
                addItem(itemEnt, itemBs, player, "Matchbox", 1, 0, -1);
            
                primary = akmClass(player, itemBs, gun, itemEnt, optic_attach);
                itemBs = ItemBase.Cast(primary);
                player.SetQuickBarEntityShortcut(primary, 0, true);
                
                break;
            // Admin 3 Loadout
            case "XXXXXXXX":
                player.RemoveAllItems();
                
                addItem(itemEnt, itemBs, player, "M65Jacket_Black", 1, 0, -1);
                addItem(itemEnt, itemBs, player, "CargoPants_Black", 1, 0, -1);
                addItem(itemEnt, itemBs, player, "JungleBoots_Black", 1, 0, -1);
                addItem(itemEnt, itemBs, player, "BallisticHelmet_Black", 1, 0, -1);
                addItem(itemEnt, itemBs, player, "DesignerGlasses", 1, 0, -1);
                addItem(itemEnt, itemBs, player, "Armband_Blue", 1, 0, -1);
                addItem(itemEnt, itemBs, player, "HighCapacityVest_Black", 1, 0, -1);
                addItem(itemEnt, itemBs, player, "TacticalGloves_Black", 1, 0, -1);
                addItem(itemEnt, itemBs, player, "AliceBag_Black", 1, 0, -1);
                
                addItem(itemEnt, itemBs, player, "Pear", 10, 0, -1);
                addItem(itemEnt, itemBs, player, "CombatKnife", 1, 0, -1);
                addItem(itemEnt, itemBs, player, "Rag", 3, 6, -1);
                addItem(itemEnt, itemBs, player, "Pot", 1, 2000, -1);
                addItem(itemEnt, itemBs, player, "BloodTestKit", 1, 0, -1);
                addItem(itemEnt, itemBs, player, "FirefighterAxe", 1, 0, 1);
                
                addItem(itemEnt, itemBs, player, "Mag_AKM_Drum75Rnd_Black", 1, 1, 2);
                addItem(itemEnt, itemBs, player, "Mag_AKM_Drum75Rnd_Black", 1, 1, 3);
                addItem(itemEnt, itemBs, player, "Mag_AKM_Drum75Rnd_Black", 1, 1, 4);
                addItem(itemEnt, itemBs, player, "Ammo_762x39", 1, 1, -1);
                addItem(itemEnt, itemBs, player, "KobraOptic", 1, 0, -1);
                addItem(itemEnt, itemBs, player, "Battery9V", 1, 0, -1);
                addItem(itemEnt, itemBs, player, "Matchbox", 1, 0, -1);
            
                primary = akmClass(player, itemBs, gun, itemEnt, optic_attach);
                itemBs = ItemBase.Cast(primary);
                player.SetQuickBarEntityShortcut(primary, 0, true);
                
                break;
            // Admin 4 Loadout
            case "XXXXXXXX":
                addItem(itemEnt, itemBs, player, "SmershBag", 1, 0, -1);
                addItem(itemEnt, itemBs, player, "Pear", 2, 0, -1);
                addItem(itemEnt, itemBs, player, "StoneKnife", 1, 0, 1);
                addItem(itemEnt, itemBs, player, "Rag", 1, 6, 2);
                addItem(itemEnt, itemBs, player, "WoodAxe", 1, 0, 0);
                addItem(itemEnt, itemBs, player, "Armband_Blue", 1, 0, 0);
                
                break;
            // Admin 5 Loadout
            case "XXXXXXXX":
                player.RemoveAllItems();
                addItem(itemEnt, itemBs, player, "TacticalShirt_Black", 1, 0, -1);
                addItem(itemEnt, itemBs, player, "CargoPants_Green", 1, 0, -1);
                addItem(itemEnt, itemBs, player, "CombatBoots_Black", 1, 0, -1);
                addItem(itemEnt, itemBs, player, "BaseballCap_CMMG_Black", 1, 0, -1);
                addItem(itemEnt, itemBs, player, "DesignerGlasses", 1, 0, -1);
                addItem(itemEnt, itemBs, player, "Armband_Blue", 1, 0, -1);
                addItem(itemEnt, itemBs, player, "SmershVestBackpack", 1, 0, -1);
                addItem(itemEnt, itemBs, player, "HuntingBag", 1, 0, -1);
                addItem(itemEnt, itemBs, player, "TacticalGloves_Black", 1, 0, -1);
                
                addItem(itemEnt, itemBs, player, "Pear", 10, 0, -1);
                addItem(itemEnt, itemBs, player, "CombatKnife", 1, 0, -1);
                addItem(itemEnt, itemBs, player, "Rag", 1, 6, -1);
                addItem(itemEnt, itemBs, player, "FirefighterAxe_Green", 1, 0, 0);
                addItem(itemEnt, itemBs, player, "Armband_Blue", 1, 0, -1);
                addItem(itemEnt, itemBs, player, "Compass", 1, 0, -1);
                addItem(itemEnt, itemBs, player, "OrienteeringCompass", 1, 0, -1);
                
                addItem(itemEnt, itemBs, player, "Mag_UMP_25Rnd", 1, 1, 2);
                addItem(itemEnt, itemBs, player, "Mag_UMP_25Rnd", 1, 1, 3);
                addItem(itemEnt, itemBs, player, "Mag_UMP_25Rnd", 1, 1, 4);
                addItem(itemEnt, itemBs, player, "Mag_UMP_25Rnd", 1, 1, 5);
                addItem(itemEnt, itemBs, player, "Mag_UMP_25Rnd", 1, 1, 6);
            
                primary = usgClass(player, itemBs, gun, itemEnt, optic_attach);
                itemBs = ItemBase.Cast(primary);
                player.SetQuickBarEntityShortcut(primary, 1, true);
                
                break;
            // Admin 6 Loadout
            case "XXXXXXXX":
                player.RemoveAllItems();
                addItem(itemEnt, itemBs, player, "NBCJacketGray", 1, 0, -1);
                addItem(itemEnt, itemBs, player, "NBCPantsGray", 1, 0, -1);
                addItem(itemEnt, itemBs, player, "NBCBootsGray", 1, 0, -1);
                addItem(itemEnt, itemBs, player, "NBCHoodGray", 1, 0, -1);
                addItem(itemEnt, itemBs, player, "NioshFaceMask", 1, 0, -1);
                addItem(itemEnt, itemBs, player, "Armband_Blue", 1, 0, -1);
                addItem(itemEnt, itemBs, player, "SmershVestBackpack", 1, 0, -1);
                addItem(itemEnt, itemBs, player, "TortillaBag", 1, 0, -1);
                addItem(itemEnt, itemBs, player, "NBCGlovesGray", 1, 0, -1);
                
                addItem(itemEnt, itemBs, player, "Pear", 10, 0, -1);
                addItem(itemEnt, itemBs, player, "CombatKnife", 1, 0, -1);
                addItem(itemEnt, itemBs, player, "Rag", 1, 6, -1);
                addItem(itemEnt, itemBs, player, "FirefighterAxe_Green", 1, 0, 0);
                addItem(itemEnt, itemBs, player, "Armband_Blue", 1, 0, -1);
                addItem(itemEnt, itemBs, player, "Compass", 1, 0, -1);
                addItem(itemEnt, itemBs, player, "OrienteeringCompass", 1, 0, -1);
                
                addItem(itemEnt, itemBs, player, "Mag_UMP_25Rnd", 1, 1, 2);
                addItem(itemEnt, itemBs, player, "Mag_UMP_25Rnd", 1, 1, 3);
                addItem(itemEnt, itemBs, player, "Mag_UMP_25Rnd", 1, 1, 4);
                addItem(itemEnt, itemBs, player, "Mag_FNX45_15Rnd", 1, 1, 5);
                addItem(itemEnt, itemBs, player, "Mag_FNX45_15Rnd", 1, 1, 6);
             // Add fnxClass into inv 
                primary = usgClass(player, itemBs, gun, itemEnt, optic_attach);
                itemBs = ItemBase.Cast(primary);
                player.SetQuickBarEntityShortcut(primary, 1, true);
                
                break;
            // Default Player Loadout
            default:
            //Arrarys
				ref TStringArray topsArray = {"TShirt_Beige","TShirt_Black","TShirt_Blue","TShirt_Green","TShirt_Grey","TShirt_OrangeWhiteStripes","TShirt_Red","TShirt_RedBlackStripes","TShirt_White"};
				ref TStringArray pantsArray = {"Jeans_Black","Jeans_Blue","Jeans_BlueDark","Jeans_Brown","Jeans_Green","Jeans_Grey"};
				ref TStringArray shoesArray = {"AthleticShoes_Black","AthleticShoes_Blue","AthleticShoes_Brown","AthleticShoes_Green","AthleticShoes_Grey","Sneakers_Black","Sneakers_Gray","Sneakers_Green","Sneakers_Red","Sneakers_White","WorkingBoots_Beige","WorkingBoots_Brown","WorkingBoots_Green","WorkingBoots_Grey","WorkingBoots_Yellow"};
				ref TStringArray drinksArray = {"SodaCan_Spite","SodaCan_Pipsi","SodaCan_Kvass","SodaCan_Cola"};
				ref TStringArray nadesArray = {"RGD5Grenade", "M67Grenade", "M18SmokeGrenade_Red", "M18SmokeGrenade_Green", "M18SmokeGrenade_Yellow", "M18SmokeGrenade_Purple", "M18SmokeGrenade_White", "RDG2SmokeGrenade_Black", "RDG2SmokeGrenade_White", "FlashGrenade"};
				player.RemoveAllItems();

				EntityAI item = player.GetInventory().CreateInInventory(topsArray.GetRandomElement());
				EntityAI item2 = player.GetInventory().CreateInInventory(pantsArray.GetRandomElement());
				EntityAI item3 = player.GetInventory().CreateInInventory(shoesArray.GetRandomElement());
				EntityAI item4 = player.GetInventory().CreateInInventory(drinksArray.GetRandomElement());
		
			// Radio 
				EntityAI radio1 = player.GetHumanInventory().CreateInHands("PersonalRadio");
				radio1.GetInventory().CreateAttachment("Battery9V");
				if (radio1.HasEnergyManager() && radio1.GetCompEM().CanSwitchOn()) {
				radio1.GetCompEM().SwitchOn();
			
                addItem(itemEnt, itemBs, player, "Rag", 1, 6, 2);
                addItem(itemEnt, itemBs, player, "Compass", 1, 0, 3);

                break;
        }
    }

    void addItem(EntityAI itemEnt, ItemBase itemBs, PlayerBase player, string item_name, int count, int stackSize, int invSlot) {
        for (int i = 0; i < count; i++) {
            itemEnt = player.GetInventory().CreateInInventory(item_name);
            itemBs = ItemBase.Cast(itemEnt);
            if (stackSize > 0) {
                itemBs.SetQuantity(stackSize);
            }
            if (invSlot >= 0 || invSlot <= 9) {
                player.SetQuickBarEntityShortcut(itemEnt, invSlot, true);
            }
        }
    }

    EntityAI akmClass(PlayerBase player, ItemBase itemBs, EntityAI gun, EntityAI itemEnt, EntityAI optic_attach) {
        gun = player.GetHumanInventory().CreateInHands("AKM");
        gun.GetInventory().CreateAttachment("AK_WoodHndgrd");
        gun.GetInventory().CreateAttachment("AK_Woodbttstck");
        gun.GetInventory().CreateAttachment("AK_Suppressor");
        optic_attach = gun.GetInventory().CreateAttachment("PSO1Optic");
        optic_attach.GetInventory().CreateAttachment("Battery9V");
        itemBs = ItemBase.Cast(gun);
        
        return gun;
    }
    
    EntityAI m4a1Class(PlayerBase player, ItemBase itemBs, EntityAI gun, EntityAI itemEnt, EntityAI optic_attach) {
        gun = player.GetHumanInventory().CreateInHands("M4A1_Green");
        gun.GetInventory().CreateAttachment("M4_PlasticHndgrd");
        gun.GetInventory().CreateAttachment("M4_OEBttstck");
        gun.GetInventory().CreateAttachment("M4_Suppressor");
        optic_attach = gun.GetInventory().CreateAttachment("ACOGOptic");
        itemBs = ItemBase.Cast(gun);
        
        return gun;
    }
    
    EntityAI usgClass(PlayerBase player, ItemBase itemBs, EntityAI gun, EntityAI itemEnt, EntityAI optic_attach) {
        gun = player.GetHumanInventory().CreateInHands("UMP45");
        gun.GetInventory().CreateAttachment("PistolSuppressor");
        optic_attach = gun.GetInventory().CreateAttachment("M68Optic");
        optic_attach.GetInventory().CreateAttachment("Battery9V");
        itemBs = ItemBase.Cast(gun);
        
        return gun;
    }

    EntityAI fnxClass(PlayerBase player, ItemBase itemBs, EntityAI gun, EntityAI itemEnt, EntityAI optic_attach) {
        gun = player.GetHumanInventory().CreateInInventory("FNX45");
        gun.GetInventory().CreateAttachment("PistolSuppressor");
        itemBs = ItemBase.Cast(gun);
        
        return gun;
    }

    EntityAI radioClass(PlayerBase player, ItemBase itemBs, EntityAI radio1, EntityAI itemEnt, EntityAI optic_attach) {
		radio1 = player.GetHumanInventory().CreateInHands("PersonalRadio");
		radio1.GetInventory().CreateAttachment("Battery9V");
		if (radio1.HasEnergyManager() && radio1.GetCompEM().CanSwitchOn()) {
		radio1.GetCompEM().SwitchOn();

        return radio1;
    }
    
	EntityAI radio2Class(PlayerBase player, ItemBase itemBs, EntityAI radio2, EntityAI itemEnt, EntityAI optic_attach) {
		radio2 = player.GetHumanInventory().CreateInInventory("PersonalRadio");
		radio2.GetInventory().CreateAttachment("Battery9V");
		if (radio2.HasEnergyManager() && radio2.GetCompEM().CanSwitchOn()) {
		radio2.GetCompEM().SwitchOn();

        return radio2;
    }
}

void main() {

    Hive ce = CreateHive();
    if ( ce )
        ce.InitOffline();

    Weather weather = g_Game.GetWeather();

    weather.GetOvercast().SetLimits(0, 0);
    weather.GetRain().SetLimits(0, 0);
    weather.GetFog().SetLimits(0, 0);

    weather.GetOvercast().SetForecastChangeLimits(0, 0);
    weather.GetRain().SetForecastChangeLimits(0, 0);
    weather.GetFog().SetForecastChangeLimits(0, 0);

    weather.GetOvercast().SetForecastTimeLimits(0, 0);
    weather.GetRain().SetForecastTimeLimits(0, 0);
    weather.GetFog().SetForecastTimeLimits(0, 0);

    weather.GetOvercast().Set(0, 0, 0);
    weather.GetRain().Set(0, 0, 0);
    weather.GetFog().Set(0, 0, 0);
    
    weather.SetWindMaximumSpeed(15);
    weather.SetWindFunctionParams(0.1, 0.3, 50);
}
  
Mission CreateCustomMission(string path) {
    return new CustomMission();
}