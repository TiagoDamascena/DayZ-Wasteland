class WastelandManager
{
    private ref array< ref WastelandPlayer > m_WastelandPlayers = new ref array< ref WastelandPlayer >;

    void WastelandManager()
    {
        Init();
    }

    void Init()
    {
        //GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLaterByName(instance, "SaveWastelandPlayers", 300 * 1000, true);
    }

	void OnPlayerConnect(PlayerIdentity playerIdent)
	{
		GetPlayer(playerIdent.GetPlainId());
	}
	
	void OnPlayerDisconnect(PlayerBase player)
	{
		if ( player.GetIdentity() ) {
			GetPlayer(player.GetIdentity().GetPlainId()).SaveData();
			UnloadPlayer(player.GetIdentity().GetPlainId());
		}
	}

    private WastelandPlayer LoadPlayer( string pId )
    {
        ref WastelandPlayer wastelandPlayer = new WastelandPlayer(pId);
        m_WastelandPlayers.Insert(wastelandPlayer);

        return wastelandPlayer;
    }
	
	private WastelandPlayer UnloadPlayer( string pId )
	{
		for ( int i = 0; i < m_WastelandPlayers.Count(); i++ )
        {
            ref WastelandPlayer wastelandPlayer = m_WastelandPlayers.Get(i);
            if ( wastelandPlayer.GetPlayerId() == pId )
            {
                m_WastelandPlayers.Remove(i);
				return wastelandPlayer;
            }
        }
		
		return null;
	}

    WastelandPlayer GetPlayer( string pId )
    {
        for ( int i = 0; i < m_WastelandPlayers.Count(); i++ )
        {
            ref WastelandPlayer wastelandPlayer = m_WastelandPlayers.Get(i);
            if ( wastelandPlayer.GetPlayerId() == pId )
            {
                return wastelandPlayer;
            }
        }

        return LoadPlayer(pId);
    }
}

ref WastelandManager m_WastelandManager;
WastelandManager GetWasteland()
{
    if (!m_WastelandManager) {
        m_WastelandManager = new WastelandManager();
    }

    return m_WastelandManager;
}
