#pragma once  
/**
*A*�㷨������
*/
#include <vector>  
#include <list>  

//����
const int kCost1 = 10; //ֱ��һ������  
const int kCost2 = 14; //б��һ������  

struct Point
{
	int x, y; //�����꣬x������ţ�y��������  
	int F, G, H; //F=G+H  
	Point *parent; //parent�����꣬����û����ָ�룬�Ӷ��򻯴���  
	Point(int _x, int _y) :x(_x), y(_y), F(0), G(0), H(0), parent(0){}  //������ʼ��  
};


class Astar
{
private:
	std::vector<std::vector<int> > maze; //��Ŷ�ά����
	std::list<Point *> openList;  //�����б�  
	std::list<Point *> closeList; //�ر��б�  
public:
	//�����õ���ͼ����
	void InitAstar(std::vector<std::vector<int> > &_maze);
	//�����õ���һ�ڵ�ĺ���
	std::list<Point *> GetPath(Point &startPoint, Point &endPoint, bool isIgnoreCorner);

private:
	//����·���ĺ���
	Point *findPath(Point &startPoint, Point &endPoint, bool isIgnoreCorner);
	//�����õ���ǰ�ڵ���Χ�ڵ�ĳ���Ա����
	std::vector<Point *> getSurroundPoints(const Point *point, bool isIgnoreCorner) const;
	//�ж�ĳ���Ƿ����������һ���жϵĳ�����
	bool isCanreach(const Point *point, const Point *target, bool isIgnoreCorner) const;
	//�жϿ���/�ر��б����Ƿ����ĳ��ĳ�����  
	Point *isInList(const std::list<Point *> &list, const Point *point) const; 
	//�ӿ����б��з���Fֵ��С�Ľڵ�  
	Point *getLeastFpoint(); 
	//����F��G��Hֵ  
	int calcG(Point *temp_start, Point *point);
	int calcH(Point *point, Point *end);
	int calcF(Point *point);
};
