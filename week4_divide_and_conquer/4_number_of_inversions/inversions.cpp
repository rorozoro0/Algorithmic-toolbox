#include <iostream>
#include <vector>
#define ll long long
using std::vector;
ll merge(vector<int> &arr,int temp[], int l, int m, int r)
{
    int i, j, k;
    ll c=0;
    i = l;
    j = m;
    k = l;
    while ((i <= m - 1) && (j <= r)) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];


            c = c+ (m - i);
        }
    }
    while (i <= m - 1)
        temp[k++] = arr[i++];
    while (j <= r)
        temp[k++] = arr[j++];
    for (i = l; i <= r; i++)
        arr[i] = temp[i];
    return c;
}
ll mergeSort(vector<int> &arr, int temp[], int l, int r)
{
    ll c=0;
    int m;
    if (l < r)
    {
        m = (l+r)/2;
        c+=mergeSort(arr,temp, l, m);
        c+=mergeSort(arr,temp, m+1, r);

        c+=merge(arr,temp, l, m+1, r);
    }
    return c;
}

long long get_number_of_inversions(vector<int> &a, vector<int> &b, int left, int right) {
  long long number_of_inversions = 0;
  int temp[a.size()];
  number_of_inversions = mergeSort(a,temp,left,right-1);
  //write your code here
  return number_of_inversions;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  vector<int> b(a.size());
  std::cout << get_number_of_inversions(a, b, 0, a.size()) << '\n';
}
