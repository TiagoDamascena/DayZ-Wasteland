class WastelandTraderManager
{
    private ref WastelandTraderConfig m_WastelandTraderConfig;

    void WastelandTraderManager()
    {
        Init();
    }

    void Init()
    {
        m_WastelandTraderConfig = new WastelandTraderConfig();
    }
	
	WastelandTraderRespawn GetRespawn(int team)
	{
        ref array<ref WastelandTraderRespawn> teamRespawns = new ref array<ref WastelandTraderRespawn>;

		ref array<ref WastelandTraderRespawn> respawns = m_WastelandTraderConfig.GetRespawns();
		for ( int i = 0; i < respawns.Count(); i++ )
        {
			ref WastelandTraderRespawn respawn = respawns.Get(i);
			if (respawn.GetTeam() == team) {
                teamRespawns.Insert(respawn);
			}
		}

        if (teamRespawns.Count()) {
            int index = Math.RandomInt(0, teamRespawns.Count());
            return teamRespawns.Get(index);
        }
		
		return null;
	}
}

ref WastelandTraderManager m_WastelandTraderManager;
WastelandTraderManager GetWastelandTrader()
{
    if (!m_WastelandTraderManager) {
        m_WastelandTraderManager = new WastelandTraderManager();
    }

    return m_WastelandTraderManager;
}
