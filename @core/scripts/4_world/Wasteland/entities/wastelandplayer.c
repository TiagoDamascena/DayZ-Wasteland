class WastelandPlayer : RestCallback
{
	static const string DIR_WASTELAND = "$profile:Wasteland/";
	static const string DIR_PLAYERS = DIR_WASTELAND + "Players/";
	
    private string id;
    private int team;

    void WastelandPlayer(string pId)
    {
        id = pId;

        Init();
    }

    void Init()
    {
		if(!FileExist(DIR_WASTELAND))
			MakeDirectory(DIR_WASTELAND);
		
        if(!FileExist(DIR_PLAYERS))
			MakeDirectory(DIR_PLAYERS);

        if(FileExist(DIR_PLAYERS + id + ".json")) {
            LoadData();
        } else {
            team = WastelandTeam.GenerateTeam();

            SaveData();
        }
    }
	
	void LoadData()
	{
		JsonFileLoader<WastelandPlayer>.JsonLoadFile(DIR_PLAYERS + id + ".json", this);
	}
	
	void SaveData()
	{
		JsonFileLoader<WastelandPlayer>.JsonSaveFile(DIR_PLAYERS + id + ".json", this);
	}
	
	string GetPlayerId()
	{
		return id;
	}

    int GetTeam()
    {
        return team;
    }
}
