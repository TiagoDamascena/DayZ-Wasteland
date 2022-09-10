class WastelandTraderRespawn
{
	private int team;
    private string position;
   
	int GetTeam()
    {
        return team;
    }

    vector GetPosition()
    {
        return position.ToVector();
    }
}