class WastelandPlayerData
{
    int team;
}

class WastelandPlayer : RestCallback
{
	static const string DIR_WASTELAND = "$profile:Wasteland/";
	static const string DIR_PLAYERS = DIR_WASTELAND + "Players/";
	
    private string m_Id;
    private int m_Team;

    void WastelandPlayer(string pId)
    {
        m_Id = pId;
        m_Team = 0;

        Init();
    }

    void Init()
    {
		if(!FileExist(DIR_WASTELAND))
			MakeDirectory(DIR_WASTELAND);
		
        if(!FileExist(DIR_PLAYERS))
			MakeDirectory(DIR_PLAYERS);

        if(FileExist(DIR_PLAYERS + m_Id + ".json")) {
            LoadData();
        } else {
            m_Team = WastelandTeam.GenerateTeam();

            SaveData();
        }
    }
	
	void LoadData()
	{
        WastelandPlayerData data = new WastelandPlayerData();
		JsonFileLoader<WastelandPlayerData>.JsonLoadFile(DIR_PLAYERS + m_Id + ".json", data);

        m_Team = data.team;
	}

	void SaveData()
	{
        WastelandPlayerData data = new WastelandPlayerData();
        data.team = m_Team;

		JsonFileLoader<WastelandPlayerData>.JsonSaveFile(DIR_PLAYERS + m_Id + ".json", data);
	}
	
	string GetPlayerId()
	{
		return m_Id;
	}

    int GetTeam()
    {
        return m_Team;
    }
}
