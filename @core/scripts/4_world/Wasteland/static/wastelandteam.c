class WastelandTeam
{
    static const int NUM_OF_TEAMS = 3;
	
	static const int TEAM_INDEPENDENT 	= 0;
	static const int TEAM_BLUFOR 		= 1;
	static const int TEAM_OPFOR 		= 2;

    static int GenerateTeam()
    {
        return Math.RandomInt(0, NUM_OF_TEAMS);
    }

    static string GetTeamName(int team)
    {
        switch (team)
        {
            case 1:
                return "Blufor";
            case 2:
                return "Opfor";
        }
		
		return "Independent";
    }
}