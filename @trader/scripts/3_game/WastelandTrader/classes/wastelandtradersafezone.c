class WastelandTraderSafezone
{
    private int team;
    private string position;
    private int radius;

    int GetTeam()
    {
        return team;
    }

    vector GetPosition()
    {
        return position.ToVector();
    }

    int GetRadius()
    {
        return radius;
    }
}