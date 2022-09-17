class WastelandTraderSafezoneUI
{
	private Widget m_WidgetRoot;
	
	private Widget m_InSafezoneIcon;
	
	private Widget m_AlertWindow;
	private TextWidget m_CounterText;
	
	void WastelandTraderSafezoneUI()
	{
		Init();
	}
	
	void Init()
	{
		m_WidgetRoot = GetGame().GetWorkspace().CreateWidgets("WastelandTrader/gui/layouts/safezone_gui.layout");
		
		m_InSafezoneIcon = m_WidgetRoot.FindAnyWidget("InSafezoneIcon");
		m_InSafezoneIcon.Show(false);
		
		m_AlertWindow = m_WidgetRoot.FindAnyWidget("AlertWindow");
		m_AlertWindow.Show(false);
		
		m_CounterText = TextWidget.Cast(m_AlertWindow.FindAnyWidget("CounterText"));
		m_CounterText.SetText("0");
	}
	
	void UpdateInSafezone(bool inSafezone)
	{
		m_InSafezoneIcon.Show(inSafezone);
	}
	
	void UpdateShowAlert(bool showAlert)
	{
		m_AlertWindow.Show(showAlert);
	}
	
	void UpdateAlertTime(int seconds)
	{
		m_CounterText.SetText(seconds.ToString());
	}
}
