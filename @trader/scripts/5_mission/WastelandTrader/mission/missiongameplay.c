modded class MissionGameplay
{
	private ref WastelandTraderSafezoneUI m_WT_SafezoneUI;
	private bool m_WT_InSafezone;
	private bool m_WT_ShowAlert;
	private int m_WT_AlertTime;
	
	void MissionGameplay()
	{
		m_WT_SafezoneUI = new WastelandTraderSafezoneUI();
		m_WT_InSafezone = false;
		m_WT_ShowAlert = false;
		m_WT_AlertTime = 0;
		
		GetRPCManager().AddRPC("WastelandTrader", "RPCUpdateSafezoneState", this, SingeplayerExecutionType.Both);
	}
	
	void RPCUpdateSafezoneState(CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target)
	{
		Param3< bool, bool, int > data;
		if ( !ctx.Read( data ) ) return;
		
		bool inSafezone = data.param1;
		bool showAlert = data.param2;
		int alertTime = data.param3;

		if (inSafezone != m_WT_InSafezone) {
			m_WT_InSafezone = inSafezone;
			GetGame().GetCallQueue( CALL_CATEGORY_GUI ).CallByName(this, "WT_UpdateInSafezone");
		}
		
		if (showAlert != m_WT_ShowAlert) {
			m_WT_ShowAlert = showAlert;
			GetGame().GetCallQueue( CALL_CATEGORY_GUI ).CallByName(this, "WT_UpdateShowAlert");
		}
		
		if (alertTime != m_WT_AlertTime) {
			m_WT_AlertTime = alertTime;
			GetGame().GetCallQueue( CALL_CATEGORY_GUI ).CallByName(this, "WT_UpdateAlertTime");
		}
	}
	
	void WT_UpdateInSafezone()
	{
		if ( !m_WT_SafezoneUI ) return;
		
		m_WT_SafezoneUI.UpdateInSafezone(m_WT_InSafezone);
	}
	
	void WT_UpdateShowAlert()
	{
		if ( !m_WT_SafezoneUI ) return;
		
		m_WT_SafezoneUI.UpdateShowAlert(m_WT_ShowAlert);
	}
	
	void WT_UpdateAlertTime()
	{
		if ( !m_WT_SafezoneUI ) return;
		
		m_WT_SafezoneUI.UpdateAlertTime(m_WT_AlertTime);
	}
}
