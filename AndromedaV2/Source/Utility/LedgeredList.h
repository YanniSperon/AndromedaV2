#pragma once

#include "IntDefinitions.h"
#ifdef AD_DEBUG
#include "Global.h"
#include <sstream>
#endif

#define DEFAULT_LIST_INCREMENT 64ull

namespace Andromeda
{
	template <class T>
	class LedgeredList
	{
	private:
		struct Node
		{
		public:
			T m_Val;
			Node* m_Prev;
			Node* m_Next;
		};

		Node* m_Head;
		Node* m_Tail;
		Array<Node*> m_Ledger;

		uint64 m_Size;
		uint64 m_Increment;

		Node* GetNodeAndIndices(uint64 nodeIndex, uint64& ledgerIndex, uint64& ledgerIncrement) const
		{
			ledgerIndex = nodeIndex / m_Increment;
			ledgerIncrement = nodeIndex % m_Increment;

			Node* cursor = nullptr;
			if (ledgerIncrement > (m_Increment / 2ull) &&
				(ledgerIndex + 1ull) < m_Ledger.size())
			{
				cursor = m_Ledger[ledgerIndex + 1ull];
				for (uint64 i = 0ull; i < (m_Increment - ledgerIncrement); ++i)
				{
					cursor = cursor->m_Prev;
				}
			}
			else
			{
				cursor = m_Ledger[ledgerIndex];
				for (uint64 i = 0ull; i < ledgerIncrement; ++i)
				{
					cursor = cursor->m_Next;
				}
			}
			return cursor;
		}

	public:
		LedgeredList()
			: m_Ledger(), m_Size(0ull), m_Increment(DEFAULT_LIST_INCREMENT), m_Head(nullptr), m_Tail(nullptr)
		{
		}

		LedgeredList(uint64 increment)
			: m_Ledger(), m_Size(0ull), m_Increment(increment == 0ull ? 1ull : increment), m_Head(nullptr), m_Tail(nullptr)
		{
		}

		LedgeredList(const LedgeredList& other)
			: m_Ledger(), m_Size(0ull), m_Increment(other.m_Increment), m_Head(nullptr), m_Tail(nullptr)
		{
			m_Ledger.reserve(other.m_Ledger.max_size());
			Node* otherCurrentNode = other.m_Head;
			for (uint64 i = 0; i < m_Size; ++i)
			{
				PushBack(otherCurrentNode->m_Val);
				otherCurrentNode = otherCurrentNode->m_Next;
			}
		}

		LedgeredList(LedgeredList&& other) noexcept
			: m_Ledger(std::move(other.m_Ledger)), m_Size(other.m_Size), m_Increment(other.m_Increment), m_Head(other.m_Head), m_Tail(other.m_Tail)
		{
			other.m_Size = 0ull;
			other.m_Increment = DEFAULT_LIST_INCREMENT;
			other.m_Head = nullptr;
			other.m_Tail = nullptr;
		}

		~LedgeredList()
		{
			Node* cursor = m_Head;
			Node* lastCursor = nullptr;
			for (uint64 i = 0ull; i < m_Size; ++i) {
				lastCursor = cursor;
				cursor = cursor->m_Next;
				delete lastCursor;
			}
		}

		T& operator[](uint64 index)
		{
			return Get(index);
		}

		T& Get(uint64 index)
		{
#ifdef AD_DEBUG
			if (index >= m_Size)
			{
				Global::GetConsoleInstance().FatalError("Index %llu out of bounds", index);
			}
#endif
			uint64 ledgerIndex, ledgerIncrement;
			return GetNodeAndIndices(index, ledgerIndex, ledgerIncrement)->m_Val;
		}

		void Insert(const T& value, uint64 index)
		{
			if (index > 0 && index < m_Size)
			{
				uint64 ledgerIndex, ledgerIncrement;
				Node* cursor = GetNodeAndIndices(index, ledgerIndex, ledgerIncrement);

				Node* newNode = new Node();
				newNode->m_Prev = cursor->m_Prev;
				if (cursor->m_Prev)
				{
					cursor->m_Prev->m_Next = newNode;
				}
				cursor->m_Prev = newNode;
				newNode->m_Next = cursor;
				newNode->m_Val = value;

				for (uint64 i = ((ledgerIncrement == 0ull) ? ledgerIndex : ledgerIndex + 1ull); i < m_Ledger.size(); ++i)
				{
					m_Ledger[i] = m_Ledger[i]->m_Prev;
				}

				++m_Size;

				if (m_Size % m_Increment == 0ull)
				{
					m_Ledger.push_back(m_Tail);
				}
			}
			else if (index == 0ull)
			{
				PushFront(value);
			}
			else if (index == m_Size)
			{
				PushBack(value);
			}
#ifdef AD_DEBUG
			else
			{
				Global::GetConsoleInstance().Error("Index %llu out of range", index);
			}
#endif
		}

