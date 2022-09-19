modded class MissionServer extends MissionBase
{
	void MissionServer()
	{
		GetWasteland();
	}

	override void InvokeOnConnect(PlayerBase player, PlayerIdentity identity)
	{
		GetWasteland().OnPlayerConnect(player);
		
		super.InvokeOnConnect(player, identity);
	}
	
	override void InvokeOnDisconnect( PlayerBase player )
	{
		GetWasteland().OnPlayerDisconnect(player);
		
		super.InvokeOnDisconnect(player);
	}
}
