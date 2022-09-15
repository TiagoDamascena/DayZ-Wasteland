modded class DayZPlayerImplementThrowing 
{
	override bool CanContinueThrowingEx(HumanInputController pHic, EntityAI pEntityInHands)
	{
		
		PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
		
		if (player.IsInSafezone())
		{
			return false;
		}
		
		return super.CanContinueThrowingEx(pHic, pEntityInHands);
	}
}