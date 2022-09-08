class WastelandPlayer : RestCallback
{
	static const string DIR_WASTELAND = "$profile:Wasteland/";
	static const string DIR_PLAYERS = DIR_WASTELAND + "Players/";
	
    private string m_PlayerId;
    private int m_Team;

    void WastelandPlayer(string pId)
    {
        m_PlayerId = pId;

        Init();
    }

    void Init()
    {
		if(!FileExist(DIR_WASTELAND))
			MakeDirectory(DIR_WASTELAND);
		
        if(!FileExist(DIR_PLAYERS))
			MakeDirectory(DIR_PLAYERS);

        if(FileExist(DIR_PLAYERS + m_PlayerId + ".json")) {
            LoadData();
        } else {
            m_Team = Math.RandomInt(0, 3);

            SaveData();
        }
    }
	
	void LoadData()
	{
		JsonFileLoader<WastelandPlayer>.JsonLoadFile(DIR_PLAYERS + m_PlayerId + ".json", this);
	}
	
	void SaveData()
	{
		JsonFileLoader<WastelandPlayer>.JsonSaveFile(DIR_PLAYERS + m_PlayerId + ".json", this);
	}
	
	string GetPlayerId()
	{
		return m_PlayerId;
	}

    int GetTeam()
    {
        return m_Team;
    }
}
