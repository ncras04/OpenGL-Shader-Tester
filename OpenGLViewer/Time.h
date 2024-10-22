#pragma once
#include <GLFW/glfw3.h>
struct Time
{
	static float GetDeltaTime() { return (float)m_deltaTime; };
	static float GetTime() { return (float)m_totalTime; };

	static void Update();
	
private:
	static int m_fpsCount;
	static double m_totalTime;
	static double m_deltaTime;
	static double m_lastTimestamp;
};

