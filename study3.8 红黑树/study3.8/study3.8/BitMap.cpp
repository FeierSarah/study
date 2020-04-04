#include <vector>
using namespace std;
/*
���ݵ�Ԫ��С�Ĺ�ϣ��
��ϣ����(������Ϊ��ֱ�Ӷ�ַ���� ���Ժ���)�� num  /   32,   num % 32
*/
class BitMap
{
public:
	BitMap(size_t range)
	{
		_array.resize((range >> 5) + 1);
	}

	//�������
	void set(int data)
	{
		//ͨ����ϣ��������λ��
		int idx = data >> 5;
		int bitIdx = data % 32;
		_array[idx] |= (1 << bitIdx);
	}
	//����
	bool test(int data)
	{
		//ͨ����ϣ��������λ��
		int idx = data >> 5;
		int bitIdx = data % 32;
		return (_array[idx] >> bitIdx) & 1;
	}
	//ɾ������
	void reset(int data)
	{
		//ͨ����ϣ��������λ��
		int idx = data >> 5;
		int bitIdx = data % 32;
		_array[idx] &= ~(1 << bitIdx);
	}

private:
	vector<int> _array;
};

void test()
{
	BitMap bm(500);
	bm.set(511);
	bm.set(16);
	bm.set(63);
	bool ret = bm.test(511);
	ret = bm.test(63);
	ret = bm.test(16);
	ret = bm.test(100);
	bm.reset(16);
	ret = bm.test(16);
}

int main()
{
	test();
	return 0;
}