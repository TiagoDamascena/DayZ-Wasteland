modded class MissionGameplay
{
	ref WastelandTraderSafezoneUI m_WastelandTraderSafezoneUI;
	private bool m_WastelandInSafezone;
	
	void MissionGameplay()
	{
		m_WastelandTraderSafezoneUI = new WastelandTraderSafezoneUI();
		m_WastelandInSafezone = false;
		
		GetRPCManager().AddRPC( "WastelandTrader", "RPCUpdateSafezoneState", this, SingeplayerExecutionType.Both );
	}
	
	void RPCUpdateSafezoneState( CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target )
	{
		Param1< bool > data
		if ( !ctx.Read( data ) ) return;
		
		bool inSafezone = data.param1;

		if ( inSafezone != m_WastelandInSafezone)
		{
			m_WastelandInSafezone = inSafezone;
			GetGame().GetCallQueue( CALL_CATEGORY_GUI ).CallLaterByName(this, "UpdateSafezoneState", 500, false);
		}
	}
	
	void UpdateSafezoneState()
	{
		if ( !m_WastelandTraderSafezoneUI ) return;
		
		m_WastelandTraderSafezoneUI.UpdateInSafezone(m_WastelandInSafezone);
	}
}
