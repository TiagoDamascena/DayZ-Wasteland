modded class MissionServer extends MissionBase
{
	override void InvokeOnConnect(PlayerBase player, PlayerIdentity identity)
	{
		GetWasteland().OnPlayerConnect(identity);
		
		super.InvokeOnConnect(player, identity);
	}
	
	override void InvokeOnDisconnect( PlayerBase player )
	{
		if ( player.GetIdentity() ) {
			GetWasteland().OnPlayerDisconnect(player);
		}
		
		super.InvokeOnDisconnect(player);
	}
}
