#pragma once
#include "list.h"


class Hotel {
	public:
		//Heap guestsOfDec;
		List rooms;   // ������� ������ ������
		Hotel();   // �����������
		~Hotel();  // ����������
		List freeRooms(); //������� ��������� �������
		void showRooms(); //�������� ��� �������
		void showRooms(List); //�������� ��������� �������
		int settle(Guest*); //�������� ������ �����. �� ������ - ����� �������, � ������� �� ��� �������.
		void moveOut(int); //�������� ����� �� ������� num

};