#include <random>
using namespace std;
int GetRandomNum(int min, int max)
{
	random_device seed;		//Ӳ���������������
	ranlux48 engine(seed());	//���������������������
	uniform_int_distribution<> distrib(min, max);	//�����������Χ����Ϊ���ȷֲ�
	return distrib(engine);
}