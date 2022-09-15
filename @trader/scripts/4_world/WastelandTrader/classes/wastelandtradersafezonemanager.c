class WastelandTraderSafezoneManager
{
	const float TICK_INTERVAL_SEC = 0.5;
	const float RESTRICTED_AREA_SEC = 30;
	
	private PlayerBase m_Player;
	
	private float m_Tick;
	private float m_RestrictedAreaTick;
	
	private bool m_IsInSafezone;
	private int m_AlertTime;
	
	void WastelandTraderSafezoneManager(PlayerBase player)
	{
		m_Player = player;
		
		m_IsInSafezone = false;
		m_AlertTime = 0;
	}
	
	void OnScheduledTick(float delta_time)
	{
		m_Tick += delta_time;
		if (m_Tick >= TICK_INTERVAL_SEC) {
			ref WastelandTraderSafezone safezone = GetWastelandTrader().CheckPlayerInSafezone(m_Player);
			if (safezone) {				
				if (safezone.GetTeam() != m_Player.GetWastelandTeam()) {
					m_RestrictedAreaTick += m_Tick;
				} else {
					m_RestrictedAreaTick = 0;
				}
				
				Print("Player is in a safezone");
			} else {
				m_RestrictedAreaTick = 0;
			}
			
			if (m_RestrictedAreaTick >= RESTRICTED_AREA_SEC) {
				m_Player.SetHealth( "GlobalHealth", "Health", 0 );
				Print("Player is now dead");
			}
			
			Updated(!!safezone);
			m_Tick = 0;
		}
	}
	
	void Updated(bool isInSafezone)
	{
		int alertTime = 0;
		if (m_RestrictedAreaTick > 0) {
			alertTime = (int)(RESTRICTED_AREA_SEC - m_RestrictedAreaTick);
		}
		
		if (isInSafezone != m_IsInSafezone || alertTime != m_AlertTime) {
			m_IsInSafezone = isInSafezone;
			m_AlertTime = alertTime;
			
			m_Player.SetIsInSafezone(isInSafezone);
			GetRPCManager().SendRPC("WastelandTrader", "RPCUpdateSafezoneState", new Param2< bool, int >( m_IsInSafezone, m_AlertTime ), true, m_Player.GetIdentity());
		}
	}
}
