modded class PlayerBase
{
	protected ref WastelandPlayer m_WastelandPlayer;
	protected int m_WastelandTeam;
	
	override void Init()
	{
		m_WastelandTeam = 0;
		RegisterNetSyncVariableInt("m_WastelandTeam", 0, 2);
		
		super.Init();
	}
	
	override void OnPlayerLoaded()
	{
		super.OnPlayerLoaded();

		if ( GetGame().IsServer() && GetIdentity() )
		{
			m_WastelandPlayer = GetWasteland().GetPlayer(GetIdentity().GetPlainId());
			SetWastelandTeam(m_WastelandPlayer.GetTeam());
		}
	}
	
	int GetWastelandTeam()
	{
		return m_WastelandTeam;
	}
	
	void SetWastelandTeam( int wasteland_team )
	{
		m_WastelandTeam = wasteland_team;
		Print("[Wasteland] Team changed to " + WastelandTeam.GetTeamName(m_WastelandTeam));

		int slot_id = InventorySlots.GetSlotIdFromString("Armband");
		EntityAI armband = GetInventory().FindAttachment(slot_id);

		if (armband && (armband.GetType() == "Armband_Blue" || armband.GetType() == "Armband_Red")) {
			GetInventory().LocalDestroyEntity(armband);
		}

		if (m_WastelandTeam) {
			if (m_WastelandTeam == WastelandTeams.Blufor) {
				GetInventory().CreateAttachmentEx("Armband_Blue", slot_id);
			} else if (m_WastelandTeam == WastelandTeams.Opfor) {
				GetInventory().CreateAttachmentEx("Armband_Red", slot_id);
			}

			GetInventory().SetSlotLock(slot_id, true);
		} else {
			GetInventory().SetSlotLock(slot_id, false);
		}

		SetSynchDirty();
	}
}