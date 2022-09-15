modded class WeaponManager
{
	override bool CanFire(Weapon_Base wpn)
	{
		if( m_player.IsInSafezone()) {
			return true;
		}
		
		return super.CanFire(wpn);
	}
}