#include<vector>
#include<isotream>
using namespace std;

//�������뵽�ķ�����ö�������е�ÿһ���� x��Ѱ���������Ƿ���� target - x��
//������ʹ�ñ�����������ķ�ʽѰ�� target - x ʱ��
//��Ҫע�⵽ÿһ��λ�� x ֮ǰ��Ԫ�ض��Ѿ��� x ƥ�����
//��˲���Ҫ�ٽ���ƥ�䡣��ÿһ��Ԫ�ز��ܱ�ʹ�����Σ���������ֻ��Ҫ�� x �����Ԫ����Ѱ�� target - x


class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		int n = nums.size();
		for (int i = 0; i < n; ++i)
		{
			for (int j = i + 1; j < n; ++j)
			{
				if (nums[i] + nums[j] == target)
				{
					return{ i, j };
				}
			}
		}
		return{};
	}
};