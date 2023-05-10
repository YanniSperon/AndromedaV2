#include "ProgramInstance.h"

namespace Andromeda
{
	namespace Game
	{
		ProgramInstance::ProgramInstance()
			: m_Contexts(), m_Random32(), m_Random64(), m_TimeConstant(1.0)//, m_PointerManagers()
		{

		}

		ProgramInstance::~ProgramInstance()
		{
			//for (auto it : m_PointerManagers)
			//{
			//	delete it.second;
			//}
			//m_PointerManagers.clear();
		}

		void ProgramInstance::Update(Duration deltaTime)
		{
			for (uint64 i = 0; i < m_Contexts.size(); ++i)
			{
				m_Contexts[i]->Update(deltaTime);
			}
		}

		void ProgramInstance::AddContext(Rendering::Context* context)
		{
			m_Contexts.push_back(context);
		}

		Array<Rendering::Context*>& ProgramInstance::GetContexts()
		{
			return m_Contexts;
		}

		void ProgramInstance::RemoveContext(uint64 contextIndex, bool shouldDelete)
		{
			if (contextIndex < m_Contexts.size())
			{
				if (shouldDelete)
				{
					delete m_Contexts[contextIndex];
				}
				m_Contexts.erase(m_Contexts.begin() + contextIndex);
			}
		}

		Random32& ProgramInstance::GetRandom32()
		{
			return m_Random32;
		}

		Random64& ProgramInstance::GetRandom64()
		{
			return m_Random64;
		}

		double ProgramInstance::GetTimeConstant()
		{
			return m_TimeConstant;
		}

		void ProgramInstance::SetTimeConstant(double newConstant)
		{
			m_TimeConstant = newConstant;
		}

	}
}