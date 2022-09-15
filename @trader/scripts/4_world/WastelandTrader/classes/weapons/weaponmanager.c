modded class WeaponManager
{
	override bool CanFire(Weapon_Base wpn)
	{
		if ( m_player.IsInSafezone() )
		{
			return false;
		}
		
		return super.CanFire(wpn);
	}
}
