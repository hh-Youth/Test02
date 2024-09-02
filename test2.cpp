////实现标准库头文件<numeric>中accumulate函数的并行版本
//#include <iostream>
//#include <thread>
//#include <numeric>
//#include <algorithm>
//#include <vector>
//#include <functional>
//#include <utility>
//#include <windows.h>
//
//
//using std::thread;
//using std::vector;
//using std::accumulate;
//using std::cout;
//using std::endl;
//
//// 被执行的函数
//
//	void accum(int f, int t, vector<int>& nums, int& maxs)
//	{
//		
//		int x = 0;
//		for (int i = f; i < t; i++)
//		{
//			x = nums[i];
//			maxs = max(maxs, abs(x));
//			// 休眠2秒
//			//std::chrono::seconds sleep_duration(1);
//			//std::this_thread::sleep_for(sleep_duration);
//			for (int j = i + 1; j < (nums.end() - nums.begin()); j++)
//			{
//
//				x += nums[j];
//				maxs = max(maxs, abs(x));
//
//			}
//		}
//	}
//
//
//	// 计时结构
//	LARGE_INTEGER t1, t2, tc;
//
//	void time_begin()
//	{
//		QueryPerformanceFrequency(&tc);
//		QueryPerformanceCounter(&t1);
//	}
//
//	float time_end()
//	{
//		QueryPerformanceCounter(&t2);
//		return ((t2.QuadPart - t1.QuadPart) * 1.0 / tc.QuadPart) * 1000;
//	}
//
//
//
//int main() {
//
//	vector<int> v = {-10, -5, -3, -3, -9, 0, 10, 10, 5, 5, 1, 1, 2, 4, 1, 10, -3, 7, -3, -10};
//	vector<int> res(1);
//	int maxs = 0;
//	
//	
//	
//	
//	
//
//	std::vector<std::thread> threads(1);
//	threads[0] = thread(ref(accum), 0, 20, ref(v), std::ref(res[0]));
//	//threads[1] = thread(ref(accum), 11, 20, ref(v), std::ref(res[1]));
//	/*threads[2] = thread(ref(accum), 10, 14, ref(v), std::ref(res[2]));
//	threads[3] = thread(ref(accum), 15, 18, ref(v), std::ref(res[3]));
//	threads[4] = thread(ref(accum), 19, 20, ref(v), std::ref(res[4]));*/
//
//	time_begin();
//	for_each(threads.begin(), threads.end(), std::mem_fn(&thread::join));
//	
//	
//
//	for (int i = 0; i < 1; i++)
//	{
//		maxs = max(maxs, res[i]);
//	}
//	cout << "time: " << time_end() << ", max = " << maxs << endl;
//
//
//
//	// 一般计算示例
//	time_begin();
//
//	accum(0, 20, v, maxs);
//	cout << "time: " << time_end() << ", sum = " << maxs << endl;
//	
//
//}


#include <iostream>
#include <vector>
#include <map>
using namespace std;


class Pe {

public:
	Pe():x(1) {

	}
	Pe(int x) {
		this->x = x;
	}
	void pr() {
		cout << "666";
	}

	int x;
};



int main2() {

	/*vector<int> v1 = { 1,2,3,4,5 };
	vector<int> v2{ 1,2,3,4,5 };

	Pe* p=new Pe(2);

	p->pr();

	int x = 10;
	int&& a = 100;*/

	int dist[20];
	memset(dist, 0x3f, sizeof dist);
	for (int i = 0; i < 20; i++)
	{
		cout << dist[i]<<"  ";
	}

	return 0;
}