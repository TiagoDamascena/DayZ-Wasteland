enum WastelandTeams
{
    Independent,
    Blufor,
    Opfor,
}

class WastelandTeam
{
    static const int NUM_OF_TEAMS = 3;

    static int GenerateTeam()
    {
        return Math.RandomInt(0, NUM_OF_TEAMS);
    }

    static string GetTeamName(int team)
    {
        switch (team)
        {
            case WastelandTeams.Blufor:
                return "Blufor";
            case WastelandTeams.Opfor:
                return "Opfor";
        }
		
		return "Independent";
    }
}