#include "heap.h"

void Heap::up(int c) { //���������� ���� �����
	int p;
	p = c / 2; //�������� ����� �������� �������� � �������
	if (p == 0) return; //���� �������� ���, �� ������������
	if (h[p].date > h[c].date) { //���� ��������� �������� ���� ���������� �������
		Item tmp;
		tmp = h[p];
		h[p] = h[c];
		h[c] = tmp; //������ �������� � ������� �������
		up(p); //��������� ���������� ��������
	}
}

void Heap::down(int p) { //���������� ���� ������
	int c;
	c = 2 * p; //������� ����� �������� ������� ������� � �������
	if (c > size) return; //���� ������ ������� ���, �� ������������
	if (c + 1 <= size && h[c + 1].date < h[c].date) //��������� ���� �� ������ ������� � �������� ������� � ���������� �����������
	{c++;}; //���� � ������� ������� ��������� ����, �� ��������� � ����
	if (h[c].date < h[p].date) { //���� ��������� ������� ���� ���������� ��������
		Item tmp;
		tmp = h[c]; 
		h[c] = h[p]; 
		h[p] = tmp; //������ �� �������
		down(c); //��������� ���������� ������� (������������ ������� ��������� �� ��������) 
	}
}

Heap::Heap(int n) {
	size = 0; //���������� ��������� � ����=0
	h = (Item*)malloc(sizeof(Item) * n); //������������ ��������� ������ ��� n ���������
}

Heap::~Heap() {
	if (h) free(h); //������������ ������ ��-��� ����
}

void Heap::add(Guest* g, int arrivalDate) { //���������� ��������
	Item x;
	x.g = g; x.date = arrivalDate;
	h[++size] = x; //���������� � ��������� ������� ���� ����� �������
	up(size); //���������� ���� ����� 
}

Guet* Heap::extract_min() {
	if (size == 0) return NULL; //���� � ���� ��� ���������
    return h[1].g; //�������� ���������� ����, ����������� ������� - ������ 
	h[1] = h[size]; //���������� � ������ ������� ���������
	down(1); //���������� ���� ������
}
