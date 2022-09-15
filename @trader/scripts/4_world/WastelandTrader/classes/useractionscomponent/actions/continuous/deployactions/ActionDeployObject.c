modded class ActionDeployObject: ActionDeployObject
{		
	override void OnStartServer( ActionData action_data )
	{
		PlayerBase player = action_data.m_Player;

		if (!player.IsInSafezone()) {
			super.OnStartServer(action_data);
		}
	}
}