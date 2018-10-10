void main()
{

	Hive ce = CreateHive();
	if ( ce )
		ce.InitOffline();

	Weather weather = g_Game.GetWeather();

	weather.GetOvercast().SetLimits( 0.0 , 1.0 );
	weather.GetRain().SetLimits( 0.0 , 1.0 );
	weather.GetFog().SetLimits( 0.0 , 0.25 );

	weather.GetOvercast().SetForecastChangeLimits( 0.0, 0.2 );
	weather.GetRain().SetForecastChangeLimits( 0.0, 0.1 );
	weather.GetFog().SetForecastChangeLimits( 0.15, 0.45 );

	weather.GetOvercast().SetForecastTimeLimits( 1800 , 1800 );
	weather.GetRain().SetForecastTimeLimits( 600 , 600 );
	weather.GetFog().SetForecastTimeLimits( 1800 , 1800 );

	weather.GetOvercast().Set( Math.RandomFloatInclusive(0.0, 0.3), 0, 0);
	weather.GetRain().Set( Math.RandomFloatInclusive(0.0, 0.2), 0, 0);
	weather.GetFog().Set( Math.RandomFloatInclusive(0.0, 0.1), 0, 0);
	
	weather.SetWindMaximumSpeed(15);
	weather.SetWindFunctionParams(0.1, 0.3, 50);
}

class CustomMission: MissionServer
{	
	ref AirDrop AirDropClass; // Class definition

void CustomMission()
{
	AirDropClass = new AirDrop;		
}

float TimerSlice; // Timeslice
override void OnUpdate( float timeslice )
{
	super.OnUpdate( timeslice );

	// FPS Fix
	TimerSlice += timeslice;
	if (TimerSlice >= AirDropClass.TimesliceMultiplyier)
	{
		AirDropClass.CreateAirDrop();
		TimerSlice = 0;	
	}
}

void SetRandomHealth(EntityAI itemEnt)
	{
		int rndHlt = Math.RandomInt(40,100);
		itemEnt.SetHealth("","",rndHlt);
	}

	override PlayerBase CreateCharacter(PlayerIdentity identity, vector pos, ParamsReadContext ctx, string characterName)
	{
		Entity playerEnt;
		playerEnt = GetGame().CreatePlayer(identity, characterName, pos, 0, "NONE");//Creates random player
		Class.CastTo(m_player, playerEnt);
		
		GetGame().SelectPlayer(identity, m_player);
		
		return m_player;
	}
	
	override void StartingEquipSetup(PlayerBase player, bool clothesChosen)
	{

//Zedmag Inventory Changes
		EntityAI itemEnt;
		ItemBase itemBs;

//Arrarys
		ref TStringArray topsArray = {"TShirt_Beige","TShirt_Black","TShirt_Blue","TShirt_Green","TShirt_Grey","TShirt_OrangeWhiteStripes","TShirt_Red","TShirt_RedBlackStripes","TShirt_White","Sweater_Blue","Sweater_Gray","Sweater_Green","Sweater_Red"};
		ref TStringArray pantsArray = {"Jeans_Black","Jeans_Blue","Jeans_BlueDark","Jeans_Brown","Jeans_Green","Jeans_Grey"};
		ref TStringArray shoesArray = {"AthleticShoes_Black","AthleticShoes_Blue","AthleticShoes_Brown","AthleticShoes_Green","AthleticShoes_Grey","Sneakers_Black","Sneakers_Gray","Sneakers_Green","Sneakers_Red","Sneakers_White","WorkingBoots_Beige","WorkingBoots_Brown","WorkingBoots_Green","WorkingBoots_Grey","WorkingBoots_Yellow"};
		ref TStringArray nadesArray = {"RGD5Grenade", "M67Grenade", "M18SmokeGrenade_Red", "M18SmokeGrenade_Green", "M18SmokeGrenade_Yellow", "M18SmokeGrenade_Purple", "M18SmokeGrenade_White", "RDG2SmokeGrenade_Black", "RDG2SmokeGrenade_White", "FlashGrenade"};
	
	player.RemoveAllItems();

		EntityAI item = player.GetInventory().CreateInInventory(topsArray.GetRandomElement());
		EntityAI item2 = player.GetInventory().CreateInInventory(pantsArray.GetRandomElement());
		EntityAI item3 = player.GetInventory().CreateInInventory(shoesArray.GetRandomElement());

		EntityAI gun3 = player.GetHumanInventory().CreateInHands("MakarovIJ70");
		gun3.GetInventory().CreateAttachment("PistolSuppressor");
		itemEnt = player.GetInventory().CreateInInventory("Mag_IJ70_8Rnd");
		itemBs = ItemBase.Cast(itemEnt);
		itemEnt = player.GetInventory().CreateInInventory("Mag_IJ70_8Rnd");
		itemBs = ItemBase.Cast(itemEnt);
		
		itemEnt = player.GetInventory().CreateInInventory("Rag");
		itemBs = ItemBase.Cast(itemEnt);
		itemBs.SetQuantity(4);
		SetRandomHealth(itemEnt);
		
		itemEnt = player.GetInventory().CreateInInventory("Ammo_380");
		itemBs = ItemBase.Cast(itemEnt);
		itemBs.SetQuantity(35);
		
		itemEnt = player.GetInventory().CreateInInventory("Pear");
		itemBs = ItemBase.Cast(itemEnt);	
	}
};
  
Mission CreateCustomMission(string path)
{
	return new CustomMission();
}