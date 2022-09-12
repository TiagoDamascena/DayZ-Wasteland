modded class MissionGameplay
{
	ref WastelandTraderSafezoneUI m_WastelandTraderSafezoneUI;
	private bool m_WastelandInSafezone;
	private bool m_WastelandSafezoneTimer;
	
	void MissionGameplay()
	{
		m_WastelandTraderSafezoneUI = new WastelandTraderSafezoneUI();
		m_WastelandInSafezone = false;
		
		GetRPCManager().AddRPC( "WastelandTrader", "RPCUpdateSafezoneState", this, SingeplayerExecutionType.Both );
	}
	
	void RPCUpdateSafezoneState( CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target )
	{
		Param2< bool, int > data
		if ( !ctx.Read( data ) ) return;
		
		bool inSafezone = data.param1;
		int safezoneTimer = data.param2;

		if ( inSafezone != m_WastelandInSafezone) {
			m_WastelandInSafezone = inSafezone;
			GetGame().GetCallQueue( CALL_CATEGORY_GUI ).CallLaterByName(this, "UpdateSafezoneState", 0, false);
		}
		
		if ( safezoneTimer != m_WastelandSafezoneTimer ) {
			m_WastelandSafezoneTimer = safezoneTimer;
			GetGame().GetCallQueue( CALL_CATEGORY_GUI ).CallLaterByName(this, "UpdateSafezoneTimer", 0, false);
		}
	}
	
	void UpdateSafezoneState()
	{
		if ( !m_WastelandTraderSafezoneUI ) return;
		
		m_WastelandTraderSafezoneUI.UpdateInSafezone(m_WastelandInSafezone);
	}
	
	void UpdateSafezoneTimer()
	{
		if ( !m_WastelandTraderSafezoneUI ) return;
		
		m_WastelandTraderSafezoneUI.UpdateAlertTimer(m_WastelandSafezoneTimer);
	}
}
