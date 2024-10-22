#include "Time.h"

float Time::m_deltaTime{};
float Time::m_totalTime{};
int Time::m_fpsCount{};
double Time::m_lastTimestamp{};

int Time::Init()
{
	Time::m_lastTimestamp = glfwGetTime();
	return 0;
}

void Time::Update()
{
	double now{ glfwGetTime() };
	double diff = now - m_lastTimestamp;
	m_deltaTime = diff;
	m_totalTime += m_deltaTime;
	m_lastTimestamp = now;

	m_fpsCount++;
}
