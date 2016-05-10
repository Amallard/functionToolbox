/*
 *   Description: This function merges two sorted arrays (vector<int>) into one sorted array.
 */

std::vector<int> mergeSorted(std::vector<int> a, std::vector<int> b) {
  std::vector<int> newArray;
  int i = 0, j = 0;
    
  while (i < a.size() && j < b.size()) {
    if (a[i] < b[j]) {
      newArray.push_back(a[i++]);
    } else {
       newArray.push_back(b[j++]);
    }
  }
  while (i < a.size()) {
    newArray.push_back(a[i++]);
  }
  while (j < b.size()) {
    newArray.push_back(b[j++]);
  }
  
  return newArray;
}
