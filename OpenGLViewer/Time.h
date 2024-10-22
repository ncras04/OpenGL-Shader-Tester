#pragma once
#include <GLFW/glfw3.h>
struct Time
{
	static int Init();
	static float GetDeltaTime() { return m_deltaTime; };
	static float GetTime() { return m_totalTime; };

	static void Update();
	
private:
	static int m_fpsCount;
	static float m_totalTime;
	static float m_deltaTime;
	static double m_lastTimestamp;
};

