#include <algorithm>
#include <iostream>
//#include <climits>
#include <vector>

using std::vector;

struct Segment {
  int start, end;
};
bool compare_t(Segment k1 ,Segment k2)
{
    return (k1.start<k2.start);
}

vector<int> optimal_points(vector<Segment> &segments) {
  vector<int> points;
  //write your code here
  for (size_t i = 0; i < segments.size();) {
    int max=i,min=i;
    while(segments[i].start<=segments[min].end && i<segments.size())
    {
        if(segments[i].end<segments[min].end)
        {
            min=i;
        }
        i++;
    }
    points.push_back(segments[min].end);
  }
  return points;
}

int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }
  sort(segments.begin(),segments.end(),compare_t);
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}
