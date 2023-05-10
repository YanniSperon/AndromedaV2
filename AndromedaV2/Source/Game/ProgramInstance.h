#pragma once

//#include "Utility/Pointers.h"
#include "Utility/Types.h"
#include "Rendering/Context.h"

namespace Andromeda {
	namespace Game {
		class ProgramInstance
		{
		protected:
			Array<Rendering::Context*> m_Contexts;

			Random32 m_Random32;
			Random64 m_Random64;
			double m_TimeConstant;

			//HashMap<UUID, PointerManager*> m_PointerManagers;

		public:
			ProgramInstance();
			~ProgramInstance();

			void Update(Duration deltaTime);

			void AddContext(Rendering::Context* context);

			Array<Rendering::Context*>& GetContexts();
			void RemoveContext(uint64 contextIndex, bool shouldDelete = true);

			Random32& GetRandom32();
			Random64& GetRandom64();

			double GetTimeConstant();
			void SetTimeConstant(double newConstant);

			//template <class T>
			//T* GetTypePointerManager()
			//{
			//	m_PointerManagers[]
			//}

		};
	}
}