		void PushFront(const T& value)
		{
			Node* prevHead = m_Head;
			m_Head = new Node();
			m_Head->m_Next = prevHead;
			m_Head->m_Val = value;

			if (prevHead)
			{
				prevHead->m_Prev = m_Head;
			}
			else
			{
				m_Tail = m_Head;
				m_Ledger.push_back(m_Head);
			}

			for (uint64 i = 0ull; i < m_Ledger.size() - 1ull; ++i)
			{
				m_Ledger[i] = m_Ledger[i]->m_Prev;
			}

			++m_Size;

			if (m_Size % m_Increment == 0)
			{
				m_Ledger.push_back(m_Tail);
			}
		}

		void PushBack(const T& value)
		{
			Node* prevTail = m_Tail;
			m_Tail = new Node();
			m_Tail->m_Prev = prevTail;
			m_Tail->m_Val = value;
			if (prevTail)
			{
				prevTail->m_Next = m_Tail;
			}
			else
			{
				m_Tail = m_Head;
				m_Ledger.push_back(m_Head);
			}

			++m_Size;

			if (m_Size % m_Increment == 0)
			{
				m_Ledger.push_back(m_Tail);
			}
		}

		void Remove(uint64 index)
		{
			if (m_Size > 0)
			{
				if (index == 0)
				{
					PopFront();
				}
				else if (index == m_Size - 1ull)
				{
					PopBack();
				}
				else
				{
					uint64 ledgerIndex, ledgerIncrement;
					Node* cursor = GetNodeAndIndices(index, ledgerIndex, ledgerIncrement);
				
					if (cursor->m_Prev)
					{
						cursor->m_Prev->m_Next = cursor->m_Next;
					}
					if (cursor->m_Next)
					{
						cursor->m_Next->m_Prev = cursor->m_Prev;
					}

					delete cursor;

					--m_Size;

					for (uint64 i = ((ledgerIncrement == 0ull) ? ledgerIndex : ledgerIndex + 1ull); i < m_Ledger.size(); ++i)
					{
						m_Ledger[i] = m_Ledger[i]->m_Next;
					}
					if (!m_Ledger[m_Ledger.size() - 1ull])
					{
						m_Ledger.pop_back();
					}
				}
			}
		}

		void PopFront()
		{
			if (m_Size > 0)
			{
				if (m_Size == 1)
				{
					m_Tail = nullptr;
				}
				else
				{
					m_Head->m_Next->m_Prev = nullptr;
				}
				Node* prevHead = m_Head;
				m_Head = m_Head->m_Next;
				delete prevHead;

				--m_Size;

				for (uint64 i = 0ull; i < m_Ledger.size(); ++i)
				{
					m_Ledger[i] = m_Ledger[i]->m_Next;
				}

				if (!m_Ledger[m_Ledger.size() - 1ull])
				{
					m_Ledger.pop_back();
				}
			}
		}

		void PopBack()
		{
			if (m_Size > 0)
			{
				if (m_Size == 1)
				{
					m_Head = nullptr;
				}
				else
				{
					m_Tail->m_Prev->m_Next = nullptr;
				}
				Node* prevTail = m_Tail;
				m_Tail = m_Tail->m_Prev;
				delete prevTail;

				--m_Size;

				if (m_Size < m_Ledger.size() * m_Increment)
				{
					m_Ledger.pop_back();
				}
			}
		}

#ifdef AD_DEBUG
		String ToString() {
			Node* cursor = m_Head;
			std::stringstream ss;

			ss << "Size: " << m_Size << "\nIncrement: " << m_Increment << "\nHead: " << m_Head << " - " << m_Head->m_Val << "\nTail: " << m_Tail << " - " << m_Tail->m_Val << "\n\nData:\n[\n";
			for (uint64 i = 0ull; i < m_Size; ++i)
			{
				ss << "    " << i << ": " << cursor << " - " << cursor->m_Val << '\n';
				cursor = cursor->m_Next;
			}

			ss << "]\n\nLedger:\n[\n";
			for (uint64 i = 0ull; i < m_Ledger.size(); ++i)
			{
				ss << "    " << i << ": " << m_Ledger[i] << " - " << m_Ledger[i]->m_Val << '\n';
			}
			ss << "]\n";

			return ss.str();
		}
#endif
	};
}