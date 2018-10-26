#include <iostream>
#include <vector>
#include <array>
#include <cmath>

double mean(int* arr, int size) {
  double out = 0;
  for(int i = 0; i < size; i++)
    out += arr[i];

  return out/(double)size;
}

double std_dev(int* arr, int size, double mean) {
  double out = 0;
  for(int i = 0; i < size; i++)
    out += arr[i]*arr[i];
  return sqrt(out/(double)size-mean*mean);
}

int findBestRoute(std::array<double, 2> r1, std::array<double, 2> r2) { //1 if r1, 2 if r2, 0 otherwise
  if(r1[0] < r2[0] && r1[1] < r2[1])
    return 1;
  else if(r1[0] > r2[0] && r1[1] > r2[1])
    return 2;
  return 0;
}

int main(int argc, char* argv[]) {
  int r, n, *nums, best;
  double m, s;
  std::vector<std::array<double, 2>> routes;

  while(true) {
    std::cin >> r;

    if(r == 0) break;

    for(int processed = 0; processed < r; processed++) {
      std::cin >> n;
      nums = new int[n];
      for(int i = 0; i < n; i++) {
        std::cin >> nums[i];
      }

      m = mean(nums, n);
      s = std_dev(nums, n, m);
      delete[] nums;

      routes.push_back(std::array<double, 2>{m, s});
    }
    best = 1;
    for(unsigned int i = 2; i < r; i++) {
      if (findBestRoute(routes[best], routes[i]) == 2) {
          best = i;
      }
    }

    if (!((routes[0][0]>=routes[best][0]) && (routes[0][1]>routes[best][1]+5))) {
      best = 0;
    }

    printf("%d %.2f %.2f\n", best+1, routes[best][0], routes[best][1]);

    routes.clear();
  }

  return 0;
}
