class WastelandTraderSafezoneUI
{
	private Widget m_WidgetRoot;
	private Widget m_Icon;
	
	void WastelandTraderSafezoneUI()
	{
		Init();
	}
	
	void Init()
	{
		m_WidgetRoot = GetGame().GetWorkspace().CreateWidgets("WastelandTrader/gui/layouts/safezone_gui.layout");
		m_Icon = m_WidgetRoot.FindAnyWidget("InSafezoneIcon");
		m_Icon.Show(false);
	}
	
	void UpdateInSafezone(bool inSafezone)
	{
		m_Icon.Show(inSafezone);
	}
}
