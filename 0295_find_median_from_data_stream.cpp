#include <queue>
#include <iostream>
using namespace std;

class MedianFinder
{
private:
  priority_queue<int, vector<int>> lowNumbers;
  priority_queue<int, vector<int>, greater<int>> highNumbers;
  int size = 0;

public:
  MedianFinder()
  {
  }

  void addNum(int num)
  {
    if (size % 2 == 0)
    {
      if (size == 0 || highNumbers.top() >= num)
      {
        lowNumbers.push(num);
      }
      else
      {
        lowNumbers.push(highNumbers.top());
        highNumbers.pop();
        highNumbers.push(num);
      }
    }
    else
    {
      if (lowNumbers.top() > num)
      {
        highNumbers.push(lowNumbers.top());
        lowNumbers.pop();
        lowNumbers.push(num);
      }
      else
      {
        highNumbers.push(num);
      }
    }
    size++;
  }

  double findMedian()
  {
    if (size % 2 == 0)
    {
      return ((double)lowNumbers.top() + (double)highNumbers.top()) / 2.0;
    }

    return (double)lowNumbers.top();
  }
};

int main(int argc, char *argv[])
{
  MedianFinder medianFinder = MedianFinder();
  medianFinder.addNum(-1);
  cout << medianFinder.findMedian() << endl;
  medianFinder.addNum(-2);
  cout << medianFinder.findMedian() << endl;
  medianFinder.addNum(-3);
  cout << medianFinder.findMedian() << endl;
  medianFinder.addNum(-4);
  cout << medianFinder.findMedian() << endl;
  medianFinder.addNum(-5);
  cout << medianFinder.findMedian() << endl;
  return 0;
}
