//#pragma once
//
//#include "StandardCollectionsDefinitions.h"
//#include "StandardDefinitions.h"
//#include "LedgeredList.h"
//#include "UUID.h"
//
//namespace Andromeda
//{
//	template <class T>
//	class PointerTypeManager;
//	template <class T>
//	class Pointer;
//	template <class T>
//	class ThreadSafeSharedPointer;
//	template <class T>
//	class SharedPointer;
//	template <class T>
//	class UniquePointer;
//	template <class T>
//	class WeakPointer;
//
//	class PointerManager
//	{
//	public:
//		virtual ~PointerManager();
//
//	};
//
//	enum DeletionMapPointerType : uint64
//	{
//		Unique = 0,
//		Shared = 1,
//		ThreadSafeShared = 2
//	};
//	template <class T>
//	class PointerTypeManager : public PointerManager {
//	private:
//		HashMap<T*, uint64> m_UniqueMap;
//		HashMap<T*, uint64> m_SharedMap;
//		HashMap<T*, uint64> m_ThreadSafeSharedMap;
//		HashMap<T*, Mutex> m_ThreadSafeSharedMutex;
//
//		HashMap<T*, DeletionMapPointerType> m_DeletionMap;
//
//	public:
//		PointerTypeManager()
//			: m_UniqueMap(), m_SharedMap(), m_ThreadSafeSharedMap(), m_ThreadSafeSharedMutex()
//		{
//		}
//		virtual ~PointerTypeManager() override
//		{
//			for (auto it : m_UniqueMap)
//			{
//				delete it.first;
//			}
//			for (auto it : m_SharedMap)
//			{
//				delete it.first;
//			}
//			for (auto it : m_ThreadSafeSharedMap)
//			{
//				delete it.first;
//			}
//			for (auto it : m_DeletionMap)
//			{
//				delete it.first;
//			}
//		}
//
//		void FlagDelete(const UniquePointer<T>& pointer)
//		{
//			m_UniqueMap[pointer.m_Pointer]--;
//
//			if (m_UniqueMap[pointer.m_Pointer] == 0ull)
//			{
//				m_DeletionMap[pointer.m_Pointer] = DeletionMapPointerType::Unique;
//				m_UniqueMap.erase(pointer.m_Pointer);
//			}
//		}
//		void FlagDelete(const SharedPointer<T>& pointer)
//		{
//			m_SharedMap[pointer->m_Pointer]--;
//
//			if (m_SharedMap[pointer.m_Pointer] == 0ull)
//			{
//				m_DeletionMap[pointer.m_Pointer] = DeletionMapPointerType::Shared;
//				m_SharedMap.erase(pointer.m_Pointer);
//			}
//		}
//		void FlagDelete(const ThreadSafeSharedPointer<T>& pointer)
//		{
//			m_ThreadSafeSharedMap[pointer->m_Pointer]--;
//
//			if (m_ThreadSafeSharedMap[pointer.m_Pointer] == 0ull)
//			{
//				m_DeletionMap[pointer.m_Pointer] = DeletionMapPointerType::ThreadSafeShared;
//				m_ThreadSafeSharedMap.erase(pointer.m_Pointer);
//				m_ThreadSafeSharedMutex.erase(pointer.m_Pointer);
//			}
//		}
//
//		void FlagUnsafeDelete(const UniquePointer<T>& pointer)
//		{
//			m_UniqueMap[pointer.m_Pointer]--;
//
//			if (m_UniqueMap[pointer.m_Pointer] == 0ull)
//			{
//				m_UniqueMap.erase(pointer.m_Pointer);
//			}
//		}
//		void FlagUnsafeDelete(const SharedPointer<T>& pointer)
//		{
//			m_SharedMap[pointer->m_Pointer]--;
//
//			if (m_SharedMap[pointer.m_Pointer] == 0ull)
//			{
//				m_SharedMap.erase(pointer.m_Pointer);
//			}
//		}
//		void FlagUnsafeDelete(const ThreadSafeSharedPointer<T>& pointer)
//		{
//			m_ThreadSafeSharedMap[pointer->m_Pointer]--;
//
//			if (m_ThreadSafeSharedMap[pointer.m_Pointer] == 0ull)
//			{
//				m_ThreadSafeSharedMap.erase(pointer.m_Pointer);
//				m_ThreadSafeSharedMutex.erase(pointer.m_Pointer);
//			}
//		}
//
//		void AddUniquePointer(T* pointer)
//		{
//			m_UniqueMap[pointer]++;
//
//			m_DeletionMap.erase(pointer);
//		}
//		void AddSharedPointer(T* pointer)
//		{
//			m_SharedMap[pointer]++;
//
//			m_DeletionMap.erase(pointer);
//		}
//		void AddThreadSafeSharedPointer(T* pointer)
//		{
//			m_ThreadSafeSharedMap[pointer]++;
//			m_ThreadSafeSharedMutex.emplace(std::piecewise_construct, std::forward_as_tuple(pointer), std::forward_as_tuple());
//			
//			m_DeletionMap.erase(pointer);
//		}
//
//		void LockThreadSafeSharedPointer(const ThreadSafeSharedPointer<T>& pointer)
//		{
//			m_ThreadSafeSharedMap[pointer->m_Pointer].second.lock();
//		}
//		void UnlockThreadSafeSharedPointer(const ThreadSafeSharedPointer<T>& pointer)
//		{
//			m_ThreadSafeSharedMap[pointer->m_Pointer].second.unlock();
//		}
//
//		void GarbageCollect()
//		{
//			for (auto it : m_DeletionMap)
//			{
//				delete it.first;
//			}
//			m_DeletionMap.clear();
//		}
//	};
//
//	template <class T>
//	class Pointer
//	{
//	protected:
//		T* m_Pointer;
//
//	public:
//		Pointer(T* pointer)
//			: m_Pointer(pointer)
//		{
//		}
//
//		virtual ~Pointer()
//		{
//			Reset();
//		}
//
//		T* Get()
//		{
//			return m_Pointer;
//		}
//
//		virtual T* Release() = 0;
//
//		virtual void Reset() = 0;
//
//		friend class PointerTypeManager<T>;
//	};
//
//	template <class T>
//	class ThreadSafeSharedPointer : public Pointer<T> {
//	public:
//		ThreadSafeSharedPointer(T* pointer)
//			: Pointer(pointer)
//		{
//		}
//
//		virtual T* Release() override
//		{
//			T* pointer = m_Pointer;
//			Reset();
//			return pointer;
//		}
//
//		virtual void Reset() override
//		{
//			// TODO implement this in a separate file where you can #include ProgramInstance.h without causing a circular dependency
//		}
//
//		friend class PointerTypeManager<T>;
//	};
//
//	template <class T>
//	class SharedPointer : public Pointer<T> {
//	public:
//		SharedPointer(T* pointer)
//			: Pointer(pointer)
//		{
//		}
//
//		virtual void Reset() override;
//
//		friend class PointerTypeManager<T>;
//	};
//
//	template <class T>
//	class UniquePointer : public Pointer<T> {
//	public:
//		UniquePointer(T* pointer)
//			: Pointer(pointer)
//		{
//		}
//
//		virtual void Reset() override;
//
//		friend class PointerTypeManager<T>;
//	};
//
//	template <class T>
//	class WeakPointer : public Pointer<T> {
//	public:
//		WeakPointer(T* pointer)
//			: Pointer(pointer)
//		{
//		}
//
//		virtual void Reset() override
//		{
//			m_Pointer = nullptr;
//		}
//
//		SharedPointer<T> ToSharedPointer()
//		{
//			return SharedPointer<T>(m_Pointer);
//		}
//	};
//}