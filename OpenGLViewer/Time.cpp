#include "Time.h"

double Time::m_deltaTime{};
double Time::m_totalTime{};
double Time::m_lastTimestamp{};
int Time::m_fpsCount{};

void Time::Update()
{
	double now{ glfwGetTime() };
	double diff = now - m_lastTimestamp;
	m_deltaTime = diff;
	m_totalTime += m_deltaTime;
	m_lastTimestamp = now;

	m_fpsCount++;
}
