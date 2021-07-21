#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool sortbysec(const pair<int,int> &a, const pair<int,int> &b)
{
    return a.second==b.second?a.first<b.first:a.second<b.second;
}

int countActivites(vector<pair<int,int> > activities){
    
    if (activities.size() <= 1) 
			return activities.size();

    sort(activities.begin(), activities.end(), sortbysec);
    int count = 1;
    int n = activities.size();
    int i = 0;
    // cout << "(" << activities[i].first << ", " << activities[i].second << "), ";
    for (int j = 1; j < n; j++)
    {
      // If this activity has start time greater than or
      // equal to the finish time of previously selected
      // activity, then select it
      if (activities[j].first >= activities[i].second)
      {
          // cout << "(" << activities[j].first << ", "
          //     << activities[j].second << "), ";
          i = j;
          count++;
      }
    }
    
    return count;
    
}


int main() {
	vector<pair<int, int>> activities = {{7,9}, {0,10}, {4,5}, {8,9}, {4,10}, {5,7}};
	int ans = countActivites(activities);
	cout<<ans<<endl;
	return 0;
}

