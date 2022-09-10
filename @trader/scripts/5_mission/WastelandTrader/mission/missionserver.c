modded class MissionServer extends MissionBase
{	
	void MissionServer()
	{
		GetWastelandTrader();
	}
	
	override PlayerBase OnClientNewEvent(PlayerIdentity identity, vector pos, ParamsReadContext ctx)
	{
		ref WastelandPlayer wastelandPlayer = GetWasteland().GetPlayer(identity.GetPlainId());
		int team = wastelandPlayer.GetTeam();
		
		ref WastelandTraderRespawn respawn = GetWastelandTrader().GetRespawn(team);
		if (respawn) {
			pos = respawn.GetPosition();
		}
		
		return super.OnClientNewEvent(identity, pos, ctx);
	}
}
