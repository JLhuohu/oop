#include "TerrainBoardUnit.h"

QJsonObject TerrainBoardUnit::getSnapshot() {
	QJsonObject terrainUnitSnapshot;//�� ���������� json-���� ������
	terrainUnitSnapshot.insert("type", "terrain");//������� ��������� � ���� ��� � ��������(������)
	terrainUnitSnapshot.insert("subtype", getName().c_str());//� ��� ��� �� ����� ��� ����� �����(�����)
	return terrainUnitSnapshot;
}