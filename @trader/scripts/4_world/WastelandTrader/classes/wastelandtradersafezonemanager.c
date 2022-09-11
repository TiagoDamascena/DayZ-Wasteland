class WastelandTraderSafezoneManager
{
	const float TICK_INTERVAL_SEC = 1;
	
	PlayerBase m_Player;
	float m_Tick;
	
	void WastelandTraderSafezoneManager(PlayerBase player)
	{
		m_Player = player;
	}
	
	void OnScheduledTick(float delta_time)
	{
		m_Tick += delta_time;
		if( m_Tick > TICK_INTERVAL_SEC )
		{
			ref WastelandTraderSafezone safezone = GetWastelandTrader().CheckPlayerInSafezone(m_Player);
			if (safezone) {
				m_Player.SetIsInSafezone(true);
				//TODO Check team of safezone
				
				Print("Player is in a safezone");
			} else {
				m_Player.SetIsInSafezone(false);
			}		
			
			m_Tick = 0;
		}
	}
}
