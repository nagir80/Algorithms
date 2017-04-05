#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;

struct Segment {
  int start, end;
};

vector<int> optimal_points(vector<Segment> &segments) {
  vector<int> points;
  //write your code here
  vector<Segment> help(segments);

  while (help.size()>0) {
	  vector<int> right;
	  vector<Segment> *help2 = new vector<Segment>(help);
	  help.clear();
	  for (Segment s : *help2) {
		  right.push_back(s.end);
	  }
	  std::sort(right.begin(), right.end());
	  points.push_back(right[0]);
	  for (Segment s : *help2) {
		  if ((right[0] < s.start) || (right[0] > s.end))
			  help.push_back(s);
	  }
	  right.clear();
	  delete help2;
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
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}
