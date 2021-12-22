#include<iostream>
#include<vector>
using namespace std;

class Sort
{
public:
	//1.√∞≈›
	void bubbleSort(vector<int> &v)
	{
		for (int i = 0; i < v.size(); ++i)
		{
			for (int j = 0 ; j < v.size() - i - 1; ++j)
			{
				if (v[j] > v[j + 1])
				{
					swap(v[j], v[j + 1]);
				}
			
			}
		}
	}
	//2.—°‘Ò
	void selectSort(vector<int>& v)
	{
		for (int i = 0; i < v.size(); ++i)
		{
			int minIndex = i, min = v[i];
			for (int j = i + 1 ; j < v.size() ; ++j)
			{
				if (v[j] < min)
				{
					minIndex = j;
					min = v[j];
				}
			}
			if(i!=minIndex) swap(v[i], v[minIndex]);
		}
	}

	//3.≤Â»Î
	void insertSort(vector<int>& v)
	{
		for (int i = 1; i < v.size(); ++i)
		{
			int pre = i - 1;
			int cur = v[i];
			while (pre >= 0 && v[pre] > cur)
			{
				v[pre + 1] = v[pre];
				pre--;
			}
			v[pre + 1] = cur;
		}
	}
	//4.œ£∂˚≈≈–Ú
	void shellSort(vector<int>& v)
	{
		int gap = v.size();
		while (gap > 1)
		{
			gap = gap / 3 + 1;
			for (int i = 0; i < v.size() - gap; ++i)
			{
				int end = i;
				int tmp = v[end + gap];
				while (end >= 0 && v[end] > tmp)
				{
					v[end + gap] = v[end];
					end -= gap;
				}
				v[end + gap] = tmp;
		
			}
		}
	}

	//5.πÈ≤¢≈≈–Ú
	void mergeSort(vector<int>& v)
	{
		merge(v, 0, v.size() - 1);
	}

	void merge(vector<int>& v,int l,int r)
	{
		int m = (l + r) / 2;
		if ((r - l) >= 1)
		{
			merge(v, l, m);
			merge(v, m+1, r);
		}
		if (l == r)return;
		vector<int> tmp;
		int i = l, j = m + 1;
		while (i <= m && j <= r)
		{
			if (v[i] < v[j])
			{
				tmp.push_back(v[i]);
				++i;
			}
			else
			{
				tmp.push_back(v[j]);
				++j;
			}
		}
		while (i <= m)
		{
			tmp.push_back(v[i]);
			++i;
		}
		while (j <= r)
		{
			tmp.push_back(v[j]);
			++j;
		}
		for (int k = 0; k < tmp.size(); ++k)
		{
			v[l+k] = tmp[k];
		}
	}

	//6.—°‘Ò≈≈–Ú
	void quickSort(vector<int>& v)
	{
		quick(v, 0, v.size() - 1);
	}

	void quick(vector<int>& v, int l, int r)
	{
		if (l >= r)
		{
			return;
		}
		int base = v[r];
		int i = l, j = l;
		while (j <= r - 1)
		{
			if (v[j] < base)
			{
				swap(v[i], v[j]);
				i++;
			}
			j++;
		}
		swap(v[i], v[r]);
		quick(v, l, i - 1);
		quick(v, i + 1, r);
	}

	//Ωªªª
	void swap(int& a, int& b)
	{
		int t = a;
		a = b;
		b = t;
	}
};

int main()
{
	Sort s;

	vector<int> v= {5,9,2,1,6,7,4};

	//s.bubbleSort(v);
	//s.selectSort(v);
	//s.insertSort(v);
	//s.shellSort(v);
	//s.mergeSort(v);
	s.quickSort(v);

	for (int i = 0; i != v.size(); ++i)
	{
		cout << v[i] << "  " << endl;
	}
}