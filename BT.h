// ��������� "�������� ������"
#pragma once
#include <fstream>

namespace BT1
{
		typedef char base;
		struct Node
		{
			Node *leftPtr; //��������� �� ����� ���������
			Node *rightPtr; //��������� �� ������ ��������� 
			base data;
			int theX1, theY1;
			Node () {leftPtr = NULL; rightPtr = NULL;} //�����������
		};
		typedef Node* binTree;

		inline binTree Create(void);
		inline bool isNull(binTree);
		inline base RootBT (binTree); // ��� ��������� ���.������
		inline binTree Left1 (binTree);// ��� ��������� ���.������
		inline binTree Right1 (binTree);// ��� ��������� ���.������
		inline binTree ConsBT(const base &x, binTree &lst,  binTree &rst);
		inline void destroy (binTree&);
		inline binTree enterBT (std::ifstream& in);
		//inline void displayBT (binTree b, int n);
		inline void search (const base x, binTree b,int &k);
		
}