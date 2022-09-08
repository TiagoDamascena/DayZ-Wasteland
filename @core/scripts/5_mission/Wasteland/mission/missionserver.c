modded class MissionServer extends MissionBase
{
	override void InvokeOnConnect(PlayerBase player, PlayerIdentity identity)
	{
		WastelandManager.GetInstance().OnPlayerConnect(identity);
		
		super.InvokeOnConnect(player, identity);
	}
	
	override void InvokeOnDisconnect( PlayerBase player )
	{
		if ( player.GetIdentity() ){
			WastelandManager.GetInstance().OnPlayerDisconnect(player);
		}
		
		super.InvokeOnDisconnect(player);
	}
	
	override PlayerBase OnClientNewEvent(PlayerIdentity identity, vector pos, ParamsReadContext ctx)
	{
		WastelandPlayer wastelandPlayer = WastelandManager.GetInstance().GetPlayer(identity.GetPlainId());
		int team = wastelandPlayer.GetTeam();
		
		if (team == 1) {
			pos = "11482 0 11334";
		} else if (team == 2) {
			pos = "3699 0 5986";
		}
		
		return super.OnClientNewEvent(identity, pos, ctx);
	}
}
