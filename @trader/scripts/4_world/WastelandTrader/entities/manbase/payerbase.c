modded class PlayerBase
{
	private bool m_WastelandIsInSafezone;
	private ref WastelandTraderSafezoneManager m_WastelandTraderSafezoneManager;
	
	override void Init()
	{
		m_WastelandIsInSafezone = false;
		RegisterNetSyncVariableBool("m_WastelandIsInSafezone");
		
		if( GetGame().IsServer() )
		{
			m_WastelandTraderSafezoneManager = new WastelandTraderSafezoneManager(this);
		}
		
		super.Init();
	}
	
	int IsInSafezone()
	{
		return m_WastelandIsInSafezone;
	}
	
	void SetIsInSafezone(bool isInSafezone)
	{
		if (isInSafezone != m_WastelandIsInSafezone)
		{
			m_WastelandIsInSafezone = isInSafezone;
			
			GetRPCManager().SendRPC("WastelandTrader", "RPCUpdateSafezoneState", new Param1< bool >( isInSafezone), true, GetIdentity());
			SetSynchDirty();
		}
	}
	
	override void OnScheduledTick(float deltaTime)
	{
		super.OnScheduledTick(deltaTime);
		
		if( !IsPlayerSelected() || !IsAlive() ) return;
		if( m_WastelandTraderSafezoneManager ) m_WastelandTraderSafezoneManager.OnScheduledTick(deltaTime);
	}
}
