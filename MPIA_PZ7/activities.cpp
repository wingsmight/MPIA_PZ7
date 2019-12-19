#include "activities.h"
#include <fstream>

std::vector<Activity> get_max_activities(const std::vector<Activity> &activities) {
	std::vector<Activity> actt = activities;
	std::vector<Activity> result;
	if (actt.size() <= 1) return actt;
	sort(actt);
	result.push_back(actt.front());
	int i = 0;
	for (int j = 1; j < actt.size(); j++)
	{
		if (actt[j].start >= actt[i].finish)
		{
			result.push_back(actt[j]);
			i = j;
		}
	}
    return result;
}

void Activity::add_act(int Start, int Finish) {
	start = Start;
	finish = Finish;
}

std::vector<Activity> read(const char name[]) {
	std::ifstream f;
	f.open(name);

	std::vector<Activity> data;
	Activity temp;
	int st, fi;
	while (f.peek() != EOF)
	{
		f >> st;
		f >> fi;
		
		temp.add_act(st, fi);
		data.push_back(temp);
	}

	f.close();
	return data;
}

void sort(std::vector<Activity> &to_sort) {
	for (int i = 0; i < to_sort.size()-1; i++)
		for (int j = i+1; j < to_sort.size(); j++)
			if (to_sort[i].finish > to_sort[j].finish) {
				Activity temp = to_sort[i];
				to_sort[i] = to_sort[j];
				to_sort[j] = temp;
			}
}