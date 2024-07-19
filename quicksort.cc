#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int> &a, int l, int r, int p)
{
    // does partitioning on the array a[l .. r] (inclusive)
    // requirements:
    // l <= p <= r
    if (!(l <= p && p <= r))
    {
        cout << "requirements of partition violated\n";
    }

    swap(a[p], a[r]); // now pivot element is at the rightmost

    // loop invariant:
    // elements in a[l .. i-1] are < a[p]
    // elements in a[i .. j-1] are >= a[p]
    // i <= j
    int i = l;
    for (int j = l; j < r; ++j)
    {
        if (a[j] < a[r])
        {
            swap(a[i], a[j]);
            ++i;
        }
    }

    swap(a[r], a[i]);

    return i;
}

void quicksort(vector<int> &a, int l, int r)
{
    // sorts a[l .. r] (inclusive)

    if (l > r)
        return;

    int p = (l + r) / 2; // choose pivot from [l, r]
    p = partition(a, l, r, p);
    quicksort(a, l, p - 1);
    quicksort(a, p + 1, r);
}

int main()
{
    int n;
    cout << "Enter the size of the array:\n";
    cin >> n;
    vector<int> a(n);
    cout << "Enter the elements of the array:\n";
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}

// todo: add some test cases
