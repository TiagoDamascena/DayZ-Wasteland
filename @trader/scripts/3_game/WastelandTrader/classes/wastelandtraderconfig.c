class WastelandTraderConfig
{
    static const string DIR_WASTELAND = "$profile:Wasteland/";
	static const string DIR_TRADER = DIR_WASTELAND + "Trader/";

	private ref array<ref WastelandTraderRespawn> m_Respawns = new ref array< ref WastelandTraderRespawn >;

    void WastelandTraderConfig()
    {
        Init();
    }

    void Init()
    {
        if (!FileExist(DIR_WASTELAND))
			MakeDirectory(DIR_WASTELAND);
		
        if (!FileExist(DIR_TRADER))
			MakeDirectory(DIR_TRADER);
		
		if (FileExist(DIR_TRADER + "respawns.json")) {
            LoadRespaws();
        }
    }

	void LoadRespaws()
    {
        JsonFileLoader<ref array<ref WastelandTraderRespawn>>.JsonLoadFile(DIR_TRADER + "respawns.json", m_Respawns);
    }
	
	array<ref WastelandTraderRespawn> GetRespawns()
	{
		return m_Respawns;
	}
}